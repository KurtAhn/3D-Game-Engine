#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(const AmbientLight &base,
                 const GLVector3 &direction) :
	AmbientLight(base),
	direction(direction) {}

DirectionalLight::DirectionalLight(const DirectionalLight &src) :
	AmbientLight(src),
	direction(src.direction) {}

DirectionalLight &DirectionalLight::operator=(const DirectionalLight &src) {
	intensity = src.intensity;
	color = src.color;
	direction = src.direction;
	return *this;
}

DirectionalLight::~DirectionalLight() {}

const GLVector3 &DirectionalLight::getDirection() const {
	return direction;
}

void DirectionalLight::setDirection(const GLVector3 &direction) {
	this->direction = direction;
}
