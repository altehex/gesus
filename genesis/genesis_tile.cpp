#include "genesis_tile.hpp"


#include <QImage>
#include <QString>


Tile::
Tile(const char * path)
	: QImage(QString(path))
{
}
