#ifndef TURNMOVE_H
#define TURNMOVE_H

#include <piece_type.h>
#include <color.h>
#include <coordinate.h>

/**
 * \struct TurnMove
 * \brief Structure représentant un tour de jeu
 * 
 * Cette structure correspond a un tour de jeu. Elle comporte le tour, la case de depart, la case d'arriver, le type de piece , la couleur et enfin si il y a eu une promotion de pion
 * 
 */
struct TurnMove{
    int numTurn; /*!< numero du tour */
    Coordinate coordinateStart; /*!< coordonnées de depart de la piece */
    Coordinate coordinateEnd; /*!< coordonnées final de la piece */
    PieceType type; /*!< type de la piece joue */
    Color color; /*!< couleur de la piece jouer */
    PieceType promote; /*!< choix de la piece choisie lors de la promotion*/


    /**
     * \brief Verifie si le tour est le meme mais à l'envers
     * 
     * Methode qui verifie si le tour est le meme mais à l'envers
     * 
     * \param TurnMove anOtherTurn : tour à comparer
     * \return true : le tour est le meme mais à l'envers
     * \return false : les tours sont independant
     */
    bool isReverseOf(TurnMove anOtherTurn){
        if( this->coordinateStart == anOtherTurn.coordinateEnd && this->coordinateEnd == anOtherTurn.coordinateStart && this->type == anOtherTurn.type && this->color == anOtherTurn.color && this->promote == anOtherTurn.promote) return true;
        return false;
    }
};


#endif