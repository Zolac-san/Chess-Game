#include <piece.h>
#include <move_two_forward_one_time.h>

MoveTwoForwardOneTime::MoveTwoForwardOneTime() : IMove() {

}

std::vector<Coordinate> MoveTwoForwardOneTime::move(Coordinate refCoord, IBoard* board){
    std::vector<Coordinate> squaresPossible;
    
    if(!this->moved){
        Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
        if (myColor == Color::WHITE){
            if( refCoord.y-2 >=0 ){
                Piece* piece = board->getSquarePiece(refCoord.x,refCoord.y-1);
                Piece* piece2 = board->getSquarePiece(refCoord.x,refCoord.y-2);
                if (piece == nullptr && piece2 == nullptr){
                    Coordinate tmpCoor;
                    tmpCoor.x = refCoord.x;
                    tmpCoor.y = refCoord.y-2;
                    squaresPossible.push_back(tmpCoor);
                }
            }
        }else if (myColor == Color::BLACK){
            if (refCoord.y+2 < board->getHeight()){
                Piece* piece = board->getSquarePiece(refCoord.x,refCoord.y+1);
                Piece* piece2 = board->getSquarePiece(refCoord.x,refCoord.y+2);
                if (piece == nullptr && piece2 == nullptr){
                    Coordinate tmpCoor;
                    tmpCoor.x = refCoord.x;
                    tmpCoor.y = refCoord.y+2;
                    squaresPossible.push_back(tmpCoor);
                }
            }
        }
    }

    
    return squaresPossible;
}

std::vector<Coordinate> MoveTwoForwardOneTime::moveCanEat(Coordinate refCoord, IBoard* board){
    
    std::vector<Coordinate> empty;
    return empty;
}