#include "manageditem.h"


#include <QFrame>
#include <QGroupBox>
#include <QSpinBox>

//------------------------------------------------------------------------------
// ManagedItemBase
//


void ManagedItemBase::bindVar(ManagedItemBase& child)
{
    childItems.push_back(&child);
}


/*
void ManagedItemBase::bindVar(ManagedItemBase& child,std::string childname)
{
    child.name = childname;
    childItems.push_back(&child);
}
*/

ManagedItemBase* ManagedItemBase::child(int row)
{
    return childItems.at(row);
}

int ManagedItemBase::childCount() const
{
    return childItems.size();
}

int ManagedItemBase::row() const
{
    //Not implemented
    return 0;
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

