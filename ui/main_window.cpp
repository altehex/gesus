#include "main_window.hpp"


#include "about.hpp"
#include "stash.hpp"
#include "style.hpp"
#include "tile_editor.hpp"

#include <QApplication>
#include <QDir>
#include <QDockWidget>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPoint>
#include <QScrollArea>
#include <QTabBar>
#include <QTabWidget>
#include <QWidget>


GesusMainWindow::
GesusMainWindow([[maybe_unused]] int     argc,
				[[maybe_unused]] char *  argv[])
	: gesusTileEditor(this),
	  gesusTileStash(this)
{
	create_missing_dirs();
	
	setup_editor_tabs();
	
	setup_file_actions();
	setup_menus();

	setup_shortcuts();
	
	setup_main_window();
}


void GesusMainWindow::
setup_main_window()
{
	QMenuBar *       gesusMenuBar             = new QMenuBar;
	QScrollArea *    gesusTileStashScrollArea = new QScrollArea;

	gesusMenuBar->addMenu(&gesusFileMenu);

	gesusTileStashScrollArea->setWidget(&gesusTileStash);

	gesusTileStashDock.setPalette  (GesusStyle::palette);
	gesusTileStashDock.setWidget   (gesusTileStashScrollArea);
	
	addDockWidget(Qt::BottomDockWidgetArea,
				  &gesusTileStashDock,
				  Qt::Horizontal);
	
	setCentralWidget  (&gesusEditorTabs    );
	setMenuBar        (gesusMenuBar       );
	setPalette        (GesusStyle::palette);
}


void GesusMainWindow::
create_missing_dirs()
{
	QDir tileDir = gesusTileStash.get_tile_dir();

	tileDir.mkpath(TILE_STASH_DEFAULT_DIR);
}


void GesusMainWindow::
setup_editor_tabs()
{
	QTabBar * gesusTabBar;
	
	gesusEditorTabs.setMovable      (true                  );
	gesusEditorTabs.setTabPosition  (QTabWidget::North     );
	gesusEditorTabs.setTabShape     (QTabWidget::Triangular);

	gesusTabBar = gesusEditorTabs.tabBar();
	gesusTabBar->setTabsClosable(true);
	
	// WIP: add icons
	gesusEditorTabs.addTab(&gesusPlaneEditor,  PLANE_EDITOR_TAB_NAME);
	gesusEditorTabs.addTab(&gesusSpriteEditor, SPRITE_EDITOR_TAB_NAME);
	gesusEditorTabs.addTab(&gesusTileEditor,   TILE_EDITOR_TAB_NAME);
}


void GesusMainWindow::
setup_file_actions()
{
	connect( &actExitApplication, &QAction::triggered, qApp,        &QApplication::quit );
	connect( &actShowAbout,       &QAction::triggered, &gesusAbout, &GesusAbout::show   );
}


void GesusMainWindow::
setup_menus()
{	
	gesusFileMenu.setTitle    (FILE_MENU_TITLE);
	gesusFileMenu.setPalette  (GesusStyle::palette);
	
	gesusFileMenu.addAction(&actShowAbout);
	gesusFileMenu.addAction(&actExitApplication);
}


void GesusMainWindow::
setup_shortcuts()
{
	connect( &scCloseTab,        &QShortcut::activated, this, [this]() { this->slot_close_selected_tab(this->gesusEditorTabs.currentIndex()); } );
	connect( &scExitApplication, &QShortcut::activated, qApp, &QApplication::quit                                                               );
	connect( &scFullscreen,      &QShortcut::activated, this, &GesusMainWindow::slot_toggle_fullscreen                                          );
	connect( &scRightTab,        &QShortcut::activated, this, [this]() { this->slot_select_adjacent_tab(this->scRightTab.key()); }              );
	connect( &scLeftTab,         &QShortcut::activated, this, [this]() { this->slot_select_adjacent_tab(this->scLeftTab.key()); }               );
	connect( &scShowStash,       &QShortcut::activated, this, &GesusMainWindow::slot_show_stash                                                 ); 

	// connect( &scFileMenu,        &QShortcut::activated, &gesusFileMenu, [this]() { this->gesusFileMenu.popup(); }                                                );
}




