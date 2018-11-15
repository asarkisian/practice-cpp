//-------------------------------------------------
// Room.h

#ifndef ROOM_H
#define ROOM_H

#pragma warning(disable : 4512)

#include "Typedefs.h"

class Room
{
public:
	Room(length_t inW, 
		 length_t inH);

	length_t xPosWestWall() const;
	length_t xPosEastWall() const;
	length_t yPosSouthWall() const;
	length_t yPosNorthWall() const;

	length_t ncols() const;
	length_t nrows() const;

	image_t northWall() const;
	image_t southWall() const;
	image_t eastWall() const;
	image_t westWall() const;
    image_t floor() const;
	image_t northEastCorner() const;
	image_t southEastCorner() const;
	image_t northWestCorner() const;
	image_t southWestCorner() const;

private:
	const length_t my_xPosWestWall;
	const length_t my_xPosEastWall;
	const length_t my_yPosSouthWall;
	const length_t my_yPosNorthWall;

	const length_t my_width;
	const length_t my_height;

	const image_t my_northWall;
	const image_t my_southWall;
	const image_t my_eastWall;
	const image_t my_westWall;
    const image_t my_floor;
	const image_t my_northEastCorner;
	const image_t my_southEastCorner;
	const image_t my_northWestCorner;
	const image_t my_southWestCorner;
};

#endif
//-------------------------------------------------