#include <board.h>


Board::Board(){

}

Board::Board(int height, int length){
    createBoard(height,length);
}

Board::~Board(){

    for(unsigned int i = 0; i < squares.size(); i++) this->squares[i]->deleteObject();
    this->squares.clear();
}

void Board::createBoard(int height, int length){
    this->height = height;
    this->length = length;

    for (int y = 0; y < height;y++){
        for (int x = 0 ; x < length; x++){
            this->squares.push_back(FactorySquare::create(x,y));
        }
    }
}

ISquare* Board::getSquare(int x, int y){
    for (unsigned int i = 0 ; i < this->squares.size();i++){
        if (squares[i]->getX() == x && squares[i]->getY() == y) return squares[i];
    }
    return nullptr;
}

ISquare* Board::getSquare(Coordinate coord){
    for (unsigned int i = 0 ; i < this->squares.size();i++){
        if (squares[i]->getCoordinate() == coord) return squares[i];
    }
    return nullptr;
}

void Board::setSquarePiece(int x, int y, Piece* piece){
    this->getSquare(x,y)->setPiece(piece);
}

void Board::setSquarePiece(Coordinate coord, Piece* piece){
    this->getSquare(coord)->setPiece(piece);
}


Piece* Board::getSquarePiece(int x, int y){
    return this->getSquare(x,y)->getPiece();
}

Piece* Board::getSquarePiece(Coordinate coord){
   
    return this->getSquare(coord)->getPiece();
}


bool Board::isPiece(int x, int y){
    return this->getSquare(x,y)->getPiece() != nullptr;
}

bool Board::isPiece(Coordinate coord){
    return this->getSquare(coord)->getPiece() != nullptr;
}

int Board::getLength(){
    return this->length;
}


int Board::getHeight(){
    return this->height;
}



bool Board::isSquareCanBeAttack(Coordinate coordToAttack, Color myColor){
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
                     
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j] == coordToAttack){
                    return true;
                }
            }

        }
    }
    return false;
}


bool Board::isSquareCanBeAttack(int x, int y, Color myColor){
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j].x == x && tmp[j].y == y){
                    return true;
                }
            }
        }
    }
    return false;
}


int Board::howManyPieceCanAttack(Coordinate coordToAttack, Color myColor){
    int nbPieceAttack = 0;
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
                     
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j] == coordToAttack){
                    nbPieceAttack++;
                }
            }

        }
    }
    return nbPieceAttack;
}

int Board::howManyPieceCanAttack(int x, int y, Color myColor){
    int nbPieceAttack = 0;
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j].x == x && tmp[j].y == y){
                    nbPieceAttack++;
                }
            }
        }
    }
    return nbPieceAttack;
}


Piece* Board::getPieceWhoAttackThisSquare(Coordinate coord, Color myColor){
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
                     
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j] == coord){
                    return squares[i]->getPiece();
                }
            }

        }
    }
    return nullptr;
}


bool Board::isSquareCanBeAttackWithoutKing(Coordinate coordToAttack, Color myColor){
    for (unsigned int i = 0; i < squares.size();i++){
        if (squares[i]->getPiece() != nullptr && squares[i]->getPiece()->getColor() != myColor && squares[i]->getPiece()->getTypePiece() != PieceType::KING){
            std::vector<Coordinate> tmp = squares[i]->getPiece()->moveCanEat(squares[i]->getCoordinate(),this);
            for(unsigned int j = 0; j <tmp.size();j++){
                if(tmp[j] == coordToAttack){
                    return true;
                }
            }
        }
    }
    return false;
}


IBoard* Board::copy(){
    IBoard* boardCopy = new Board(this->getHeight(), this->getLength());
    // Vrai copy
    for (int y = 0; y < this->getHeight(); y++){
        for (int x = 0; x < this->getLength(); x++){
             if(this->isPiece(x,y)) boardCopy->setSquarePiece(x,y,this->getSquarePiece(x,y)->copy());
        }
    }
    return boardCopy;
}


void Board::deleteObject(){
    delete this;
}