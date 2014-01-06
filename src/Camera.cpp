#include "Camera.h"

const float Camera::DEFAULT_Z_NEAR = 0.5f;
const float Camera::DEFAULT_Z_FAR = 100.0f;
const float Camera::DEFAULT_FOV = 75.0f;
const float Camera::DEFAULT_ASPECT = 1.0f;
const float Camera::DEFAULT_SCALE = 1.0f;
const glm::vec3 Camera::DEFAULT_POSITION = glm::vec3(0.0f, 0.0f, 0.0f);
const glm::vec3 Camera::DEFAULT_LATERAL = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 Camera::DEFAULT_NORMAL = glm::vec3(0.0f, 1.0f, 0.0f);
const glm::vec3 Camera::DEFAULT_LONGITUDINAL = glm::vec3(0.0f, 0.0f, 1.0f);

Camera::Camera() = default;

Camera::Camera(const float &_zNear,
               const float &_zFar,
               const float &_fov,
               const float &_aspect) :
            zNear(_zNear), zFar(_zFar), fov(_fov), aspect(_aspect) {}

Camera::~Camera() {
    //dtor
}


const float &Camera::getZNear() const {
    return zNear;
}

void Camera::setZNear(const float &_zNear) {
    if (_zNear > zFar)
        zNear = zFar;
    else if (_zNear < 0.0f)
        zNear = 0.0f;
    else
        zNear = _zNear;
}

const float &Camera::getZFar() const {
    return zFar;
}

void Camera::setZFar(const float &_zFar) {
    if (_zFar < zNear)
        zFar = zNear;
    else if (_zFar < 0.0f)
        zFar = 0.0f;
    else
        zFar = _zFar;
}

const float &Camera::getFov() const {
    return fov;
}

void Camera::setFov(const float &_fov) {
    if (_fov < 0.0f)
        fov = 0.0f;
    else
        fov = _fov;
}

const float &Camera::getAspect() const {
    return aspect;
}

void Camera::setAspect(const float &_aspect) {
    if (_aspect < 0.0f)
        aspect = 0.0f;
    else
        aspect = _aspect;
}

const float &Camera::getScale() const {
    return scale;
}

void Camera::setScale(const float &_scale) const {
    if (_scale < 0.0f)
        scale = 0.0f;
    else
        scale = _scale;
}

const glm::vec3 &Camera::getPosition() const {
    return position;
}

void Camera::setPosition(const glm::vec3 &_position) const {
    position = _position;
}

const glm::vec3 &Camera::getLateral() const {
    return lateral;
}

void Camera::setLateral(const glm::vec3 &_lateral) const {
    lateral = _lateral;
}

const glm::vec3 &Camera::getNormal() const {
    return normal;
}

void Camera::setNormal(const glm::vec3 &_normal) const {
    normal = _normal;
}

const glm::vec3 &Camera::getLongitudinal() const {
    return longitudinal;
}

void Camera::setLongitudinal(const glm::vec3 &_longitudinal) const {
    longitudinal = _longitudinal;
}

glm::mat4 Camera::getTransform() const {
    return glm::mat4(glm::vec4(lateral, position.x),
                glm::vec4(normal, position.y),
                glm::vec4(longitudinal, position.z),
                glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
}


void Camera::translate(const glm::vec3 &direction, const float &distance) const {
    float d = glm::length(direction);
    if (d)
        position += direction * distance / d;
}

void Camera::rotate(const glm::vec3 &axis, const float &deg) const {
    float h = glm::tan(deg / 2);

    glm::quat q(1, axis.x * h, axis.y * h, axis.z * h);
    glm::quat q_(1, -axis.x * h, -axis.y * h, -axis.z * h);

    glm::quat q_lat = q * glm::quat(0, lateral) * q_;
    lateral = glm::vec3(q_lat.x, q_lat.y, q_lat.z);

    glm::quat q_nor = q * glm::quat(0, normal) * q_;
    normal = glm::vec3(q_nor.x, q_nor.y, q_nor.z);

    if (normal.y >= 0) {
        glm::quat q_lon = q * glm::quat(0, longitudinal) * q_;
        longitudinal = glm::vec3(q_lon.x, q_lon.y, q_lon.z);

        lateral = glm::normalize(lateral);
        normal = glm::normalize(normal);
        longitudinal = glm::normalize(longitudinal);
    } else {
        normal.y = 0.01f;
        normal = glm::normalize(normal);
        lateral = glm::normalize(lateral);
        longitudinal = glm::cross(lateral, normal);
    }
}

void Camera::zoom(const float &amount) const {
    setScale(scale + amount);
}

#ifdef DEBUG
std::ostream &operator<<(std::ostream &os, const Camera &camera) {
    os << "LAT: <" << camera.lateral.x << ", " << camera.lateral.y << ", " << camera.lateral.z << ">" << std::endl
       << "NOR: <" << camera.normal.x << ", " << camera.normal.y << ", " << camera.normal.z << ">" << std::endl
       << "LON: <" << camera.longitudinal.x << ", " << camera.longitudinal.y << ", " << camera.longitudinal.z << ">" << std::endl;
    return os;
}
#endif
