#ifndef MOVE_DIAGONAL_H
#define MOVE_DIAGONAL_H


#include <imove.h>


/**
 * \class MoveDiagonal
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente le mouvement en diagonal.
 * 
 */
class MoveDiagonal : public IMove{
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe MoveDiagonal
         * 
         */
        MoveDiagonal();

        /**
         * \brief Renvoie les déplacements possible
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles
         */
        std::vector<Coordinate> move(Coordinate refCoord, IBoard* board) override;
};



#endif