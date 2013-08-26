#ifndef MANAGEDVAR_H
#define MANAGEDVAR_H

#include <typeinfo>


#include <QLayout>
#include <QString>
#include <QCheckBox>
#include <QLabel>
#include <QFormLayout>

#include "settingswindow.h"

#include "confitem.h"

//------------------------------------------------------------------------------
// ConfItem
//

template< typename VarType>
ConfItem<VarType>::ConfItem()
{
    ///cout << "Default constructor: " << typeid(itemData).name() << " "<<this<< endl;

    //Call default constructor
    itemData = VarType{};
    name = "DefaultName";
}


template< typename VarType>
ConfItem<VarType>::ConfItem(VarType f_itemData,std::string f_name)
{

    //cout << "Special Constructor: " << f_name <<" " <<this << endl;

    itemData = f_itemData;
    name = f_name;
}

template< typename VarType>
ConfItem<VarType>::ConfItem(ConfItemBase* parent_this_p, VarType f_itemData,std::string f_name)
{

    //cout << "Special Constructor: " << f_name <<" " <<this << endl;
    itemData = f_itemData;
    name = f_name;

    parent_this_p->bindVar(*this);
}

template< typename VarType>
void ConfItem<VarType>::setValue(VarType &f_itemData)
{
    itemData = f_itemData;
}


template< typename VarType>
VarType& ConfItem<VarType>::getData()
{
    return  itemData;
}


template< typename VarType>
void ConfItem<VarType>::print(std::string prefix) const
{
    std::cout <<prefix << "-- '" << name <<"' " << itemData << " "
              << "("<< typeid(itemData).name() <<")"<<  " "<< this << endl;
}



template< typename VarType>
void  ConfItem<VarType>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    cout << "YYY" << endl;
    QLabel* label = new QLabel(QString(name.c_str()),smngr);

    cur_widget->addRow(label);
}



// Template specialization for rendering
//--------------------------------------------------------------------------

template<>
void ConfItem<bool>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    element = new QCheckBox(smngr);
    element->setLayoutDirection(Qt::RightToLeft);

    cur_widget->addRow(QString(name.c_str()),element);

    //XXX wait for Qt 5 to make signals public
    //QObject::connect(element,&QCheckBox::stateChanged,this,&ConfItem<bool>::setValue);
}

template <>
bool ConfItem<bool>::getValue() const
{
    if(element->checkState() == Qt::Checked)
        return true;
    return false;
}


template<>
void  ConfItem<int>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    QSpinBox* spinbox = new QSpinBox(smngr);

    spinbox->setValue(this->itemData);

    cur_widget->addRow(QString(name.c_str()),spinbox);

}

template <>
int ConfItem<int>::getValue() const
{
    return element->value();
}


//------------------------------------------------------------------------------
// Numeric Item
//

template< typename VarType>
void NumericConfItem<VarType>::setBounds(VarType lower, VarType upper)
{
    lowerBound = lower;
    upperBound = upper;
}


template< typename VarType>
void NumericConfItem<VarType>::setOptBounds(VarType lower, VarType upper)
{
    optLowerBound = lower;
    optUpperBound = upper;
}


template< typename VarType>
void NumericConfItem<VarType>::getBounds(VarType& lower, VarType& upper) const
{
    lower = lowerBound;
    upper = upperBound;
}


template< typename VarType>
void NumericConfItem<VarType>::getOptBounds(VarType& lower, VarType& upper) const
{
    lower = optLowerBound;
    upper = optUpperBound;
}



//Template Specializations

template class ConfItem<bool>;
template class ConfItem<int>;
template class NumericConfItem<int>;



#endif // MANAGEDVAR_H
