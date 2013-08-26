#ifndef CONF_UTIL_H



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

//#define C_OBJECT friend class ConfItemBase; std::string classname{__CLASS_NAME__};

#define C_OBJECT friend class ConfItemBase;

template<typename ValType>
struct MIType
{
    typedef ConfItem<ValType> Type;
};

template <>
struct MIType<int>
{
    typedef NumericConfItem<int> Type;
};


//      C_VAR( bool tmpvar = false,
#define C_VAR(VARTYPE,VARNAME,VARVAL,DESCR) MIType<VARTYPE>::Type VARNAME{this, VARVAL,DESCR};



#define CONF_UTIL_H

#endif // CONF_UTIL_H
