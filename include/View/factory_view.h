#ifndef FACTORY_VIEW_H
#define FACTORY_VIEW_H

#include <view.h>

/**
 * \brief Factory View
 * 
 * Factory permettant de creer une vue
 * 
 */
class FactoryView{
	public:
		/**
		 * \brief Creer une vue
		 * 
		 * Fonction qui creer une vue
		 * 
		 * \return IView* : vue
		 */
		static IView* create();

		/**
		 * \brief Creer une vue
		 * 
		 * Fonction qui creer une vue
		 * 
		 * \param IModel* model : model qu'utilisera la vue 
		 * \return IView* : vue
		 */
		static IView* create(IModel* model);
};

#endif