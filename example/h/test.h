#ifndef TEST_H
#define TEST_H

#include "confitem.h"


#include <iostream>
using namespace std;

template <typename testType>
class Test1_1: public ConfItemBase
{
    C_OBJECT // Sets the object name to the class name

    std::string name{"Function A"}; //overwrites the object name

    testType var100;

    C_VAR(bool, var2_1, true, "refvar 1"  )
    C_VAR(int,  var2_2,   2, "variable 2" )

};


class Test1_2_1: public ConfItemBase
{
public:
    ~Test1_2_1()
    {
        cout << "Destructor called" << endl;
    };
private:
    C_OBJECT

    std::string name{"Function C"};

    C_VAR(bool,var2_1,true,"XVar 1")
    C_VAR(int, var2_2,   2,"XVar 2")

};

class Test1_2: public ConfItemBase
{
public:
    ~Test1_2()
    {
        cout << "Destructor called" << endl;
    };
private:
    C_OBJECT

    std::string name{"Function B"};

    C_VAR(bool,var2_1,true,"XVar 1")
    C_VAR(int, var2_2,   2,"XVar 2")


    Test1_2_1 m_subclass;
public:
    Test1_2();
};




class Test1: public ConfItemBase
{
public:
    std::string name{"Test1"};


    //ConfItem<bool>        var1{false, "var 1"};
    //NumericConfItem<int>  var2{1    , "var 2"};
    //NumericConfItem<int>  var3{4   ,  "var 3"};

    C_VAR(bool, var1, true, "var 1")
    C_VAR(int,  var2,    1, "var 2")
    C_VAR(int,  var3,    4, "var 3")


public:

    Test1_1<bool> m_subclass;

    Test1_2 m_subclass2;

public:
    Test1();
};


#endif // TEST_H
