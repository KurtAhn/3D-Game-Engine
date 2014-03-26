#include "SpotLight.h"

SpotLight::SpotLight(const PointLight &base,
		  const GLVector3 &direction,
		  const float &cutoff) :
	PointLight(base),
	direction(direction),
	cutoff(cutoff) {}

SpotLight::SpotLight(const SpotLight &src) :
	PointLight(src),
	direction(src.direction),
	cutoff(src.cutoff) {}

SpotLight &SpotLight::operator=(const SpotLight &src) {
	intensity = src.intensity;
	color = src.color;
	attenuation = src.attenuation;
	position = src.position;
	range = src.range;
	direction = src.direction;
	cutoff = src.cutoff;
	return *this;
}

SpotLight::~SpotLight() {}

const GLVector3 &SpotLight::getDirection() const {
	return direction;
}

void SpotLight::setDirection(const GLVector3 &direction) {
	this->direction = direction;
}

const float &SpotLight::getCutoff() const {
	return cutoff;
}

void SpotLight::setCutoff(const float &cutoff) {
	this->cutoff = cutoff;
}
