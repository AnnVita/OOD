#pragma once
#include "AbstractCommand.h"
#include "CDocumentItemStorage.h"

class CInsertParagraphCommand :
	public CAbstractCommand
{
public:
	CInsertParagraphCommand(CDocumentItemStorage & target, std::string const & text, boost::optional<size_t> position);

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	std::shared_ptr<IParagraph> m_paragraph;
	CDocumentItemStorage & m_target;
	size_t m_position;
};

