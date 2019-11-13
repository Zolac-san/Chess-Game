#include <king.h>


King::King() : Piece(){
    this->pieceType = PieceType::KING;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveAroundKing());
    m->addMove(new MoveCastling());
    this->setMove(m);
}


King::King(Color color) : Piece(color){
    this->pieceType = PieceType::KING;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveAroundKing());
    m->addMove(new MoveCastling());
    this->setMove(m);
}


King::King(Color color,Coordinate coord) : Piece(color,coord){
    this->pieceType = PieceType::KING;
    CompositeMove* m = new CompositeMove();
    m->addMove(new MoveAroundKing());
    m->addMove(new MoveCastling());
    this->setMove(m);
}

King::~King(){
    
}

PieceType King::getTypePiece(){
    return this->pieceType;
}

Piece* King::copy(){
    Piece* newPiece = new King(this->getColor(),this->getCoordinate());
    newPiece->setMoved(this->haveMove());
    return newPiece;
}