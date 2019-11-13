#include <imove.h>

IMove::IMove(){
    moved = false;
}


bool IMove::haveMove(){
    return moved;
}

void IMove::setMoved(bool moved){
    this->moved = moved;
}

std::vector<Coordinate> IMove::moveCanEat(Coordinate refCoord, IBoard* board){
    return move(refCoord,board);
    
    
}

std::vector<Coordinate> IMove::move(Coordinate refCoord, IBoard* board){
    return std::vector<Coordinate>();
}
