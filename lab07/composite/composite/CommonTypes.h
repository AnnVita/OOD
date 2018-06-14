#pragma once

template <typename T>
struct Rect
{
	T left;
	T top;
	T width;
	T height;
};

typedef Rect<double> RectDouble;
typedef uint32_t RGBAColor;