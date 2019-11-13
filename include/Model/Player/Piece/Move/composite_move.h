#ifndef COMPOSITE_MOVE_H
#define COMPOSITE_MOVE_H


#include <icomposite_move.h>

/**
 * \class CompositeMove
 * \brief Classe représentant un composé de deplacement
 * 
 * Cette classe repsente un ensemble de deplacements.
 * 
 */
class CompositeMove : public ICompositeMove{

    std::vector<IMove*> moves; /*!< liste des deplacements */

    public:

        /**
         * \brief Constructeur
         * 
         * Constructeur de la classe CompositeMove
         * 
         */
        CompositeMove();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe CompositeMove
         * 
         * \param IMove* oneMove : un deplacement de base
         */
        CompositeMove(IMove* oneMove);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe CompositeMove
         * 
         * \param std::vector<IMove*> moves : liste de deplacements de base
         */
        CompositeMove(std::vector<IMove*> moves);

        /**
         * \brief Renvoie les déplacements possible
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles
         */
        std::vector<Coordinate> move(Coordinate refCoord,IBoard* board) override;
        
        /**
         * \brief Renvoie les déplacements possible qui peuvent manger une piece 
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer pour manger une piece.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles pour manger une piece
         */
        std::vector<Coordinate> moveCanEat(Coordinate refCoord, IBoard* board) override;

        /**
         * \brief Ajoute un deplacement
         * 
         * Methode qui rajoute un deplacement à la liste des deplacements
         * 
         * \param IMove* moveToAdd : deplacement à ajouter
         */
        void addMove(IMove* moveToAdd);

        /**
         * \brief Renvoie si la piece a deja bougé
         * 
         * Methode qui renvoie si la piece a deja bougé
         * 
         * \return true : la piece s'est deja deplacé
         * \return false : la piece ne s'est pas encore deplacé
         */
        bool haveMove();

        /**
         * \brief Definit si la piece a bougé
         * 
         * Methode qui definit si la piece a bougé
         * 
         * \param bool moved : boolean si la piece a bougé
         */
        void setMoved(bool moved) override;
};



#endif