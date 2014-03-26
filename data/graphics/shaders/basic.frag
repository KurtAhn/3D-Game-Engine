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

uniform struct AmbientLight {
	float intensity;
	vec3 color;
} ambientLight;

uniform struct DirectionalLight {
	AmbientLight base;
	vec3 direction;
} directionalLight;

struct Attenuation {
	float constant;
	float linear;
	float quadratic;
};

uniform struct PointLight {
	AmbientLight base;
	Attenuation attenuation;
	vec3 position;
	float range;
} pointLights[MAX_POINT_LIGHTS];

uniform struct SpotLight {
	PointLight base;
	vec3 direction;
	float cutoff;
} spotLights[MAX_SPOT_LIGHTS];

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
	//gl_FragColor = vec4(mod(fragment.position, 1), 1);
	gl_FragColor = texture2D(drawable.sampler, fragment.texCoord);
	//gl_FragColor = vec4(fragment.texCoord.x, fragment.texCoord.y, 0, 1);
	//gl_FragColor = vec4(fragment.normal.x, fragment.normal.y, fragment.normal.z, 1);
}