#ifndef AMBIENTLIGHT_H
#define AMBIENTLIGHT_H

#include "GraphicsCommon.h"

class AmbientLight {
public:
    AmbientLight() = delete;
    AmbientLight(const float &intensity,
                 const GLVector3 &color);
    AmbientLight(const AmbientLight &src);
    AmbientLight &operator=(const AmbientLight &src);
    virtual ~AmbientLight();

protected:
    float intensity;
    GLVector3 color;

public:
    const float &getIntensity() const;
    void setIntensity(const float &intensity);
    const GLVector3 &getColor() const;
    void setColor(const GLVector3 &color);
};

#endif // AMBIENTLIGHT_H
