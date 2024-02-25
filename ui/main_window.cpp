#include "main_window.hpp"


#include "stash.hpp"
#include "style.hpp"
#include "tile_editor.hpp"

#include <QApplication>
#include <QDockWidget>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPoint>
#include <QTabBar>
#include <QTabWidget>


GesusMainWindow::
GesusMainWindow(int     argc,
				char *  argv[])
	: gesusTileEditor(this),
	  gesusTileStash(this)
{	
	setup_editor_tabs();
	
	setup_file_actions();
	setup_menus();

	setup_shortcuts();
	
	setup_main_window();
}


void GesusMainWindow::
setup_main_window()
{
	QMenuBar *    gesusMenuBar       = new QMenuBar();
	QDockWidget * gesusTileStashDock = new QDockWidget(TILE_STASH_DOCK_NAME);

	gesusMenuBar->addMenu(&gesusFileMenu);
	
	gesusTileStashDock->setPalette  (GesusStyle::palette);
	gesusTileStashDock->setWidget   (&gesusTileStash);
	
	this->addDockWidget(Qt::BottomDockWidgetArea,
						gesusTileStashDock,
						Qt::Horizontal);
	
	this->setCentralWidget  (gesusEditorTabs    );
	this->setMenuBar        (gesusMenuBar       );
	this->setPalette        (GesusStyle::palette);
}


void GesusMainWindow::
setup_editor_tabs()
{
	gesusEditorTabs = new QTabWidget;
	
	gesusEditorTabs->setMovable       (true                  );
	gesusEditorTabs->setTabPosition   (QTabWidget::North     );
	gesusEditorTabs->setTabsClosable  (true                  );
	gesusEditorTabs->setTabShape      (QTabWidget::Triangular);

	// WIP: add icons
	gesusEditorTabs->addTab(&gesusPlaneEditor,  PLANE_EDITOR_TAB_NAME);
	gesusEditorTabs->addTab(&gesusSpriteEditor, SPRITE_EDITOR_TAB_NAME);
	gesusEditorTabs->addTab(&gesusTileEditor,   TILE_EDITOR_TAB_NAME);
}


void GesusMainWindow::
setup_file_actions()
{
	connect(&exitApplication, &QAction::triggered,  qApp,       &QApplication::quit);
	connect(&showAbout,       &QAction::triggered, &gesusAbout, &QWidget::show     );
}


void GesusMainWindow::
setup_menus()
{	
	gesusFileMenu.setTitle    (FILE_MENU_TITLE);
	gesusFileMenu.setPalette  (GesusStyle::palette);
	
	gesusFileMenu.addAction(&showAbout);
	gesusFileMenu.addAction(&exitApplication);

	// connect();
}


void GesusMainWindow::
setup_shortcuts()
{
	
}


// void GesusMainWindow::
// slot_about_opened()
// {
// 	gesusAbout;
// }


void GesusMainWindow::
slot_menu_opened(      QMenu *   menu,
				 const QPoint &  point)
{
	menu->popup(point);
}
