#pragma once

#include "Board.h"	

class Snake
{
private:
	// contains information about each segment of a snake's body/ its growth and direction and movement.
	class Segment
	{
	public:
		void Follow(const Segment& next);
		void Draw(Board & bd) const;
		void MoveBy(const Location& delta_loc);
		void InitHead(const Location& loc);
		void InitBody();
		const Location& GetLocation() const;
	private:
		Location loc;
		Color c;
	};

private:
	static constexpr int nSegMax = 100;
	Segment seg[nSegMax];
	int nSeg = 1;
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& bd)const;
	Location GetNextHeadLocation(const Location & delta_loc) const;
	bool IsInTile(const Location& target) const;
	bool IsInTileExceptEnd(const Location& target) const;


};