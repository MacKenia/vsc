# pip install requests beautifulsoup4 pyDes
"""
date 格式 yyyy-mm-dd 示例 2022-05-10
"""
from secrets import choice
import requests as rts
import base64 as bs
import time
from pyDes import des, ECB, PAD_PKCS5
import bs4 as Bss
import json
import re


class BookYourDream:
    def __init__(self):
        self.D_ONE = 141  # 梦一厅
        self.D_TWO = 142  # 梦二厅
        self.D_THREE = 261  # 梦三厅

        self.TIME_TABLE = ["07:30-09:59", "10:00-11:59", "12:00-13:59",
                           "14:00-15:59", "16:00-17:59", "18:00-19:59", "20:00-23:30"]

        self.main_se = rts.session()

        self.index_url = "http://202.202.209.15:8081/index.html"

        self.ver_image = "https://csxrz.cqnu.edu.cn:443/cas/verCode?random=="

        self.login_url = "https://csxrz.cqnu.edu.cn/cas/login?service=https://csxmh.cqnu.edu.cn/PersonalApplications/viewPage?active_nav_num=1"
        self.login_url = "https://csxrz.cqnu.edu.cn/cas/login?service=http%3A%2F%2F202.202.209.15%3A8081%2Findex.html"

        self.inquire_url = "http://202.202.209.15:8081/product/findtime.html"

        self.double_url = "http://202.202.209.15:8081/product/doublingTimeVer.html?stockid="

        self.book_url = "http://202.202.209.15:8081/order/tobook.html"

        self.search_url = "http://202.202.209.15:8081/yyuser/searchorder.html?page=1&rows=8&status=1&iscomment="

        self.cancel_url = "http://202.202.209.15:8081/order/delorder.html"

        self.normal_headers = {
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36"
        }

    def deVer(self, ver):
        """
        验证码解析接口
        https://market.aliyun.com/products/57124001/cmapi027426.html?spm=5176.2020520132.101.1.45ab72185BHAcX#sku=yuncode2142600000
        注册成功后 复制APPCODE
        粘贴到headers 中
        示例：注意空格
        "Authorization":"APPCODE 你的APPCODE" 
        """
        ascii_ver = bs.b64encode(ver).decode('ascii')
        headers = {
            "image": ascii_ver,
            "type": "1001",
            "Authorization": "APPCODE cad56c434d124a17a7d990ae746ffa07"
        }
        url = "https://302307.market.alicloudapi.com/ocr/captcha"
        res = rts.post(url, headers=headers)
        if res and res.json()["code"] == 0:
            return res.json()["data"]["captcha"]
        else:
            print(res.headers["X-Ca-Error-Message"])
            return False

    def encrypt_des(self, data, key):
        k = des(key, ECB, key, pad=None, padmode=PAD_PKCS5)
        en = k.encrypt(data.encode('utf-8'), padmode=PAD_PKCS5)
        return str(bs.b64encode(en), 'utf-8')

    def login(self, user, passwd):
        ping = self.main_se.get(self.index_url, headers=self.normal_headers)

        pings = Bss.BeautifulSoup(ping.text, "html.parser")

        # print(type(pings))

        ping_inputs = pings.find_all("input")

        ver_img = self.main_se.get(
            self.ver_image + str(int(time.time()*100)), headers=self.normal_headers)

        ver_code = self.deVer(ver_img.content)

        # ver_code = False

        if not ver_code:
            with open("验证码.jpg", "wb") as f:
                f.write(ver_img.content)
            ver_code = input("验证码解析失败\n请手动输入:")
        print(ver_code)

        key = ping_inputs[4].get("value")[:8]
        execution = ping_inputs[5].get("value")

        password = self.encrypt_des(passwd, key)

        data = {
            "username": user,
            "password": password,
            "authCode": ver_code,
            "lt": ping_inputs[4].get("value"),
            "execution": execution,
            "_eventId": "submit",
            "isQrSubmit": "false",
            "isMobileLogin": "false",
            "qrValue": ""
        }

        login_res = self.main_se.post(
            self.login_url, data=data, headers=self.normal_headers)
        # print(login_res.text)
        if login_res.content.decode('utf-8').find("梦厅") != login_res.content.decode("utf-8").find("场地"):
            print("登录成功")
            return True
        else:
            print("登录失败")
            return False

    def inquire(self, room, date, allday=False):
        params = {
            "type": "day",
            "s_dates": date,
            "serviceid": room
        }
        r = self.main_se.get(self.inquire_url, params=params)
        for i in r.json()["object"]:
            print(i)

        reserve = {}

        for i in r.json()["object"]:
            if not allday:
                print(f"{i['TIME_NO']}\n剩余数量 {i['SURPLUS']}")
                c = input("是否预定?(y/n)").strip()
            if allday or c == "y" or c == "Y" or c == "":
                reserve[str(i['ID'])] = "1"
        return reserve

    def booked(self):
        booked_list = []
        r = self.main_se.get(self.search_url, headers=self.normal_headers)
        for i in r.json():
            booked_list.append({'orderid': i['orderid'],
                                'servicenames': i['servicenames'],
                                'remark1': i['remark1'],
                                'remark': i['remark']
                                })
        return booked_list

    def book(self, table):
        data = {
            "param": json.dumps({
                "stock": table,
                "extend": {}
            }),
            "json": True
        }

        r = self.main_se.post(self.book_url, data=data)
        print(r.text)

    def book_time(self, room, date, time):
        param = {
            "type": "day",
            "s_dates": date,
            "serviceid": room
        }

        t = 1
        e = 1
        while True:
            print(f"第{t}次尝试预定", end="\r")
            r = self.main_se.get(self.inquire_url, params=param)
            if not r:
                if e == 3:
                    print("失败")
                    return
                print("出现错误，正在重试")
                return
            for i in r.json()["object"]:
                if i["TIME_NO"] == time:
                    self.book({str(i['ID']): "1"})
                    print("\n预定成功")
                    return
            t += 1
            time.sleep(1)

    def book_table(self, room, date, place, b_time=None):
        param = {
            "type": "day",
            "s_dates": date,
            "serviceid": room
        }

        t = 1
        e = 1
        suc = 0
        while True:
            print(f"第{t}次尝试预定", end="\r")
            r = self.main_se.get(self.inquire_url, params=param)
            if not r:
                if e == 3:
                    print("失败")
                    return
                print("出现错误，正在重试")
                e += 1
                continue
            for i in r.json()["object"]:
                if b_time != None and i["TIME_NO"] == b_time:
                    if i["SURPLUS"] == 401-place:
                        self.book({str(i['ID']): "1"})
                        print(f"\n{i['TIME_NO']}预定成功")
                        return
                    elif i["SURPLUS"] < 401-place:
                        print("剩余数量不足")
                        return
                elif not b_time:
                    if i["SURPLUS"] == 401-place:
                        self.book({str(i['ID']): "1"})
                        suc += 1
                        print(f"\n{i['TIME_NO']} 预定成功")
                        if suc == 7:
                            print("预定完成")
                            return
            t += 1
            time.sleep(1)

    def cancel_all(self):
        for i in self.booked():
            id = i["orderid"]
            data = {
                "orderid": id,
                "json": True
            }
            print(
                f"已取消 {i['servicenames']} 的 {i['remark1']} 时间段的 {i['remark']}")
            self.main_se.post(self.cancel_url, data=data,
                              headers=self.normal_headers)
        print(f"已取消 {len(self.booked())} 个订单")

    def main(self):
        room = [self.D_ONE, self.D_TWO, self.D_THREE]
        print("请先登录")
        user = input("账号:")
        passwd = input("密码:")
        if not self.login(user, passwd):
            return
        while True:
            choice = int(input("\n1.预定\n2.取消\n3.查询\n4.退出\n请输入:"))
            if choice == 1:
                choice = int(input("\n1.日期预定\n2.时间预定\n3.位置预定\n请输入:"))
                cRoom = int(input("1. 梦一厅\n2. 梦二厅\n3. 梦三厅\n场地:"))
                date = input("日期(yyyy-mm-dd):")
                if choice == 1:
                    reserve = self.inquire(room[cRoom-1], date)
                    if reserve:
                        self.book(reserve)
                elif choice == 2:
                    for i, j in enumerate(self.TIME_TABLE):
                        print(f"{i+1}. {j}")
                    time = input("时间:")
                    self.book_time(room[cRoom-1], date,
                                   self.TIME_TABLE[int(time)-1])
                elif choice == 3:
                    for i, j in enumerate(self.TIME_TABLE):
                        print(f"{i+1}. {j}")
                    print("8. 全天")
                    time = int(input("时间:"))
                    place = int(input("位置:"))
                    if time == 8:
                        self.book_table(room[cRoom-1], date, place)
                    else:
                        self.book_table(
                            room[cRoom-1], date, self.TIME_TABLE[int(time)-1], place)
                else:
                    return

            elif choice == 2:
                n = input("将会取消所有订单，是否继续?(y/n)")
                if n == "n" or n == "N":
                    continue
                self.cancel_all()

            elif choice == 3:
                r = self.booked()
                print("已预定:")
                for i in r:
                    print(
                        f"{i['servicenames']} 的 {i['remark1']} 时间段的 {i['remark']}")
            elif choice == 4:
                return
            else:
                print("输入错误")
                continue


if __name__ == "__main__":
    y = BookYourDream()
    # y.book(y.inquire(y.D_ONE, "2022-05-14", True))
    # y.cancel_all()
    # r = y.booked()
    # print("已预定:")
    # for i in r:
    #     print(f"{i['servicenames']} 的 {i['remark1']} 时间段的 {i['remark']}")
    y.main()
