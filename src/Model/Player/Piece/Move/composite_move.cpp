#include <composite_move.h>


CompositeMove::CompositeMove() : ICompositeMove(){

}


CompositeMove::CompositeMove(IMove* oneMove) : ICompositeMove(){
    this->moves.push_back(oneMove);

}


CompositeMove::CompositeMove(std::vector<IMove*> moves) : ICompositeMove(){
    this->moves = moves;
    
}

void CompositeMove::addMove(IMove* moveToAdd){
    this->moves.push_back(moveToAdd);
}

std::vector<Coordinate> CompositeMove::move(Coordinate refCoord, IBoard* board){
    std::vector<Coordinate> allSquares;
    for (unsigned int i = 0;i < this->moves.size();i++){
        std::vector<Coordinate> tmpSquares = this->moves[i]->move(refCoord,board);
        for (unsigned int j = 0; j < tmpSquares.size();j++){
            allSquares.push_back(tmpSquares[j]);
        }
        
    }
    return allSquares;
}

bool CompositeMove::haveMove(){
    return this->moved;
}


void CompositeMove::setMoved(bool moved){
    this->moved = moved;
    for (unsigned int i = 0;i < this->moves.size();i++){
        this->moves[i]->setMoved(moved);
    }

}


std::vector<Coordinate> CompositeMove::moveCanEat(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> allSquares;
    for (unsigned int i = 0;i < this->moves.size();i++){
        
        std::vector<Coordinate> tmpSquares = this->moves[i]->moveCanEat(refCoord,board);
        for (unsigned int j = 0; j < tmpSquares.size();j++){
            allSquares.push_back(tmpSquares[j]);
        }
        
    }

    return allSquares;
}