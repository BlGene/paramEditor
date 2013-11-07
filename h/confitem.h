#ifndef CONFITEM_H
#define CONFITEM_H


#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>

#include "confitembase.h"

class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class SettingsManager;

//This is the default option
template< typename Var>
struct QtElement
{
    typedef QLabel Type;
};

//These are the specializations
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
public:
    ConfItem();
    ConfItem(VarType f_itemData,std::string f_name);
    ConfItem(ConfItemBase* parent_this_p,VarType f_itemData,std::string f_name);

    //~ConfItem(){cout << "Destructor: "<<this << endl;}

	//For Qt
    void setValue(VarType &f_itemData);
    VarType getValue() const;

	//For python bindings/ everything else
    VarType& getData();
	void setData(const VarType &f_itemData);

	void print(std::string prefix="") const override;
    void render(SettingsManager* smngr,QFormLayout* cur_widget) override;
	
	boost::python::object getPyValue() const ;
	void setPyValue(boost::python::object& v) ;
    
    //The assign operator
    ConfItem<VarType> & operator= (const VarType& other)
    {
        if(itemData != other)
            itemData = other;

        //by convention always return *this
        return *this;
    }

    //Conversion operators
    operator VarType()
    {
        return itemData;
    }

    operator VarType() const
    {
        return itemData;
    }

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



