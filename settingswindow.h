#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H


class Viewer;

#include <QMenu>


class QKeyEvent;
//class QMenu;
class QAction;
class QSettings;
class QLayout;

class ManagedItemBase;

#include "ui_settingswindow.h"

//namespace Ui
//{
//    class SettingsManager;
//}

class SettingsManager : public QWidget
{
    Q_OBJECT

public:
    SettingsManager(QWidget * const parent=nullptr);

    void toogleWindow();
    void render(ManagedItemBase& item);

    Ui::SettingsManager* ui;

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void openIniFile();
    void about();

private:
    QWidget *m_parent;

    void createActions();
    void createMenus();
    void setSettingsObject(QSettings *settings);



    QMenu *fileMenu;
    QMenu *optionsMenu;
    QAction *openSettingsAct;
    QAction *openIniFileAct;
    QAction *refreshAct;
    QAction *exitAct;
    QAction *autoRefreshAct;
    QAction *fallbacksAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};


#endif // SETTINGSWINDOW_H
