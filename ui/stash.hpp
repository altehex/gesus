#pragma once


#include "../genesis/genesis_tile.hpp"

#include <QDir>
#include <QList>
#include <QPushButton>
#include <QString>
#include <QTableView>

#include <list>
using std::list;


#define TILE_STASH_DOCK_NAME   "Tile Stash"
#define TILE_STASH_DEFAULT_DIR "./tiles"


class TileItem : public QPushButton
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	TileItem(const QString &);
	
signals: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void sentToEditor(Tile &);
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	Tile tile;
};


class TileStash : public QTableView
{
	Q_OBJECT

public: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	explicit TileStash(const QWidget * parent = nullptr);

	const QDir & getTileDir(void) const { return tileDir; }
	
private: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	static inline QDir tileDir = QDir(TILE_STASH_DEFAULT_DIR);
	
	list<TileItem *> tiles;
	
	void load_tiles_from_directory(const QDir & dir = tileDir);
	void setup_table(void);
															  
private slots: // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	void slot_receive_from_editor(void);
};
