//
//  Cube.cpp
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "Cube.h"

Cube::Cube(float size) {
    this->size = size;
}

void Cube::animate(int time) {
    // no animation...
}

void Cube::draw() {
    if (this->isDrawn) {
        return;
    }
    this->preDraw();
    
    glBegin(GL_POLYGON);   //Vorderseite
    glColor4f(1.0f,0.0f,0.0f,1.0f);	//ROT
    glVertex3f(-this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
    glVertex3f(+this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
    glVertex3f(+this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
    glVertex3f(-this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glEnd();
    
    
    glBegin(GL_POLYGON);   //Rechte Seite
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
    glVertex3f(+this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,1.0f,1.0f,1.0f);	//CYAN
    glVertex3f(+this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
    glVertex3f(+this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glEnd();
    
    
    glBegin(GL_POLYGON);   //Rueckseite
    glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
    glVertex3f(+this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glEnd();
    
    
    glBegin(GL_POLYGON);   //Linke Seite
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT
    glVertex3f(-this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
    glVertex3f(-this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glEnd();
    
    glBegin(GL_POLYGON);   //Deckflaeche
    glColor4f(1.0f,0.0f,1.0f,1.0f); //MAGENTA
    glVertex3f(-this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,1.0f,1.0f,1.0f); //WEISS
    glVertex3f(+this->size/2.0f,+this->size/2.0f,+this->size/2.0f);
    glColor4f(0.0f,1.0f,1.0f,1.0f); //CYAN
    glVertex3f(+this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,0.0f,1.0f,1.0f); //BLAU
    glVertex3f(-this->size/2.0f,+this->size/2.0f,-this->size/2.0f);
    glEnd();
    
    glBegin(GL_POLYGON);   //Bodenflaeche
    glColor4f(0.0f,0.0f,0.0f,1.0f); //SCHWARZ
    glVertex3f(-this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(0.0f,1.0f,0.0f,1.0f); //GRUEN
    glVertex3f(+this->size/2.0f,-this->size/2.0f,-this->size/2.0f);
    glColor4f(1.0f,1.0f,0.0f,1.0f); //GELB
    glVertex3f(+this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glColor4f(1.0f,0.0f,0.0f,1.0f); //ROT
    glVertex3f(-this->size/2.0f,-this->size/2.0f,+this->size/2.0f);
    glEnd();
    
    this->postDraw();
}
