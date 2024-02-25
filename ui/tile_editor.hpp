#pragma once


#include "../genesis/genesis_tile.hpp"

#include <functional>
using std::function;

#include <QObject>
#include <QWidget>


#define TILE_EDITOR_TAB_NAME "Tile Editor"


class TileCanvas
{

public:
	TileCanvas(QWidget * parent = nullptr);
	~TileCanvas(void);
	
private:
	Tile * activeTile;

	
};

	
class TileEditor : public QWidget
{
	Q_OBJECT

public:
	TileEditor(QWidget * parent = nullptr);
	~TileEditor(void);

	void save_as_tilemap(void);
	void compress(function<void(void)>);
	void save_as_image(void);
	
signals:
	void sentToStash(void);

private:
	TileCanvas tileCanvas;

private slots:
	void receive_from_stash(void);
};
