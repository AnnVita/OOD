#pragma once
#include "stdafx.h"

using namespace std;

class IParagraph
{
public:
	virtual const string & GetText()const = 0;
	virtual void SetText(string text) = 0;
	virtual ~IParagraph() = default;
};