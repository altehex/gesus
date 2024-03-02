#pragma once


#include "../genesis/genesis_tile.hpp"

#include <QDir>
#include <QDockWidget>
#include <QGridLayout>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QWidget>

#include <list>
using std::list;


#define TILE_STASH_DOCK_NAME   "Tile Stash"
#define TILE_STASH_DEFAULT_DIR "./tiles"


class TileItem : public QPushButton
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	TileItem(const QString &);

	const Tile & getTile(void) const { return tile; }
	
signals: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void sentToEditor(Tile &);
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	Tile tile;
};


class TileStash : public QWidget
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	explicit TileStash(QWidget * = nullptr);

	const QDir & get_tile_dir(void) const { return tileDir; }
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	static inline QDir tileDir = QDir(TILE_STASH_DEFAULT_DIR);
	
	QGridLayout       tileItemGrid;
	list<TileItem *>  tileItems;
	
	void load_tiles_from_directory(const QDir & = tileDir);
	void setup_grid(void);
															  
private slots: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void slot_receive_from_editor(void);
};
