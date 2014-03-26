#include "AmbientLight.h"

AmbientLight::AmbientLight(const float &intensity,
                 const GLVector3 &color) :
	intensity(intensity),
	color(color) {}

AmbientLight::AmbientLight(const AmbientLight &src) :
	intensity(src.intensity),
	color(src.color) {}

AmbientLight &AmbientLight::operator=(const AmbientLight &src) {
	intensity = src.intensity;
	color = src.color;
	return *this;
}

AmbientLight::~AmbientLight() {}

const float &AmbientLight::getIntensity() const {
	return intensity;
}

void AmbientLight::setIntensity(const float &intensity) {
	this->intensity = intensity;
}

const GLVector3 &AmbientLight::getColor() const {
	return color;
}

void AmbientLight::setColor(const GLVector3 &color) {
	this->color = color;
}
