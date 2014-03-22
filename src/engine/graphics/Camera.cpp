#include "Camera.h"

const GLVector3 Camera::ORIGIN = GLVector3(0.0f, 0.0f, 5.0f);
const GLVector3 Camera::X_STD = GLVector3(1.0f, 0.0f, 0.0f);
const GLVector3 Camera::Y_STD = GLVector3(0.0f, 1.0f, 0.0f);
const GLVector3 Camera::Z_STD = GLVector3(0.0f, 0.0f, 1.0f);

Camera::Camera() :
    Camera(0.5f,
           100.0f,
           75.0f,
           1.25f) {}

Camera::Camera(const float &zNear,
               const float &zFar,
               const float &fov,
               const float &aspect) :
    Camera(zNear,
           zFar,
           fov,
           aspect,
           1.0f,
           GLVector3(0.0f, 0.0f, 0.0f),
           GLVector3(1.0f, 0.0f, 0.0f),
           GLVector3(0.0f, 1.0f, 0.0f),
           GLVector3(0.0f, 0.0f, 1.0f)) {}

Camera::Camera(const float &zNear,
               const float &zFar,
               const float &fov,
               const float &aspect,
               const float &scale,
               const GLVector3 &position,
               const GLVector3 &xAxis,
               const GLVector3 &yAxis,
               const GLVector3 &zAxis) :
    zNear(zNear),
    zFar(zFar),
    fov(fov),
    aspect(aspect),
    scale(scale),
    position(position),
    xAxis(xAxis),
    yAxis(yAxis),
    zAxis(zAxis) {}

Camera::Camera(const Camera &src) :
    Camera(src.zNear,
           src.zFar,
           src.fov,
           src.aspect,
           src.scale,
           src.position,
           src.xAxis,
           src.yAxis,
           src.zAxis) {}

Camera &Camera::operator=(const Camera &src) {
    zNear = src.zNear;
    zFar = src.zFar;
    fov = src.fov;
    aspect = src.aspect;
    scale = src.scale;
    position = src.position;
    xAxis = src.xAxis;
    yAxis = src.yAxis;
    zAxis = src.zAxis;

    return *this;
}

Camera::~Camera() {}


const float &Camera::getZNear() const {
    return zNear;
}

void Camera::setZNear(const float &zNear) {
    if (zNear > zFar)
        this->zNear = zFar;
    else if (zNear < 0.0f)
        this->zNear = 0.0f;
    else
        this->zNear = zNear;
}

const float &Camera::getZFar() const {
    return zFar;
}

void Camera::setZFar(const float &zFar) {
    if (zFar < zNear)
        this->zFar = zNear;
    else if (zFar < 0.0f)
        this->zFar = 0.0f;
    else
        this->zFar = zFar;
}

const float &Camera::getFov() const {
    return fov;
}

void Camera::setFov(const float &fov) {
    if (fov < 0.0f)
        this->fov = 0.0f;
    else
        this->fov = fov;
}

const float &Camera::getAspect() const {
    return aspect;
}

void Camera::setAspect(const float &aspect) {
    if (aspect < 0.0f)
        this->aspect = 0.0f;
    else
        this->aspect = aspect;
}

const float &Camera::getScale() const {
    return scale;
}

void Camera::setScale(const float &scale) {
    if (scale < 0.0f)
        this->scale = 0.0f;
    else
        this->scale = scale;
}

const GLVector3 &Camera::getPosition() const {
    return position;
}

void Camera::setPosition(const GLVector3 &position) {
    this->position = position;
}

const GLVector3 &Camera::getXAxis() const {
    return xAxis;
}

void Camera::setXAxis(const GLVector3 &xAxis) {
    this->xAxis = xAxis;
}

const GLVector3 &Camera::getYAxis() const {
    return yAxis;
}

void Camera::setYAxis(const GLVector3 &yAxis) {
    this->yAxis = yAxis;
}

const GLVector3 &Camera::getZAxis() const {
    return zAxis;
}

void Camera::setZAxis(const GLVector3 &zAxis) {
    this->zAxis = zAxis;
}

glm::mat4 Camera::getTransform() const {
    return glm::mat4(glm::vec4(xAxis, position.x),
                glm::vec4(yAxis, position.y),
                glm::vec4(zAxis, position.z),
                glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
}


void Camera::translate(const GLVector3 &direction, const float &distance) {
    float d = glm::length(direction);
    if (d)
        position += direction * distance / d;
    //std::cout << position.x << " " << position.y << " " << position.z << std::endl;
}

void Camera::rotate(const GLVector3 &axis, const float &deg) {
    float h = glm::tan(deg / 2);

    GLQuaternion q(1, axis.x * h, axis.y * h, axis.z * h);
    GLQuaternion q_(1, -axis.x * h, -axis.y * h, -axis.z * h);

    GLQuaternion q_xAxis = q * GLQuaternion(0, xAxis) * q_;
    xAxis = GLVector3(q_xAxis.x, q_xAxis.y, q_xAxis.z);

    GLQuaternion q_yAxis = q * GLQuaternion(0, yAxis) * q_;
    yAxis = GLVector3(q_yAxis.x, q_yAxis.y, q_yAxis.z);

    GLQuaternion q_zAxis = q * GLQuaternion(0, zAxis) * q_;
    zAxis = GLVector3(q_zAxis.x, q_zAxis.y, q_zAxis.z);

    xAxis = glm::normalize(xAxis);
    yAxis = glm::normalize(yAxis);
    zAxis = glm::normalize(zAxis);
/*
    if (normal.y >= 0) {
        GLQuaternion q_lon = q * GLQuaternion(0, longitudinal) * q_;
        longitudinal = GLVector3(q_lon.x, q_lon.y, q_lon.z);

        lateral = glm::normalize(lateral);
        normal = glm::normalize(normal);
        longitudinal = glm::normalize(longitudinal);
    } else {
        normal.y = 0.01f;
        normal = glm::normalize(normal);
        lateral = glm::normalize(lateral);
        longitudinal = glm::cross(lateral, normal);
    }*/
}

void Camera::zoom(const float &amount) {
    setScale(scale + amount);
}

#define NDEBUG
#ifndef NDEBUG
std::ostream &operator<<(std::ostream &os, const Camera &camera) {
    /*os << "POS: <" << camera.position.x << ", " << camera.position.y << ", " << camera.position.z << ">" << std::endl
       << "LAT: <" << camera.xAxis.x << ", " << camera.xAxis.y << ", " << camera.xAxis.z << ">" << std::endl
       << "NOR: <" << camera.yAxis.x << ", " << camera.yAxis.y << ", " << camera.yAxis.z << ">" << std::endl
       << "LON: <" << camera.zAxis.x << ", " << camera.zAxis.y << ", " << camera.zAxis.z << ">" << std::endl;*/
    os << "FAR:     " << camera.zFar
       << "NEAR:    " << camera.zNear
       << "FOV:     " << camera.fov
       << "ASPECT:  " << camera.aspect;
    return os;
}
#endif
#undef NDEBUG
