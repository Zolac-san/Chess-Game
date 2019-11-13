#include <piece.h>
#include <move_forward.h>

MoveForward::MoveForward() : IMove() {

}

std::vector<Coordinate> MoveForward::move(Coordinate refCoord, IBoard* board){
    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    if (myColor == Color::WHITE){
        if( refCoord.y-1 >= 0){
            Piece* piece = board->getSquarePiece(refCoord.x,refCoord.y-1);
            if (piece == nullptr){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x;
                tmpCoor.y = refCoord.y-1;
                squaresPossible.push_back(tmpCoor);
            }
        }
    }else if (myColor == Color::BLACK){
        if(refCoord.y+1 < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x,refCoord.y+1);
            if (piece == nullptr){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x;
                tmpCoor.y = refCoord.y+1;
                squaresPossible.push_back(tmpCoor);
            }
        }
        
    }



    return squaresPossible;
}


std::vector<Coordinate> MoveForward::moveCanEat(Coordinate refCoord, IBoard* board){
   
    std::vector<Coordinate> empty;
    return empty;
}