#include <piece.h>


Piece::Piece(){
    setColor(Color::NONE);
    Coordinate coord = {0,0};
    setCoordinate(coord);
}

Piece::Piece(Color color){
    setColor(color);
    Coordinate coord = {0,0};
    setCoordinate(coord);
}

Piece::Piece(Color color,Coordinate coord){
    setColor(color);
    setCoordinate(coord);
}
        

Piece::~Piece(){
    delete movementType;
}

bool Piece::haveMove(){
    return this->movementType->haveMove();
}

void Piece::setMoved(bool moved){
    this->movementType->setMoved(moved);
}


std::vector<Coordinate> Piece::move(Coordinate refCoord,IBoard* board){
    return this->movementType->move(refCoord,board);
}

std::vector<Coordinate> Piece::move(IBoard* board){
    
    return this->movementType->move(this->coord,board);
}


void Piece::setColor(Color color){
    this->color = color;
}
Color Piece::getColor(){
    return this->color;
}

void Piece::setCoordinate(Coordinate coord){
    this->coord = coord;
}

void Piece::setCoordinate(int x, int y){
    Coordinate tmp = {x,y};
    this->coord = tmp;
}

Coordinate Piece::getCoordinate(){
    return this->coord;
}


void Piece::setMove(IMove* movementType){
    this->movementType = movementType;
}




IMove* Piece::getMove(){
    return this->movementType;
}


std::vector<Coordinate> Piece::moveCanEat(Coordinate refCoord,IBoard* board){
    return this->movementType->moveCanEat(refCoord,board);
}

std::vector<Coordinate> Piece::moveCanEat(IBoard* board){
    return this->movementType->moveCanEat(this->coord,board);
}

Piece* Piece::copy(){
	Piece* newPiece = new Piece(this->getColor(),this->getCoordinate());
	newPiece->setMoved(this->haveMove());
    return newPiece;
}

PieceType Piece::getTypePiece(){
    return PieceType::UNKNOW;
}