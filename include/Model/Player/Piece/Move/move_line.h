#ifndef MOVE_LINE_H
#define MOVE_LINE_H


#include <imove.h>


/**
 * \class MoveLine
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente le mouvement en ligne droite.
 * 
 */
class MoveLine : public IMove{
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe MoveLine
         * 
         */
        MoveLine();

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