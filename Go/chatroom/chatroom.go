package main

import (
	"os"
	"net"
	"fmt"
)

// 错误检查
func checkError(err error, info string) (res bool) {
	if err != nil {
		fmt.Println(info + " " + err.Error())
		return false
	}
	return true
}

// 服务器端接收数据线程
func Handler(conn net.Conn, message chan string)  {
	fmt.Println("connection is connected from ...", conn.RemoteAddr().String())

	buf := make([]byte, 1024)
	for {
		length, err := conn.Read(buf)
		if !checkError(err, "Connection") {
			conn.Close()
			break
		}
		if length > 0 {
			buf[length] = 0
		}
		//fmt.Println("Rec[", conn.RemoteAddr().String(),"] Say :", string(buf[0:length]))
		receiveStr := string(buf[0:length])
		message <- receiveStr
	}
}

// 服务器发送数据线程
func echoHandler(conns *map[string]net.Conn, messages chan string)  {
	for {
		msg := <- messages
		fmt.Println(msg)
		for key, value := range *conns {
			fmt.Println("connection is connected from ...", key)
			_, err := value.Write([]byte(msg))
			if err != nil {
				fmt.Println(err.Error())
				delete(*conns, key)
			}
		}
	}
}

// 启动服务器
func startServer(port string)  {
	service := ":" + port
	tcpAddr, err := net.ResolveTCPAddr("tcp4", service)
	checkError(err, "ResoveTCPAddr")
	l, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err, "ListenTCP")
	conns := make(map[string]net.Conn)
	messages := make(chan string, 10)
	// 启动服务器广播线程
	go echoHandler(&conns, messages)

	for {
		fmt.Println("Listening ...")
		conn, err := l.Accept()
		checkError(err, "Accept")
		fmt.Println("Accepting ...")
		conns[conn.RemoteAddr().String()] = conn
		// 启动一个新线程
		go Handler(conn, messages)
	}
}

// 客户端发送线程
func chatSend(conn net.Conn)  {
	var input string
	username := conn.LocalAddr().String()
	fmt.Println("You can input message now(input '/quit' to quit)")
	for {
		fmt.Scanln(&input)
		fmt.Println("Your input: ", input)
		if input == "/quit" {
			fmt.Println("ByeBye..")
			conn.Close()
			os.Exit(0)
		}

		lens, err := conn.Write([]byte(username + " Say :::" + input))
		fmt.Println(lens)
		if err != nil {
			fmt.Println(err.Error())
			conn.Close()
			break
		}
	}
}

// 客户端启动函数
func startClient(tcpaddr string)  {
	tcpAddr, err := net.ResolveTCPAddr("tcp4", tcpaddr)
	checkError(err, "ResoveTCPAddr")
	conn, err := net.DialTCP("tcp", nil, tcpAddr)
	if !checkError(err, "DialTCP") {
		fmt.Println("Can not connect to server ...Exit")
		os.Exit(0)
	}
	// 启动客户端发送线程
	go chatSend(conn)

	// 开始客户端轮询
	buf := make([]byte, 1024)
	for {
		length, err := conn.Read(buf)
		if !checkError(err, "Connection") {
			conn.Close()
			fmt.Println("Server is dead ...ByeBye")
			os.Exit(0)
		}
		fmt.Println(string(buf[0:length]))
	}
}

// 启动服务端：chatroom server [port]	
//				eg: chatroom server 9090
// 启动客户端：chatroom client [server ip addr]:[server port]
//				eg: chatroom client 127.0.0.1:9090
func main() {
	if len(os.Args) == 3 {
		switch os.Args[1] {
		case "server":
			startServer(os.Args[2])
		case "client":
			startClient(os.Args[2])
		}
	} else {
		fmt.Println("Wrong pare")
		os.Exit(0)
	}
}