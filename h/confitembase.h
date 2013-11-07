#ifndef CONFITEMBASE_H
#define CONFITEMBASE_H

#include <vector>
#include <iostream>
#include <string>
#include <typeinfo>

class SettingsManager;
class QLabel;
class QSpinBox;
class QCheckBox;
class QFormLayout;
class QVariant;

//#include <boost/python/object_fwd.hpp>
#if PARAMEDITOR_USE_PYTHON
	#include <boost/python.hpp>
	#include <boost/bind.hpp>
	#include <boost/function.hpp>
	#undef BO // see http://stackoverflow.com/a/15078676/1037407

	namespace bp = boost::python;


#endif //PARAMEDITOR_USE_PYTHON



/*******************************************************************************
 *
 * The base class for configurable items, in order to provide a tree
 * datastructure this class can hold a value as well as a vector of child items
 *
 * The problem with this class is that is relys on raw pointers to child items
 * so it needs deep copying of these in order to prevent segfaults.
 *
 * In order to solve this problem the assigment and copy operators are replaced
 * with new calss instantiaiton. This means variable state will get lost.
 *
 *
 ******************************************************************************/

class ConfItemBase
{
public:

    std::string name;
    std::string classname;
    std::string tooltip;


    //Construction operator needed for copy and assignment operators
    ConfItemBase()
    {
    //    cout << "default constructor called" << endl;
    }

    ConfItemBase(const ConfItemBase& other)
    {
        if(this != &other)
        {
            ConfItemBase{};
        }
    }

	std::string getName() const
	{
		return name;
	}

    ConfItemBase& operator=( const ConfItemBase& other)
    {
        if(this != &other)
        {
            ConfItemBase{};
        }
        return *this;
    }

    //QT functio
    ConfItemBase* parent();

    void setTooltip(std::string& f_tooltip);
    void setName(std::string& f_name);


    //Quite evil
    template<class ConfItemBaseType>
    void bindVar(ConfItemBaseType& child)
    {
        //cout << "Pretty: " << __PRETTY_FUNCTION__ << endl;
        //cout << "Typeid: " << typeid(*this).name() << endl;
        //cout << "Name:   " << child.name << endl;

        ConfItemBase& baseRef = child;

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

    void bindVar(ConfItemBase& child );

    void bindName(std::string f_name);

    virtual void print(std::string prefix="") const;
    virtual void render(SettingsManager* smngr,QFormLayout* cur_widget=nullptr);

	virtual boost::python::object getPyValue() const;
	virtual void setPyValue(boost::python::object v);


    ConfItemBase* getChild(int row) const
    {
        return childItems.at(row);
    }

    ConfItemBase& getChild2(int row) const
    {
        return *childItems.at(row);
    }

    int size() const
    {
        return childItems.size();
    }


    //Qt compatibility functions
    //--------------------------------------------------------------------------
    int row() const;

    virtual QVariant data(int column) const;

	//should be private
    std::vector<ConfItemBase*> childItems;
    ConfItemBase *parentItem = nullptr;

private:

};

#endif // CONFITEMBASE_H



