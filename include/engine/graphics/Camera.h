#ifndef CAMERA_H
#define CAMERA_H

#include "Common.h"

class Camera {
#ifdef DEBUG
    friend std::ostream &operator<<(std::ostream &os, const Camera &camera);
#endif

// Static constants
protected:
    static const float DEFAULT_Z_NEAR;
    static const float DEFAULT_Z_FAR;
    static const float DEFAULT_FOV;
    static const float DEFAULT_ASPECT;
    static const float DEFAULT_SCALE;
    static const glm::vec3 DEFAULT_POSITION;
    static const glm::vec3 DEFAULT_LATERAL;
    static const glm::vec3 DEFAULT_NORMAL;
    static const glm::vec3 DEFAULT_LONGITUDINAL;

// cdtor, copy
public:
    Camera() = default;
    explicit Camera(const float &zNear,
           const float &zFar,
           const float &fov,
           const float &aspect);
    Camera(const Camera &src) = delete;
    Camera &operator=(const Camera &c) = delete;

    virtual ~Camera();

// Data/Access
protected:
    float zNear = DEFAULT_Z_NEAR;
    float zFar = DEFAULT_Z_FAR;
    float fov = DEFAULT_FOV;
    float aspect = DEFAULT_ASPECT;

    mutable float scale = DEFAULT_SCALE;
    mutable glm::vec3 position = DEFAULT_POSITION;
    mutable glm::vec3 lateral = DEFAULT_LATERAL;
    mutable glm::vec3 normal = DEFAULT_NORMAL;
    mutable glm::vec3 longitudinal = DEFAULT_LONGITUDINAL;

public:
    const float &getZNear() const;
    void setZNear(const float &zNear);
    const float &getZFar() const;
    void setZFar(const float &zFar);
    const float &getFov() const;
    void setFov(const float &fov);
    const float &getAspect() const;
    void setAspect(const float &aspect);

public:
    const float &getScale() const;
    void setScale(const float &scale) const;
    const glm::vec3 &getPosition() const;
    void setPosition(const glm::vec3 &position) const;
    const glm::vec3 &getLateral() const;
    void setLateral(const glm::vec3 &lateral) const;
    const glm::vec3 &getNormal() const;
    void setNormal(const glm::vec3 &normal) const;
    const glm::vec3 &getLongitudinal() const;
    void setLongitudinal(const glm::vec3 &longitudinal) const;
    glm::mat4 getTransform() const;

    void translate(const glm::vec3 &direction, const float &distance) const;
    void rotate(const glm::vec3 &axis, const float &deg) const;
    void zoom(const float &amount) const;
};
#ifdef DEBUG
std::ostream &operator<<(std::ostream &os, const Camera &camera);
#endif
#endif // CAMERA_H
