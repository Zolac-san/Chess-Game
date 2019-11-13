#ifndef FACTORY_BOARD_H
#define FACTORY_BOARD_H

#include <board.h>

/**
 * \brief Factory Board
 * 
 * Factory permettant de creer un plateau de jeu
 * 
 */
class FactoryBoard{
	public:

		/**
		 * \brief Creer un plateau de jeu
		 * 
		 * Fonction qui creer un tableau 
		 * 
		 * \return IBoard* : plateau
		 */
		static IBoard* create();

		/**
		 * \brief Creer un plateau
		 * 
		 * Fonction qui creer un tableau avec un taille defini en parametre.
		 * 
		 * \param int height : hauteur du plateau
		 * \param int length : Longueur du plateau
		 * \return IBoard* : plateau
		 */
		static IBoard* create(int height, int length);
		
};

#endif