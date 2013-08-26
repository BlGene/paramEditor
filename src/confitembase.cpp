#include "confitembase.h"

#include <algorithm>
#include <vector>

#include <QFrame>
#include <QGroupBox>
#include <QSpinBox>
#include <QGroupBox>
#include <QString>

#include "settingswindow.h"

#include "ui_settingswindow.h"


//------------------------------------------------------------------------------
// ConfItemBase
//

void ConfItemBase::bindVar(ConfItemBase& child)
{
    childItems.push_back(&child);
    child.parentItem = this;
    //cout << "child: " << &child  << "->" << this << " "<<child.name << endl;
}


//This is necessary because the bindVar macro handels assigning the choosen
//name ot the ConfItemBase baseclass
void ConfItemBase::bindName(std::string f_name)
{
    name = f_name;
}


void ConfItemBase::print(std::string prefix) const
{
    if(prefix == "")
    {
        std::string int_prefix = prefix + "|"; //intermediate
        std::string end_prefix = prefix + " "; //intermediate

        if(childItems.size()>0)
        {
            cout << prefix << "ConfItemBase:" << endl;
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
        cout <<prefix<<"-- " << "ConfItemBase:" << endl;

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

void ConfItemBase::render(SettingsManager* smngr,QFormLayout* cur_widget)
{
    //cout << "Base Render Called " << endl;

    QFormLayout* layout = new QFormLayout();

    if(childItems.size()>0)
    {
        //cout << childItems.size() << endl;

        for(int i=0;i<childItems.size();i++)
        {
            //cout << "render addr: " << &(childItems.at(i)) << " "<< childItems.at(i)->name << endl;
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

ConfItemBase* ConfItemBase::parent()
{
    return parentItem;
}

void ConfItemBase::setTooltip(std::string& f_tooltip)
{
    tooltip = f_tooltip;
}

void ConfItemBase::setName(std::string& f_name)
{
    name = f_name;
}


int ConfItemBase::row() const
{
    if(parentItem == nullptr)
    {
        return 0;
    }
    else
    {
        //cout << "search actuall called" << endl;
        //cout << "Looking for " << this <<" " <<parentItem->childItems.size() <<endl;
        //for(int i=0;i<parentItem->childItems.size();i++)
        //{
        //    cout << parentItem->childItems[i] << endl;
        //}

        std::vector<ConfItemBase*>::const_iterator iter = std::find(
                    parentItem->childItems.cbegin(),
                    parentItem->childItems.cend(),
                    const_cast<const ConfItemBase*>(this));

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

QVariant ConfItemBase::data(int column) const
{
    if (column != 0)
        return QVariant();
    return QVariant(QString(name.c_str()));
}


