from email import header
import requests

data = "StudentId=2020051615308&Name=%E6%9D%A8%E9%B8%BF%E5%BC%BA&Sex=%E7%94%B7&SpeType=B&CollegeNo=0516&SpeGrade=2020&SpecialtyName=%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%A7%91%E5%AD%A6%E4%B8%8E%E6%8A%80%E6%9C%AF&ClassName=20%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%A7%91%E5%AD%A6%E4%B8%8E%E6%8A%80%E6%9C%AF4%E7%8F%AD%EF%BC%88%E6%99%AE%E9%80%9A%E6%9C%AC%E7%A7%91%EF%BC%89&MoveTel=19122542802&Province=500000&City=500100&County=500116&ComeWhere=%E9%BE%99%E5%8D%8E%E9%95%87&FaProvince=500000&FaCity=500100&FaCounty=500116&FaComeWhere=%E9%BE%99%E5%8D%8E%E9%95%87%E6%A2%81%E5%AE%B6%E6%9D%91&radio_1=55b00e0d-6a40-41be-94d8-4189725b5bbd&radio_2=670ab16b-6bdc-4cb6-827a-2affccf3c12b&radio_3=b5fa4643-081d-40c5-a0a4-7f84799d0874&radio_4=a916ade2-9eae-43c5-9ca9-1b7e1abdf44c&radio_5=cc1b9b2b-3e97-4fdd-beee-a4352c23e07f&radio_6=4d155938-9935-4b6a-b5f0-6f931cfbcd78&Other=&GetAreaUrl=%2FSPCP%2FWeb%2FReport%2FGetArea&IdCard=500381200011243913&ProvinceName=%E9%87%8D%E5%BA%86%E5%B8%82&CityName=%E9%87%8D%E5%BA%86%E5%B8%82%E5%B8%82%E8%BE%96%E5%8C%BA&CountyName=%E6%B1%9F%E6%B4%A5%E5%8C%BA&FaProvinceName=%E9%87%8D%E5%BA%86%E5%B8%82&FaCityName=%E9%87%8D%E5%BA%86%E5%B8%82%E5%B8%82%E8%BE%96%E5%8C%BA&FaCountyName=%E6%B1%9F%E6%B4%A5%E5%8C%BA&radioCount=6&checkboxCount=0&blackCount=0&PZData=%5B%7B%22OptionName%22%3A%22%E6%98%AF%22%2C%22SelectId%22%3A%2255b00e0d-6a40-41be-94d8-4189725b5bbd%22%2C%22TitleId%22%3A%2296db33a6-a4e1-49f9-8bc1-971411c4f201%22%2C%22OptionType%22%3A%220%22%7D%2C%7B%22OptionName%22%3A%22%E4%BD%8E%E9%A3%8E%E9%99%A9%E5%9C%B0%E5%8C%BA%22%2C%22SelectId%22%3A%22670ab16b-6bdc-4cb6-827a-2affccf3c12b%22%2C%22TitleId%22%3A%224220786b-7dcc-4996-8bf8-b26508fce74a%22%2C%22OptionType%22%3A%220%22%7D%2C%7B%22OptionName%22%3A%22%E5%81%A5%E5%BA%B7%EF%BC%8C%E4%B8%80%E5%88%87%E6%AD%A3%E5%B8%B8%22%2C%22SelectId%22%3A%22b5fa4643-081d-40c5-a0a4-7f84799d0874%22%2C%22TitleId%22%3A%2209473581-178e-4b9a-9271-adb9cccccf04%22%2C%22OptionType%22%3A%220%22%7D%2C%7B%22OptionName%22%3A%22%E5%90%A6%22%2C%22SelectId%22%3A%22a916ade2-9eae-43c5-9ca9-1b7e1abdf44c%22%2C%22TitleId%22%3A%22f7e70693-c294-4de6-87d2-b1a05cffdbc7%22%2C%22OptionType%22%3A%220%22%7D%2C%7B%22OptionName%22%3A%22%E6%97%A0%22%2C%22SelectId%22%3A%22cc1b9b2b-3e97-4fdd-beee-a4352c23e07f%22%2C%22TitleId%22%3A%22828017d8-cb30-41b2-ba3f-d7c58245ff40%22%2C%22OptionType%22%3A%220%22%7D%2C%7B%22OptionName%22%3A%22%E6%97%A0%22%2C%22SelectId%22%3A%224d155938-9935-4b6a-b5f0-6f931cfbcd78%22%2C%22TitleId%22%3A%222039addc-f5f5-4c7a-8f49-37127d0b5cd2%22%2C%22OptionType%22%3A%220%22%7D%5D&ReSubmiteFlag=a6587d7a-a029-4e88-9c36-4a5c31b38640"

