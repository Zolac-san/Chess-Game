#include <factory_piece.h>

Piece* FactoryPiece::create(PieceType type){
	if(type == PieceType::PAWN) return new Pawn();
	else if(type == PieceType::BISHOP) return new Bishop();
	else if(type == PieceType::KNIGHT) return new Knight();
	else if(type == PieceType::ROOK) return new Rook();
	else if(type == PieceType::QUEEN) return new Queen();
	else if(type == PieceType::KING) return new King();
	else return new Piece();
}


Piece* FactoryPiece::create(PieceType type, Color color){
	if(type == PieceType::PAWN) return new Pawn(color);
	else if(type == PieceType::BISHOP) return new Bishop(color);
	else if(type == PieceType::KNIGHT) return new Knight(color);
	else if(type == PieceType::ROOK) return new Rook(color);
	else if(type == PieceType::QUEEN) return new Queen(color);
	else if(type == PieceType::KING) return new King(color);
	else return new Piece(color);
}


Piece* FactoryPiece::create(PieceType type, Color color,Coordinate coord){
	if(type == PieceType::PAWN) return new Pawn(color,coord);
	else if(type == PieceType::BISHOP) return new Bishop(color,coord);
	else if(type == PieceType::KNIGHT) return new Knight(color,coord);
	else if(type == PieceType::ROOK) return new Rook(color,coord);
	else if(type == PieceType::QUEEN) return new Queen(color,coord);
	else if(type == PieceType::KING) return new King(color,coord);
	else return new Piece(color,coord);
}