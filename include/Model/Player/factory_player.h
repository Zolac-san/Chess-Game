#ifndef FACTORY_PLAYER_H
#define FACTORY_PLAYER_H

#include <player.h>

/**
 * \brief Factory Player
 * 
 * Factory permettant de creer un joueur
 * 
 */
class FactoryPlayer{
	public:
		/**
		 * \brief Creer un joueur
		 * 
		 * Creer un joueur avec différent paramètres
		 * 
		 * \param Color color : couleur du joueur
		 * \param bool ai : boolean pour definir si c'est une ia ou non
		 * \return IPlayer* : joueur
		 */
		static IPlayer* create(Color color,bool ai);
};

#endif