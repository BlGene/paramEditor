#include <iostream>

#include <QFileDialog>
#include <QSettings>
#include <QAction>
#include <QMessageBox>
#include <QKeyEvent>
#include <QLayout>

#include <QGridLayout>
#include <QCheckBox>

using namespace std;

#include "settingswindow.h"
#include "ui_settingswindow.h"

#include "manageditem.h"

//extern template class ManagedItem<bool>;

SettingsManager::SettingsManager(QWidget * const parent):
    QWidget(parent),
    ui(new Ui::SettingsManager),
    m_parent(parent)
{
    ui->setupUi(this);
    setWindowTitle("Settings Editor");


    createActions();
    createMenus();

}

void SettingsManager::render(ConfTreeModel *ctm)
{

    cout << "New Settings Manager" << endl;

    this->ui->treeView->setModel(ctm);

    ctm->render(this);


}


//Configuration Settings
//------------------------------------------------------------------------------
void SettingsManager::toogleWindow()
{
    if(isVisible())
        hide();
    else
        show();
    /*
    if (!locationDialog)
        locationDialog = new LocationDialog(this);

    if (locationDialog->exec()) {
        QSettings *settings = new QSettings(locationDialog->format(),
                                            locationDialog->scope(),
                                            locationDialog->organization(),
                                            locationDialog->application());
        setSettingsObject(settings);
        fallbacksAct->setEnabled(true);
    }
    */
}

void SettingsManager::keyPressEvent(QKeyEvent *event)
{
    switch ( event->key() )
    {
        case Qt::Key_Escape:
            hide();
            break;
    }
}


void SettingsManager::openIniFile()
{
    /*
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open INI File"),
                               "", tr("INI Files (*.ini *.conf)"));
    if (!fileName.isEmpty()) {
        QSettings *settings = new QSettings(fileName, QSettings::IniFormat);
        setSettingsObject(settings);
        fallbacksAct->setEnabled(false);
    }
    */
}

void SettingsManager::about()
{
    /*
    QMessageBox::about(this, tr("About Settings Editor"),
            tr("The <b>Settings Editor</b> example shows how to access "
               "application settings using Qt."));
    */
}

void SettingsManager::createActions()
{
    /*
    openSettingsAct = new QAction(tr("&Open Application Settings..."), this);
    openSettingsAct->setShortcuts(QKeySequence::Open);
    connect(openSettingsAct, SIGNAL(triggered()), this, SLOT(openSettings()));

    openIniFileAct = new QAction(tr("Open I&NI File..."), this);
    openIniFileAct->setShortcut(tr("Ctrl+N"));
    connect(openIniFileAct, SIGNAL(triggered()), this, SLOT(openIniFile()));

    if(m_settingstree != NULL)
    {
        refreshAct = new QAction(tr("&Refresh"), this);
        refreshAct->setShortcut(tr("Ctrl+R"));
        refreshAct->setEnabled(false);
        connect(refreshAct, SIGNAL(triggered()), m_settingstree, SLOT(refresh()));
    }
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    autoRefreshAct = new QAction(tr("&Auto-Refresh"), this);
    autoRefreshAct->setShortcut(tr("Ctrl+A"));
    autoRefreshAct->setCheckable(true);
    autoRefreshAct->setEnabled(false);
    connect(autoRefreshAct, SIGNAL(triggered(bool)),
            m_settingstree, SLOT(setAutoRefresh(bool)));
    connect(autoRefreshAct, SIGNAL(triggered(bool)),
            refreshAct, SLOT(setDisabled(bool)));

    fallbacksAct = new QAction(tr("&Fallbacks"), this);
    fallbacksAct->setShortcut(tr("Ctrl+F"));
    fallbacksAct->setCheckable(true);
    fallbacksAct->setEnabled(false);
    connect(fallbacksAct, SIGNAL(triggered(bool)),
            m_settingstree, SLOT(setFallbacksEnabled(bool)));

    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    */
}

void SettingsManager::createMenus()
{
    /*
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openSettingsAct);
    fileMenu->addAction(openIniFileAct);
    fileMenu->addSeparator();
    fileMenu->addAction(refreshAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionsMenu = menuBar()->addMenu(tr("&Options"));
    optionsMenu->addAction(autoRefreshAct);
    optionsMenu->addAction(fallbacksAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
    */
}

void SettingsManager::setSettingsObject(QSettings *settings)
{
    /*
    settings->setFallbacksEnabled(fallbacksAct->isChecked());
    m_settingstree->setSettingsObject(settings);

    refreshAct->setEnabled(true);
    autoRefreshAct->setEnabled(true);

    QString niceName = settings->fileName();
    niceName.replace("\\", "/");
    int pos = niceName.lastIndexOf("/");
    if (pos != -1)
        niceName.remove(0, pos + 1);

    if (!settings->isWritable())
        niceName = tr("%1 (read only)").arg(niceName);

    setWindowTitle(tr("%1 - %2").arg(niceName).arg(tr("Settings Editor")));
    */
}


