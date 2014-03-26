#include "PointLight.h"

PointLight::PointLight(const AmbientLight &base,
           const Attenuation &attenuation,
           const GLVector3 &position,
           const float &range) :
	AmbientLight(base),
	attenuation(attenuation),
	position(position),
	range(range) {}

PointLight::PointLight(const PointLight &src) :
	AmbientLight(src),
	attenuation(src.attenuation),
	position(src.position),
	range(src.range) {}

PointLight &PointLight::operator=(const PointLight &src) {
	intensity = src.intensity;
	color = src.color;
	attenuation = src.attenuation;
	position = src.position;
	range = src.range;
	return *this;
}

PointLight::~PointLight() {}

const Attenuation &PointLight::getAttenuation() const {
	return attenuation;
}

void PointLight::setAttenuation(const Attenuation &attenuation) {
	this->attenuation = attenuation;
}

const GLVector3 &PointLight::getPosition() const {
	return position;
}

void PointLight::setPosition(const GLVector3 &position) {
	this->position = position;
}

const float &PointLight::getRange() const {
	return range;
}

void PointLight::setRange(const float &range) {
	this->range = range;
}
