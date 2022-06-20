import random
import sys

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (QApplication, QHBoxLayout, QLabel, QLineEdit,
                               QListWidget, QPushButton, QVBoxLayout, QWidget,
                               QMenu, QMainWindow)

from PySide6.QtGui import (QAction)


class randYourSelf(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("做尼玛")

        self.Menu()
        self.Quiz()

        self.show()

    def Menu(self):
        self.file = QMenu("文件")
        self.quiz = QMenu("题目")

        self.open = QAction("打开", self)
        self.save = QAction("保存", self)
        self.exit = QAction("退出", self)
        self.about = QAction("关于", self)

        self.single = QAction("专项训练", self)

        self.file.addAction(self.open)
        self.file.addAction(self.save)
        self.file.addAction(self.exit)
        self.file.addAction(self.about)

        self.quiz.addAction(self.single)

        self.menuBar().addMenu(self.file)
        self.menuBar().addMenu(self.quiz)

    def Quiz(self):
        self.sum = [0,0]

        self.quiz = []
        self.quiz.append(QLabel())
        self.quiz.append(QLabel())
        self.quiz.append(QLabel())
        self.quiz.append(QLabel("="))
        self.quiz.append(QLineEdit())

        self.quiz[0].setAlignment(Qt.AlignCenter)
        self.quiz[2].setAlignment(Qt.AlignCenter)
        self.quiz[4].setAlignment(Qt.AlignCenter)

        self.pl1 = QHBoxLayout()
        for i in self.quiz:
            self.pl1.addWidget(i)

        self.quiz[4].returnPressed.connect(self.confirm)

        self.button = QPushButton("确认")
        self.button.clicked.connect(self.confirm)


        self.history = QListWidget()
        self.pl2 = QVBoxLayout()

        self.s = QLabel(f"总题数: {self.sum[0] + self.sum[1]}  🟢: {self.sum[0]}  🔴: {self.sum[1]}  正确率: 0%")

        self.pl2.addLayout(self.pl1)
        self.pl2.addWidget(self.button)
        self.pl2.addWidget(self.history)
        self.pl2.addWidget(self.s)

        self.dia = QWidget()
        self.dia.setLayout(self.pl2)

        self.setCentralWidget(self.dia)
        self.update()

    def confirm(self):
        if self.t[3] == int(self.quiz[4].text()):
            self.sum[0] += 1
            self.history.addItem("{} {} {} = {}\t✅".format(self.t[0], self.t[1], self.t[2], self.t[3]))
        else:
            self.sum[1] += 1
            self.history.addItem("{} {} {} = {}\t❌".format(self.t[0], self.t[1], self.t[2], self.quiz[4].text()))
        self.s.setText(f"总题数: {self.sum[0] + self.sum[1]}  🟢: {self.sum[0]}\t🔴: {self.sum[1]}\t正确率: {self.sum[0] / (self.sum[0] + self.sum[1]) * 100:.0f}%")
        self.update()
        self.quiz[4].setText("")
        return
    
    def update(self):
        self.t = self.gen()
        for i, x in enumerate(self.t):
            if i == 3:
                break
            self.quiz[i].setText(str(x))


    def gen(self):
        # 随机出题系统 10以内四则运算 并统计正确率
        a = b =  0
        op = ["+", "-", "*", "/"]

        o = random.randint(0, 3)
        a = random.randint(1, 10)
        b = random.randint(1, 10)
         
        # 排除特殊情况
        if o == 1:
            if a < b:
                a, b = b, a
        if o == 3:
            while a % b != 0 or a < b:
                a = random.randint(1, 10)
                b = random.randint(1, 10)

        ans = 0

        if o == 0:
            ans = a + b
        elif o == 1:
            ans = a - b
        elif o == 2:
            ans = a * b
        elif o ==3:
            ans = a / b

        return (a, op[o], b, ans)

if __name__ == "__main__":
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)
    
    ran = randYourSelf()
    
    app.exec()
