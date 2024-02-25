#pragma once


#include <cstdint>


#ifndef _X_
#   define _X_ *
#endif


#include <QColor>
#include <QObject>
#include <QPushButton>


class GenesisColor : public QObject
{
	Q_OBJECT
	
public:
	uint16_t to_word(void);

	uint8_t getId(void);
	
signals:
	void modified(void);

private:
	uint8_t id;
	QColor  color;
};


class GenesisPixel : public QPushButton
{
	Q_OBJECT

private:
	GenesisColor * color;
};
