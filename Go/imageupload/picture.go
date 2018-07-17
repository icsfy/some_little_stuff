package main

import (
	"fmt"
	"log"
	"io/ioutil"
	"io"
	"os"
	"net/http"
	"html/template"
)

const (
	UPLOAD_DIR = "./uploads"
)

func uploadHandler(w http.ResponseWriter, r *http.Request)  {
	if r.Method == "GET" {
		t, _ := template.ParseFiles("upload.html")
		t.Execute(w, nil)
	} else {
		f, h, err := r.FormFile("image")
		defer f.Close()
		if err != nil {
			fmt.Fprintf(w, "%s\n", err.Error())
			return
		}
		filename := h.Filename
		t, err := os.Create(UPLOAD_DIR + "/" + filename)
		defer t.Close()
		if err != nil {
			fmt.Fprintf(w, "%s\n", err.Error())
			return
		}
		_, err = io.Copy(t, f)
		if err != nil {
			return
		}
		http.Redirect(w, r, "view?id=" + filename, http.StatusFound)
	}
}

func deleteHandler(w http.ResponseWriter, r *http.Request) {
	imageId := r.FormValue("id")
	imagePath := UPLOAD_DIR + "/" + imageId
	err := os.Remove(imagePath)
	if err != nil {
		fmt.Fprintf(w, "%s\n", err.Error())
		return
	}
	http.Redirect(w, r, "/", http.StatusFound)
}

func viewHandler(w http.ResponseWriter, r *http.Request)  {
	imageId := r.FormValue("id")
	imagePath := UPLOAD_DIR + "/" + imageId
	w.Header().Set("Content-Type", "image")
	http.ServeFile(w, r, imagePath)
}

func listHandler(w http.ResponseWriter, r *http.Request)  {
	fileInfoArr, _ := ioutil.ReadDir(UPLOAD_DIR)

	locals := make(map[string]interface{})
	images := []string{}

	for _, fileInfo := range fileInfoArr {
		images = append(images, fileInfo.Name())
	}
	locals["images"] = images
	t, _ := template.ParseFiles("list.html")
	t.Execute(w, locals)
}

func main() {
	http.HandleFunc("/upload", uploadHandler)
	http.HandleFunc("/view", viewHandler)
	http.HandleFunc("/", listHandler)
	http.HandleFunc("/delete", deleteHandler)

	err := http.ListenAndServe(":9090", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err.Error())
	}
}