#ifndef MANAGEDITEM_H
#define MANAGEDITEM_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include  <typeinfo>

class SettingsManager;
class QFormLayout;


class ManagedItemBase
{
public:
    std::string name;
    std::string classname;
    std::string tooltip;


    ManagedItemBase* parent();
    ManagedItemBase* child(int row);

    void setTooltip(std::string& f_tooltip);
    void setName(std::string& f_name);


    //Quite evil
    template<class ManagedItemBaseType>
    void bindVar(ManagedItemBaseType& child)
    {
        //cout << "Pretty: " << __PRETTY_FUNCTION__ << endl;
        //cout << "Typeid: " << typeid(*this).name() << endl;
        //cout << "Name:   " << child.name << endl;
        ManagedItemBase& baseRef = child;

        if(child.name != "")
        {
            baseRef.name = child.name;
        }
        else if(child.classname != "")
        {
            baseRef.name = child.classname;
        }
        bindVar(baseRef);
    }

    void bindVar(ManagedItemBase& child );

    int childCount() const;
    int row() const;

    virtual void print(std::string prefix="") const;

    virtual void render(SettingsManager* smngr,QFormLayout* cur_widget=nullptr);


private:
    vector<ManagedItemBase*> childItems;
    ManagedItemBase *parentItem;

};



template< typename VarType>
class ManagedItem: public ManagedItemBase
{

public:
    ManagedItem();
    ManagedItem(VarType f_itemData,std::string f_name);
    ManagedItem(ManagedItemBase* parent_this_p,VarType f_itemData,std::string f_name);


    //~ManagedItem(){cout << "Destructor: "<<this << endl;}

    void init(ManagedItemBase* parent, VarType f_itemData,std::string f_tooltip);

    void setData(VarType &f_itemData);
    VarType& getData();

    void print(std::string prefix="") const;

    void render(SettingsManager* smngr,QFormLayout* cur_widget);


protected:
    VarType itemData;

};



template< typename VarType>
class ManagedNumericItem: public ManagedItem<VarType>
{
    VarType lowerBound;
    VarType upperBound;

    VarType optLowerBound;
    VarType optUpperBound;

public:
    ManagedNumericItem(): ManagedItem<VarType>{} {}

    ManagedNumericItem(VarType f_var,std::string f_name):
        ManagedItem<VarType>{f_var,f_name} {}

    void setBounds(VarType lower, VarType upper);
    void setOptBounds(VarType lower, VarType upper);

    void getBounds(VarType& lower, VarType& upper) const;
    void getOptBounds(VarType& lower, VarType& upper) const;

};

template class ManagedItem<bool>;
template class ManagedItem<int>;


#include "manageditem_impl.h"

#endif // MANAGEDITEM_H



