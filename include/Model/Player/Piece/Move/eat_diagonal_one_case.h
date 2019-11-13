#ifndef EAT_DIAGONAL_ONE_CASE_H
#define EAT_DIAGONAL_ONE_CASE_H


#include <imove.h>

/**
 * \class EatDiagonalOneCase
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente un movement de une case vers une diagonal qui se trouve en face de la piece.
 * 
 */
class EatDiagonalOneCase : public IMove{
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe EatDiagonalOneCase
         * 
         */
        EatDiagonalOneCase();

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