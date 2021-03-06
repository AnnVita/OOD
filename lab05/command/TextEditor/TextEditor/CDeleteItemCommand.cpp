#include "stdafx.h"
#include "CDeleteItemCommand.h"

CDeleteItemCommand::CDeleteItemCommand(CDocumentItemStorage& target, size_t position)
	: m_target(target)
	, m_position(position)
{
	m_item = m_target.GetItem(position);
}

void CDeleteItemCommand::DoExecute()
{
	m_target.DeleteDocumentItem(m_position);
}

void CDeleteItemCommand::DoUnexecute()
{
	m_target.InsertDocumentItem(m_item, m_position);
}