/********************************************************************************
** Form generated from reading UI file 'user.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_H
#define UI_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_User
{
public:
    QPushButton *pushButton;
    QLabel *label_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *User_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password;

    void setupUi(QDialog *User)
    {
        if (User->objectName().isEmpty())
            User->setObjectName(QString::fromUtf8("User"));
        User->resize(455, 353);
        pushButton = new QPushButton(User);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(150, 280, 111, 41));
        label_3 = new QLabel(User);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 20, 281, 61));
        widget = new QWidget(User);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 100, 381, 151));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        User_2 = new QLineEdit(widget);
        User_2->setObjectName(QString::fromUtf8("User_2"));
        User_2->setFont(font);

        horizontalLayout->addWidget(User_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        Password = new QLineEdit(widget);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setFont(font);
        Password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(User);

        QMetaObject::connectSlotsByName(User);
    } // setupUi

    void retranslateUi(QDialog *User)
    {
        User->setWindowTitle(QApplication::translate("User", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("User", "Confirmar", nullptr));
        label_3->setText(QApplication::translate("User", "<html><head/><body><p><span style=\" font-size:10pt;\">Ingrese los datos, una vez que tenga </span></p><p><span style=\" font-size:10pt;\">seguridad de click al bot\303\263n confirmar.</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("User", "User name:", nullptr));
        label_2->setText(QApplication::translate("User", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class User: public Ui_User {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_H
