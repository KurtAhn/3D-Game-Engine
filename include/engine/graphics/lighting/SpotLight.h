#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include "GraphicsCommon.h"
#include "PointLight.h"

class SpotLight : public PointLight {
public:
    SpotLight() = delete;
    SpotLight(const PointLight &base,
              const GLVector3 &direction,
              const float &cutoff);
    SpotLight(const SpotLight &src);
    SpotLight &operator=(const SpotLight &src);
    virtual ~SpotLight();

protected:
    GLVector3 direction;
    float cutoff;

public:
    const GLVector3 &getDirection() const;
    void setDirection(const GLVector3 &direction);
    const float &getCutoff() const;
    void setCutoff(const float &cutoff);
};

#endif // SPOTLIGHT_H
