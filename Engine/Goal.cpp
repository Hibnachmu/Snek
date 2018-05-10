#include "Goal.h"

Goal::Goal(Board & bd, Snake & snake, std::mt19937 & rng)
{
	Respawn(bd, snake, rng);
}



void Goal::draw(Board & bd) const
{
	bd.DrawCell(loc, c);
}

void Goal::Respawn(Board & bd, Snake & snake, std::mt19937 & rng)
{
	std::uniform_int_distribution<int> xDist(0, bd.getGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, bd.getGridHeight() - 1);
	Location nLoc;
	do
	{
		nLoc.x = xDist(rng);
		nLoc.y = yDist(rng);
	} while (snake.IsInTile(nLoc));

	loc = nLoc;
}
 
const Location & Goal::GetLocation() const
{
	return loc;
}
