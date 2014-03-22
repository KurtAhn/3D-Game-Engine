#version 400 core

/**
 * Default lighting constants used when no values are specified by
 * the main application.
 */
#define DEFAULT_LIGHTING
 
#ifdef DEFAULT_LIGHTING
	#define MAX_POINT_LIGHTS 5
	#define MAX_SPOT_LIGHTS 5
#endif


layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

struct Material {
	float shininess;
	float specularity;
	float diffuseness;
	vec4 color;
};

uniform struct Drawable {
	mat4 transform;
	sampler2D sampler;
	Material material;
} drawable;

uniform struct Camera {
	float zNear;
	float zFar;
	float fov;
	float aspect;
	float scale;
	vec3 position;
	vec3 xAxis;
	vec3 yAxis;
	vec3 zAxis;
} camera;

out Fragment {
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} fragment;

mat4 cameraMatrix() {
	mat4 t = mat4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-camera.position.x, -camera.position.y, -camera.position.z, 1
	);
	
	mat4 r = mat4(
		camera.xAxis.x, camera.yAxis.x, camera.zAxis.x, 0,
		camera.xAxis.y, camera.yAxis.y, camera.zAxis.y, 0,
		camera.xAxis.z, camera.yAxis.z, camera.zAxis.z, 0,
		0, 0, 0, 1
	);
	
	mat4 p = mat4(
		1.0 / tan(radians(camera.fov / 2)) * camera.scale * camera.aspect, 0, 0, 0,
		0, 1.0 / tan(radians(camera.fov / 2)) * camera.scale, 0, 0,
		0, 0, (-camera.zFar - camera.zNear) / (camera.zFar - camera.zNear), -1,
		0, 0, -2 * camera.zFar * camera.zNear / (camera.zFar - camera.zNear), 0
	);
	
	return p * r * t;
}

void main() {
	gl_Position = cameraMatrix() * vec4(position, 1);
	fragment.position = position;
	fragment.normal = normal;
	fragment.texCoord = texCoord;
	
	//gl_Position = vec4(position.xy, 0, 1);
}