from socket import *
serverPort = 80
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(('', serverPort))
serverSocket.listen(1)
print 'The server is ready to receive'
while 1:
    connectionSocket, addr = serverSocket.accept()
    sentence = connectionSocket.recv(2048)
    print sentence
    connectionSocket.send('HTTP/1.1 400 Not Found\
    Server: ECHO\
    Content-Type: text/html\
    Content-Length: 3\
    Connection: close\
    \
    404')
    connectionSocket.close()
