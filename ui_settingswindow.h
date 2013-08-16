/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created: Fri Aug 16 17:49:03 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QScrollArea>
#include <QtGui/QSplitter>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsManager
{
public:
    QSplitter *splitter;
    QTreeView *treeView;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *formLayoutWidget;
    QFormLayout *ConfLayout;

    void setupUi(QWidget *SettingsManager)
    {
        if (SettingsManager->objectName().isEmpty())
            SettingsManager->setObjectName(QString::fromUtf8("SettingsManager"));
        SettingsManager->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SettingsManager->sizePolicy().hasHeightForWidth());
        SettingsManager->setSizePolicy(sizePolicy);
        splitter = new QSplitter(SettingsManager);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 401, 301));
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        splitter->addWidget(treeView);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setEnabled(true);
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 135, 297));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(scrollAreaWidgetContents_3);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 290, 291));
        ConfLayout = new QFormLayout(formLayoutWidget);
        ConfLayout->setObjectName(QString::fromUtf8("ConfLayout"));
        ConfLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        ConfLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        splitter->addWidget(scrollArea);

        retranslateUi(SettingsManager);

        QMetaObject::connectSlotsByName(SettingsManager);
    } // setupUi

    void retranslateUi(QWidget *SettingsManager)
    {
        SettingsManager->setWindowTitle(QApplication::translate("SettingsManager", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsManager: public Ui_SettingsManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
