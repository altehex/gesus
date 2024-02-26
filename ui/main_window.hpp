#pragma once


#include "tile_editor.hpp"
#include "palette_editor.hpp"
#include "plane_editor.hpp"
#include "sprite_editor.hpp"
#include "stash.hpp"

#include "settings.hpp"
#include "about.hpp"

#include <QAction>
#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>
#include <QMenu>
#include <QObject>
#include <QPoint>
#include <QShortcut>
#include <Qt>
#include <QTabWidget>


class GesusMainWindow : public QMainWindow
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	GesusMainWindow(int, char * []);

private slots: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void slot_close_selected_tab(int);
	void slot_select_adjacent_tab(const QKeySequence &);
	void slot_toggle_fullscreen(void);
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	QTabWidget *    gesusEditorTabs;
	
	SpriteEditor    gesusSpriteEditor;
	TileEditor      gesusTileEditor;
	TileStash       gesusTileStash;
	PaletteEditor   gesusPaletteEditor;
	PlaneEditor     gesusPlaneEditor;
	
	GesusSettings   gesusSettings;
	GesusAbout      gesusAbout;

	/*  Initialization functions
	 */
	void create_missing_dirs(void);
	void setup_editor_tabs(void);
	void setup_file_actions(void);
	void setup_main_window(void);
	void setup_menus(void);
	void setup_shortcuts(void);

	/*  Menus
	 */
#define FILE_MENU_TITLE  "File"
	QMenu gesusFileMenu;

	QAction actShowAbout       = QAction("About", this);
	QAction actExitApplication = QAction("Exit",  this);
	
	/*  Shortcuts
	 */
	QShortcut scCloseTab        = QShortcut(Qt::CTRL | Qt::Key_W,      this);
	QShortcut scExitApplication = QShortcut(Qt::CTRL | Qt::Key_Q,      this);
	QShortcut scFileMenu        = QShortcut(Qt::CTRL | Qt::Key_F,      this);
	QShortcut scFullscreen      = QShortcut(Qt::Key_F11,               this);
	QShortcut scLeftTab         = QShortcut(Qt::SHIFT | Qt::Key_Left,  this);
	QShortcut scRightTab        = QShortcut(Qt::SHIFT | Qt::Key_Right, this);
	
}; // class GesusMainWindow
