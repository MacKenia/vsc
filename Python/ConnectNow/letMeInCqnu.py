from email import header
import requests
# import socket

# def get_host_ip():
#     """
#     查询本机ip地址
#     :return: ip
#     """
#     try:
#         s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
#         s.connect(('10.0.251.18', 80))
#         ip = s.getsockname()[0]
#     finally:
#         s.close()
#         return ip

# 获取相关数据

# fi = open("passwd.txt","r")
# user = fi.readline()
# passwd = fi.readline()

# user = "2020051615308"
# passwd = "11243913"

user = ["20130942","20200045","20130889","20148407","2020051615308","2021051615296"]
passwd = ["031960","013145","050044","ddm2018","11243913","727503"]

choice = 0

print(user[choice])
print(passwd[choice])

# url = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanuserip="+ str(get_host_ip()) +"&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

url = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

datas = {
    "DDDDD":",0,"+user[choice]+"@telecom",
    "upass": passwd[choice],
    "R1":"0",
    "R2": "",
    "R6": "0",
    "para": "00",
    "0MKKey": "123456"
}

header_desktop = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Length": "87",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "10.0.251.18:801",
    "Origin": "http://10.0.251.18",
    "Referer": "http://10.0.251.18/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31"
}

header_phone = {
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "10.0.251.18:801",
    "Origin": "http://10.0.251.18",
    "Referer": "http://10.0.251.18/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Linux; Android 10; HuaWei Mate Pro) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Mobile Safari/537.36 EdgA/98.0.1108.62"
}

response = requests.post(url, data=datas, headers=header_phone).status_code
print("{}".format(response))
