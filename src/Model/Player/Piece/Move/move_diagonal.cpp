#include <piece.h>
#include <move_diagonal.h>

MoveDiagonal::MoveDiagonal() : IMove() {

}

std::vector<Coordinate> MoveDiagonal::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    bool MoreCaseUpLeft = true;
    bool MoreCaseUpRight = true;
    bool MoreCaseDownLeft = true;
    bool MoreCaseDownRight = true;

    int checkToXCase = 1;
    while (MoreCaseUpLeft || MoreCaseUpRight || MoreCaseDownLeft || MoreCaseDownRight){
        if(MoreCaseUpLeft && refCoord.x-checkToXCase >= 0 && refCoord.y-checkToXCase >= 0){
            Piece* piece = board->getSquarePiece(refCoord.x-checkToXCase , refCoord.y-checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x-checkToXCase;
            coordToAdd.y =refCoord.y-checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseUpLeft = false;
            }else{
                 MoreCaseUpLeft = false;
            }
        }else{
            MoreCaseUpLeft = false;
        }



        if(MoreCaseUpRight && refCoord.x+checkToXCase < board->getLength() && refCoord.y-checkToXCase >= 0){
            Piece* piece = board->getSquarePiece(refCoord.x+checkToXCase , refCoord.y-checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x+checkToXCase;
            coordToAdd.y =refCoord.y-checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseUpRight = false;
            }else{
                 MoreCaseUpRight = false;
            }
        }else{
            MoreCaseUpRight = false;
        }


        if(MoreCaseDownLeft && refCoord.x-checkToXCase >= 0 && refCoord.y+checkToXCase < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x-checkToXCase , refCoord.y+checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x-checkToXCase;
            coordToAdd.y = refCoord.y+checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseDownLeft = false;
            }else{
                 MoreCaseDownLeft = false;
            }
        }else{
            MoreCaseDownLeft = false;
        }


        if(MoreCaseDownRight && refCoord.x+checkToXCase < board->getLength() && refCoord.y+checkToXCase < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x+checkToXCase , refCoord.y+checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x+checkToXCase;
            coordToAdd.y =refCoord.y+checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseDownRight = false;
            }else{
                 MoreCaseDownRight = false;
            }
        }else{
            MoreCaseDownRight = false;
        }

        checkToXCase += 1;
    }

    return squaresPossible;
}
