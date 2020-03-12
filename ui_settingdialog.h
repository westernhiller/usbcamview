/********************************************************************************
** Form generated from reading UI file 'settingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGDIALOG_H
#define UI_SETTINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SettingDialog
{
public:
    QPushButton *btnBrowse;
    QLabel *label;
    QLineEdit *editPath;
    QCheckBox *checkFPS;
    QCheckBox *checkDefog;
    QCheckBox *checkClock;
    QComboBox *comboBox;
    QLabel *label_2;

    void setupUi(QDialog *SettingDialog)
    {
        if (SettingDialog->objectName().isEmpty())
            SettingDialog->setObjectName(QStringLiteral("SettingDialog"));
        SettingDialog->resize(1280, 800);
        QFont font;
        font.setPointSize(28);
        SettingDialog->setFont(font);
        btnBrowse = new QPushButton(SettingDialog);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));
        btnBrowse->setGeometry(QRect(1148, 40, 91, 51));
        label = new QLabel(SettingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 40, 301, 61));
        editPath = new QLineEdit(SettingDialog);
        editPath->setObjectName(QStringLiteral("editPath"));
        editPath->setGeometry(QRect(400, 40, 721, 51));
        editPath->setReadOnly(true);
        checkFPS = new QCheckBox(SettingDialog);
        checkFPS->setObjectName(QStringLiteral("checkFPS"));
        checkFPS->setGeometry(QRect(100, 180, 291, 51));
        checkDefog = new QCheckBox(SettingDialog);
        checkDefog->setObjectName(QStringLiteral("checkDefog"));
        checkDefog->setGeometry(QRect(100, 430, 301, 61));
        checkClock = new QCheckBox(SettingDialog);
        checkClock->setObjectName(QStringLiteral("checkClock"));
        checkClock->setGeometry(QRect(100, 310, 301, 61));
        comboBox = new QComboBox(SettingDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(670, 180, 451, 51));
        label_2 = new QLabel(SettingDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 170, 161, 61));

        retranslateUi(SettingDialog);

        QMetaObject::connectSlotsByName(SettingDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingDialog)
    {
        SettingDialog->setWindowTitle(QApplication::translate("SettingDialog", "Dialog", nullptr));
        btnBrowse->setText(QApplication::translate("SettingDialog", "...", nullptr));
        label->setText(QApplication::translate("SettingDialog", "\345\233\276\345\203\217\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        checkFPS->setText(QApplication::translate("SettingDialog", "\346\230\276\347\244\272\345\270\247\351\242\221", nullptr));
        checkDefog->setText(QApplication::translate("SettingDialog", "\345\216\273\351\233\276", nullptr));
        checkClock->setText(QApplication::translate("SettingDialog", "\346\230\276\347\244\272\346\227\266\351\227\264", nullptr));
        comboBox->setItemText(0, QApplication::translate("SettingDialog", "1920x1080", nullptr));
        comboBox->setItemText(1, QApplication::translate("SettingDialog", "1280x1024", nullptr));
        comboBox->setItemText(2, QApplication::translate("SettingDialog", "1024x768", nullptr));
        comboBox->setItemText(3, QApplication::translate("SettingDialog", "640x480", nullptr));

        label_2->setText(QApplication::translate("SettingDialog", "\345\210\206\350\276\250\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingDialog: public Ui_SettingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGDIALOG_H
