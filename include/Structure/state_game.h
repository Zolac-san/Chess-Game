#ifndef STATE_GAME_H
#define STATE_GAME_H


/**
 * \enum StateGame
 * \brief Enumeration des etats d'une partie
 * 
 * Enumeration qui liste les differrents etats d'une partie style pat, echec , echec et mat  ou rien.
 * 
 */
enum StateGame{
    NOTHING,
    STALEMATE,
    CHECK,
    CHECKMATE
};


#endif