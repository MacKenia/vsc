import requests
import time

# id = int(input("请输入第一门课的ID:"))

data = {
  "username": "106372020051615308",
  "ownerId": "1509021",
  "parentId": "335852886",
  "action": "0",
  "courseId": "334568935",
  "sectionId": "663593",
  "chapterId": "257801",
  "category": "2"
}

header = {
    "accept": "*/*",
    "accept-encoding": "gzip, deflate",
    "connection": "keep-alive",
    "content-length": "163",
    "cookie": "xsid=31867359899510CE; player=1",
    "accept-language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "origin":"http://www.cqooc.net",
    "DNT": "1",
    "Host": "www.cqooc.net",
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4688.0 Safari/537.36 Edg/97.0.1069.0"
}

url = "http://www.cqooc.net/learnLog/api/add"

result = requests.post(url, data, header).status_code
print("{}".format(result))
 