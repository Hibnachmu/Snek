#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & loc)
{
	seg[0].InitHead(loc);
}

//To move the snake in the direction thats specified by delta_loc.
void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSeg-1; i>0; i--)
	{
		seg[i].Follow(seg[i-1]);
	}
	seg[0].MoveBy(delta_loc);
}

//expand the snake when it eats.
void Snake::Grow()
{
	if (nSeg < nSegMax)
	{
		seg[nSeg].InitBody();
		nSeg++;
	}
}

// draw the segments of snake on screen
void Snake::Draw(Board & bd) const
{
	for (int i = 0; i < nSeg; i++)
	{
		seg[i].Draw(bd);
	}
}

//returns the next location of head of snake.
Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(seg[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

//to check if any segment of a snake overlaps with other segments of snake.
bool Snake::IsInTile(const Location & target) const
{
	for (int i = 0; i < nSeg; i++)
	{
		if (seg[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

//to check if the head collides with any segment of the snake excluding the tail.
bool Snake::IsInTileExceptEnd(const Location & target) const
{
	for (int i = 0; i < nSeg - 1; i++)
	{
		if (seg[i].GetLocation() == target)
		{
			return true;
		}
	}
	return false;
}

//for making the pathings for segments/ to follow the direction of snake.
void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

//to draw segments 
void Snake::Segment::Draw(Board & bd) const
{
	bd.DrawCell(loc, c);
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);  //to check for valid horizontal or vertical movements only.
	loc.Add(delta_loc);
}

//initialize the snake's head.
void Snake::Segment::InitHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

// to make the snake's body as it eats.
void Snake::Segment::InitBody()
{
	c = Snake::bodyColor;
}

//returns the current location of the snake's segments.
const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
