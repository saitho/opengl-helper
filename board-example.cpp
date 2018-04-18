#include <GL/freeglut.h>         //l‰dt alles f¸r OpenGL
#include <list>
#include <iterator>
#include "../ColorHelper.h"
#include "../Cube.h"
#include "custom_objects/MovingCube.h"

float fRotation = 315.0;
float fRotation2 = 315.0;
std::list<AbstractObject*> scene = std::list<AbstractObject*>();


void BuildScene()
{
    // right cube: rotated inside the animate method inside of MovingCube
    MovingCube* cube = new MovingCube(0.4);
    cube->rotate(45., RotateAxes::Z);
    cube->translate(0.5, 0.5, 0.5);
    scene.push_back(cube);
    
    // left cube: not animated
    Cube* cube3 = new Cube(0.3);
    cube3->translate(-0.5, -0.5, -0.5);
    scene.push_back(cube3);
    
    // center cube: rotated inside the animate function in this file
    Cube* cube2 = new Cube(0.2);
    cube2->rotate(45., RotateAxes::XZ);
    scene.push_back(cube2);
}

void Init() {
    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);
    BuildScene();
}

void RenderScene() //Zeichenfunktion
{
    // Reset model/view transformation matrix
    glLoadIdentity ();
    glClearColor( Color::ORANGE );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    // look on the scene from top left
    gluLookAt ( 0., 0., 1., 0., 0., -1., 0., 1., 0.);
    
    for(std::list<AbstractObject*>::iterator it = scene.begin(); it != scene.end(); ++it) {
        (*it)->draw();
    }
    
    glutSwapBuffers();
}

void Reshape(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    // Reset model/view transformation matrix
    glLoadIdentity ();
    // define viewport
    glViewport(0,0, width, height);
    // set perspective
    gluPerspective(90., 1., 0.1, 2.0);
    // matrix for modelling/viewing
    glMatrixMode(GL_MODELVIEW);
}



void Animate (int value)
{
    fRotation -= 0.5;
    if ( fRotation <= 0.0) {
        fRotation += 360.0;
    }
    // grab last item on the scene and rotate it...
    scene.back()->rotate(-fRotation);
    
    // call RenderScene
    glutPostRedisplay();
    
    // call animate() on each object
    for(std::list<AbstractObject*>::iterator it = scene.begin(); it != scene.end(); ++it) {
        (*it)->animate(value);
    }
    
    // call method again after 1 ms
    glutTimerFunc(1, Animate, ++value);
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );                // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH );
    glutInitWindowSize( 600, 600 );
    glutCreateWindow( "Board example" );
    glutDisplayFunc( RenderScene );
    glutReshapeFunc( Reshape );
    
    // Register TimerCallback and call it after 1ms with initial value 0
    glutTimerFunc( 1, Animate, 0);
    Init();
    glutMainLoop();
    return 0;
}
