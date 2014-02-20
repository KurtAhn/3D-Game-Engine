#version 400 core


layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out Fragment {
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} f;

uniform struct Camera {
	float zNear;
	float zFar;
	float  fov;
	float aspect;
	float scale;
	vec3 position;
	vec3 lateral;
	vec3 normal;
	vec3 longitudinal;
} c;

mat4 cameraMatrix() {
	mat4 t = mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-c.position.x, -c.position.y, -c.position.z, 1
	);
	
	mat4 r = mat4(
		c.lateral.x, c.normal.x, c.longitudinal.x, 0,
		c.lateral.y, c.normal.y, c.longitudinal.y, 0,
		c.lateral.z, c.normal.z, c.longitudinal.z, 0,
		0, 0, 0, 1
	);
	
	mat4 p = mat4(
		1.0 / tan(radians(c.fov / 2)) * c.scale * c.aspect, 0, 0, 0,
		0, 1.0 / tan(radians(c.fov / 2)) * c.scale, 0, 0,
		0, 0, (-c.zFar - c.zNear) / (c.zFar - c.zNear), -1,
		0, 0, -2 * c.zFar * c.zNear / (c.zFar - c.zNear), 0
	);
	
	return p * r * t;
}

void main() {
	gl_Position = cameraMatrix() * vec4(position, 1);
	f.position = position;
	f.normal = normal;
	f.texCoord = texCoord;
}