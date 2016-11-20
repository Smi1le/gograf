



bool PointIsInRadius(vec2 pos, vec2 center, float radius, int condition)
{
	
	return condition == 0 ? 
			((pos.x - center.x) * (pos.x - center.x) + (pos.y - center.y) * (pos.y - center.y)) >= radius * radius :
			((pos.x - center.x) * (pos.x - center.x) + (pos.y - center.y) * (pos.y - center.y)) <= radius * radius;
}

void main()
{
	vec2 pos = gl_TexCoord[0].xy;
    vec2 center = vec2(2.0, 2.0);
	float firstRadius = 0.5;
	float secondRadius = 0.7;
	gl_FragColor = vec4((PointIsInRadius(pos, center, firstRadius, 0) && PointIsInRadius(pos, center, secondRadius, 1)) ? 0.0 : 1.0);
	

    
}	
