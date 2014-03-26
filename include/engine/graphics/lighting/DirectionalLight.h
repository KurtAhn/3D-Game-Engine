#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include "GraphicsCommon.h"
#include "AmbientLight.h"

class DirectionalLight : public AmbientLight {
public:
    DirectionalLight() = delete;
    DirectionalLight(const AmbientLight &base,
                     const GLVector3 &direction);
    DirectionalLight(const DirectionalLight &src);
    DirectionalLight &operator=(const DirectionalLight &src);
    virtual ~DirectionalLight();

protected:
    GLVector3 direction;

public:
    const GLVector3 &getDirection() const;
    void setDirection(const GLVector3 &direction);
};

#endif // DIRECTIONALLIGHT_H
