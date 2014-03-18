#version 400 core

/**
 * Default lighting constants used when no values are specified by
 * the main application.
 */
#ifdef DEFAULT_LIGHTING
	#define MAX_POINT_LIGHTS 5
	#define MAX_SPOT_LIGHTS 5
#endif

uniform struct Light {
	float intensity;
	vec3 color;
} ambientLight;

uniform struct DirectionalLight {
	Light base;
	vec3 direction;
} directionalLight;

struct Attenuation {
	float constant;
	float linear;
	float quadratic;
};

uniform struct PointLight {
	Light base;
	Attenuation attenuation;
	vec3 position;
	float range;
} pointLights[MAX_POINT_LIGHTS];

uniform struct SpotLight {
	PointLight pointLight;
	vec3 direction;
	float cutoff;
} spotLights[MAX_SPOT_LIGHTS];

uniform struct Drawable {
	mat4 transform;
	
	struct Material {
		sampler2D sampler;
		float shininess;
		float specularity;
		float diffuseness;
		vec3 color;
	} material;
} drawable;

uniform struct Camera {
	float zNear;
	float zFar;
	float  fov;
	float aspect;
	float scale;
	vec3 position;
	vec3 xAxis;
	vec3 yAxis;
	vec3 zAxis;
} camera;

in Fragment {
	vec3 position;
	vec3 normal;
	vec2 texCoord;
} fragment;


void main() {
	//fColor = vColor;
	gl_FragColor = vec4(clamp(mod(f.position, 1), 0, 1), 1);
	//gl_FragColor = vec4(1, 1, 1, 1);
}