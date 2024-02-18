#pragma once


#include "tile_editor.hpp"
#include "palette_editor.hpp"
#include "plane_editor.hpp"
#include "sprite_editor.hpp"
#include "settings.hpp"

#include <QMainWindow>
#include <QObject>



class GesusMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	GesusMainWindow(QWidget * parent = nullptr);
	~GesusMainWindow();
	
private:
	QMainWindow *    window;
	
	SpriteEditor    spriteEditor;
	TileEditor      tileEditor;
	TileStash       tileStash;
	PaletteEditor   paletteEditor;
	PlaneEditor     planeEditor;
	GesusSettings   gesusSettings;
};
