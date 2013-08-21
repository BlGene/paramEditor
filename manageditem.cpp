#include "manageditem.h"

#include <algorithm>
#include <vector>

#include <QFrame>
#include <QGroupBox>
#include <QSpinBox>

//------------------------------------------------------------------------------
// ManagedItemBase
//


void ManagedItemBase::bindVar(ManagedItemBase& child)
{
    childItems.push_back(&child);
    child.parentItem = this;
    //cout << "child: " << &child  << "->" << this << endl;
}


//This is necessary because the bindVar macro handels assigning the choosen
//name ot the ManagedItemBase baseclass
void ManagedItemBase::bindName(std::string f_name)
{
    name = f_name;
}


void ManagedItemBase::print(std::string prefix) const
{
    if(prefix == "")
    {
        std::string int_prefix = prefix + "|"; //intermediate
        std::string end_prefix = prefix + " "; //intermediate

        if(childItems.size()>0)
        {
            cout << prefix << "ManagedItemBase:" << endl;
            int i;
            for(i=0;i<childItems.size()-1;i++)
            {
                childItems.at(i)->print(int_prefix);
            }
            childItems.at(i)->print(end_prefix);
        }

    }
    else
    {
        cout <<prefix<<"-- " << "ManagedItemBase:" << endl;

        std::string int_prefix = prefix + "   |"; //intermediate
        std::string end_prefix = prefix + "   `"; //intermediate

        if(childItems.size()>0)
        {
            int i;
            for(i=0;i<childItems.size()-1;i++)
            {
                childItems.at(i)->print(int_prefix);
            }
            childItems.at(i)->print(end_prefix);
        }
    }

}

void ManagedItemBase::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    QFormLayout* layout = new QFormLayout();

    if(childItems.size()>0)
    {
        cout << childItems.size() << endl;

        for(int i=0;i<childItems.size();i++)
        {
            childItems.at(i)->render(smngr,layout);
        }

    }

    QGroupBox* box = new QGroupBox(QString(name.c_str()),smngr);
    box->setLayout(layout);

    if(cur_widget == nullptr)
    {
        smngr->ui->ConfLayout->addWidget(box);
    }
    else
    {
        cur_widget->addWidget(box);
    }

}

ManagedItemBase* ManagedItemBase::parent()
{
    return parentItem;
}

void ManagedItemBase::setTooltip(std::string& f_tooltip)
{
    tooltip = f_tooltip;
}

void ManagedItemBase::setName(std::string& f_name)
{
    name = f_name;
}


int ManagedItemBase::row() const
{
    if(parentItem == nullptr)
    {
        return 0;
    }
    else
    {
        cout << "search actuall called" << endl;
        //cout << "Looking for " << this <<" " <<parentItem->childItems.size() <<endl;
        for(int i=0;i<parentItem->childItems.size();i++)
        {
            cout << parentItem->childItems[i] << endl;
        }

        std::vector<ManagedItemBase*>::const_iterator iter = std::find(
                    parentItem->childItems.cbegin(),
                    parentItem->childItems.cend(),
                    const_cast<const ManagedItemBase*>(this));

        size_t index = std::distance(parentItem->childItems.cbegin(), iter);
        if(index == parentItem->childItems.size())
        {
            cout << "XXX1 Error " <<index << endl;
            return 0;
        }

        return index;
    }

    cout << "XXX2 Error" << endl;
    return 0;
}


// Stuff so that we can be a QAbstractItemModel
//--------------------------------------------------------------------------


QModelIndex ConfTreeModel::index(int row, int column,
                  const QModelIndex &parent ) const
{
    // Returns the index of the item in the model specified by the given row,
    // column and parent index.


    /*
    if ( row >= childItems.size() and column != 0)
    {
        return QModelIndex();
    }
    */
    if (hasIndex(row,column,parent))
        return QModelIndex();


    const ManagedItemBase* parentItem_;

    if(!parent.isValid())
    {
        parentItem_ = rootItem;
    }
    else
        parentItem_ = static_cast<const ManagedItemBase*>(parent.internalPointer());

    ManagedItemBase* childItem_ = parentItem_->childItems.at(row);
    if(childItem_)
        return createIndex(row,column,childItem_);
    else
        return QModelIndex();
}

QModelIndex ConfTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    ManagedItemBase *childItem = static_cast<ManagedItemBase*>(index.internalPointer());
    ManagedItemBase *parentItem_ = childItem->parent();

    if(!parentItem_)
        return QModelIndex();
    else
        return createIndex(parentItem_->row(), 0, parentItem_);
}


int ConfTreeModel::rowCount(const QModelIndex &parent ) const
{
    const ManagedItemBase* parentItem_;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
    {
        parentItem_ = rootItem;
    }
    else
        parentItem_ = static_cast<ManagedItemBase*>(parent.internalPointer());

    return parentItem_->childItems.size();
}

int ConfTreeModel::columnCount(const QModelIndex &parent ) const
{
    return 1;
}


QVariant ConfTreeModel::data(const QModelIndex &index, int role) const
{

    if (!index.isValid())
    {
        return QVariant();
    }

    if (role != Qt::DisplayRole)
        return QVariant();

    const ManagedItemBase* Item_;
    Item_ = static_cast<ManagedItemBase*>(index.internalPointer());

    return Item_->data(index.column());
}

int ConfTreeModel::childCount() const
{
    return 1;
}

int ConfTreeModel::columnCount() const
 {
     return 1;
}

QVariant ConfTreeModel::headerData(int section, Qt::Orientation orientation,
                    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)

        return QVariant( QString((rootItem->name + " -- Configuration Tree").c_str()));
    return QVariant();
}






// Template specialization for rendering
//--------------------------------------------------------------------------


template<>
void  ManagedItem<bool>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    QCheckBox* checkbox = new QCheckBox(smngr);
    checkbox->setLayoutDirection(Qt::RightToLeft);

    cur_widget->addRow(QString(name.c_str()),checkbox);

}

template<>
void  ManagedItem<int>::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    QSpinBox* spinbox = new QSpinBox(smngr);

    spinbox->setValue(this->itemData);

    cur_widget->addRow(QString(name.c_str()),spinbox);

}

