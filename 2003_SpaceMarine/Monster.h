//-------------------------------------------------
// Monster.h

#pragma warning(disable : 4512)

#ifndef MONSTER_H
#define MONSTER_H

#include "Typedefs.h"

class SpaceMarine;

class Monster
{
public:
	// Constructors
	Monster(length_t inX, 
		    length_t inY, 
		    direction_t inD, 
		    health_t inH,
			health_t inMH,
			int inDM);
	
	virtual ~Monster();

	// Modifiers
	void adjustHealth(const health_t inH);
	void setHealth(const health_t inH);
	void setMove(SpaceMarine& sm);
	void stepForward();
	void stepBackward();
	void stepLeft();
	void stepRight();
	void turnLeft();
	void turnRight();
	void processMove(SpaceMarine& sm);

	// Accessors
	length_t xPosition() const;
	length_t yPosition() const;
	direction_t directionFacing() const;
	health_t health() const;
	bool isAlive() const;
	image_t image() const;

	virtual bool isReadyToAttack(const SpaceMarine& csm) const;
    virtual bool isReadyToTurn(const SpaceMarine& csm) const;
	void attack(SpaceMarine& sm) const;
	virtual move_t turnMove(const SpaceMarine& csm) const;
    virtual move_t stepMove(const SpaceMarine& csm) const;

private:
	// Data
	length_t my_xPosition;
	length_t my_yPosition;
	direction_t my_directionFacing;
	health_t my_health;

	const move_t my_stepForward;
	const move_t my_stepBackward;
	const move_t my_stepLeft;
	const move_t my_stepRight;
	const move_t my_turnLeft;
	const move_t my_turnRight;

	move_t my_move;

	const health_t my_minHealth;
	const health_t my_maxHealth;

	bool isValidHealth() const;
	bool isValidPosition() const;
	bool isValidDirection() const;

	const direction_t my_north;
	const direction_t my_south;
	const direction_t my_east;
	const direction_t my_west;
	const length_t my_stepSize;

	void limitPosition();
	void limitHealth();

	const image_t my_imageNorth;
	const image_t my_imageEast;
	const image_t my_imageSouth;
	const image_t my_imageWest;

	const char my_attack;
	const char my_imageDead;
	const int my_damage;
};

#endif
//-------------------------------------------------