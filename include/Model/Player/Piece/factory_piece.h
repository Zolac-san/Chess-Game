#ifndef FACTORY_PIECE_H
#define FACTORY_PIECE_H

#include <piece.h>
#include <pawn.h>
#include <bishop.h>
#include <knight.h>
#include <rook.h>
#include <queen.h>
#include <king.h>

/**
 * \brief Factory Piece
 * 
 * Factory permettant de creer une piece de n'importe quel type
 * 
 */
class FactoryPiece{
	public:

		/**
		 * \brief Creer une piece
		 * 
		 * Fonction qui creer un piece
		 * 
		 * \param PieceType type : type de la piece
		 * \return Piece* : piece
		 */
		static Piece* create(PieceType type);

		/**
		 * \brief Creer une piece
		 * 
		 * Fonction qui creer une piece
		 * 
		 * \param PieceType type : type de la piece
		 * \param Color color : couleur de la piece 
		 * \return Piece* : piece
		 */
		static Piece* create(PieceType type, Color color);

		/**
		 * \brief Creer une piece
		 * 
		 * Fonction qui creer une piece
		 * 
		 * \param PieceType type : type de la piece
		 * \param Color color : couleur de la piece 
		 * \param Coordinate coord : coordonée de la piece
		 * \return Piece* : piece
		 */
		static Piece* create(PieceType type, Color color,Coordinate coord);
		
};

#endif