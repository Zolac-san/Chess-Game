#ifndef FACTORY_MODEL_H
#define FACTORY_MODEL_H

#include <model.h>

/**
 * \brief Factory Model
 * 
 * Factory permettant de creer un model
 * 
 */
class FactoryModel{
	public:
		/**
		 * \brief Creer un model
		 * 
		 * Fonction qui creer un model
		 * 
		 * \return IModel* : model
		 */
		static IModel* create();
};

#endif