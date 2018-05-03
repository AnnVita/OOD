#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#define WIN32_LEAN_AND_MEAN
#define _USE_MATH_DEFINES

#include <string>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "EColor.h"

struct Vertex
{
	float x;
	float y;
};

using namespace std;

static EColor GetColorFromString(string colorAsString)
{
	map<string, EColor> colors = {
		{ "black", EColor::BLACK },
		{ "blue", EColor::BLUE },
		{ "green", EColor::GREEN },
		{ "pink", EColor::PINK },
		{ "red", EColor::RED },
		{ "yellow", EColor::YELLOW }
	};

	return colors.at(colorAsString);
}

static string ColorToString(EColor color)
{
	map<EColor, string> colorsTable = {
		{ EColor::BLACK, "black" },
		{ EColor::BLUE, "blue" },
		{ EColor::GREEN, "green" },
		{ EColor::PINK, "pink" },
		{ EColor::RED, "red" },
		{ EColor::YELLOW, "yellow" }
	};
	return colorsTable.at(color);
}

static vector<string> GetParamsFromString(const string &paramsAsString)
{
	stringstream paramsAsStream(paramsAsString);
	vector<string> paramsList;
	string param;

	while (paramsAsStream >> param)
	{
		paramsList.push_back(param);
	}

	return paramsList;
}