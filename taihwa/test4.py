# -*- coding: utf-8 -*-
"""
Created on Mon Aug 26 21:18:46 2019

@author: TaeHwaShin

Customize@Keyboard@Category:File@Print Preview:Ctrl+Shift+P@Assign
Seismic Evalutaion@Add to Quick Access Toolbars
"""
import pyautogui as gen
import time
import sys
import pyautogui
from PyQt5.QtWidgets import *
from PyQt5.QtGui import QPixmap


class MyApp(QWidget):

    def __init__(self):
        super().__init__()

        self.open_btn_rcbeam = QPushButton('RC Beam Data(Dz,Ry)')
        self.label = []

        self.open_btn_rccol = QPushButton('RC Col Data(Dx,Dy,Dz,Ry,Rz)')
        self.label = []

        self.open_btn_rcwall = QPushButton('RC Wall Data(Dx,Dz,Ry)')
        self.label = []

        self.click_btn_rcbeam = QPushButton('Exit')
        self.click_btn_rccol = QPushButton('Exit')
        self.click_btn_rcwall = QPushButton('Exit')
        self.fname = []
        self.hbox_label = QHBoxLayout()
        self.vbox = QVBoxLayout()
        self.initUI()

    def initUI(self):

        self.vbox.addWidget(self.open_btn_rcbeam)
        self.vbox.addStretch(1)
        self.vbox.addLayout(self.hbox_label)
        self.vbox.addStretch(1)

        self.vbox.addWidget(self.open_btn_rccol)
        self.vbox.addStretch(1)
        self.vbox.addLayout(self.hbox_label)
        self.vbox.addStretch(1)

        self.vbox.addWidget(self.open_btn_rcwall)
        self.vbox.addStretch(1)
        self.vbox.addLayout(self.hbox_label)
        self.vbox.addStretch(1)

        self.vbox.addWidget(self.click_btn_rcbeam)
        self.setLayout(self.vbox)

        self.open_btn_rcbeam.clicked.connect(self.RCBeam_Data)
        self.click_btn_rcbeam.clicked.connect(self.click_btn_RCBeam)

        self.open_btn_rccol.clicked.connect(self.RCCol_Data)
        self.click_btn_rccol.clicked.connect(self.click_btn_RCCol)

        self.open_btn_rcwall.clicked.connect(self.RCWall_Data)
        self.click_btn_rcwall.clicked.connect(self.click_btn_RCWall)

        self.setWindowTitle('DataMacro-Test1')
        self.setGeometry(300, 300, 300, 200)
        self.show()

    def RCBeam_Data(self):

        rcbeam = gen.locateCenterOnScreen('./rcbeam.png')
        gen.moveTo(rcbeam)
        gen.click(clicks=1, interval=0.1)
        gen.press('tab', 5, interval=0.1)
        gen.press('space')
        gen.press('tab', 2)
        gen.press('down')

        time.sleep(1)

        floor1 = gen.locateCenterOnScreen('./1F.png')
        gen.moveTo(floor1)

        time.sleep(1)

        gen.dragRel(0, 70, duration=0.2)

        time.sleep(1)

        gen.press('space')
        gen.press('enter')

        Dz = gen.locateCenterOnScreen('Dz.png')
        gen.moveTo(Dz)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(1)

        zoomout = gen.locateCenterOnScreen('zoomout.png')
        time.sleep(1)
        gen.click(zoomout, clicks=10, interval=0.1)

        time.sleep(1)

        gen.press('space')

        #lastzoom = gen.locateCenterOnScreen('lastzoom.png')
        #gen.press('space')

        time.sleep(0.1)

        zoomin = gen.locateCenterOnScreen('zoomin.png')
        gen.click(zoomin, clicks=4, interval=0.1)

        gen.press('p')
        time.sleep(1)
        gen.press('a')
        time.sleep(1)
        gen.press('enter')
        time.sleep(1)
        gen.typewrite('RC_Beam_Dz', interval=0.1)
        gen.press('enter')

        time.sleep(2)

        Ry = gen.locateCenterOnScreen('Ry.png')
        gen.moveTo(Ry)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(1)
        gen.typewrite('RC_Beam_Ry', interval=0.1)
        gen.press('enter')

    def click_btn_RCBeam(self):
        n = int(self.n_le.text())
        t = float(self.t_le.text())

        if self.x_le.text() and self.y_le.text():
            x_pos = int(self.x_le.text())
            y_pos = int(self.y_le.text())
            pyautogui.click(x_pos, y_pos, clicks=n, interval=t)
        elif len(self.fname):
            print(self.fname)
            for i in range(n):
                for j in range(len(self.fname)):
                    center = pyautogui.locateCenterOnScreen(self.fname[j])
                    pyautogui.click(center, interval=t)


    def RCCol_Data(self):

        rccol = gen.locateCenterOnScreen('rccol.png')
        gen.moveTo(rccol)
        gen.click(clicks=1, interval=0.1)
        gen.press('tab', 5, interval=0.1)
        gen.press('space')
        gen.press('tab', 2)
        gen.press('down')
        time.sleep(1)
        floor1 = gen.locateCenterOnScreen('1F.png')
        gen.moveTo(floor1)
        time.sleep(1)
        gen.dragRel(0, 70, duration=0.2)
        time.sleep(1)
        gen.press('space')
        gen.press('enter')
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(2)
        zoomout = gen.locateCenterOnScreen('zoomout.png')
        time.sleep(1)
        gen.click(zoomout, clicks=10, interval=0.1)
        time.sleep(1)
        gen.press('space')
        time.sleep(0.1)
        zoomin = gen.locateCenterOnScreen('zoomin.png')
        gen.click(zoomin, clicks=4, interval=0.1)
        gen.press('p')
        time.sleep(1)
        gen.press('a')
        time.sleep(1)
        gen.press('enter')
        time.sleep(1)
        gen.typewrite('RC_Col_Dx', interval=0.1)
        gen.press('enter')

        time.sleep(2)

        Dy = gen.locateCenterOnScreen('Dy.png')
        gen.moveTo(Dy)
        gen.click()
        time.sleep(2)
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(1)
        gen.press('p')
        time.sleep(1)
        gen.press('a')
        time.sleep(1)
        gen.press('enter')
        time.sleep(1)
        gen.typewrite('RC_Col_Dy', interval=0.1)
        gen.press('enter')

        time.sleep(1)
        Dz = gen.locateCenterOnScreen('Dz.png')
        gen.moveTo(Dz)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(2)
        gen.typewrite('RC_Col_Dz', interval=0.1)
        gen.press('enter')

        time.sleep(1)
        Ry = gen.locateCenterOnScreen('Ry.png')
        gen.moveTo(Ry)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(2)
        gen.typewrite('RC_Col_Ry', interval=0.1)
        gen.press('enter')

        time.sleep(1)
        Rz = gen.locateCenterOnScreen('Rz.png')
        gen.moveTo(Rz)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(2)
        gen.typewrite('RC_Col_Rz', interval=0.1)
        gen.press('enter')

    def click_btn_RCCol(self):
        n = int(self.n_le.text())
        t = float(self.t_le.text())

        if self.x_le.text() and self.y_le.text():
            x_pos = int(self.x_le.text())
            y_pos = int(self.y_le.text())
            pyautogui.click(x_pos, y_pos, clicks=n, interval=t)
        elif len(self.fname):
            print(self.fname)
            for i in range(n):
                for j in range(len(self.fname)):
                    center = pyautogui.locateCenterOnScreen(self.fname[j])
                    pyautogui.click(center, interval=t)

    def RCWall_Data(self):

        rcwall = gen.locateCenterOnScreen('rcwall.png')
        gen.moveTo(rcwall)
        gen.click(clicks=1, interval=0.1)
        gen.press('tab', 5, interval=0.1)
        gen.press('space')
        gen.press('tab', 2)
        gen.press('down')
        time.sleep(1)
        floor1 = gen.locateCenterOnScreen('1F.png')
        gen.moveTo(floor1)
        time.sleep(1)
        gen.dragRel(0, 70, duration=0.2)
        time.sleep(1)
        gen.press('space')
        gen.press('enter')
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(2)
        zoomout = gen.locateCenterOnScreen('zoomout.png')
        time.sleep(1)
        gen.click(zoomout, clicks=10, interval=0.1)
        time.sleep(1)
        gen.press('space')
        time.sleep(0.1)
        zoomin = gen.locateCenterOnScreen('zoomin.png')
        gen.click(zoomin, clicks=4, interval=0.1)
        gen.press('p')
        time.sleep(1)
        gen.press('a')
        time.sleep(1)
        gen.press('enter')
        time.sleep(1)
        gen.typewrite('RC_Wall_Dx', interval=0.1)
        gen.press('enter')

        time.sleep(2)

        Dz = gen.locateCenterOnScreen('Dz.png')
        gen.moveTo(Dz)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(2)
        gen.typewrite('RC_Wall_Dz', interval=0.1)
        gen.press('enter')

        time.sleep(1)
        Ry = gen.locateCenterOnScreen('Ry.png')
        gen.moveTo(Ry)
        gen.click()
        gen.hotkey('ctrl', 'shift', 'p')
        time.sleep(0.2)
        gen.press('p')
        time.sleep(0.2)
        gen.press('a')
        time.sleep(0.2)
        gen.press('enter')
        time.sleep(2)
        gen.typewrite('RC_Wall_Ry', interval=0.1)
        gen.press('enter')



    def click_btn_RCWall(self):
        n = int(self.n_le.text())
        t = float(self.t_le.text())

        if self.x_le.text() and self.y_le.text():
            x_pos = int(self.x_le.text())
            y_pos = int(self.y_le.text())
            pyautogui.click(x_pos, y_pos, clicks=n, interval=t)
        elif len(self.fname):
            print(self.fname)
            for i in range(n):
                for j in range(len(self.fname)):
                    center = pyautogui.locateCenterOnScreen(self.fname[j])
                    pyautogui.click(center, interval=t)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyApp()
    sys.exit(app.exec_())