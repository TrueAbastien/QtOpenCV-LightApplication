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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageModifierAppClass
{
public:
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionBlur;
    QAction *actionErode;
    QAction *actionDilate;
    QAction *actionOpening;
    QAction *actionClosing;
    QAction *actionCannyFilter;
    QAction *actionDetectEdges;
    QAction *actionDetectVertices;
    QAction *actionReset;
    QAction *actionOpenToolbox;
    QAction *actionDetectObjects;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *imgHLayout;
    QLabel *imgOriginal;
    QLabel *imgTransformed;
    QMenuBar *menuBar;
    QMenu *menuEdit;
    QMenu *menuTool;
    QMenu *menuTransform;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageModifierAppClass)
    {
        if (ImageModifierAppClass->objectName().isEmpty())
            ImageModifierAppClass->setObjectName(QString::fromUtf8("ImageModifierAppClass"));
        ImageModifierAppClass->resize(870, 400);
        actionLoad = new QAction(ImageModifierAppClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(ImageModifierAppClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionBlur = new QAction(ImageModifierAppClass);
        actionBlur->setObjectName(QString::fromUtf8("actionBlur"));
        actionErode = new QAction(ImageModifierAppClass);
        actionErode->setObjectName(QString::fromUtf8("actionErode"));
        actionDilate = new QAction(ImageModifierAppClass);
        actionDilate->setObjectName(QString::fromUtf8("actionDilate"));
        actionOpening = new QAction(ImageModifierAppClass);
        actionOpening->setObjectName(QString::fromUtf8("actionOpening"));
        actionClosing = new QAction(ImageModifierAppClass);
        actionClosing->setObjectName(QString::fromUtf8("actionClosing"));
        actionCannyFilter = new QAction(ImageModifierAppClass);
        actionCannyFilter->setObjectName(QString::fromUtf8("actionCannyFilter"));
        actionDetectEdges = new QAction(ImageModifierAppClass);
        actionDetectEdges->setObjectName(QString::fromUtf8("actionDetectEdges"));
        actionDetectVertices = new QAction(ImageModifierAppClass);
        actionDetectVertices->setObjectName(QString::fromUtf8("actionDetectVertices"));
        actionReset = new QAction(ImageModifierAppClass);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionReset->setCheckable(true);
        actionReset->setChecked(true);
        actionOpenToolbox = new QAction(ImageModifierAppClass);
        actionOpenToolbox->setObjectName(QString::fromUtf8("actionOpenToolbox"));
        actionDetectObjects = new QAction(ImageModifierAppClass);
        actionDetectObjects->setObjectName(QString::fromUtf8("actionDetectObjects"));
        centralWidget = new QWidget(ImageModifierAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        imgHLayout = new QHBoxLayout();
        imgHLayout->setSpacing(6);
        imgHLayout->setObjectName(QString::fromUtf8("imgHLayout"));
        imgOriginal = new QLabel(centralWidget);
        imgOriginal->setObjectName(QString::fromUtf8("imgOriginal"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        imgOriginal->setFont(font);
        imgOriginal->setAlignment(Qt::AlignCenter);

        imgHLayout->addWidget(imgOriginal);

        imgTransformed = new QLabel(centralWidget);
        imgTransformed->setObjectName(QString::fromUtf8("imgTransformed"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        imgTransformed->setFont(font1);
        imgTransformed->setAlignment(Qt::AlignCenter);

        imgHLayout->addWidget(imgTransformed);

        imgHLayout->setStretch(0, 1);
        imgHLayout->setStretch(1, 1);

        gridLayout->addLayout(imgHLayout, 0, 0, 1, 1);

        ImageModifierAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageModifierAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 870, 21));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QString::fromUtf8("menuTool"));
        menuTransform = new QMenu(menuTool);
        menuTransform->setObjectName(QString::fromUtf8("menuTransform"));
        menuTransform->setEnabled(true);
        ImageModifierAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageModifierAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ImageModifierAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageModifierAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ImageModifierAppClass->setStatusBar(statusBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuEdit->addAction(actionLoad);
        menuEdit->addAction(actionSave);
        menuTool->addAction(menuTransform->menuAction());
        menuTransform->addAction(actionReset);
        menuTransform->addSeparator();
        menuTransform->addAction(actionBlur);
        menuTransform->addAction(actionErode);
        menuTransform->addAction(actionDilate);
        menuTransform->addAction(actionOpening);
        menuTransform->addAction(actionClosing);
        menuTransform->addAction(actionCannyFilter);
        menuTransform->addAction(actionDetectEdges);
        menuTransform->addAction(actionDetectVertices);
        menuTransform->addAction(actionDetectObjects);
        menuTransform->addSeparator();
        menuTransform->addAction(actionOpenToolbox);

        retranslateUi(ImageModifierAppClass);

        QMetaObject::connectSlotsByName(ImageModifierAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageModifierAppClass)
    {
        ImageModifierAppClass->setWindowTitle(QApplication::translate("ImageModifierAppClass", "ImageModifierApp", nullptr));
        actionLoad->setText(QApplication::translate("ImageModifierAppClass", "Load", nullptr));
        actionSave->setText(QApplication::translate("ImageModifierAppClass", "Save", nullptr));
        actionBlur->setText(QApplication::translate("ImageModifierAppClass", "Blur", nullptr));
        actionErode->setText(QApplication::translate("ImageModifierAppClass", "Erode", nullptr));
        actionDilate->setText(QApplication::translate("ImageModifierAppClass", "Dilate", nullptr));
        actionOpening->setText(QApplication::translate("ImageModifierAppClass", "Opening", nullptr));
        actionClosing->setText(QApplication::translate("ImageModifierAppClass", "Closing", nullptr));
        actionCannyFilter->setText(QApplication::translate("ImageModifierAppClass", "Canny Filter", nullptr));
        actionDetectEdges->setText(QApplication::translate("ImageModifierAppClass", "Detect Edges", nullptr));
        actionDetectVertices->setText(QApplication::translate("ImageModifierAppClass", "Detect Vertices", nullptr));
        actionReset->setText(QApplication::translate("ImageModifierAppClass", "Reset", nullptr));
        actionOpenToolbox->setText(QApplication::translate("ImageModifierAppClass", "Open Toolbox", nullptr));
        actionDetectObjects->setText(QApplication::translate("ImageModifierAppClass", "Detect Objects", nullptr));
        imgOriginal->setText(QApplication::translate("ImageModifierAppClass", "NO IMAGE FOUND", nullptr));
        imgTransformed->setText(QApplication::translate("ImageModifierAppClass", "NO IMAGE FOUND", nullptr));
        menuEdit->setTitle(QApplication::translate("ImageModifierAppClass", "File", nullptr));
        menuTool->setTitle(QApplication::translate("ImageModifierAppClass", "Tool", nullptr));
        menuTransform->setTitle(QApplication::translate("ImageModifierAppClass", "Transform", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageModifierAppClass: public Ui_ImageModifierAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEMODIFIERAPP_H
