#include <piece.h>
#include <move_castling.h>

MoveCastling::MoveCastling() : IMove() {

}

std::vector<Coordinate> MoveCastling::move(Coordinate refCoord, IBoard* board){

    std::vector<Coordinate> squaresPossible;

    if(!this->moved){
            
        Color myColor = board->getSquarePiece(refCoord.x,refCoord.y)->getColor();
        
        
        bool obstacleRight = false;
        
        Piece* pieceRight = board->getSquarePiece(board->getLength()-1,refCoord.y);

        if (pieceRight != nullptr && !pieceRight->haveMove() && pieceRight->getTypePiece() == PieceType::ROOK){
            for (int i = refCoord.x+1; i < board->getLength()-1;i++){
                Coordinate coordToCheck = {i,refCoord.y};
                if ( board->getSquarePiece(i,refCoord.y) != nullptr || board->isSquareCanBeAttack(coordToCheck,myColor)) obstacleRight = true;
            }

			if(board->isSquareCanBeAttack(board->getLength()-1,refCoord.y ,myColor) || board->isSquareCanBeAttack(refCoord,myColor)) obstacleRight = true;

			if (!obstacleRight){
				Coordinate tmp = {refCoord.x+2, refCoord.y};
				squaresPossible.push_back(tmp);
			}
        }
        
        
        

        bool obstacleLeft = false;
        
        Piece* pieceLeft = board->getSquarePiece(0,refCoord.y);

        if (pieceLeft != nullptr && !pieceLeft->haveMove() && pieceLeft->getTypePiece() == PieceType::ROOK){
            for (int i = 1; i < refCoord.x;i++){
                Coordinate coordToCheck = {i,refCoord.y};
                if ( board->getSquarePiece(i,refCoord.y) != nullptr  || board->isSquareCanBeAttack(coordToCheck,myColor)) obstacleLeft = true;
            }

			if(board->isSquareCanBeAttack(0,refCoord.y ,myColor) || board->isSquareCanBeAttack(refCoord,myColor)) obstacleLeft = true;

			if (!obstacleLeft){
				Coordinate tmp = {refCoord.x-2, refCoord.y};
				squaresPossible.push_back(tmp);
			}
        }
        
    }


    return squaresPossible;
}

std::vector<Coordinate> MoveCastling::moveCanEat(Coordinate refCoord, IBoard* board){
    std::vector<Coordinate> empty;
    return empty;
}
