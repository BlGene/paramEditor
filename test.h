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

//#define C_OBJECT friend class ManagedItemBase; std::string classname{__CLASS_NAME__};

#define C_OBJECT friend class ManagedItemBase;

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


//      C_VAR( bool tmpvar = false,
#define C_VAR(VARTYPE,VARNAME,VARVAL,DESCR) MIType<VARTYPE>::Type VARNAME{this, VARVAL,DESCR};



template <typename testType>
class Test2: public ManagedItemBase
{
    C_OBJECT // Sets the object name to the class name

    std::string name{"Function A"}; //overwrites the object name

    testType var100;

    C_VAR(bool, var2_1, true, "refvar 1"  )
    C_VAR(int,  var2_2,   2, "variable 2" )

};

class Test3: public ManagedItemBase
{
    C_OBJECT

    std::string name{"Function B"};

    C_VAR(bool,var2_1,true,"variable 1")
    C_VAR(int, var2_2,   2,"variable 2")

};



class Test1: public ManagedItemBase
{
public:
    std::string name{"Test1"};


    //ManagedItem<bool>        var1{false, "var 1"};
    //ManagedNumericItem<int>  var2{1    , "var 2"};
    //ManagedNumericItem<int>  var3{4   ,  "var 3"};

    C_VAR(bool, var1, true, "var 1")
    C_VAR(int,  var2,    1, "var 2")
    C_VAR(int,  var3,    4, "var 3")


public:

    Test2<bool> m_subclass;

    Test3 m_subclass2;

public:
    Test1();
};


#endif // TEST_H
