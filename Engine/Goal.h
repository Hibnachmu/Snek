#pragma once
#include "Snake.h"
#include <random>
#include "Board.h"	
//creates goals that randomly appears on the screen. 
class Goal
{
public:
	Goal(Board& bd, Snake& snake, std::mt19937& rng);
	void draw(Board& bd)const ;
	void Respawn(Board& bd, Snake& snake, std::mt19937& rng);
	const Location & GetLocation()const;
private:
	Location loc;
	static constexpr Color c = Colors::Red;
	
};