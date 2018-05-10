#pragma once

#include "Graphics.h"
#include "Location.h"
//basic design of the game board. 
class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int getGridWidth()const;
	int getGridHeight()const;
	bool isInsideBoard(const Location &loc) const;
	void DrawBorder();

private:
	static constexpr int dim = 20;
	static constexpr int width=25;
	static constexpr int height=25;
	static constexpr int x = 25;
	static constexpr int y = 25;
	static constexpr int borderWdth = 4;
	static constexpr int borderPad = 2;
	static constexpr Color brdrC = Colors::White;
	static constexpr int cellPadding = 1;

	Graphics& gfx;
};