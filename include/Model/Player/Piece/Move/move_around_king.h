#ifndef MOVE_AROUND_KING_H
#define MOVE_AROUND_KING_H


#include <imove.h>


/**
 * \class MoveAroundKing
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente le mouvement d'un roi.
 * 
 */
class MoveAroundKing : public IMove{
    
    /**
     * \brief Verifie si un roi n'est pas a une case à coté
     * 
     * Methode qui evrifie si un roi d'une autre couleur est acoté de case demandé
     * 
     * \param Coordinate coordToCheck : coordonnées de la case à tester
     * \param IBoard* board : plateau à utiliser
     * \param Color myColor : couleur à ignorer
     * \return true : un roi ennemie est à coté de la case
     * \return false : aucun roi ennemie à coté de la case
     */
    bool haveKingEnnemyAround(Coordinate coordToCheck, IBoard* board, Color myColor);
    
    
    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe MoveAroundKing
         * 
         */
        MoveAroundKing();

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