#ifndef ICOMPOSITE_MOVE_H
#define ICOMPOSITE_MOVE_H


#include <imove.h>


/**
 * \interface ICompositeMove
 * \brief Interface d'un composé de movement
 * 
 * Cette classe représente l'inteface d'un compose de mouvement
 * 
 */
class ICompositeMove : public IMove{

    public:
        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe ICompositeMove
         * 
         */
        ICompositeMove();

        /**
         * \brief Ajoute un deplacement
         * 
         * Methode qui rajoute un deplacement à la liste des deplacements
         * 
         * \param IMove* moveToAdd : deplacement à ajouter
         */
        virtual void addMove(IMove moveToAdd);

        /**
         * \brief Definit si la piece a bougé
         * 
         * Methode qui definit si la piece a bougé
         * 
         * \param bool moved : boolean si la piece a bougé
         */
        virtual void setMoved(bool moved);
        
};



#endif