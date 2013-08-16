#ifndef MANAGEDITEM_H
#define MANAGEDITEM_H

#include <vector>
#include <iostream>
#include <string>
using namespace std;

#include  <typeinfo>

#include <QAbstractItemModel>

class SettingsManager;
class QFormLayout;


class ManagedItemBase
        :public QAbstractItemModel
{
public:
    std::string name;
    std::string classname;
    std::string tooltip;


    ManagedItemBase* parent();

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

    void bindName(std::string f_name);

    virtual void print(std::string prefix="") const;

    virtual void render(SettingsManager* smngr,QFormLayout* cur_widget=nullptr);


    // Stuff so that we can be a QAbstractItemModel
    //--------------------------------------------------------------------------
    // When subclassing QAbstractItemModel, at the very least you must implement
    // index(), parent(), rowCount(), columnCount(), and data(). These functions
    // are used in all read-only models, and form the basis of editable models.

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant data(int column) const;

    int childCount() const;

    int columnCount() const;

    bool hasChildren() const {return true;}


    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    int row() const;



private:
    vector<ManagedItemBase*> childItems;
    ManagedItemBase *parentItem = nullptr;

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

    void setValue(VarType &f_itemData);
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
    ManagedNumericItem(): ManagedItem<VarType>() {}

    ManagedNumericItem(VarType f_var,std::string f_name):
        ManagedItem<VarType>(f_var,f_name) {}

    ManagedNumericItem(ManagedItemBase* parent_this_p,VarType f_itemData,std::string f_name):
        ManagedItem<VarType>(parent_this_p,f_itemData,f_name) {}

    void setBounds(VarType lower, VarType upper);
    void setOptBounds(VarType lower, VarType upper);

    void getBounds(VarType& lower, VarType& upper) const;
    void getOptBounds(VarType& lower, VarType& upper) const;

};

template class ManagedItem<bool>;
template class ManagedItem<int>;


#include "manageditem_impl.h"

#endif // MANAGEDITEM_H



