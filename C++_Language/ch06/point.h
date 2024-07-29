#pragma once

class Point {
	int width;
	int height;
	static int max_width;
	static int max_height;

public:
	void show();
	Point();
	Point(int x, int y);
	void setXY(int x, int y);
	static void setMax(int x, int y);
};