#version 400 core

in Fragment {
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} f;

void main() {
	//fColor = vColor;
	gl_FragColor = vec4(clamp(mod(f.position, 1), 0, 1), 1);
}