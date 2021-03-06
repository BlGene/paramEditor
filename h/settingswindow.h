#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H


class Viewer;

#include <QMenu>


class QKeyEvent;
//class QMenu;
class QAction;
class QSettings;
class QLayout;

class ConfItemBase;
class ConfTreeModel;


namespace Ui
{
    class SettingsManager;
}


class SettingsManager : public QWidget
{
    Q_OBJECT


public:
    SettingsManager(QWidget * const parent=nullptr);
    ~SettingsManager();

    Ui::SettingsManager* ui;


    void toogleWindow();
    void render(ConfItemBase *item);

protected:
    virtual void keyPressEvent(QKeyEvent *e);

private slots:
    void openIniFile();
    void about();

private:

    ConfTreeModel* m_model;

    QWidget *m_parent;

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

    void createActions();
    void createMenus();
    void setSettingsObject(QSettings *settings);



};


#endif // SETTINGSWINDOW_H
