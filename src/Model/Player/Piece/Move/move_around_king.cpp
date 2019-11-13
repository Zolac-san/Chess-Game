#include <piece.h>
#include <move_around_king.h>


MoveAroundKing::MoveAroundKing() : IMove(){
    
}

std::vector<Coordinate> MoveAroundKing::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    
    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){
            if ( !(x == 0 && y == 0) && refCoord.x+x >= 0 && refCoord.x+x < board->getLength() && refCoord.y+y >= 0 && refCoord.y+y < board->getHeight()){     
                Piece* piece = board->getSquarePiece(refCoord.x+x,refCoord.y+y);
                Coordinate coord = {refCoord.x+x,refCoord.y+y};
                if(!(piece != nullptr && piece->getColor() == myColor)){
                    //Besoinde simuler le coup
                    Piece* pieceToMem = board->getSquarePiece(coord);
                    board->setSquarePiece(coord, board->getSquarePiece(refCoord));
                    board->setSquarePiece(refCoord, nullptr);
                    board->getSquarePiece(coord)->setCoordinate(coord);

                    if(!board->isSquareCanBeAttack(coord,myColor)){

                      
                        

                        if (!haveKingEnnemyAround(coord,board,myColor)){
                        
                            if (piece ==  nullptr || piece->getColor() != myColor){
                                squaresPossible.push_back(coord);
                            }
                        }
                    }
                      //On remet 
                    board->setSquarePiece(refCoord, board->getSquarePiece(coord));
                    board->setSquarePiece(coord,pieceToMem);
                    board->getSquarePiece(refCoord)->setCoordinate(refCoord);


                }
                
            }
        }
    }

    return squaresPossible;
}


bool MoveAroundKing::haveKingEnnemyAround(Coordinate coordToCheck, IBoard* board, Color myColor){
    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){
            if (coordToCheck.x+x >= 0 && coordToCheck.x+x < board->getLength() && coordToCheck.y+y >= 0 && coordToCheck.y+y < board->getHeight()){
                // Pour gagner du temps d'exec on separe la condition pour stocker une info
                Piece* piece = board->getSquarePiece(coordToCheck.x+x,coordToCheck.y+y);
                if (piece !=  nullptr && piece->getTypePiece() == PieceType::KING && piece->getColor() != myColor){
                    return true;
                }
            }
        }
    }
    return false;
}


std::vector<Coordinate> MoveAroundKing::moveCanEat(Coordinate refCoord, IBoard* board){
    std::vector<Coordinate> squaresPossible;

    Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){
            if ( !(x == 0 && y == 0) && refCoord.x+x >= 0 && refCoord.x+x < board->getLength() && refCoord.y+y >= 0 && refCoord.y+y < board->getHeight()){     
                Piece* piece = board->getSquarePiece(refCoord.x+x,refCoord.y+y);
                Coordinate coord = {refCoord.x+x,refCoord.y+y};
                if(!(piece != nullptr && piece->getColor() == myColor)){
                    //Besoinde simuler le coup
                    Piece* pieceToMem = board->getSquarePiece(coord);
                    board->setSquarePiece(coord, board->getSquarePiece(refCoord));
                    board->setSquarePiece(refCoord, nullptr);
                    
                    board->getSquarePiece(coord)->setCoordinate(coord);
                    if(!board->isSquareCanBeAttackWithoutKing(coord,myColor)){
                      
                        

                        if (!haveKingEnnemyAround(coord,board,myColor)){
                        
                            if (piece ==  nullptr || piece->getColor() != myColor){
                                squaresPossible.push_back(coord);
                            }
                        }
                    }
                      //On remet 
                    board->setSquarePiece(refCoord, board->getSquarePiece(coord));
                    board->setSquarePiece(coord,pieceToMem);
                    board->getSquarePiece(refCoord)->setCoordinate(refCoord);

                }
                
            }
        }
    }
    return squaresPossible;
}