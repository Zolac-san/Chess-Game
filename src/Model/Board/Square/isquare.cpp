#include <isquare.h>

// Fichier juste pour initialiser les fonction pour les override par la suite

Coordinate ISquare::getCoordinate(){
    return Coordinate{};
}

void ISquare::setX(int x){

}

void ISquare::setY(int y){

}

int ISquare::getX(){
    return 0;
}

int ISquare::getY(){
    return 0;
}

void ISquare::setPiece(Piece* piece){

}

Piece* ISquare::getPiece(){
    return nullptr;
}

void ISquare::deleteObject(){
    
}