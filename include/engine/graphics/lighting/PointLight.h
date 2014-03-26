#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "GraphicsCommon.h"
#include "AmbientLight.h"
#include "Attenuation.h"

class PointLight : public AmbientLight {
public:
    PointLight() = delete;
    PointLight(const AmbientLight &base,
               const Attenuation &attenuation,
               const GLVector3 &position,
               const float &range);
    PointLight(const PointLight &src);
    PointLight &operator=(const PointLight &src);
    virtual ~PointLight();

protected:
    Attenuation attenuation;
    GLVector3 position;
    float range;

public:
    const Attenuation &getAttenuation() const;
    void setAttenuation(const Attenuation &attenuation);
    const GLVector3 &getPosition() const;
    void setPosition(const GLVector3 &position);
    const float &getRange() const;
    void setRange(const float &range);
};


#endif // POINTLIGHT_H
