/*-----------------------------------------------------------------------------
COPYRIGHT NOTICE

Camera.h
    Used as an input to a vertex shader to create the illusion of looking
    through a camera in 3D space.
-----------------------------------------------------------------------------*/

#ifndef CAMERA_H
#define CAMERA_H

#include "GraphicsCommon.h"

class Camera {
#ifndef NDEBUG
    friend std::ostream &operator<<(std::ostream &os, const Camera &camera);
#endif

public:
    /**
     *
     */
    static const GLVector3 ORIGIN;

    /**
     *
     */
    static const GLVector3 X_STD;

    /**
     *
     */
     static const GLVector3 Y_STD;

    /**
     *
     */
    static const GLVector3 Z_STD;

public:
    /**
     * Constructs a Camera with default parameters.
     */
    Camera();

    /**
     * Constructs a Camera with given parameters.
     *
     * @param zNear -
     * @param zFar -
     * @param fov -
     * @param aspect -
     */
    Camera(const float &zNear,
           const float &zFar,
           const float &fov,
           const float &aspect);

    /**
     * Constructs a Camera with the given parameters.
     *
     * @param zNear -
     * @param zFar -
     * @param fov -
     * @param aspect -
     * @param scale -
     * @param position -
     * @param xAxis -
     * @param yAxis -
     * @param zAxis -
     */
    Camera(const float &zNear,
           const float &zFar,
           const float &fov,
           const float &aspect,
           const float &scale,
           const GLVector3 &position,
           const GLVector3 &xAxis,
           const GLVector3 &yAxis,
           const GLVector3 &zAxis);

    /**
     * Constructs a copy of a Camera.
     */
    Camera(const Camera &src);

    /**
     * Sets this Camera as a copy of the given Camera.
     *
     * @return This Camera after copy operation.
     */
    Camera &operator=(const Camera &src);

    /**
     * Destroys the Camera.
     */
    virtual ~Camera();

protected:
    /**
     * The near clip plane's z-coordinate.
     * Strictly greater than zero and less than Camera::zFar.
     */
    float zNear;

    /**
     * The far clip plane's z-coordinate.
     * Strictly greater than zero and greater than Camera::zNear.
     */
    float zFar;

    /**
     * The vertical field of view of the Camera in degrees.
     * Greater than or equal to zero and strictly less than 180.0.
     */
    float fov;

    /**
     * The ratio, FOVx : FOVy, where FOVx is the horizontal field of view,
     * and FOVy is the vertical field of view (i.e. Camera::fov).
     * Greater than or equal to zero.
     */
    float aspect;

    /**
     * The zoom scale of the Camera.
     * Greater than or equal to zero.
     */
    float scale;

    /**
     * The world coordinate of the Camera.
     */
    GLVector3 position;

    /**
     * The x rotation axis of the Camera.
     * Positive multiples of the axis are directed to right.
     */
    GLVector3 xAxis;

    /**
     * The y rotation axis of the Camera.
     * Positive multiples of the axis are directed upward.
     */
    GLVector3 yAxis;

    /**
     * The z rotation axis of the Camera.
     * Positive multiples of the axis are directed out of the screen.
     */
    GLVector3 zAxis;

public:
    /**
     *
     */
    const float &getZNear() const;

    /**
     *
     */
    void setZNear(const float &zNear);

    /**
     *
     */
    const float &getZFar() const;

    /**
     *
     */
    void setZFar(const float &zFar);

    /**
     *
     */
    const float &getFov() const;

    /**
     *
     */
    void setFov(const float &fov);

    /**
     *
     */
    const float &getAspect() const;

    /**
     *
     */
    void setAspect(const float &aspect);

public:
    /**
     *
     */
    const float &getScale() const;

    /**
     *
     */
    void setScale(const float &scale);

    /**
     *
     */
    const GLVector3 &getPosition() const;

    /**
     *
     */
    void setPosition(const GLVector3 &position);

    /**
     *
     */
    const GLVector3 &getXAxis() const;

    /**
     *
     */
    void setXAxis(const GLVector3 &xAxis);

    /**
     *
     */
    const GLVector3 &getYAxis() const;

    /**
     *
     */
    void setYAxis(const GLVector3 &yAxis);

    /**
     *
     */
    const GLVector3 &getZAxis() const;

    /**
     *
     */
    void setZAxis(const GLVector3 &zAxis);

    /**
     *
     */
    glm::mat4 getTransform() const;


    /**
     *
     */
    void translate(const GLVector3 &direction, const float &distance);

    /**
     *
     */
    void rotate(const GLVector3 &axis, const float &deg);

    /**
     *
     */
    void zoom(const float &amount);
};
#ifndef NDEBUG
std::ostream &operator<<(std::ostream &os, const Camera &camera);
#endif
#endif // CAMERA_H
