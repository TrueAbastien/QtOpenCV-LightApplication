/********************************************************************************
** Form generated from reading UI file 'ImageModifierApp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEMODIFIERAPP_H
#define UI_IMAGEMODIFIERAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageModifierAppClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageModifierAppClass)
    {
        if (ImageModifierAppClass->objectName().isEmpty())
            ImageModifierAppClass->setObjectName(QString::fromUtf8("ImageModifierAppClass"));
        ImageModifierAppClass->resize(600, 400);
        menuBar = new QMenuBar(ImageModifierAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ImageModifierAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageModifierAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImageModifierAppClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ImageModifierAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ImageModifierAppClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ImageModifierAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageModifierAppClass->setStatusBar(statusBar);

        retranslateUi(ImageModifierAppClass);

        QMetaObject::connectSlotsByName(ImageModifierAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageModifierAppClass)
    {
        ImageModifierAppClass->setWindowTitle(QApplication::translate("ImageModifierAppClass", "ImageModifierApp", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageModifierAppClass: public Ui_ImageModifierAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEMODIFIERAPP_H
