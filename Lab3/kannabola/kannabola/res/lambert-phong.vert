varying vec3 n;
varying vec3 v;

void main(void)
{
	float x = gl_Vertex.x;
	float radius = (1.0 + sin(x)) * (1.0 + 0.9 * cos(8.0 * x)) * (1.0 + 0.1 * cos(24.0 * x)) * (0.5 + 0.05 * cos(140.0 * x));
	vec4 vertex = vec4(radius * cos(x), radius * sin(x), 0.0, 1.0);

	v = vec3(gl_ModelViewMatrix * vertex);
    vec4 position = gl_ModelViewProjectionMatrix * vertex;
	n = normalize(gl_NormalMatrix * gl_Normal);
    gl_Position = position;
}
