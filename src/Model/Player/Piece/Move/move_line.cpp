#include <piece.h>
#include <move_line.h>

MoveLine::MoveLine() : IMove() {

}

std::vector<Coordinate> MoveLine::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    bool MoreCaseUp = true;
    bool MoreCaseRight = true;
    bool MoreCaseDown = true;
    bool MoreCaseLeft = true;

    int checkToXCase = 1;
    while (MoreCaseUp || MoreCaseRight || MoreCaseDown || MoreCaseLeft){
        if(MoreCaseUp && refCoord.y-checkToXCase >= 0){
            Piece* piece = board->getSquarePiece(refCoord.x, refCoord.y-checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x;
            coordToAdd.y =refCoord.y-checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseUp = false;
            }else{
                 MoreCaseUp = false;
            }
        }else{
            MoreCaseUp= false;
        }



        if(MoreCaseRight && refCoord.x+checkToXCase < board->getLength() ){
            Piece* piece = board->getSquarePiece(refCoord.x+checkToXCase , refCoord.y);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x+checkToXCase;
            coordToAdd.y =refCoord.y;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseRight = false;
            }else{
                 MoreCaseRight = false;
            }
        }else{
            MoreCaseRight = false;
        }


        if(MoreCaseDown && refCoord.y+checkToXCase < board->getHeight()){
            Piece* piece = board->getSquarePiece(refCoord.x , refCoord.y+checkToXCase);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x;
            coordToAdd.y =refCoord.y+checkToXCase;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseDown = false;
            }else{
                 MoreCaseDown = false;
            }
        }else{
            MoreCaseDown = false;
        }


        if(MoreCaseLeft && refCoord.x-checkToXCase >=0 ){
            Piece* piece = board->getSquarePiece(refCoord.x-checkToXCase , refCoord.y);
            Coordinate coordToAdd;
            coordToAdd.x = refCoord.x-checkToXCase;
            coordToAdd.y =refCoord.y;
            if (piece == nullptr){
                squaresPossible.push_back(coordToAdd);
            }else if (piece->getColor() != myColor){
                squaresPossible.push_back(coordToAdd);
                MoreCaseLeft = false;
            }else{
                 MoreCaseLeft = false;
            }
        }else{
            MoreCaseLeft = false;
        }

        checkToXCase += 1;
    }

    return squaresPossible;
}