header = {
"Content-Type": "application/x-www-form-urlencoded",
"DNT": "1",
"Origin": "https://protalxsgz.cqnu.edu.cn",
"Referer": "https://protalxsgz.cqnu.edu.cn/SPCP/Web/Report/Index",
"sec-ch-ua": '" Not A;Brand";v="99", "Chromium";v="100", "Microsoft Edge";v="100"',
"sec-ch-ua-mobile": "?0",
"sec-ch-ua-platform": "Linux",
"Upgrade-Insecure-Requests": "1",
"User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/100.0.4863.0 Safari/537.36 Edg/100.0.1163.1",
}

formated_data = {
"StudentId": "2020051615308",
"Name": "杨鸿强",
"Sex": "男",
"SpeType": "B",
"CollegeNo": "0516",
"SpeGrade": "2020",
"SpecialtyName": "计算机科学与技术",
"ClassName": "20计算机科学与技术4班（普通本科）",
"MoveTel": "19122542802",
"Province": "500000",
"City": "500100",
"County": "500116",
"ComeWhere": "龙华镇",
"FaProvince": "500000",
"FaCity": "500100",
"FaCounty": "500116",
"FaComeWhere": "龙华镇梁家村",
"radio_1": "55b00e0d-6a40-41be-94d8-4189725b5bbd",
"radio_2": "670ab16b-6bdc-4cb6-827a-2affccf3c12b",
"radio_3": "b5fa4643-081d-40c5-a0a4-7f84799d0874",
"radio_4": "a916ade2-9eae-43c5-9ca9-1b7e1abdf44c",
"radio_5": "cc1b9b2b-3e97-4fdd-beee-a4352c23e07f",
"radio_6": "4d155938-9935-4b6a-b5f0-6f931cfbcd78",
"Other": "",
"GetAreaUrl": "/SPCP/Web/Report/GetArea",
"IdCard": "500381200011243913",
"ProvinceName": "重庆市",
"CityName": "重庆市市辖区",
"CountyName": "江津区",
"FaProvinceName": "重庆市",
"FaCityName": "重庆市市辖区",
"FaCountyName": "江津区",
"radioCount": "6",
"checkboxCount": "0",
"blackCount": "0",
"PZData": [{"OptionName":"是","SelectId":"55b00e0d-6a40-41be-94d8-4189725b5bbd","TitleId":"96db33a6-a4e1-49f9-8bc1-971411c4f201","OptionType":"0"},{"OptionName":"低风险地区","SelectId":"670ab16b-6bdc-4cb6-827a-2affccf3c12b","TitleId":"4220786b-7dcc-4996-8bf8-b26508fce74a","OptionType":"0"},{"OptionName":"健康，一切正常","SelectId":"b5fa4643-081d-40c5-a0a4-7f84799d0874","TitleId":"09473581-178e-4b9a-9271-adb9cccccf04","OptionType":"0"},{"OptionName":"否","SelectId":"a916ade2-9eae-43c5-9ca9-1b7e1abdf44c","TitleId":"f7e70693-c294-4de6-87d2-b1a05cffdbc7","OptionType":"0"},{"OptionName":"无","SelectId":"cc1b9b2b-3e97-4fdd-beee-a4352c23e07f","TitleId":"828017d8-cb30-41b2-ba3f-d7c58245ff40","OptionType":"0"},{"OptionName":"无","SelectId":"4d155938-9935-4b6a-b5f0-6f931cfbcd78","TitleId":"2039addc-f5f5-4c7a-8f49-37127d0b5cd2","OptionType":"0"}],
"ReSubmiteFlag": "a6587d7a-a029-4e88-9c36-4a5c31b38640",
}

url = "https://protalxsgz.cqnu.edu.cn/SPCP/Web/Report/Index"

respond = requests.post(url, formated_data, headers=header).status_code

print("{}".format(respond))
