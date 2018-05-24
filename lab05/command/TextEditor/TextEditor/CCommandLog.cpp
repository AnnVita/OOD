#include "stdafx.h"
#include "CCommandLog.h"
#include "ICommand.h"

CCommandLog::CCommandLog()
{}

bool CCommandLog::CanUndo() const
{
	return m_nextCommandIndex != 0;
}

bool CCommandLog::CanRedo() const
{
	return m_nextCommandIndex != m_commands.size();
}

void CCommandLog::Undo()
{
	if (CanUndo())
	{
		m_commands[m_nextCommandIndex - 1]->Unexecute();
		--m_nextCommandIndex;
	}
}

void CCommandLog::Redo()
{
	if (CanRedo())
	{
		m_commands[m_nextCommandIndex]->Execute();
		++m_nextCommandIndex;
	}
}

void CCommandLog::AddAndExecuteCommand(ICommandPtr && command)
{
	if (m_nextCommandIndex < m_commands.size())
	{
		command->Execute();
		++m_nextCommandIndex;
		m_commands.resize(m_nextCommandIndex);
		m_commands.back() = move(command);
	}
	else
	{
		assert(m_nextCommandIndex == m_commands.size());

		if (m_commands.size() == m_maxHistorySize)
		{
			m_commands.pop_front();
			--m_nextCommandIndex;
		}
		m_commands.emplace_back(nullptr);
		try
		{
			command->Execute();
			m_commands.back() = move(command);
			++m_nextCommandIndex;
		}
		catch (...)
		{
			m_commands.pop_back();
			throw;
		}

	}
}
