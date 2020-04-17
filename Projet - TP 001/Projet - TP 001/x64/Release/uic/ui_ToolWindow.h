/********************************************************************************
** Form generated from reading UI file 'ToolWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLWINDOW_H
#define UI_TOOLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Toolbox
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *toolBtnReset;
    QPushButton *toolBtnBlackWhite;
    QPushButton *toolBtnBlur;
    QPushButton *toolBtnErode;
    QPushButton *toolBtnDilate;
    QPushButton *toolBtnOpen;
    QPushButton *toolBtnClose;
    QPushButton *toolBtnCannyFilter;
    QPushButton *toolBtnDetectEdge;
    QPushButton *toolBtnDetectVertex;
    QPushButton *toolBtnDetectObject;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Toolbox)
    {
        if (Toolbox->objectName().isEmpty())
            Toolbox->setObjectName(QString::fromUtf8("Toolbox"));
        Toolbox->resize(225, 402);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Toolbox->sizePolicy().hasHeightForWidth());
        Toolbox->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(Toolbox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 221, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(verticalLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayoutWidget_2 = new QWidget(groupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(29, 19, 161, 315));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolBtnReset = new QPushButton(verticalLayoutWidget_2);
        toolBtnReset->setObjectName(QString::fromUtf8("toolBtnReset"));

        verticalLayout_2->addWidget(toolBtnReset);

        toolBtnBlackWhite = new QPushButton(verticalLayoutWidget_2);
        toolBtnBlackWhite->setObjectName(QString::fromUtf8("toolBtnBlackWhite"));

        verticalLayout_2->addWidget(toolBtnBlackWhite);

        toolBtnBlur = new QPushButton(verticalLayoutWidget_2);
        toolBtnBlur->setObjectName(QString::fromUtf8("toolBtnBlur"));

        verticalLayout_2->addWidget(toolBtnBlur);

        toolBtnErode = new QPushButton(verticalLayoutWidget_2);
        toolBtnErode->setObjectName(QString::fromUtf8("toolBtnErode"));

        verticalLayout_2->addWidget(toolBtnErode);

        toolBtnDilate = new QPushButton(verticalLayoutWidget_2);
        toolBtnDilate->setObjectName(QString::fromUtf8("toolBtnDilate"));

        verticalLayout_2->addWidget(toolBtnDilate);

        toolBtnOpen = new QPushButton(verticalLayoutWidget_2);
        toolBtnOpen->setObjectName(QString::fromUtf8("toolBtnOpen"));

        verticalLayout_2->addWidget(toolBtnOpen);

        toolBtnClose = new QPushButton(verticalLayoutWidget_2);
        toolBtnClose->setObjectName(QString::fromUtf8("toolBtnClose"));

        verticalLayout_2->addWidget(toolBtnClose);

        toolBtnCannyFilter = new QPushButton(verticalLayoutWidget_2);
        toolBtnCannyFilter->setObjectName(QString::fromUtf8("toolBtnCannyFilter"));

        verticalLayout_2->addWidget(toolBtnCannyFilter);

        toolBtnDetectEdge = new QPushButton(verticalLayoutWidget_2);
        toolBtnDetectEdge->setObjectName(QString::fromUtf8("toolBtnDetectEdge"));

        verticalLayout_2->addWidget(toolBtnDetectEdge);

        toolBtnDetectVertex = new QPushButton(verticalLayoutWidget_2);
        toolBtnDetectVertex->setObjectName(QString::fromUtf8("toolBtnDetectVertex"));

        verticalLayout_2->addWidget(toolBtnDetectVertex);

        toolBtnDetectObject = new QPushButton(verticalLayoutWidget_2);
        toolBtnDetectObject->setObjectName(QString::fromUtf8("toolBtnDetectObject"));

        verticalLayout_2->addWidget(toolBtnDetectObject);


        verticalLayout->addWidget(groupBox);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(verticalLayoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);


        verticalLayout->addLayout(hboxLayout);

        verticalLayout->setStretch(0, 2);

        retranslateUi(Toolbox);
        QObject::connect(okButton, SIGNAL(clicked()), Toolbox, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Toolbox, SLOT(reject()));

        QMetaObject::connectSlotsByName(Toolbox);
    } // setupUi

    void retranslateUi(QDialog *Toolbox)
    {
        Toolbox->setWindowTitle(QApplication::translate("Toolbox", "Toolbox", nullptr));
        groupBox->setTitle(QApplication::translate("Toolbox", "Tools", nullptr));
        toolBtnReset->setText(QApplication::translate("Toolbox", "Reset", nullptr));
        toolBtnBlackWhite->setText(QApplication::translate("Toolbox", "Monochrome", nullptr));
        toolBtnBlur->setText(QApplication::translate("Toolbox", "Blur", nullptr));
        toolBtnErode->setText(QApplication::translate("Toolbox", "Erode", nullptr));
        toolBtnDilate->setText(QApplication::translate("Toolbox", "Dilate", nullptr));
        toolBtnOpen->setText(QApplication::translate("Toolbox", "Opening", nullptr));
        toolBtnClose->setText(QApplication::translate("Toolbox", "Closing", nullptr));
        toolBtnCannyFilter->setText(QApplication::translate("Toolbox", "Canny Filter", nullptr));
        toolBtnDetectEdge->setText(QApplication::translate("Toolbox", "Detect Edges", nullptr));
        toolBtnDetectVertex->setText(QApplication::translate("Toolbox", "Detect Vertices", nullptr));
        toolBtnDetectObject->setText(QApplication::translate("Toolbox", "Detect Objects", nullptr));
        okButton->setText(QApplication::translate("Toolbox", "OK", nullptr));
        cancelButton->setText(QApplication::translate("Toolbox", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Toolbox: public Ui_Toolbox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLWINDOW_H
