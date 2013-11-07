#include "test.h"
#include <typeinfo>

#include <QApplication>

#include "settingswindow.h"

#include "conftreemodel.h"

Test1_2::Test1_2()
{
    bindName(name);
    bindVar(m_subclass);
}

//Constructor
Test1::Test1()
    //:m_subclass(Test2{})
{
    //cout << "Test1: " << typeid(*this).name() << endl;


    //--------------------------------------------------------------------------

    //cout << "New m_subclass2" <<endl;
    //m_subclass2 = Test3{};

    //Should work, assignment operator creates a new instancce of ConfItemBase.


    //--------------------------------------------------------------------------


    //Test3* m_subclass3 = new Test3{};
    //bindVar(m_subclass3);

    //Works, because a new class is created that is not destroyed when the
    //default constructor goes out of scope.


    //--------------------------------------------------------------------------


    //Test3 m_subclass3 = Test3{};
    //bindVar(m_subclass3);

    //Should not work: m_subclass3 goes out of scope after constructor ends


    //--------------------------------------------------------------------------


    bindName(name);

    cout << "Binding" << endl;
    bindVar(m_subclass);
    bindVar(m_subclass2);
}


int main(int argc, char** argv)
{

    //Create an instance of ConfItemBase
    Test1 inst1{};

    //Do a test print showing item tree
    //inst1.print();

    //Create a Qt Application
    QApplication application(argc,argv);

    //Create the SettingManager Widget and connect it to the model
    SettingsManager smngr;
    smngr.render(&inst1);
    smngr.show();

    return application.exec();

}

void register_python()
{
	namespace bp = boost::python;
	bp::class_<Test1, bp::bases<ConfItemBase> > cls_Test1("Test1");

	cls_Test1.add_property("var1", get_c_var(&Test1::var1));

	{
		bp::scope outer = cls_Test1;

		bp::class_<Test1_2, bp::bases<ConfItemBase> > cls_Test1_2("Test1_2");

		{
			bp::scope outer = cls_Test1_2;

			// class_ ..
		}
	}
}

BOOST_PYTHON_MODULE(libparamEditorDemo)
{
	register_python();
}

