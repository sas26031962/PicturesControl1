/********************************************************************************
** Form generated from reading UI file 'fmview.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FMVIEW_H
#define UI_FMVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_fmView
{
public:
    QLabel *labelMain;
    QLabel *labelInfo;
    QSlider *horizontalSliderScale;

    void setupUi(QDialog *fmView)
    {
        if (fmView->objectName().isEmpty())
            fmView->setObjectName(QStringLiteral("fmView"));
        fmView->resize(830, 860);
        labelMain = new QLabel(fmView);
        labelMain->setObjectName(QStringLiteral("labelMain"));
        labelMain->setGeometry(QRect(5, 5, 821, 821));
        labelMain->setStyleSheet(QStringLiteral("background-color: rgb(239, 246, 255);"));
        labelMain->setAlignment(Qt::AlignCenter);
        labelInfo = new QLabel(fmView);
        labelInfo->setObjectName(QStringLiteral("labelInfo"));
        labelInfo->setGeometry(QRect(10, 830, 621, 22));
        labelInfo->setStyleSheet(QStringLiteral("background-color: rgb(248, 255, 250);"));
        horizontalSliderScale = new QSlider(fmView);
        horizontalSliderScale->setObjectName(QStringLiteral("horizontalSliderScale"));
        horizontalSliderScale->setGeometry(QRect(650, 830, 171, 22));
        horizontalSliderScale->setMinimum(410);
        horizontalSliderScale->setMaximum(1640);
        horizontalSliderScale->setValue(821);
        horizontalSliderScale->setOrientation(Qt::Horizontal);

        retranslateUi(fmView);

        QMetaObject::connectSlotsByName(fmView);
    } // setupUi

    void retranslateUi(QDialog *fmView)
    {
        fmView->setWindowTitle(QApplication::translate("fmView", "ViewPicture", 0));
        labelMain->setText(QString());
        labelInfo->setText(QApplication::translate("fmView", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class fmView: public Ui_fmView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FMVIEW_H
