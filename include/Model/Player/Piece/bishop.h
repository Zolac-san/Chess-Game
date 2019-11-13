#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>
#include <move_diagonal.h>

/**
 * \class Bishop
 * \brief Classe représentant le fou
 * 
 * Cette classe représente un fou. Elle comprend les deplacement d'un fou , sa couleur et ses coordonées.
 * 
 */
class Bishop : public Piece{

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Bishop
         * 
         */
        Bishop();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Bishop
         * 
         * \param Color color : couleur de la piece
         */
        Bishop(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Bishop
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Bishop(Color color, Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Bishop
         * 
         */
        virtual ~Bishop();

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