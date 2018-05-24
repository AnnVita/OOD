#include "stdafx.h"
#include "CCommandHandler.h"

int main()
{
	CCommandHandler commandHandler(std::cin, std::cout);
	commandHandler.HandleInput();
}
