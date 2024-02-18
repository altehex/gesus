#include <main_window.hpp>

#include <QApplication>


int
main(int argc, char * argv[])
{
	QApplication gesusApp(argc, argv);
	GesusMainWindow gesusWindow;
	
	gesusWindow.show();

	return gesusApp.exec();
}
