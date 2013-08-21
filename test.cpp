#include "test.h"
#include <typeinfo>

#include <QApplication>
#include "settingswindow.h"



//Constructor
Test1::Test1()
    //:m_subclass(Test2{})
{
    //cout << "Test1: " << typeid(*this).name() << endl;

    //Causes segfault because of copy operator
    //cout << "Start" <<endl;
    //m_subclass2 = Test3{};
    //cout << "Stop" <<endl;
    //cout << "New instance address: " << &m_subclass << endl;

    bindName(name);
    bindVar(m_subclass);
    bindVar(m_subclass2);
}


int main(int argc, char** argv)
{
    Test1 inst1{};

    //cout <<  "Print: " << endl;
    //inst1.print();

    cout << "XXX: " << inst1.name << endl;

    QApplication application(argc,argv);

    ConfTreeModel* model = new ConfTreeModel(&inst1);

    SettingsManager smngr;
    smngr.render(model);
    smngr.show();

    return application.exec();
}


/*
 * Notations:
 *
 *  Bind(var1)
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

