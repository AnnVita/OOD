#pragma once
#include "AbstractCommand.h"
#include "CDocumentItemStorage.h"

class CDeleteItemCommand :
	public CAbstractCommand
{
public:
	CDeleteItemCommand(CDocumentItemStorage & target, size_t position);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	CDocumentItemStorage & m_target;
	size_t m_position;
	DocumentItemPtr m_item;
};



