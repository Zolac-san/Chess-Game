#ifndef ICONTROLLER_H
#define ICONTROLLER_H

#include <iview.h>
#include <imodel.h>
#include <state_game.h>
#include <aichoice.h>

/**
 * \interface IController 
 * \brief Interface d'un controlleur
 * 
 * Cette classe représente l'interface du controller
 * 
 */
class IController{

    public:

        /**
         * \brief Renvoie le model
         * 
         * Renvoie le model utiliser par le controlleur.
         * 
         * \return IModel* : model utilisé par le controlleur 
         */
        virtual IModel* getModel();

        /**
         * \brief Renvoie la vue
         * 
         * Renvoie la vue utilisé par le controlleur
         * 
         * \return IView* : vue utilisé par le controlleur
         */
        virtual IView* getView();


        /**
         * \brief demarre le jeu
         * 
         * Demarre le jeu et effectue une boucle infini jusqu'a ce que la fenetre soit fermé
         * 
         */
        virtual void start();

        /**
         * \brief Ferme l'application
         * 
         * Ferme la fenetre, met fin au thread pool et a la vue, et sort de la boucle infini genere par la fonction start
         * 
         */
        virtual void closeApp();
    
        
        
};
                                                    

#endif