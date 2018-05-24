#pragma once
#include "stdafx.h"

class CCommandLog
{
public:
	CCommandLog();
	bool CanUndo()const;
	void Undo();
	bool CanRedo()const;
	void Redo();
	void AddAndExecuteCommand(ICommandPtr && command);
private:
	std::deque<ICommandPtr> m_commands;
	size_t m_nextCommandIndex = 0;
	const int m_maxHistorySize = 10;
};