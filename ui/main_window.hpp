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
#include <QMainWindow>
#include <QMenu>
#include <QObject>
#include <QPoint>
#include <QShortcut>
#include <QTabWidget>


class GesusMainWindow : public QMainWindow
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	
	GesusMainWindow(int, char * []);

private slots: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void slot_menu_opened(QMenu *, const QPoint &);
	
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
	void setup_editor_tabs(void);
	void setup_file_actions();
	void setup_main_window(void);
	void setup_menus(void);
	void setup_shortcuts(void);

	/*  Menus
	 */
#define FILE_MENU_TITLE  "File"
	QMenu gesusFileMenu;

	QAction showAbout       = QAction("About", this);
	QAction exitApplication = QAction("Exit", this);
	
	/*  Shortcuts
	 */
	// QShortcut exitApplicationSC;
	
}; // class GesusMainWindow
