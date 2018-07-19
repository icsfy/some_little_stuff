package apis

import (
	"fmt"
	"log"
	"net/http"
	"strconv"

	. "../models"

	"github.com/gin-gonic/gin"
)

func IndexApi(c *gin.Context) {
	c.String(http.StatusOK, "It works")
}

func AddPersonApi(c *gin.Context) {
	firstName := c.Request.FormValue("first_name")
	lastName := c.Request.FormValue("last_name")

	person := Person{FirstName: firstName, LastName: lastName}

	ra, err := person.AddPerson()
	if err != nil {
		log.Fatalln(err)
	}
	msg := fmt.Sprintf("insert successful %d", ra)
	c.JSON(http.StatusOK, gin.H{
		"msg": msg,
	})
}

func GetPersonsApi(c *gin.Context) {
	var person Person
	persons, err := person.GetPersons()
	if err != nil {
		log.Fatalln(err)
	}
	c.JSON(http.StatusOK, gin.H{
		"persons": persons,
	})
}

func GetPersonApi(c *gin.Context) {
	id, err := strconv.Atoi(c.Param("id"))
	person := Person{Id: id}
	err = person.GetPerson()
	if err != nil {
		log.Println(err)
		c.JSON(http.StatusOK, gin.H{
			"person": nil,
		})
		return
	}

	c.JSON(http.StatusOK, gin.H{
		"person": person,
	})
}

func ModPersonApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	person := Person{Id: id}
	err = c.Bind(&person)
	if err != nil {
		log.Fatalln(err)
	}

	ra, err := person.ModPerson()
	if err != nil {
		log.Fatal(err.Error())
	}
	msg := fmt.Sprintf("Update person %d successful %d", person.Id, ra)
	c.JSON(http.StatusOK, gin.H{
		"msg": msg,
	})
}

func DelPersonApi(c *gin.Context) {
	cid := c.Param("id")
	id, err := strconv.Atoi(cid)
	person := Person{Id: id}
	if err != nil {
		log.Fatalln(err)
	}
	ra, err := person.DelPerson()
	if err != nil {
		log.Fatalln(err)
	}
	msg := fmt.Sprintf("DELETE person %d successful %d", id, ra)
	c.JSON(http.StatusOK, gin.H{
		"msg": msg,
	})
}
