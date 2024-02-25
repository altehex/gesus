#pragma once


#include "../genesis/genesis_tile.hpp"

#include <vector>
using std::vector;

#include <QAbstractScrollArea>
#include <QPushButton>


#define TILE_STASH_DOCK_NAME   "Tile Stash"
#define TILE_STASH_DEFAULT_DIR "./tiles"


class TileItem : public QPushButton
{
	Q_OBJECT

public:
	TileItem(const char *);
	
private:
	Tile tile;
};


class TileStash : public QAbstractScrollArea
{
	Q_OBJECT

public:
	explicit TileStash(const QWidget * parent = nullptr);
	
signals:
	void sentToEditor(Tile &);
	
private:
	vector<TileItem *> tiles;
	
	void load_tiles_from_directory(const char * dir = TILE_STASH_DEFAULT_DIR);
													
private slots:
	void receive_from_editor(void);
};
