#pragma once
#include "AbstractCommand.h"
#include "CDocumentItemStorage.h"

class CInsertImageCommand :
	public CAbstractCommand
{
public:
	static string imagesDirName;
	static Path imagePathTemplate;

	CInsertImageCommand(CDocumentItemStorage & m_target, int width, int height, Path path, boost::optional<size_t> position);
	~CInsertImageCommand() = default;

protected:
	void DoExecute() override;
	void DoUnexecute() override;

private:
	CDocumentItemStorage & m_target;
	int m_width, m_height;
	Path m_path;
	size_t m_position;
	shared_ptr<IImage> m_image;

	Path GetRelativeImagePath(Path source);
};