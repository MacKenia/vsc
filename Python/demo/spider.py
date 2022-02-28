from urllib import request
import requests

url = "https://www.zhihu.com/explore"

urlbin = "http://httpbin.org/post"

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31"
}

def post():
    return requests.post(urlbin, data={"name":"jim","age":"22"})

def uploadfile():
    files = {'file': open("im.py","rb")}
    return requests.post(urlbin, files=files)

def cookies():
    r = requests.get("https://baidu.com")
    for key,value in r.cookies.items():
        print(key + "=" + value)

def session():
    s = requests.Session()
    s.get("http://httpbin.org/cookies/set/number/123345")
    r = s.get("http://httpbin.org/cookies")
    print(r.text)


session()