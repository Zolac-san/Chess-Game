#include <rook.h>


Rook::Rook() : Piece(){
    this->pieceType = PieceType::ROOK;
    this->setMove(new MoveLine());
}


Rook::Rook(Color color) : Piece(color){
    this->pieceType = PieceType::ROOK;
    this->setMove(new MoveLine());
}


Rook::Rook(Color color,Coordinate coord) : Piece(color,coord){
    this->pieceType = PieceType::ROOK;
    this->setMove(new MoveLine());
}

Rook::~Rook(){
    
}

PieceType Rook::getTypePiece(){
    return this->pieceType;
}

Piece* Rook::copy(){
    Piece* newPiece = new Rook(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}