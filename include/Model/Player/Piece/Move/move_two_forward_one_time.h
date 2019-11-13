#ifndef MOVE_TWO_FORWARD_ONE_TIME_H
#define MOVE_TWO_FORWARD_ONE_TIME_H


#include <imove.h>


/**
 * \class MoveTwoForwardOneTime
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente le mouvement de 2 case en avant qui est executable qu'au premier mouvement de la piece.
 * 
 */
class MoveTwoForwardOneTime : public IMove{
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe MoveTwoForwardOneTime
         * 
         */
        MoveTwoForwardOneTime();

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
        
        /**
         * \brief Renvoie les déplacements possible qui peuvent manger une piece 
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer pour manger une piece.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles pour manger une piece
         */
        std::vector<Coordinate> moveCanEat(Coordinate refCoord, IBoard* board) override;
};



#endif