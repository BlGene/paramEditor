# set project's name
PROJECT( paramEditorDemo )

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")

# enable warnings
ADD_DEFINITIONS( -Wall -fPIC )
SET(CMAKE_CXX_FLAGS "-O0 -ggdb -std=c++11")


set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/..)
message("Looking for modules in: " ${CMAKE_MODULE_PATH})

include(FindParamEditor)
if(NOT EXISTS ${PARAMEDITOR_INCLUDE_DIR}) # and ${PARAMEDITOR_LIBRARIES})
    message( FATAL_ERROR "Failed to find ParamEditor")
endif()

set( PARAMEDITOR_USE_PYTHON true)
set( PARAMEDITORDEMO_USE_PYTHON true)

if(PARAMEDITORDEMO_USE_PYTHON)

    find_package(Boost COMPONENTS filesystem system date_time python REQUIRED)
    message("Include dirs of boost: " ${Boost_INCLUDE_DIRS} )
    message("Libs of boost: " ${Boost_LIBRARIES} )

    #Manual setting of python as the python version needs to match the boost
    #python bindings version. And gentoo FindPythonLibs.cmake cannot find
    #lower version numbers.

    #find_package(PythonLibs 2.7 REQUIRED )
    set( PYTHON_INCLUDE_DIRS /usr/include/python2.7)
    set( PYTHON_LIBRARIES  /usr/lib/libpython2.7.so)

    message("Include dirs of Python: " ${PYTHON_INCLUDE_DIRS} )
    message("Libs of Python: " ${PYTHON_LIBRARIES} )

    add_definitions(-DPARAMEDITOR_USE_PYTHON)
    add_definitions(-DPARAMEDITORDEMO_USE_PYTHON)

endif()



# this command finds Qt4 libraries and sets all required variables
# note that it's Qt4, not QT4 or qt4
FIND_PACKAGE( Qt4 REQUIRED )

# with SET() command you can change variables or define new ones
# here we define SAMPLE_SRCS variable that contains a list of all .cpp files
# note that we don't need \ at the end of line
SET( SAMPLE_SRCS ./src/test.cpp  )

# another list, this time it includes all header files that should be treated with moc
#SET( SAMPLE_MOC_HDRS  ./h/settingswindow.h)
#./h/confitem.h ./h/conftreemodel.h

# some .ui files
#SET( SAMPLE_UIS ./ui/settingswindow.ui )
#   ./src/ui/Dialog1.ui
#   ./src/ui/Dialog2.ui
#)

# and finally an resource file
#SET( SAMPLE_RCS
#   ./src/rc/sample.qrc
#)

# add some useful macros and variables
# (QT_USE_FILE is a variable defined by FIND_PACKAGE( Qt4 ) that contains a path to CMake script)
INCLUDE( ${QT_USE_FILE} )

# this command will generate rules that will run rcc on all files from SAMPLE_RCS
# in result SAMPLE_RC_SRCS variable will contain paths to files produced by rcc
QT4_ADD_RESOURCES( SAMPLE_RC_SRCS ${SAMPLE_RCS} )

# this will run uic on .ui files:
QT4_WRAP_UI( SAMPLE_UI_HDRS ${SAMPLE_UIS} )

# and finally this will run moc:
QT4_WRAP_CPP( SAMPLE_MOC_SRCS ${SAMPLE_MOC_HDRS} )

# we need this to be able to include headers produced by uic in our code
# (CMAKE_BINARY_DIR holds a path to the build directory, while INCLUDE_DIRECTORIES() works just like INCLUDEPATH from qmake)

INCLUDE_DIRECTORIES( ${CMAKE_BINARY_DIR} 
	./h 
	${PARAMEDITOR_INCLUDE_DIR} 
	${Boost_INCLUDE_DIRS}
	${PYTHON_INCLUDE_DIRS}
	)

# here we instruct CMake to build "sample" executable from all of the source files
#ADD_EXECUTABLE( paramEditorDemo ${SAMPLE_SRCS} ${SAMPLE_MOC_SRCS} ${SAMPLE_RC_SRCS} ${SAMPLE_UI_HDRS} )
ADD_LIBRARY( paramEditorDemo SHARED ${SAMPLE_SRCS} ${SAMPLE_MOC_SRCS} ${SAMPLE_RC_SRCS} ${SAMPLE_UI_HDRS} )



# last thing we have to do is to tell CMake what libraries our executable needs,
# luckily FIND_PACKAGE prepared QT_LIBRARIES variable for us:
#TARGET_LINK_LIBRARIES( paramEditorDemo 
#    ${QT_LIBRARIES}
#    ${PARAMEDITOR_LIBRARIES}
#    ${Boost_LIBRARIES}
#    ${PYTHON_LIBRARIES})


TARGET_LINK_LIBRARIES( paramEditorDemo
    ${QT_LIBRARIES}
    ${PARAMEDITOR_LIBRARIES}
    ${Boost_LIBRARIES}
    ${PYTHON_LIBRARIES})





INSTALL( TARGETS paramEditorDemo DESTINATION bin )


