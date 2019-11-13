#ifndef IMOVE_H
#define IMOVE_H


#include <vector>
#include <coordinate.h>
#include <iboard.h>
#include <iostream>


/**
 * \class IMove
 * \brief classe abstrait représentant un mouvement
 * 
 * Classe abstraite représent une mouvement d'une piece d'echec.
 */
class IMove{
    protected:
        bool moved;  /*!< boolean pour savoir si la piece s'est deplacé */
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe IMove
         * 
         */
        IMove();

        /**
         * \brief Renvoie si la piece a deja bougé
         * 
         * Methode qui renvoie si la piece a deja bougé
         * 
         * \return true : la piece s'est deja deplacé
         * \return false : la piece ne s'est pas encore deplacé
         */
        bool haveMove();

        /**
         * \brief Definit si la piece a bougé
         * 
         * Methode qui definit si la piece a bougé
         * 
         * \param bool moved : boolean si la piece a bougé
         */
        virtual void setMoved(bool moved);

        /**
         * \brief Renvoie les déplacements possible
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles
         */
        virtual std::vector<Coordinate> move(Coordinate refCoord, IBoard* board);

        /**
         * \brief Renvoie les déplacements possible qui peuvent manger une piece 
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer pour manger une piece.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles pour manger une piece
         */
        virtual std::vector<Coordinate> moveCanEat(Coordinate refCoord, IBoard* board);
        
};

#endif