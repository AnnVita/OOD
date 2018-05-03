#pragma once
#include "stdafx.h"
#include <boost/iterator/indirect_iterator.hpp>
#include "Shape.h"

class CPictureDraft
{
public:
	typedef std::vector<std::unique_ptr<CShape>> ShapeStorage;

	typedef  boost::indirect_iterator<ShapeStorage::const_iterator, const CShape&> ConstIterator;
	CPictureDraft();
	bool IsEmpty() const;
	size_t GetShapeCount() const;
	ConstIterator begin() const;
	ConstIterator end() const;
	void AddShape(std::unique_ptr<CShape>&& shape);

	CPictureDraft(CPictureDraft&&) = default;
	CPictureDraft& operator=(CPictureDraft&&) = default;
	CPictureDraft(const CPictureDraft&) = delete;
	CPictureDraft& operator=(const CPictureDraft&) = delete;

	~CPictureDraft();
private:
	ShapeStorage m_shapes;
};