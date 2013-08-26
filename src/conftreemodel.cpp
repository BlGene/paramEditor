#include "conftreemodel.h"
#include "confitem.h"


#include <QFormLayout>
#include <QVariant>



void ConfTreeModel::render(SettingsManager* ptr)
{
    if(rootItem)
    {
        rootItem->render(ptr);
    }
}

// Stuff so that we can be a QAbstractItemModel
//--------------------------------------------------------------------------


QModelIndex ConfTreeModel::index(int row, int column,
                  const QModelIndex &parent ) const
{
    // Returns the index of the item in the model specified by the given row,
    // column and parent index.


    //if ( row >= childItems.size() and column != 0)
    //    return QModelIndex();


    //This does not seem to work

    //if (hasIndex(row,column,parent))
    //    return QModelIndex();


    const ConfItemBase* parentItem_;

    if(!parent.isValid())
    {
        parentItem_ = rootItem;
    }
    else
        parentItem_ = static_cast<const ConfItemBase*>(parent.internalPointer());

    ConfItemBase* childItem_ = parentItem_->getChild(row);

    if(childItem_)
        return createIndex(row,column,childItem_);
    else
        return QModelIndex();
}

QModelIndex ConfTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    ConfItemBase *childItem = static_cast<ConfItemBase*>(index.internalPointer());
    ConfItemBase *parentItem_ = childItem->parent();

    if(!parentItem_)
        return QModelIndex();
    else
        return createIndex(parentItem_->row(), 0, parentItem_);
}


int ConfTreeModel::rowCount(const QModelIndex &parent ) const
{
    const ConfItemBase* parentItem_;

    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
    {
        parentItem_ = rootItem;
    }
    else
        parentItem_ = static_cast<ConfItemBase*>(parent.internalPointer());

    return parentItem_->size();
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

    const ConfItemBase* Item_;

    Item_ = static_cast<ConfItemBase*>(index.internalPointer());

    return Item_->data(index.column());
}


QVariant ConfTreeModel::headerData(int section, Qt::Orientation orientation,
                    int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return QVariant( QString((rootItem->name + " -- Configuration Tree").c_str()));

    return QVariant();
}



