//
//  Scene.cpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 17.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "Scene.hpp"

const std::list<AbstractObject*>& Scene::getBoard() {
    return this->board;
}

void Scene::setActiveCamera(int index) {
    this->activeCamera = index;
}

void Scene::add(AbstractObject* object) {
    this->board.push_back(object);
}

void Scene::add(Camera* camera) {
    this->cameras.push_back(camera);
}

Camera* Scene::getActiveCamera() {
    return this->cameras.at(this->activeCamera);
}

Scene::~Scene() {
    for(std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); ++it) {
        delete *it;
    }
    for(std::vector<Camera*>::iterator it = this->cameras.begin(); it != this->cameras.end(); ++it) {
        delete *it;
    }
}

void Scene::reshape(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    // Reset model/view transformation matrix
    glLoadIdentity ();
    // define viewport
    glViewport(0,0, width, height);
    // set perspective
    gluPerspective(45., 1., 0.1, 2.0);
    // matrix for modelling/viewing
    glMatrixMode(GL_MODELVIEW);
}

void Scene::setShowAxes(bool showAxes) {
    this->showAxes = showAxes;
}

bool Scene::isShowAxes() {
    return this->showAxes;
}

void Scene::animate(int value) {
    // call RenderScene
    glutPostRedisplay();
    
    // call animate() on each object
    for(std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); ++it) {
        (*it)->animate(value);
    }
}

void Scene::display() {
    // Reset model/view transformation matrix
    glLoadIdentity ();
    glClearColor( Color::ORANGE );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    Camera* activeCameraPtr = this->cameras.at(this->activeCamera);
    Vector3D eye = activeCameraPtr->getCameraPosition();
    Vector3D center = activeCameraPtr->getCameraLookAt();
    Vector3D vertical = activeCameraPtr->getCameraVertical();
    
    // eye, center, up
    gluLookAt (
        eye.x, eye.y, eye.z,
        center.x, center.y, center.z,
        vertical.x, vertical.y, vertical.z
    );
    
    if (this->showAxes) {
        AxisHelper().renderAxes();
    }
    
    for(std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); ++it) {
        (*it)->draw();
    }
    
    glutSwapBuffers();
    // reset drawn state on all objects
    for(std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); ++it) {
        // check if group
        AbstractObjectGroup* group = dynamic_cast<AbstractObjectGroup*>(*it);
        if (group != nullptr) {
            group->resetDrawn();
        } else {
            (*it)->resetDrawn();
        }
    }
}
