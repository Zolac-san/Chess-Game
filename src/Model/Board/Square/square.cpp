#include <square.h>


Square::Square(int x, int y){
    this->coord.x = x;
    this->coord.y = y;
    this->piece = nullptr;
}


Square::~Square(){
  
    if(piece != nullptr) delete piece;
}

Coordinate Square::getCoordinate(){
    return this->coord;
}


void Square::setX(int x){
    this->coord.x = x;
}


void Square::setY(int y){
    this->coord.y = y;
}


int Square::getX(){
    return this->coord.x;
}



int Square::getY(){
    return this->coord.y;
}


void Square::setPiece(Piece* piece){
    this->piece = piece;
}


Piece* Square::getPiece(){
    return this->piece;
}

void Square::deleteObject(){
    delete this;
}