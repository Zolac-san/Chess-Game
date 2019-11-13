#include <bishop.h>


Bishop::Bishop() : Piece(){
    this->pieceType = PieceType::BISHOP;
    this->setMove(new MoveDiagonal());
}

Bishop::Bishop(Color color) : Piece(color){
    this->pieceType = PieceType::BISHOP;
    this->setMove(new MoveDiagonal());
}

Bishop::Bishop(Color color,Coordinate coord) : Piece(color,coord){
    this->pieceType = PieceType::BISHOP;
    this->setMove(new MoveDiagonal());
}

Bishop::~Bishop(){
    
}

PieceType Bishop::getTypePiece(){
    return this->pieceType;
}

Piece* Bishop::copy(){
    Piece* newPiece = new Bishop(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}