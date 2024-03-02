#pragma once


#include "genesis_color.hpp"

#include <QPixmap>
#include <QString>


class Tile : public QPixmap
{
public:
	Tile(void) {}
	Tile(const QString &);
};
