#pragma once
#include "stdafx.h"
#include "CDocument.h"

using namespace std;

class CCommandHandler
{
public:
	CCommandHandler(istream & input, ostream & output);

	void HandleInput();
	void List();
	void SetTitle(const std::string & title);
	void Help();

private:
	void ExecuteCommand(const std::string & commandLine);
	
	CDocument m_document;
	istream & m_input;
	ostream & m_output;
};

