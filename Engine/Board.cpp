#include "Board.h"
#include <assert.h>

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	const int off_x = x + borderWdth + borderPad;
	const int off_y = y + borderWdth + borderPad;
	gfx.DrawRectDim(loc.x*dim + off_x, loc.y*dim + off_y, dim -2 * cellPadding, dim - 2 * cellPadding, c);
}

int Board::getGridWidth() const
{
	return width;
}

int Board::getGridHeight() const
{
	return height;
}

//checks if snake is inside the board.
bool Board::isInsideBoard(const Location & loc) const
{
	return loc.x>=0 && loc.x< width &&
		loc.y>=0 && loc.y< height;
}

void Board::DrawBorder()
{
	const int top = y;
	const int left = x;
	const int bottom = y + 2 * (borderPad + borderWdth) + dim*height;
	const int right = x + 2 * (borderPad + borderWdth) + dim* width;
	//top 
	gfx.DrawRect(left, top, right, top + borderWdth, brdrC);
	//left
	gfx.DrawRect(left, top + borderWdth, left + borderWdth, bottom - borderWdth, brdrC);
	//right
	gfx.DrawRect(right - borderWdth, top + borderWdth, right, bottom - borderWdth, brdrC);
	//bottom
	gfx.DrawRect(left, bottom - borderWdth, right, bottom, brdrC);
}
