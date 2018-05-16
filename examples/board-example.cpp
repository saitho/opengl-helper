#include <GL/freeglut.h>         //l‰dt alles f¸r OpenGL
#include "../ColorHelper.h"
#include "../Cube.h"
#include "Scene.hpp"

Scene scene = Scene();

// Add objects to scene
void BuildScene()
{
    // Cameras
    
    // front
    Camera* camera = new Camera();
    camera->moveTo(0, 0, 1);
    camera->lookAt(0, 0, -1);
    scene.add(camera);
    
    // right
    Camera* camera2 = new Camera();
    camera2->moveTo(1, 0, 0);
    camera2->lookAt(-1, 0, 0);
    scene.add(camera2);
    
    // center cube: rotated inside the animate function in this file
    Cube* cube2 = new Cube(0.2);
    cube2->translate(.1, .1, 0);
    cube2->rotate(45., RotateAxes::XZ);
    scene.add(cube2);
    
    // left cube
    Cube* cube3 = new Cube(0.3);
    cube3->translate(-.1, -.1, 0);
    cube3->clipTo(cube2);
    scene.add(cube3);
    
    // left cube
    Cube* cube4 = new Cube(0.1);
    cube4->translate(-.1, -.1, .15);
    cube4->clipTo(cube3);
    scene.add(cube4);
}

void DisplayFunc() {
    scene.display();
}

void ReshapeFunc(int width, int height) {
    scene.reshape(width, height);
}

void TimerFunc(int value)
{
    scene.animate(value);
    glutTimerFunc(1, TimerFunc, ++value); // call method again after 1 ms
}

void KeyboardFunc(unsigned char c, int a, int b) {
    switch(c) {
        case '1':
            scene.setActiveCamera(0);
            break;
        case '2':
            scene.setActiveCamera(1);
            break;
        case '3':
            scene.setActiveCamera(2);
            break;
    }
}

int main(int argc, char **argv)
{
    BuildScene();
    
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH );
    glutInitWindowSize( 600, 600 );
    glutCreateWindow( "Example" );
    glutDisplayFunc( DisplayFunc );
    glutReshapeFunc( ReshapeFunc );
    glutKeyboardFunc( KeyboardFunc );
    
    // Register TimerCallback and call it after 1ms with initial value 0
    glutTimerFunc( 1, TimerFunc, 0);
    
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    glutMainLoop();
    return 0;
}
