#ifndef CONFTREEMODEL_H
#define CONFTREEMODEL_H


#include <QAbstractItemModel>

class ConfItemBase;
class QFormLayout;
class SettingsManager;


/*******************************************************************************
 *
 * ConfTreeModel
 *
 *
 ******************************************************************************/

class ConfTreeModel
        :public QAbstractItemModel
{

public:
    friend ConfItemBase;
    // Stuff so that we can be a QAbstractItemModel
    //--------------------------------------------------------------------------
    // When subclassing QAbstractItemModel, at the very least you must implement
    // index(), parent(), rowCount(), columnCount(), and data(). These functions
    // are used in all read-only models, and form the basis of editable models.

    ConfTreeModel(ConfItemBase* f_rootItem)
    {
        rootItem = f_rootItem;
    }

    void render(SettingsManager* ptr);

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;


private:
    ConfItemBase* rootItem;
};


#endif // CONFTREEMODEL_H
