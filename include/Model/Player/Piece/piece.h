#ifndef PIECE_H
#define PIECE_H


#include <iostream>
#include <vector>

#include <color.h>
#include <coordinate.h>
#include <piece_type.h>
#include <iboard.h>
#include <imove.h>

/**
 * \class Piece
 * \brief Classe abstraite représentant une piece
 * 
 * Cette classe abstraite représente une piece avec sa couleur et ses coordonnées
 * 
 */
class Piece{
    Color color; /*!< Couleur de la piece */
    IMove* movementType; /*!< Movement de la piece */
    Coordinate coord; /*!< Coordonnées de la piece */

    protected:
        PieceType pieceType; /*!< type de la piece */

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Piece
         * 
         */
        Piece();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Piece
         * 
         * \param Color color : couleur de la piece
         */
        Piece(Color color);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Piece
         * 
         * \param Color color : couleur de la piece
         * \param Coordinate coord : coordonnées de la piece
         */
        Piece(Color color,Coordinate coord);

        /**
         * \brief Destructeur
		 * 
		 * Destructeur de la classe Piece
         * 
         */
        ~Piece();

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
        void setMoved(bool moved);


        /**
         * \brief Renvoie les déplacements possible
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles
         */
        std::vector<Coordinate> move(Coordinate refCoord,IBoard* board);

        /**
         * \brief Renvoie les déplacements possible qui peuvent manger une piece 
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer pour manger une piece.
         * 
         * \param Coordinate refCoord : coordonnées de depart de la piece
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles pour manger une piece
         */
        std::vector<Coordinate> moveCanEat(Coordinate refCoord,IBoard* board);

        /**
         * \brief Renvoie les déplacements possible
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer.
         * 
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles
         */
        std::vector<Coordinate> move(IBoard* board);

        /**
         * \brief Renvoie les déplacements possible qui peuvent manger une piece 
         * 
         * methode qui renvoie les deplacements ( coordonnées ) que la piece peut effectuer pour manger une piece.
         * 
         * \param IBoard* board : plateau à utiliser
         * \return std::vector<Coordinate> : liste des deplacements possibles pour manger une piece
         */
        std::vector<Coordinate> moveCanEat(IBoard* board);

        /**
         * \brief Renvoie le type de la piece
         * 
         * Methode qui renvoie le type de la piece
         * 
         * \return PieceType : type de la piece
         */
        virtual PieceType getTypePiece();
        
        /**
         * \brief Definit la couleur de la piece
         * 
         * Methode qui definit la couleur de la piece
         * 
         * \param Color color : couleur à mettre à la piece
         */
        void setColor(Color color);

        /**
         * \brief Renvoie la couleur de la piece
         * 
         * Methode qui renvoie la couleur de la piece
         * 
         * \return Color : couleur de la piece
         */
        Color getColor();

        /**
         * \brief Definit les coordonnées de la piece
         * 
         * Methode qui definit les coordonnées de la piece
         * 
         * \param Coordinate coord : coordonnées à mettre à la piece
         */
        void setCoordinate(Coordinate coord);

        /**
         * \brief Definit les coordonnées de la piece
         * 
         * Methode qui definit les coordonnées de la piece
         * 
         * \param int x : coordonnée x à mettre à la piece
         * \param int y : coordonnée y à mettre à la piece
         */
        void setCoordinate(int x, int y);

        /**
         * \brief Renvoie les coordonnées de la piece
         * 
         * Methode qui renvoie les coordonnées de la piece
         * 
         * \return Coordinate : coordonnées de la piece
         */
        Coordinate getCoordinate();

        /**
         * \brief Definit le mouvement de la piece
         * 
         * Methode qui definit le mouvement de la piece
         * 
         * \param IMove* movementType : movement à assigner à la piece
         */
        void setMove(IMove* movementType);

        /**
         * \brief Renvoie le movement de la piece
         * 
         * Methode qui renvoie le movement de la piece
         * 
         * \return IMove* : movement de la piece
         */
        IMove* getMove();

        /**
         * \brief Copie la piece
         * 
         * Methode qui copie la piece
         * 
         * \return Piece* : copie de la piece
         */
        virtual Piece* copy();
};




#endif