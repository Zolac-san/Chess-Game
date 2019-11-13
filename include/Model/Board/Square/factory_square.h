#ifndef FACTORY_SQUARE_H
#define FACTORY_SQUARE_H

#include <square.h>

/**
 * \brief Factory Square
 * 
 * Factory permettant de creer une case de plateau
 * 
 */
class FactorySquare{
	public:

		/**
		 * \brief Creer une case
		 * 
		 * Fonction qui creer une case aux coordonées x,y
		 * 
		 * \param int x : 
		 * \param int y : Coordonnée y 
		 * \return ISquare* : case
		 */
		static ISquare* create(int x, int y);
			
};

#endif