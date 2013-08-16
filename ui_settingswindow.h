/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created: Thu Aug 15 22:08:28 2013
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
        splitter = new QSplitter(SettingsManager);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(0, 0, 401, 301));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setEnabled(true);
        sizePolicy.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy);
        splitter->addWidget(treeView);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setEnabled(true);
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 195, 297));
        sizePolicy.setHeightForWidth(scrollAreaWidgetContents_3->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_3->setSizePolicy(sizePolicy);
        formLayoutWidget = new QWidget(scrollAreaWidgetContents_3);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 0, 191, 291));
        ConfLayout = new QFormLayout(formLayoutWidget);
        ConfLayout->setObjectName(QString::fromUtf8("ConfLayout"));
        ConfLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        ConfLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        formLayoutWidget->raise();
        treeView->raise();
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
