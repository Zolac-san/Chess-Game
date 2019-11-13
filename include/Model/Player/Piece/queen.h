#ifndef QUEEN_H
#define QUEEN_H

#include <piece.h>
#include <composite_move.h>
#include <move_line.h>
#include <move_diagonal.h>

/**
 * \class Queen
 * \brief Classe représentant la reine
 * 
 * Cette classe représente une reine. Elle comprend les deplacement d'une reine , sa couleur et ses coordonées.
 * 
 */
class Queen : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Queen
         * 
         */
        Queen();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Queen
         * 
         * \param Color color : couleur de la piece
         */
        Queen(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Queen
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Queen(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Queen
         * 
         */
        virtual ~Queen();

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