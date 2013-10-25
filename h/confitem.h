#ifndef CONFITEM_H
#define CONFITEM_H

#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>

#include <QVariant>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

#include "confitembase.h"

using namespace std;


class SettingsManager;
class QFormLayout;


template< typename Var>
struct QtElement
{
    typedef QLabel Type;
};

template<>
struct QtElement<bool>
{
    typedef QCheckBox Type;
};

template<>
struct QtElement<int>
{
    typedef QSpinBox Type;
};

template< typename VarType>
class ConfItem: public ConfItemBase
{
    //friend typename QtElement<VarType>::Type;

public:
    ConfItem();
    ConfItem(VarType f_itemData,std::string f_name);
    ConfItem(ConfItemBase* parent_this_p,VarType f_itemData,std::string f_name);

    //~ConfItem(){cout << "Destructor: "<<this << endl;}

    void setValue(VarType &f_itemData);

    VarType& getData();

    void print(std::string prefix="") const;

    void render(SettingsManager* smngr,QFormLayout* cur_widget);


    VarType getValue() const;

protected:
    VarType itemData;

    typename QtElement<VarType>::Type* element;


};



template< typename VarType>
class NumericConfItem: public ConfItem<VarType>
{
    VarType lowerBound;
    VarType upperBound;

    VarType optLowerBound;
    VarType optUpperBound;

public:
    NumericConfItem(): ConfItem<VarType>() {}

    NumericConfItem(VarType f_var,std::string f_name):
        ConfItem<VarType>(f_var,f_name) {}

    NumericConfItem(ConfItemBase* parent_this_p,VarType f_itemData,std::string f_name):
        ConfItem<VarType>(parent_this_p,f_itemData,f_name) {}

    void setBounds(VarType lower, VarType upper);
    void setOptBounds(VarType lower, VarType upper);

    void getBounds(VarType& lower, VarType& upper) const;
    void getOptBounds(VarType& lower, VarType& upper) const;

};

#include "conf_util.h"



#endif // CONFITEM_H



