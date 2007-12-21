/********************************************************************************
** Form generated from reading ui file 'clave.ui'
**
** Created: Thu 20. Dec 22:01:16 2007
**      by: Qt User Interface Compiler version 4.3.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CLAVE_H
#define UI_CLAVE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

class Ui_ClaveClass
{
public:
    QFrame *line_2;
    QLabel *label_6;
    QPushButton *botonCrear;
    QLabel *label_5;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label_2;
    QSpinBox *spinN;
    QHBoxLayout *hboxLayout1;
    QLabel *label;
    QSpinBox *spinCC;
    QPushButton *botonMezclar;
    QLabel *label_4;
    QPushButton *botonResolver;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_3;
    QPushButton *botonAbrir;

    void setupUi(QWidget *ClaveClass)
    {
    if (ClaveClass->objectName().isEmpty())
        ClaveClass->setObjectName(QString::fromUtf8("ClaveClass"));
    ClaveClass->setWindowModality(Qt::NonModal);
    ClaveClass->resize(718, 625);
    line_2 = new QFrame(ClaveClass);
    line_2->setObjectName(QString::fromUtf8("line_2"));
    line_2->setGeometry(QRect(50, 350, 201, 20));
    line_2->setFrameShape(QFrame::HLine);
    line_2->setFrameShadow(QFrame::Sunken);
    label_6 = new QLabel(ClaveClass);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setEnabled(false);
    label_6->setGeometry(QRect(40, 380, 211, 31));
    botonCrear = new QPushButton(ClaveClass);
    botonCrear->setObjectName(QString::fromUtf8("botonCrear"));
    botonCrear->setGeometry(QRect(40, 180, 221, 24));
    label_5 = new QLabel(ClaveClass);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setEnabled(false);
    label_5->setGeometry(QRect(40, 250, 191, 42));
    layoutWidget = new QWidget(ClaveClass);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(160, 90, 104, 52));
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(11);
    vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
    vboxLayout->setContentsMargins(0, 0, 0, 0);
    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    hboxLayout->addWidget(label_2);

    spinN = new QSpinBox(layoutWidget);
    spinN->setObjectName(QString::fromUtf8("spinN"));
    spinN->setMinimum(2);
    spinN->setMaximum(16);
    spinN->setValue(3);

    hboxLayout->addWidget(spinN);


    vboxLayout->addLayout(hboxLayout);

    hboxLayout1 = new QHBoxLayout();
    hboxLayout1->setSpacing(6);
    hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    hboxLayout1->addWidget(label);

    spinCC = new QSpinBox(layoutWidget);
    spinCC->setObjectName(QString::fromUtf8("spinCC"));
    spinCC->setMinimum(2);
    spinCC->setMaximum(22);
    spinCC->setValue(2);

    hboxLayout1->addWidget(spinCC);


    vboxLayout->addLayout(hboxLayout1);

    botonMezclar = new QPushButton(ClaveClass);
    botonMezclar->setObjectName(QString::fromUtf8("botonMezclar"));
    botonMezclar->setEnabled(false);
    botonMezclar->setGeometry(QRect(40, 310, 221, 24));
    label_4 = new QLabel(ClaveClass);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(40, 60, 91, 21));
    botonResolver = new QPushButton(ClaveClass);
    botonResolver->setObjectName(QString::fromUtf8("botonResolver"));
    botonResolver->setEnabled(false);
    botonResolver->setGeometry(QRect(40, 430, 221, 24));
    label_3 = new QLabel(ClaveClass);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(40, 100, 125, 70));
    line = new QFrame(ClaveClass);
    line->setObjectName(QString::fromUtf8("line"));
    line->setEnabled(false);
    line->setGeometry(QRect(50, 220, 201, 20));
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line_3 = new QFrame(ClaveClass);
    line_3->setObjectName(QString::fromUtf8("line_3"));
    line_3->setGeometry(QRect(50, 470, 201, 20));
    line_3->setFrameShape(QFrame::HLine);
    line_3->setFrameShadow(QFrame::Sunken);
    botonAbrir = new QPushButton(ClaveClass);
    botonAbrir->setObjectName(QString::fromUtf8("botonAbrir"));
    botonAbrir->setEnabled(true);
    botonAbrir->setGeometry(QRect(40, 510, 221, 24));
    botonAbrir->setDefault(false);
    QWidget::setTabOrder(spinN, spinCC);
    QWidget::setTabOrder(spinCC, botonCrear);
    QWidget::setTabOrder(botonCrear, botonMezclar);
    QWidget::setTabOrder(botonMezclar, botonResolver);

    retranslateUi(ClaveClass);

    QMetaObject::connectSlotsByName(ClaveClass);
    } // setupUi

    void retranslateUi(QWidget *ClaveClass)
    {
    ClaveClass->setWindowTitle(QApplication::translate("ClaveClass", "Clave", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("ClaveClass", "3. Por \303\272ltimo, aplicamos nuestro algortimo<br>en busca de una soluci\303\263n", 0, QApplication::UnicodeUTF8));
    botonCrear->setWhatsThis(QApplication::translate("ClaveClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    botonCrear->setText(QApplication::translate("ClaveClass", "Crear", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("ClaveClass", "2. Ahora necesitamos mezclar las fichas<br>   para que obtener un<br>verdadero rompecabezas.", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ClaveClass", "N:", 0, QApplication::UnicodeUTF8));
    spinN->setSuffix(QString());
    label->setText(QApplication::translate("ClaveClass", "#Colores:", 0, QApplication::UnicodeUTF8));
    botonMezclar->setText(QApplication::translate("ClaveClass", "Mezclar", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("ClaveClass", "<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><span style=\" font-size:9pt; font-weight:600; color:#000000;\">Instrucciones:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    botonResolver->setText(QApplication::translate("ClaveClass", "Resolver", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("ClaveClass", "1. Primero debemos<br>crear un nuevo puzzle,<br>de tama\303\261o N x N con<br>una determinada cantidad<br>de posibles colores", 0, QApplication::UnicodeUTF8));
    botonAbrir->setText(QApplication::translate("ClaveClass", "&Abrir", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ClaveClass);
    } // retranslateUi

};

namespace Ui {
    class ClaveClass: public Ui_ClaveClass {};
} // namespace Ui

#endif // UI_CLAVE_H
