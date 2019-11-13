#ifndef MOVE_JUMP_H
#define MOVE_JUMP_H


#include <imove.h>


/**
 * \class MoveJump
 * \brief Classe représentant un deplacement
 * 
 * Cette classe représente le mouvement d'un cavalier.
 * 
 */
class MoveJump : public IMove{

    /**
     * \brief Verifie si la case est atteignable
     * 
     * Methode qui verifie si la case est atteignable
     * 
     * \param Coordinate coordToTest : coordonnées à tester
     * \param  board : plateau à utiliser
     * \param  myColor : couleur de la piece utiliser
     * \return true : la piece peut se deplacer sur la case
     * \return false : la piece ne peut pas se deplacer sur la case
     */
    bool canMoveOn(Coordinate coordToTest, IBoard* board, Color myColor);

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe MoveJump
         * 
         */
        MoveJump();

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