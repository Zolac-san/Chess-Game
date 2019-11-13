#ifndef FACTORY_CONTROLLER_H
#define FACTORY_CONTROLLER_H

#include <controller.h>

/**
 * \brief Factory Controller
 * 
 * Factory permettant de creer un controller
 * 
 */
class FactoryController{
	public:

		/**
		 * \brief Creer un controlleur
		 * 
		 * Fonction qui creer un controlleur
		 * 
		 * \return IController* : controlleur
		 */
		static IController* create();
		
};



#endif