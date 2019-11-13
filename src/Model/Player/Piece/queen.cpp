#include <queen.h>


Queen::Queen() : Piece(){
    this->pieceType = PieceType::QUEEN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveDiagonal());
    m->addMove(new MoveLine());
    this->setMove(m);
}

Queen::Queen(Color color) : Piece(color){
    this->pieceType = PieceType::QUEEN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveDiagonal());
    m->addMove(new MoveLine());
    this->setMove(m);
}

Queen::Queen(Color color, Coordinate coord) : Piece(color,coord){

    this->pieceType = PieceType::QUEEN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveDiagonal());
    m->addMove(new MoveLine());
    this->setMove(m);
}

Queen::~Queen(){
    
}

PieceType Queen::getTypePiece(){
    return this->pieceType;
}

Piece* Queen::copy(){
    Piece* newPiece = new Queen(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}