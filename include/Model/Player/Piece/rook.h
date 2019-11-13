#ifndef ROOK_H
#define ROOK_H

#include <piece.h>
#include <move_line.h>


/**
 * \class Rook
 * \brief Classe représentant la tour
 * 
 * Cette classe représente une reine. Elle comprend les deplacement d'un tour , sa couleur et ses coordonées.
 * 
 */
class Rook : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Rook
         * 
         */
        Rook();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Rook
         * 
         * \param Color color : couleur de la piece
         */
        Rook(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Rook
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Rook(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Rook
         * 
         */
        virtual ~Rook();

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