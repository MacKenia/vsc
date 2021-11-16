import requests
import time
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

fi = open("passwd.txt","r")
user = fi.readline()
passwd = fi.readline()

user = user.rstrip()
passwd = passwd.rstrip()

# url = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanuserip="+ str(get_host_ip()) +"&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

url = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

datas = {
    "DDDDD":",0,"+user+"@telecom",
    "upass": passwd,
    "R1":"0",
    "R2": "",
    "R6": "0",
    "para": "00",
    "0MKKey": "123456"
}

header = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Length": "87",
    "Content-Type": "application/x-www-form-urlencoded",
    "Cookie": "namevalue=,0," + str(user) + "@telecom; passvalue=" + str(passwd) + "; PHPSESSID=bu60f0l0g0cl6ank1uh5s1uvv3",
    "Host": "10.0.251.18:801",
    "Origin": "http://10.0.251.18",
    "Referer": "http://10.0.251.18/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31"
}
while True:
    date = time.localtime()
    try:
        response = requests.post(url, data=datas, headers=header).status_code
        print("[{:0>2d}:{:0>2d}:{:0>2d}]: Success!".format(date[3],date[4],date[5]))
        print("[{:0>2d}:{:0>2d}:{:0>2d}]: Send next login message after 60 seconds!".format(date[3],date[4],date[5]))
        time.sleep(60)
    except:
        print("[{:0>2d}:{:0>2d}:{:0>2d}]: Post error! Next try after 10 minutes!".format(date[3],date[4],date[5]))
        time.sleep(60*10)
fi.close()

