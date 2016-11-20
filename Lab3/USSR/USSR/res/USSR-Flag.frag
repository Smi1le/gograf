// Check if the point p is on the left side of the line p0p1
bool RealEq(float a, float b)
{
	return abs(a - b) <= 1e-3;
}

bool RealMoreEq(float a, float b)
{
	return a - b >= 1e-3;
}

bool EqPoint(vec2 p1, vec2 p2)
{
	return RealEq(p1.x, p2.x) && RealEq(p1.y, p2.y);
}

bool AtOtres(vec2 p1, vec2 p2, vec2 p)
{
	if (EqPoint(p1, p2))
	{
		return EqPoint(p1, p);
	}
	else
	{
		return RealEq((p.x - p1.x) * (p2.y - p1.y) - (p.y - p1.y) * (p2.x - p1.x), 0) && 
				( (RealMoreEq(p.x, p1.x) && RealMoreEq(p2.x, p.x)) || 
				 ( RealMoreEq(p.x, p2.x) && RealMoreEq(p1.x, p.x) ) );
	}
}


bool PointIsOnTheLeft(vec2 p0, vec2 p1, vec2 p)
{
    vec2 p0p1 = p1 - p0;
    // find the orthogonal vector to p0p1
    vec2 n = vec2(-p0p1.y, p0p1.x);
    // Find the dot product between n and (p - p0)
    return dot(p - p0, n) > 0.0;
}

bool PointIsInsideTheHammer(vec2 p)
{
	vec2 p0 = vec2(0.575, 3.075);
	vec2 p1 = vec2(0.775, 3.275);
	vec2 p2 = vec2(0.65, 3.3);
	vec2 p3 = vec2(0.525, 3.175);
	vec2 p4 = vec2(0.65, 3.15);
	vec2 p5 = vec2(0.68, 3.18);
	vec2 p6 = vec2(1.08, 2.72);
	vec2 p7 = vec2(1.1, 2.65);
    return (PointIsOnTheLeft(p0, p1, p) &&
           PointIsOnTheLeft(p1, p2, p) &&
           PointIsOnTheLeft(p2, p3, p) &&
		   PointIsOnTheLeft(p3, p0, p)) ||
		   (PointIsOnTheLeft(p7, p6, p) &&
           PointIsOnTheLeft(p6, p5, p) &&
           PointIsOnTheLeft(p5, p4, p) &&
		   PointIsOnTheLeft(p4, p7, p));
}

bool PointIsInRadius(vec2 pos, vec2 center, float radius, int condition)
{
	
	return condition == 0 ? 
			((pos.x - center.x) * (pos.x - center.x) + (pos.y - center.y) * (pos.y - center.y)) >= radius * radius :
			((pos.x - center.x) * (pos.x - center.x) + (pos.y - center.y) * (pos.y - center.y)) <= radius * radius;
}

bool PointIsInsideBladeSickle(vec2 pos)
{
	vec2 firstCenter = vec2(0.625, 3.2);
	vec2 secondCenter = vec2(0.65, 3.175);
	float firstRadius = 0.3;
	float secondRadius = 0.3;
	return PointIsInRadius(pos, firstCenter, firstRadius, 0) && PointIsInRadius(pos, secondCenter, secondRadius, 1) &&
			pos.x - firstCenter.x >= 0.0 && pos.y - firstCenter.y <= 0.2;
}

bool PointIsInsideGripSickle(vec2 pos)
{
	vec2 p0 = vec2(0.53, 2.735);
	vec2 p1 = vec2(0.63, 2.88);
	vec2 p2 = vec2(0.605, 2.9);
	vec2 p3 = vec2(0.51, 2.755);
    return (PointIsOnTheLeft(p0, p1, pos) &&
           PointIsOnTheLeft(p1, p2, pos) &&
           PointIsOnTheLeft(p2, p3, pos) &&
		   PointIsOnTheLeft(p3, p0, pos));
}

bool PointIsInStar(vec2 pos)
{
	vec2 p0 = vec2(0.7, 3.4);
	vec2 p1 = vec2(0.75, 3.5);
	vec2 p2 = vec2(0.8, 3.4);
	vec2 p3 = vec2(0.775, 3.55);
	vec2 p4 = vec2(0.825, 3.6);
	vec2 p5 = vec2(0.765, 3.6);
	vec2 p6 = vec2(0.75, 3.65);
	vec2 p7 = vec2(0.735, 3.6);
	vec2 p8 = vec2(0.675, 3.6);
	vec2 p9 = vec2(0.725, 3.55);
	return AtOtres(p0, p1, pos) ||
			AtOtres(p1, p2, pos) || 
			AtOtres(p2, p3, pos) ||
			AtOtres(p3, p4, pos) ||
			AtOtres(p4, p5, pos) ||
			AtOtres(p5, p6, pos) ||
			AtOtres(p6, p7, pos) || 
			AtOtres(p7, p8, pos) ||
			AtOtres(p8, p9, pos) ||
			AtOtres(p9, p0, pos);
}

void main()
{
    vec2 pos = gl_TexCoord[0].xy;
    const vec2 p0 = vec2(1.0, 1.0);
    const vec2 p1 = vec2(3.0, 2.0);
    const vec2 p2 = vec2(2.5, 3.5);
    if (PointIsInsideTheHammer(pos) || PointIsInsideBladeSickle(pos) || PointIsInsideGripSickle(pos) || PointIsInStar(pos))
    {
        gl_FragColor = vec4(1.0, 0.83, 0.0, 1.0);
    }
    else
    {
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    }
}
