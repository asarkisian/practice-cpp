//-------------------------------------------------
// Room.cpp

#include "Room.h"

/*
Horizontal Pipe   cd
Vertical Pipe     ba
North-East Corner bb
North-West Corner c9
South-East Corner bc
South-West Corner c8
*/

// Public Modifier Member Functions
Room::Room(length_t inW, 
		   length_t inH)
:my_xPosWestWall(0),
 my_xPosEastWall(39), 
 my_yPosSouthWall(0),
 my_yPosNorthWall(19),
 my_width(inW),
 my_height(inH),
 my_northWall('\xcd'),
 my_southWall('\xcd'),
 my_eastWall('\xba'),
 my_westWall('\xba'), 
 my_floor(' '),
 my_northEastCorner('\xbb'),
 my_southEastCorner('\xbc'),
 my_northWestCorner('\xc9'),
 my_southWestCorner('\xc8')
{}
 
// Public Accessor Member Functions
length_t Room::xPosWestWall() const
{
    return my_xPosWestWall;
}

length_t Room::xPosEastWall() const
{
    return my_xPosEastWall;
}

length_t Room::yPosSouthWall() const
{
    return my_yPosSouthWall;
}

length_t Room::yPosNorthWall() const
{
    return my_yPosNorthWall;
}

length_t Room::ncols() const
{
	return  my_width;
}

length_t Room::nrows() const
{
	return my_height;
}

image_t Room::northWall() const
{
    return my_northWall;
}

image_t Room::southWall() const
{
    return my_southWall;
}

image_t Room::eastWall() const
{
    return my_eastWall;
}

image_t Room::westWall() const
{
    return my_westWall;
}

image_t Room::floor() const
{
    return my_floor;
}

image_t Room::northEastCorner() const
{
    return my_northEastCorner;
}

image_t Room::southEastCorner() const
{
    return my_southEastCorner;
}

image_t Room::northWestCorner() const
{
    return my_northWestCorner;
}

image_t Room::southWestCorner() const
{
    return my_southWestCorner;
}
//-------------------------------------------------