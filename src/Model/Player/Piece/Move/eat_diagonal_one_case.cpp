#include <piece.h>
#include <eat_diagonal_one_case.h>

EatDiagonalOneCase::EatDiagonalOneCase() : IMove() {

}

std::vector<Coordinate> EatDiagonalOneCase::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    if (myColor == Color::WHITE){
        if (refCoord.x-1 >= 0 && refCoord.y-1 >=0){
            Piece* piece = board->getSquarePiece(refCoord.x-1,refCoord.y-1);
            if (piece != nullptr && piece->getColor() != myColor){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x-1;
                tmpCoor.y = refCoord.y-1;
                squaresPossible.push_back(tmpCoor);
            }
        }

        if (refCoord.x+1 < board->getLength() && refCoord.y-1 >=0){
            Piece* piece = board->getSquarePiece(refCoord.x+1,refCoord.y-1);
            if (piece != nullptr && piece->getColor() != myColor){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x+1;
                tmpCoor.y = refCoord.y-1;
                squaresPossible.push_back(tmpCoor);
            }
        }
    }else if (myColor == Color::BLACK){
        if (refCoord.x-1 >= 0 && refCoord.y+1 < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x-1,refCoord.y+1);
            if (piece != nullptr && piece->getColor() != myColor){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x-1;
                tmpCoor.y = refCoord.y+1;
                squaresPossible.push_back(tmpCoor);
            }
        }

        if (refCoord.x+1 < board->getLength() && refCoord.y+1 < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x+1,refCoord.y+1);
            if (piece != nullptr && piece->getColor() != myColor){
                Coordinate tmpCoor;
                tmpCoor.x = refCoord.x+1;
                tmpCoor.y = refCoord.y+1;
                squaresPossible.push_back(tmpCoor);
            }
        }
    }



    return squaresPossible;
}

std::vector<Coordinate> EatDiagonalOneCase::moveCanEat(Coordinate refCoord, IBoard* board){
    
    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    if (myColor == Color::WHITE){
        if (refCoord.x-1 >= 0 && refCoord.y-1 >=0){
            
            Coordinate tmpCoor;
            tmpCoor.x = refCoord.x-1;
            tmpCoor.y = refCoord.y-1;
            
            squaresPossible.push_back(tmpCoor);
            
        }

        if (refCoord.x+1 < board->getLength() && refCoord.y-1 >=0){
            
            Coordinate tmpCoor;
            tmpCoor.x = refCoord.x+1;
            tmpCoor.y = refCoord.y-1;
            squaresPossible.push_back(tmpCoor);
            
        }
    }else if (myColor == Color::BLACK){
        if (refCoord.x-1 >= 0 && refCoord.y+1 < board->getHeight()){
            
            Coordinate tmpCoor;
            tmpCoor.x = refCoord.x-1;
            tmpCoor.y = refCoord.y+1;
            squaresPossible.push_back(tmpCoor);
            
        }

        if (refCoord.x+1 < board->getLength() && refCoord.y+1 < board->getHeight()){
            
            Coordinate tmpCoor;
            tmpCoor.x = refCoord.x+1;
            tmpCoor.y = refCoord.y+1;
            squaresPossible.push_back(tmpCoor);
            
        }
    }


    
    return squaresPossible;
}
