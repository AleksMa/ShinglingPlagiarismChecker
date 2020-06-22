package main

import (
	"bytes"
	"fmt"
	"github.com/AleksMa/StealLovingYou/lex_utils"
	"io/ioutil"
	"math/rand"
	"net/http"
	"path/filepath"
	"strconv"
	"strings"
	"time"

	_ "github.com/AleksMa/StealLovingYou/lex_utils"
)

func SendUser(name string) {
	url := "http://localhost:5000/api/user/" + name
	fmt.Println("URL:>", url)

	stid := rand.Int()

	var jsonStr = []byte(`{
  "studentid": "` + strconv.Itoa(stid) + `",
  "fullname": "` + name + `"
}`)
	req, err := http.NewRequest("POST", url, bytes.NewBuffer(jsonStr))
	req.Header.Set("Content-Type", "application/json")

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()

	fmt.Println("response Status:", resp.Status)
	fmt.Println("response Headers:", resp.Header)
	body, _ := ioutil.ReadAll(resp.Body)
	fmt.Println("response Body:", string(body))
}

func SendAttempt(code string, name string, task string) int {
	url := "http://localhost:5000/api/attempt"
	fmt.Println("URL:>", url)

	var jsonStr = []byte(`{
  "user": "` + name + `",
  "task": "` + task + `",
  "sourceCode": "` + code + `"
}`)
	fmt.Println(string(jsonStr))
	req, err := http.NewRequest("POST", url, bytes.NewBuffer(jsonStr))
	req.Header.Set("Content-Type", "application/json")

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()

	fmt.Println("response Status:", resp.Status)
	fmt.Println("response Headers:", resp.Header)
	body, _ := ioutil.ReadAll(resp.Body)
	fmt.Println("response Body:", string(body))

	return resp.StatusCode
}

func main() {

	i := 0
	j := 0

	var totalTime int64
	var totalTimeUser int64
	dir := "./testing/files/polinom"
	items, _ := ioutil.ReadDir(dir)
	for _, item := range items {
		if i > 50 {
			i++
			continue
		}
		name := item.Name()
		temp := strings.Split(name, ".")
		name = temp[len(temp) - 2]
		temp = strings.Split(name, "_")
		name = temp[len(temp) - 2] + "_" + temp[len(temp) - 3]
		fmt.Println(name)
		now := time.Now()
		//SendUser(name)
		fmt.Println(time.Now().Sub(now))
		totalTimeUser += (time.Now().Sub(now)).Nanoseconds()

		body, _ := ioutil.ReadFile(filepath.Join(dir, item.Name()))
		body = bytes.Replace(body, []byte("\""), []byte("\\\""), -1)
		code := lex_utils.Normalize(string(body))
		fmt.Println(code)

		now = time.Now()
		c := SendAttempt(code, name, "polinom")
		fmt.Println("Attempt: ", time.Now().Sub(now))
		if c / 100 == 2 {
			totalTime += (time.Now().Sub(now)).Nanoseconds()
			j++
		}

		i++
	}
	fmt.Println("COUNT: ", i)
	fmt.Println("TIME: ", totalTime / int64(j))
	fmt.Println("TIME USER: ", totalTimeUser / int64(i))
}
