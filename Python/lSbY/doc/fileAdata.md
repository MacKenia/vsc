# 文件和数据

## 2、实例11：自动轨迹绘画

基本步骤：

第一步：定义数据文件格式（接口）

第二步：根据文件界面分析参数，编写绘图程序

第3步：准备数据文件

数据格式：

示例：300,1144,0,1,0

行驶距离、转向判断（0左、1右）、转向角、RGB三通道颜色

```python
import turtle as t
t.title("自动轨迹绘制")
t.setup(800,600,0,0)
t.pencolor("red")
t.pensize(5)

# 数据读取
datals = []
f = open("data.txt")
for line in f:
    line = line.replace("\n","")
    datals.append(list(map(eval,line.split(","))))
f.close()

for i in range(len(datals)):
    t.pencolor(datals[i][3],datals[i][4],datals[i][5])
    t.fd(datals[i][0])
    if datals[i][1]:
        t.right(datals[i][2])
    else:
        t.left(datals[i][2])
```

## 3、一位数据的格式化和处理

### 3.1 一维数据的表示

如果时间有序，使用列表类型
如果数据无序，使用集合类型
### 3.2 一维数据的存储

方式一：空格分隔
使用一个或多个空格分隔，不换行

缺点：数据中不能存在空格。

方式二：逗号分隔
使用英文半角逗号分隔数据进行存储，不换行；

缺点：数据中不能有英文逗号。

方式三：其他符号
使用其他符号或符号组合分隔，建议采用特殊符号

缺点：需要根据数据特点定义，通用性较差

### 3.3 一维数据的处理

```python
# 从空格分隔的文件中读入数据
txt = open("f_deal").read()
ls_1 = txt.split()

# 从特殊符号分隔的文件中读入数据
txt = open("f_deal").read()
ls_2 = txt.split("$")

# 采用空格分隔方式将数据写入文件
ls = ['中国','美国','日本']
f = open("f_deal.txt",'w')
f.write(''.join(ls))
f.close()

# 采用特殊分隔方式将数据写入文件
ls = ['中国','美国','日本']
f = open("f_deal.txt",'w')
f.write(''.join(ls))
f.close()
```

## 4、二维数据的格式化和处理

### 4.1 二维数据的表示

使用二维列表类型表达二维数据

– 使用两层for循环遍历每个元素

– 外层列表中每个元素对应一行/列

### 4.2 二维数据的存储

国际通用的一二维数据存储格式
每行一个一维数据，采用逗号分隔，无空行
Excel和一般编辑软件都可以读入或另存为csv文件
如果某个元素缺失，逗号仍要保留
二维数据的表头可以作为数据存储，也可以另行存储
逗号为英文半角逗号，逗号与数据之间无额外空格

存储规范：

按行存或者按列存都可以，具体由程序决定
一般索引习惯: `ls[ row ][column]` ，先行后列
根据一般习惯，外层列表每个元素是一行，按行存

### 4.3 二维数据的处理

```python
# 从 CSV 格式的文件中读入数据
fo = open("f_deal.txt")
ls_1 = []
for line in fo:
    line = line.replace("\n","")
    ls_1.append(line.split(","))
fo.close()

# 将数据写入 CSV 格式的文件
ls_2 = [['China','CN'],['American','USA'],['Japan','JPN']]
fw = open("f_deal.txt","w")
for item in ls_2:
    fw.write(','.join(item)+'\n')
fw.close()
```

## 5、模块6：wordcloud库的使用

词云的含义：

以词语为基本单元，将词语通过图片可视化的方式，直观和艺术地展示出来。

`wordcloud`库的安装：

`pip install wordcloud`

`wordcloud`库的基本使用

`w = wordcloud.WordCloud()`

– 以WordCloud对象为基础

– 实现配置参数，加载文本，输出文件

常规方法：

方法	描述

```python
w.generate(txt)	向WordCloud对象w中加载文本txt
>>>w.generate( “Python and wordCloud” )
w.to_file(filename)	将词云输出为图像文件，.png或.jpg格式
>>>w.to_fi1e( “outfile.png” )
```

```python
# 常规方法：
import wordcloud
# 步骤1：配置对象参数
c = wordcloud.WordCloud()
# 步骤2：加载词云文本
c.generate("wordcloud by python")
# 步骤3：输出词云文件
c.to_file("pywordcloud.png")
配置对象参数

w = wordcloud.WordCloud(<参数>)
```

参数	描述

```python
width	指定词云对象生成图片的宽度，默认400像素
>>>w=wordcloud.wordCloud(width=600)
height	指定词云对象生成图片的高度，默认200像素
>>>w=wordcloud.wordCloud( height=400)
min_font_size	指定词云中字体的最小字号，默认4号
>>>w=wordcloud.wordCloud(min_font_size=10)
max_font _size	指定词云中字体的最大字号，根据高度自动调节
>>>w=wordcloud.wordcloud(max_font_size=20)
font_step	指定词云中字体字号的步进间隔，默认为1
>>>w=wordcloud.wordCloud(font_step=2)
font_path	指定字体文件的路径，默认None
>>>w=wordcloud.wordCloud(font_path=“msyh.ttc”)
max_words	指定词云显示的最大单词数量，默认200
>>>w=wordcloud.wordCloud(max_words=20)
stop_words	指定词云的排除词列表，即不显示的单词列表
>>>w=wordcloud.wordCloud(stop_words={ “Python”})
mask	指定词云形状，默认为长方形，需要引用imread()函数
>>>from scipy.misc import imread
>>>mk=imread( “pic.png”)
>>>w=wordcloud.wordcloud(mask=mk)
background_color	指定词云图片的背景颜色，默认为黑色
>>>w=wordcloud.wordCloud(background_color=“white”)
```

```python
# 应用实例1：英文词云
import wordcloud
txt = "life is shorted, you need python"
w = wordcloud.WordCloud(
    background_color = 'white')
w.generate(txt)
w.to_file("pywcloud.png")

# 应用实例2：中文词云
import jieba
import wordcloud
txt = "程序设计语言是计算机能够理解和" \
      "识别用户操作意图的一种交互体系" \
      "它按照\特定规则组织计算机指令" \
      "使计算机能够自\动进行各种运算处理。"
w = wordcloud.WordCloud(width = 1000,
    font_path="msyh.ttc",height=700)
w.generate(" ".join(jieba.lcut(txt)))
w.to_file("pywcloud.png")
```

## 6、实例:

```python
# 原课程中是政府工作报告词云
import jieba
import wordcloud
from imageio import imread

diymask = imread(".\实例12：政府工作报告词云\五角星.png")
f = open(".\实例12：政府工作报告词云\目光.txt", encoding='UTF-8')
t = f.read()
f.close()
ls = jieba.lcut(t)
ls = [i for i in ls if len(i)>1] # 去除单个字以及各类字符 
txt = " ".join(ls)
w = wordcloud.WordCloud(
    font_path = "msyh.ttc", mask = diymask,width = 1000, height = 700,
    background_color='white', max_words = 20,
    stopwords={"这个","可以","我们",'他们','很多','什么','一个','没有','就是',"一些","所以",'他们','一种'}
)
w.generate(txt)
w.to_file("grwordcloud.png")
```