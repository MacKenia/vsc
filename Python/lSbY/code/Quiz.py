import random, sys, time

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (QApplication, QHBoxLayout, QLabel, QLineEdit,
                               QListWidget, QPushButton, QVBoxLayout, QWidget,
                               QMenu, QMainWindow, QMessageBox, QComboBox,
                               QFileDialog)

from PySide6.QtGui import (QAction)


class randYourSelf(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("随机出题程序")

        self.op_list = ["+", "-", "*", "/"]
        self.plus_mode = False

        self.Menu()
        self.Quiz()

        self.show()

    def Menu(self):
        self.file = QMenu("文件")
        self.quiz = QMenu("题目")

        self.open = QAction("打开", self)
        self.save = QAction("保存", self)
        self.exit = QAction("退出", self)
        self.about_us = QAction("关于", self)

        self.single = QAction("专项训练", self)

        self.file.addAction(self.open)
        self.file.addAction(self.save)
        self.file.addAction(self.exit)
        self.file.addAction(self.about_us)

        self.quiz.addAction(self.single)

        self.open.triggered.connect(self.openFile)
        self.save.triggered.connect(self.saveFile)
        self.exit.triggered.connect(self.close)
        self.about_us.triggered.connect(self.about_f)
        self.single.triggered.connect(self.single_f)

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
        if self.plus_mode:
            quiz_t = self.quiz_p
            self.t[1] = self.op.currentIndex()
        else:
            quiz_t = self.quiz

        ans = 0

        if self.t[1] == 0:
            ans = self.t[0] + self.t[2]
        elif self.t[1] == 1:
            ans = self.t[0] - self.t[2]
        elif self.t[1] == 2:
            ans = self.t[0] * self.t[2]
        elif self.t[1] == 3:
            ans = self.t[0] / self.t[2]

        if ans == int(quiz_t[4].text()):
            self.sum[0] += 1
            self.history.insertItem(0,"{} {} {} = {}\t✅".format(self.t[0], self.op_list[self.t[1]], self.t[2], quiz_t[4].text()))
        else:
            self.sum[1] += 1
            self.history.insertItem(0,"{} {} {} = {}\t❌".format(self.t[0], self.op_list[self.t[1]], self.t[2], quiz_t[4].text()))
        self.s.setText(f"总题数: {self.sum[0] + self.sum[1]}  🟢: {self.sum[0]}  🔴: {self.sum[1]}  正确率: {self.sum[0] / (self.sum[0] + self.sum[1]) * 100:.0f}%")
        self.update()
        quiz_t[4].setText("")
        return
    
    def update(self):
        self.t = self.gen()
        if self.plus_mode:
            quiz_t = self.quiz_p
        else:
            quiz_t = self.quiz
        for i, x in enumerate(self.t):
            if i == 1 and self.plus_mode:
                continue
            elif i == 1 and not self.plus_mode:
                quiz_t[i].setText(self.op_list[x])
                continue
            if i == 3:
                break
            
            quiz_t[i].setText(str(x))


    def gen(self):
        # 随机出题系统 10以内四则运算 并统计正确率
        a = b = 0

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

        if self.plus_mode:
            o = self.op.currentIndex()

        return [a, o, b]

    def single_f(self):
        self.plus_mode = True
        for i in range(self.pl1.count()):
            self.pl1.itemAt(i).widget().deleteLater()

        self.op = QComboBox()
        self.op.addItems(self.op_list)

        self.quiz_p = []
        self.quiz_p.append(QLabel())
        self.quiz_p.append(self.op)
        self.quiz_p.append(QLabel())
        self.quiz_p.append(QLabel("="))
        self.quiz_p.append(QLineEdit())

        self.quiz_p[0].setAlignment(Qt.AlignCenter)
        self.quiz_p[2].setAlignment(Qt.AlignCenter)
        self.quiz_p[4].setAlignment(Qt.AlignCenter)

        for i in self.quiz_p:
            self.pl1.addWidget(i)

        self.quiz_p[4].returnPressed.connect(self.confirm)
        
        self.update()

    def openFile(self):
        fname = QFileDialog.getOpenFileName(self, 'Open file', './')
        print(fname)
        if fname[0]:
            self.file = fname[0]
            # read file and strip \n
            with open(self.file, "r", encoding="utf-8") as f:
                for i in f.readlines():
                    self.history.addItem(i.strip())
            for i in range(self.history.count()):
                if self.history.item(i).text().count("✅") > 0:
                    self.sum[0] += 1
                elif self.history.item(i).text().count("❌") > 0:
                    self.sum[1] += 1
        if self.sum[0] + self.sum[1] != 0:
            self.s.setText(f"总题数: {self.sum[0] + self.sum[1]}  🟢: {self.sum[0]}  🔴: {self.sum[1]}  正确率: {self.sum[0] / (self.sum[0] + self.sum[1]) * 100:.0f}%")

    def saveFile(self):
        list = self.history
        with open (("history_"+ str(time.asctime()).replace(":", "").replace(" ","") +".txt"), "w", encoding="utf-8") as f:
            for i in range(list.count()):
                f.write(list.item(i).text() + "\n")


    def about_f(self):
        QMessageBox.about(self, "关于", "这是由PySide6编写的随机出题系统!")

    def close(self):
        exit()

if __name__ == "__main__":
    app = QApplication.instance()
    if not app:
        app = QApplication(sys.argv)
    
    ran = randYourSelf()
    
    app.exec()
