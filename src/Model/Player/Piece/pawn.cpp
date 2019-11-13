#include <pawn.h>


Pawn::Pawn() : Piece(){
    this->pieceType = PieceType::PAWN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveForward());
    m->addMove(new MoveTwoForwardOneTime());
    m->addMove(new EatDiagonalOneCase());
    this->setMove(m);
}

Pawn::Pawn(Color color) : Piece(color){
    this->pieceType = PieceType::PAWN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveForward());
    m->addMove(new MoveTwoForwardOneTime());
    m->addMove(new EatDiagonalOneCase());
    this->setMove(m);
}

Pawn::Pawn(Color color,Coordinate coord) : Piece(color,coord){
    this->pieceType = PieceType::PAWN;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveForward());
    m->addMove(new MoveTwoForwardOneTime());
    m->addMove(new EatDiagonalOneCase());
    this->setMove(m);
}

Pawn::~Pawn(){
    
}

PieceType Pawn::getTypePiece(){
    return this->pieceType;
}

Piece* Pawn::copy(){
    Piece* newPiece = new Pawn(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}