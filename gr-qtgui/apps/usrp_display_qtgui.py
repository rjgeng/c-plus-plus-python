# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'usrp_display_qtgui.ui'
#
# Created: Thu Jul 16 22:06:24 2009
#      by: PyQt4 UI code generator 4.4.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(820, 774)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout_2 = QtGui.QGridLayout(self.centralwidget)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.horizontalLayout_2 = QtGui.QHBoxLayout()
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.groupBox = QtGui.QGroupBox(self.centralwidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.groupBox.sizePolicy().hasHeightForWidth())
        self.groupBox.setSizePolicy(sizePolicy)
        self.groupBox.setMinimumSize(QtCore.QSize(240, 150))
        self.groupBox.setMaximumSize(QtCore.QSize(240, 16777215))
        self.groupBox.setObjectName("groupBox")
        self.formLayoutWidget = QtGui.QWidget(self.groupBox)
        self.formLayoutWidget.setGeometry(QtCore.QRect(10, 20, 221, 124))
        self.formLayoutWidget.setObjectName("formLayoutWidget")
        self.formLayout = QtGui.QFormLayout(self.formLayoutWidget)
        self.formLayout.setObjectName("formLayout")
        self.frequencyLabel = QtGui.QLabel(self.formLayoutWidget)
        self.frequencyLabel.setObjectName("frequencyLabel")
        self.formLayout.setWidget(
            0, QtGui.QFormLayout.LabelRole, self.frequencyLabel)
        self.gainLabel = QtGui.QLabel(self.formLayoutWidget)
        self.gainLabel.setObjectName("gainLabel")
        self.formLayout.setWidget(
            1, QtGui.QFormLayout.LabelRole, self.gainLabel)
        self.bandwidthLabel = QtGui.QLabel(self.formLayoutWidget)
        self.bandwidthLabel.setObjectName("bandwidthLabel")
        self.formLayout.setWidget(
            2, QtGui.QFormLayout.LabelRole, self.bandwidthLabel)
        self.frequencyEdit = QtGui.QLineEdit(self.formLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.frequencyEdit.sizePolicy().hasHeightForWidth())
        self.frequencyEdit.setSizePolicy(sizePolicy)
        self.frequencyEdit.setMinimumSize(QtCore.QSize(120, 26))
        self.frequencyEdit.setObjectName("frequencyEdit")
        self.formLayout.setWidget(
            0, QtGui.QFormLayout.FieldRole, self.frequencyEdit)
        self.gainEdit = QtGui.QLineEdit(self.formLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.gainEdit.sizePolicy().hasHeightForWidth())
        self.gainEdit.setSizePolicy(sizePolicy)
        self.gainEdit.setMinimumSize(QtCore.QSize(120, 26))
        self.gainEdit.setObjectName("gainEdit")
        self.formLayout.setWidget(
            1, QtGui.QFormLayout.FieldRole, self.gainEdit)
        self.bandwidthEdit = QtGui.QLineEdit(self.formLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.bandwidthEdit.sizePolicy().hasHeightForWidth())
        self.bandwidthEdit.setSizePolicy(sizePolicy)
        self.bandwidthEdit.setMinimumSize(QtCore.QSize(120, 26))
        self.bandwidthEdit.setObjectName("bandwidthEdit")
        self.formLayout.setWidget(
            2, QtGui.QFormLayout.FieldRole, self.bandwidthEdit)
        self.amplifierLabel = QtGui.QLabel(self.formLayoutWidget)
        self.amplifierLabel.setObjectName("amplifierLabel")
        self.formLayout.setWidget(
            3, QtGui.QFormLayout.LabelRole, self.amplifierLabel)
        self.amplifierEdit = QtGui.QLineEdit(self.formLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.amplifierEdit.sizePolicy().hasHeightForWidth())
        self.amplifierEdit.setSizePolicy(sizePolicy)
        self.amplifierEdit.setMinimumSize(QtCore.QSize(120, 26))
        self.amplifierEdit.setObjectName("amplifierEdit")
        self.formLayout.setWidget(
            3, QtGui.QFormLayout.FieldRole, self.amplifierEdit)
        self.horizontalLayout_2.addWidget(self.groupBox)
        self.frame_2 = QtGui.QFrame(self.centralwidget)
        self.frame_2.setMinimumSize(QtCore.QSize(200, 0))
        self.frame_2.setFrameShape(QtGui.QFrame.StyledPanel)
        self.frame_2.setFrameShadow(QtGui.QFrame.Raised)
        self.frame_2.setObjectName("frame_2")
        self.verticalLayoutWidget = QtGui.QWidget(self.frame_2)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(10, -1, 191, 151))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout_3 = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.dcCancelCheckBox = QtGui.QCheckBox(self.verticalLayoutWidget)
        self.dcCancelCheckBox.setObjectName("dcCancelCheckBox")
        self.verticalLayout_3.addWidget(self.dcCancelCheckBox)
        self.horizontalLayout = QtGui.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.dcGainLabel = QtGui.QLabel(self.verticalLayoutWidget)
        self.dcGainLabel.setObjectName("dcGainLabel")
        self.horizontalLayout.addWidget(self.dcGainLabel)
        self.dcGainEdit = QtGui.QLineEdit(self.verticalLayoutWidget)
        self.dcGainEdit.setObjectName("dcGainEdit")
        self.horizontalLayout.addWidget(self.dcGainEdit)
        self.verticalLayout_3.addLayout(self.horizontalLayout)
        spacerItem = QtGui.QSpacerItem(
            20, 40, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Expanding)
        self.verticalLayout_3.addItem(spacerItem)
        self.horizontalLayout_2.addWidget(self.frame_2)
        spacerItem1 = QtGui.QSpacerItem(
            40, 20, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem1)
        self.verticalLayout = QtGui.QVBoxLayout()
        self.verticalLayout.setObjectName("verticalLayout")
        spacerItem2 = QtGui.QSpacerItem(
            20, 80, QtGui.QSizePolicy.Minimum, QtGui.QSizePolicy.Fixed)
        self.verticalLayout.addItem(spacerItem2)
        self.pauseButton = QtGui.QPushButton(self.centralwidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.pauseButton.sizePolicy().hasHeightForWidth())
        self.pauseButton.setSizePolicy(sizePolicy)
        self.pauseButton.setObjectName("pauseButton")
        self.verticalLayout.addWidget(self.pauseButton)
        self.closeButton = QtGui.QPushButton(self.centralwidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Fixed, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(
            self.closeButton.sizePolicy().hasHeightForWidth())
        self.closeButton.setSizePolicy(sizePolicy)
        self.closeButton.setMinimumSize(QtCore.QSize(75, 0))
        self.closeButton.setObjectName("closeButton")
        self.verticalLayout.addWidget(self.closeButton)
        self.horizontalLayout_2.addLayout(self.verticalLayout)
        self.gridLayout_2.addLayout(self.horizontalLayout_2, 1, 0, 1, 1)
        self.verticalLayout_2 = QtGui.QVBoxLayout()
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.frame = QtGui.QFrame(self.centralwidget)
        sizePolicy = QtGui.QSizePolicy(
            QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(1)
        sizePolicy.setHeightForWidth(
            self.frame.sizePolicy().hasHeightForWidth())
        self.frame.setSizePolicy(sizePolicy)
        self.frame.setMinimumSize(QtCore.QSize(800, 550))
        self.frame.setFrameShape(QtGui.QFrame.StyledPanel)
        self.frame.setFrameShadow(QtGui.QFrame.Raised)
        self.frame.setObjectName("frame")
        self.gridLayout = QtGui.QGridLayout(self.frame)
        self.gridLayout.setObjectName("gridLayout")
        self.sinkLayout = QtGui.QHBoxLayout()
        self.sinkLayout.setObjectName("sinkLayout")
        self.gridLayout.addLayout(self.sinkLayout, 0, 0, 1, 1)
        self.verticalLayout_2.addWidget(self.frame)
        self.gridLayout_2.addLayout(self.verticalLayout_2, 0, 0, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 820, 24))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtGui.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionExit = QtGui.QAction(MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.actionSaveData = QtGui.QAction(MainWindow)
        self.actionSaveData.setObjectName("actionSaveData")
        self.menuFile.addAction(self.actionSaveData)
        self.menuFile.addAction(self.actionExit)
        self.menubar.addAction(self.menuFile.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QObject.connect(self.closeButton, QtCore.SIGNAL(
            "clicked()"), MainWindow.close)
        QtCore.QObject.connect(self.actionExit, QtCore.SIGNAL(
            "triggered()"), MainWindow.close)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(QtGui.QApplication.translate(
            "MainWindow", "USRP Display", None, QtGui.QApplication.UnicodeUTF8))
        self.groupBox.setTitle(QtGui.QApplication.translate(
            "MainWindow", "Receiver Parameters", None, QtGui.QApplication.UnicodeUTF8))
        self.frequencyLabel.setText(QtGui.QApplication.translate(
            "MainWindow", "Frequency (Hz)", None, QtGui.QApplication.UnicodeUTF8))
        self.gainLabel.setText(QtGui.QApplication.translate(
            "MainWindow", "RF Gain", None, QtGui.QApplication.UnicodeUTF8))
        self.bandwidthLabel.setText(QtGui.QApplication.translate(
            "MainWindow", "Bandwidth", None, QtGui.QApplication.UnicodeUTF8))
        self.amplifierLabel.setText(QtGui.QApplication.translate(
            "MainWindow", "Amplifier", None, QtGui.QApplication.UnicodeUTF8))
        self.dcCancelCheckBox.setText(QtGui.QApplication.translate(
            "MainWindow", "Cancel DC", None, QtGui.QApplication.UnicodeUTF8))
        self.dcGainLabel.setText(QtGui.QApplication.translate(
            "MainWindow", "DC Canceller Gain", None, QtGui.QApplication.UnicodeUTF8))
        self.pauseButton.setText(QtGui.QApplication.translate(
            "MainWindow", "Pause", None, QtGui.QApplication.UnicodeUTF8))
        self.closeButton.setText(QtGui.QApplication.translate(
            "MainWindow", "Close", None, QtGui.QApplication.UnicodeUTF8))
        self.menuFile.setTitle(QtGui.QApplication.translate(
            "MainWindow", "&File", None, QtGui.QApplication.UnicodeUTF8))
        self.actionExit.setText(QtGui.QApplication.translate(
            "MainWindow", "E&xit", None, QtGui.QApplication.UnicodeUTF8))
        self.actionSaveData.setText(QtGui.QApplication.translate(
            "MainWindow", "&Save Data", None, QtGui.QApplication.UnicodeUTF8))
