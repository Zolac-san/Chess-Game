#include <piece.h>
#include <move_jump.h>

MoveJump::MoveJump() : IMove() {

}

std::vector<Coordinate> MoveJump::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    
    Coordinate coordTL = {refCoord.x-1 , refCoord.y-2};
    if (canMoveOn(coordTL,board,myColor)) squaresPossible.push_back(coordTL);

    Coordinate coordTR = {refCoord.x+1 , refCoord.y-2};
    if (canMoveOn(coordTR,board,myColor)) squaresPossible.push_back(coordTR);

    Coordinate coordRT = {refCoord.x+2 , refCoord.y-1};
    if (canMoveOn(coordRT,board,myColor)) squaresPossible.push_back(coordRT);

    Coordinate coordRD = {refCoord.x+2 , refCoord.y+1};
    if (canMoveOn(coordRD,board,myColor)) squaresPossible.push_back(coordRD);

    Coordinate coordDR = {refCoord.x+1 , refCoord.y+2};
    if (canMoveOn(coordDR,board,myColor)) squaresPossible.push_back(coordDR);

    Coordinate coordDL = {refCoord.x-1 , refCoord.y+2};
    if (canMoveOn(coordDL,board,myColor)) squaresPossible.push_back(coordDL);

    Coordinate coordLD = {refCoord.x-2 , refCoord.y+1};
    if (canMoveOn(coordLD,board,myColor)) squaresPossible.push_back(coordLD);

    Coordinate coordLT = {refCoord.x-2 , refCoord.y-1};
    if (canMoveOn(coordLT,board,myColor)) squaresPossible.push_back(coordLT);
    
    return squaresPossible;
}



bool MoveJump::canMoveOn(Coordinate coordToTest, IBoard* board, Color myColor){
    if( coordToTest.x >=0 && coordToTest.x < board->getLength() && coordToTest.y >=0 && coordToTest.y < board->getHeight()){
        Piece* piece = board->getSquarePiece(coordToTest.x,coordToTest.y);
        if (piece == nullptr || piece->getColor() != myColor){
            return true;
        }
    }
    return false;
}