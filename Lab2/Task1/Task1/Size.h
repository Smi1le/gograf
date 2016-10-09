#pragma once

struct SSize
{
	SSize() = default;
	SSize(float w, float h)
		: width(w), height(h)
	{}
	float width;
	float height;
};