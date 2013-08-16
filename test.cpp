#include "test.h"
#include <typeinfo>

#include <QApplication>
#include "settingswindow.h"




//Constructor
template<>
Test2<bool>::Test2()
{
    //bindVar(var2_1);
    bindVar(var2_2);
    //var2_2.setBounds(0,100);

}

Test3::Test3()
{
    bindVar(var2_1);
    bindVar(var2_2);
    //var2_2.setBounds(0,100);
}


//Constructor
Test1::Test1()
    //:m_subclass(Test2{})
{
    //cout << "Test1: " << typeid(*this).name() << endl;

    bindVar(var1);
    bindVar(var2);

    //Causes segfault because of copy operator
    //cout << "Start" <<endl;
    //m_subclass = Test2{};
    //cout << "Stop" <<endl;
    //cout << "New instance address: " << &m_subclass << endl;

    bindVar(m_subclass);

    bindVar(var3);

    bindVar(m_subclass2);

}


int main(int argc, char** argv)
{
    Test1 inst1{};

    cout <<  "Print: " << endl;
    inst1.print();

    QApplication application(argc,argv);
    SettingsManager smngr;

    smngr.render(inst1);
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

