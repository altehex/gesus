#include "ui/main_window.hpp"
#include "ui/style.hpp"

#include <QApplication>


int
main(int argc, char * argv[])
{
	QApplication::setStyle(new GesusStyle);
	
	QApplication gesusApp(argc, argv);
	GesusMainWindow gesusWindow(argc, argv);	

	gesusWindow.show();

	return gesusApp.exec();
}
