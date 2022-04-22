from cv2 import sort
import jieba
words = {}
text = ""

with open("threekingdoms.txt","r") as f:
    text = f.read()

for i in ["，","。","！","？","\n","；","：","\"","、", " "]:
    text = text.replace(i,"")

for i in jieba.lcut(text):
    if i not in words:
        words[i] = 1
    else:
        words[i] += 1

words = sorted(words.items(),key=lambda x:x[1],reverse=False)

for i in words:
    print(i)

