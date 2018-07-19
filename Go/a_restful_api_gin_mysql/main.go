package main

import (
	"./db"
)

func main() {

	defer db.SqlDB.Close()

	router := initRouter()

	router.Run(":8080")
}
