# 一个简单的 Restful 风格的 API

Gin 框架 + MySQL 驱动

`$ go get github.com/gin-gonic/gin`

`$ go get github.com/go-sql-driver/mysql`

```
.
|-- apis
|   `-- person.go
|-- db
|   `-- mysql.go
|-- main.go
|-- models
|   `-- person.go
|-- router.go
`-- scheme.sql
```

`$ mysql -u user -p test < scheme.sql`

`$ go run *.go`

## It works

```sh
$ curl http://127.0.0.1:8080
It works
```

## CURD 增删改查

### 增

```sh
 $ curl -X POST http://127.0.0.1:8080/person -d "first_name=hello&last_name=world"
 {"msg":"insert successful 1"}

 $ curl -X POST http://127.0.0.1:8080/person -d "first_name=myfirst&last_name=mylast"
 {"msg":"insert successful 2"}

 $ curl -X POST http://127.0.0.1:8080/person -d "first_name=ming&last_name=xiao" | python -m json.tool
   % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100    59  100    29  100    30  13557  14025 --:--:-- --:--:-- --:--:-- 30000
{
    "msg": "insert successful 3"
}
 ```

### 查

```sh
$  curl http://127.0.0.1:8080/persons | python -m json.tool
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100   164  100   164    0     0   165k      0 --:--:-- --:--:-- --:--:--  160k
{
    "persons": [
        {
            "first_name": "hello",
            "id": 1,
            "last_name": "world"
        },
        {
            "first_name": "myfirst",
            "id": 2,
            "last_name": "mylast"
        },
        {
            "first_name": "ming",
            "id": 3,
            "last_name": "xiao"
        }
    ]
}

$ curl http://127.0.0.1:8080/person/1 | python -m json.tool
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100    60  100    60    0     0  26041      0 --:--:-- --:--:-- --:--:-- 60000
{
    "person": {
        "first_name": "hello",
        "id": 1,
        "last_name": "world"
    }
}
```

### 改

```sh
# 使用 urlencode 方式更新
$  curl -X PUT http://127.0.0.1:8080/person/2 -d "first_name=yang&last_name=zhang"
{"msg":"Update person 2 successful 1"}

# 使用 json 方式更新
$  curl -X PUT http://127.0.0.1:8080/person/1 -H "Content-Type: application/json" -d '{"first_name": "xing", "last_name": "wu"}'
{"msg":"Update person 1 successful 1"}
```

### 删

```sh
$ curl -X DELETE http://127.0.0.1:8080/person/3
{"msg":"DELETE person 3 successful 1"}
```

```sh
$ curl http://127.0.0.1:8080/persons | python -m json.tool
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
100   108  100   108    0     0  56603      0 --:--:-- --:--:-- --:--:--  105k
{
    "persons": [
        {
            "first_name": "xing",
            "id": 1,
            "last_name": "wu"
        },
        {
            "first_name": "yang",
            "id": 2,
            "last_name": "zhang"
        }
    ]
}
```
