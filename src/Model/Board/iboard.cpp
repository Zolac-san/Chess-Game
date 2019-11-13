#include <iboard.h>

// Fichier juste pour initialiser les fonction pour les override par la suite

int IBoard::getLength()
{
    return 0;
}

int IBoard::getHeight()
{
    return 0;
}

void IBoard::setSquarePiece(int x, int y, Piece *piece)
{
}

void IBoard::setSquarePiece(Coordinate coord, Piece *piece)
{
}

Piece *IBoard::getSquarePiece(int x, int y)
{
    return nullptr;
}

Piece *IBoard::getSquarePiece(Coordinate coord)
{
    return nullptr;
}

ISquare *IBoard::getSquare(int x, int y)
{
    return nullptr;
}

ISquare *IBoard::getSquare(Coordinate coord)
{
    return nullptr;
}

void IBoard::createBoard(int height, int length)
{
}

bool IBoard::isPiece(int x, int y)
{
    return false;
}

bool IBoard::isPiece(Coordinate coord)
{
    return false;
}

bool IBoard::isSquareCanBeAttack(Coordinate coordToAttack, Color myColor)
{
    return false;
}

bool IBoard::isSquareCanBeAttack(int x, int y, Color myColor)
{
    return false;
}

Piece *IBoard::getPieceWhoAttackThisSquare(Coordinate coord, Color myColor)
{
    return nullptr;
}

bool IBoard::isSquareCanBeAttackWithoutKing(Coordinate coordToAttack, Color myColor)
{
    return false;
}

IBoard* IBoard::copy(){
	return nullptr;
}

void IBoard::deleteObject(){

}

int IBoard::howManyPieceCanAttack(Coordinate coordToAttack, Color myColor){
    return 0;
}

int IBoard::howManyPieceCanAttack(int x, int y, Color myColor){
    return 0;
}
