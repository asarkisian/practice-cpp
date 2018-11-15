//-------------------------------------------------
// SpaceMarine.h

#ifndef SPACEMARINE_H
#define SPACEMARINE_H

#pragma warning(disable : 4512)

#include "Typedefs.h"
#include <iosfwd>
#include <vector>

class Monster;

class SpaceMarine
{
public:
	// Constructor
	SpaceMarine(std::istream& inIS, 
				length_t inX, 
				length_t inY, 
				direction_t inD, 
				health_t inH, 
				armor_t inA);
	
	// Modifiers
	void adjustArmor(const armor_t inA);
	void setArmor(const armor_t inA);
	void adjustHealth(const health_t inH);
	void setHealth(const health_t inH);
	void setMove();
	void stepForward();
	void stepBackward();
	void stepLeft();
	void stepRight();
	void turnLeft();
	void turnRight();

	void processMove(const std::vector<Monster*>& mon);

	void respawn(length_t inX, length_t inY, direction_t inD, health_t inH, armor_t inA);

	// Accessors
	length_t xPosition() const;
	length_t yPosition() const;
	direction_t directionFacing() const;
	health_t health() const;
	armor_t armor() const;
	std::string createStatusBar() const;
	bool quitGame() const;
	bool isAlive() const;
	image_t image() const;

	bool isReadyToAttack(const Monster& target) const;
//	bool isReadyToAttack(const Zombie& czo) const;
//	bool isReadyToAttack(const ShotgunGuy& csg) const;
//	bool isReadyToAttack(const PinkDemon& cpd) const;

	void attack(Monster& target) const;
//	void attack(Zombie& zo) const;
//	void attack(ShotgunGuy& sg) const;
//	void attack(PinkDemon& pd) const;

private:
	// Data
	length_t my_xPosition;
	length_t my_yPosition;
	direction_t my_directionFacing;
	health_t my_health;
	armor_t my_armor;

	move_t my_move;

	const health_t my_minHealth;
	const health_t my_maxHealth;
	const armor_t my_minArmor;
	const armor_t my_maxArmor;

	bool isValidHealth() const;
	bool isValidArmor() const;
	bool isValidPosition() const;
	bool isValidDirection();

	const length_t my_stepSize;

	void limitPosition();
	void limitHealth();
	void limitArmor();

	const image_t my_imageNorth;
	const image_t my_imageEast;
	const image_t my_imageSouth;
	const image_t my_imageWest;

	const char my_imageDead;
	const int my_damage;

	std::istream& my_input;

	unsigned int my_deathCount;
};

#endif
//-------------------------------------------------