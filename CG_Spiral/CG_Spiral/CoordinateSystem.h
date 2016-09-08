#pragma once
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <boost\noncopyable.hpp>
#include <vector>
#include <memory>
#include "Rectangle.h"
#include "Size.h"

class CCoordinateSystem : private boost::noncopyable
{
public:
	void Init(SSize const &size);
	void Redraw() const;
private:
	std::vector<std::unique_ptr<CRectangle>> m_divisions;
	SSize m_size;
};