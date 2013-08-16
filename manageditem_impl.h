#ifndef MANAGEDVAR_H
#define MANAGEDVAR_H

#include <typeinfo>


#include <QLayout>
#include <QString>
#include <QCheckBox>
#include <QLabel>




#include "settingswindow.h"



//------------------------------------------------------------------------------
// ManagedItem
//

template< typename VarType>
ManagedItem<VarType>::ManagedItem()
{
    ///cout << "Default constructor: " << typeid(itemData).name() << " "<<this<< endl;

    //Call default constructor
    itemData = VarType{};
    name = "DefaultName";
}


template< typename VarType>
ManagedItem<VarType>::ManagedItem(VarType f_itemData,std::string f_name)
{

    //cout << "Special Constructor: " << f_name <<" " <<this << endl;

    itemData = f_itemData;
    name = f_name;
}

template< typename VarType>
ManagedItem<VarType>::ManagedItem(ManagedItemBase* parent_this_p, VarType f_itemData,std::string f_name)
{

    //cout << "Special Constructor: " << f_name <<" " <<this << endl;
    itemData = f_itemData;
    name = f_name;

    parent_this_p->bindVar(*this);
}



template< typename VarType>
void ManagedItem<VarType>::setValue(VarType &f_itemData)
{
    itemData = f_itemData;
}


template< typename VarType>
VarType& ManagedItem<VarType>::getData()
{
    return  itemData;
}


template< typename VarType>
void ManagedItem<VarType>::print(std::string prefix) const
{
    std::cout <<prefix << "-- '" << name <<"' " << itemData << " "
              << "("<< typeid(itemData).name() <<")"<< endl;
}



template< typename VarType>
void  ManagedItem<VarType>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    QLabel* label = new QLabel(QString(name.c_str()),smngr);

    cur_widget->addRow(label);
}





//------------------------------------------------------------------------------
// Numeric Item
//

template< typename VarType>
void ManagedNumericItem<VarType>::setBounds(VarType lower, VarType upper)
{
    lowerBound = lower;
    upperBound = upper;
}


template< typename VarType>
void ManagedNumericItem<VarType>::setOptBounds(VarType lower, VarType upper)
{
    optLowerBound = lower;
    optUpperBound = upper;
}


template< typename VarType>
void ManagedNumericItem<VarType>::getBounds(VarType& lower, VarType& upper) const
{
    lower = lowerBound;
    upper = upperBound;
}


template< typename VarType>
void ManagedNumericItem<VarType>::getOptBounds(VarType& lower, VarType& upper) const
{
    lower = optLowerBound;
    upper = optUpperBound;
}



#endif // MANAGEDVAR_H
