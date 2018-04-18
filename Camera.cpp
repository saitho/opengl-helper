//
//  Camera.cpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 17.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "Camera.hpp"

void Camera::moveBy(Vector3D point) {
    this->cameraPosition = this->cameraPosition + point;
}

void Camera::moveBy(float x, float y, float z) {
    this->moveBy(Vector3D(x, y, z));
}

void Camera::moveTo(Vector3D point) {
    this->cameraPosition = point;
}

void Camera::moveTo(float x, float y, float z) {
    this->moveTo(Vector3D(x, y, z));
}

void Camera::setVerticalVector(Vector3D point) {
    this->cameraVertical = point;
}

void Camera::setVerticalVector(float x, float y, float z) {
    this->setVerticalVector(Vector3D(x, y, z));
}

void Camera::lookAt(Vector3D point) {
    this->cameraLookAt = point;
}

void Camera::lookAt(float x, float y, float z) {
    this->lookAt(Vector3D(x, y, z));
}

void Camera::lookAtRel(Vector3D point) {
    this->cameraLookAt = this->cameraLookAt + point;
}

void Camera::lookAtRel(float x, float y, float z) {
    this->lookAtRel(Vector3D(x, y, z));
}

Vector3D Camera::getCameraPosition() {
    return this->cameraPosition;
}

Vector3D Camera::getCameraVertical() {
    return this->cameraVertical;
}

Vector3D Camera::getCameraLookAt() {
    return this->cameraLookAt;
}
