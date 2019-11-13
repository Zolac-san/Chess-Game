#ifndef IVIEW_H
#define IVIEW_H

#include <imodel.h>


/**
 * \interface IView
 * \brief Interface représentant une vue dans le pattern design MVC
 * 
 * Cette classe représente une interface d'une vue dans le pattren design MVC.
 * 
 */
class IView{

    public:

        /**
         * \brief Affiche les informations
         * 
         * Methode qui affiche les differents element dans la fenetre
         * 
         */
        virtual void displayLoop();

        /**
         * \brief Definit le model
         * 
         * Methode qui definit le model qu'utilisera la vue.
         * 
         * \param IModel* model : model que la vue utilisera. 
         */
        virtual void setModel(IModel* model);

        /**
         * \brief Renvoie le model
         * 
         * Methode qui renvoie le model utilisée par la vue
         * 
         * \return IModel* : model utilisé
         */
        virtual IModel* getModel();
};




#endif
