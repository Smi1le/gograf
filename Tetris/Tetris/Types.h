#pragma once




enum class SHAPE_TYPE
{
	first ,
	second ,
	third ,
	fourth ,
	fifth ,
	sixth ,
	seventh
};

enum SIDE
{
	first = 0, 
	second, 
	third,
	fourth
};

enum class ROTATE
{
	left,
	right
};



namespace
{
	const float LEFT_SIDE = 100.f;
	const SSize SHAPE_SIZE = { 25.f, 25.f };
	const glm::fvec3 FIRST_SHAPE_COLOR = { 0.19f, 0.95f, 1.f };
	const glm::fvec3 SECOND_SHAPE_COLOR = { 0.3f, 0.2f, 1.f };
	const glm::fvec3 THIRD_SHAPE_COLOR = { 0.97f, 0.55f, 0.22f };
	const glm::fvec3 FOURTH_SHAPE_COLOR = { 1.f, 0.98f, 0.18f };
	const glm::fvec3 FIFTH_SHAPE_COLOR = { 0.18f, 1.f, 0.18f };
	const glm::fvec3 SIXTH_SHAPE_COLOR = { 0.7f, 0.32f, 0.86f };
	const glm::fvec3 SEVENTH_SHAPE_COLOR = { 1.f, 0.18f, 0.2f };
	const glm::fvec3 BLUE = { 0.07f, 0.09f, 0.96f };
	const glm::fvec3 GRAY = { 0.51f, 0.51f, 0.51f };
	const glm::fvec2 FIRST_POSITION = { LEFT_SIDE, SHAPE_SIZE.height * 1 };
}
