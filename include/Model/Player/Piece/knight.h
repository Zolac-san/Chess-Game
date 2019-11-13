#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>
#include <move_jump.h>


/**
 * \class Knight
 * \brief Classe représentant le cavalier
 * 
 * Cette classe représente un cavalier. Elle comprend les deplacement d'un cavalier , sa couleur et ses coordonées.
 * 
 */
class Knight : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Knight
         * 
         */
        Knight();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Knight
         * 
         * \param Color color : couleur de la piece
         */
        Knight(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Knight
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Knight(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Knight
         * 
         */
        virtual ~Knight();

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