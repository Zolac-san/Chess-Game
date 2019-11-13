#ifndef PAWN_H
#define PAWN_H

#include <piece.h>
#include <composite_move.h>
#include <move_forward.h>
#include <move_two_forward_one_time.h>
#include <eat_diagonal_one_case.h>

/**
 * \class Pawn
 * \brief Classe représentant le pion
 * 
 * Cette classe représente un pion. Elle comprend les deplacement d'un pion , sa couleur et ses coordonées.
 * 
 */
class Pawn : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Pawn
         * 
         */
        Pawn();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Pawn
         * 
         * \param Color color : couleur de la piece
         */
        Pawn(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Pawn
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Pawn(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Pawn
         * 
         */
        virtual ~Pawn();

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