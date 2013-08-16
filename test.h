#ifndef TEST_H
#define TEST_H

#include "manageditem.h"


inline std::string className(const std::string& prettyFunction)
{
    size_t colons = prettyFunction.find("::");
    if (colons == std::string::npos)
        return "::";
    size_t begin = prettyFunction.substr(0,colons).rfind(" ") + 1;
    size_t end = colons - begin;

    return prettyFunction.substr(begin,end);
}

#define __CLASS_NAME__ className(__PRETTY_FUNCTION__)

#define C_OBJECT friend class ManagedItemBase; std::string classname{__CLASS_NAME__};


template<typename ValType>
struct MIType
{
    typedef ManagedItem<ValType> Type;
};

template <>
struct MIType<int>
{
    typedef ManagedNumericItem<int> Type;
};


#define CVAR(VARTYPE,VARNAME,VARVAL,DESCR) MIType<VARTYPE>::Type VARNAME{VARVAL,DESCR};


//Conf{


template <typename testType>
class Test2: public ManagedItemBase
{
    C_OBJECT // Sets the object name to the class name

    std::string name{"Function A"}; //overwrites the object name

public:
    testType var100;

    ManagedItem<bool>        var2_1{this, true, "refvar 1"};

    CVAR(int,var2_2,2   , "variable 2");

public:
    Test2();
};

class Test3: public ManagedItemBase
{
    friend class ManagedItemBase;
    std::string name{"Function B"};

    //ManagedItem<bool>        var2_1{true, "variable 1"};

    CVAR(bool,var2_1,true,"varaible 1");

    ManagedNumericItem<int>  var2_2{2   , "variable 2"};

public:
    Test3();
};



class Test1: public ManagedItemBase
{
public:
    ManagedItem<bool>        var1{false, "var 1"};
    ManagedNumericItem<int>  var2{1    , "var 2"};
    ManagedNumericItem<int>  var3{4   ,  "var 3"};

public:

    Test2<bool> m_subclass;
    Test3 m_subclass2;

public:
    Test1();
};


#endif // TEST_H