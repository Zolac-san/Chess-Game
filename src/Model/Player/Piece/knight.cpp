#include <knight.h>


Knight::Knight() : Piece(){
    this->pieceType = PieceType::KNIGHT;
    this->setMove(new MoveJump());
}

Knight::Knight(Color color) : Piece(color){
    this->pieceType = PieceType::KNIGHT;
    this->setMove(new MoveJump());
}

Knight::Knight(Color color, Coordinate coord) : Piece(color,coord){
    this->pieceType = PieceType::KNIGHT;
    this->setMove(new MoveJump());
}

Knight::~Knight(){
    
}

PieceType Knight::getTypePiece(){
    return this->pieceType;
}

Piece* Knight::copy(){
    Piece* newPiece = new Knight(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}