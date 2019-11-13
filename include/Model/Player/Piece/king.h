#ifndef KING_H
#define KING_H

#include <piece.h>
#include <composite_move.h>
#include <move_around_king.h>
#include <move_castling.h>


/**
 * \class King
 * \brief Classe représentant le roi
 * 
 * Cette classe représente un roi. Elle comprend les deplacement d'un roi , sa couleur et ses coordonées.
 * 
 */
class King : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe King
         * 
         */
        King();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe King
         * 
         * \param Color color : couleur de la piece
         */
        King(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe King
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        King(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe King
         * 
         */
        virtual ~King();

        /**
         * \brief Renvoie le type de la piece
         * 
         * Methode qui renvoie le type de la piece
         * 
         * \return PieceType : type de la piece
         */
        PieceType getTypePiece() override;

        /**
         * \brief Copie la piece
         * 
         * Moethode qui copie la piece
         * 
         * \return Piece* : copie de la piece
         */
        Piece* copy() override;
        
};

#endif