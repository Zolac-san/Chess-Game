#ifndef SQUARE_H
#define SQUARE_H


#include <isquare.h>
#include <piece.h>


/**
 * \brief Classe représentant une cellule du plateau
 * 
 * Classe qui represnete une case du plateau. Elle connait sa position et la pice qui a les meme coordonnées
 * 
 */
class Square : public ISquare{

    Coordinate coord; /*!< coordonnées de la case */
    Piece* piece; /*!< piece sur la case */

    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Square
         * 
         * \param int x : coordonnée x de la case
         * \param int y : coordonnée y de la case
         */
        Square(int x,int y);

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe Square
         * 
         */
        ~Square();


        /**
         * \brief Renvoie les coordonnées
         * 
         * Renvoie les coordonées de la case
         * 
         * \return Coordinate : coordonnées
         */
        Coordinate getCoordinate() override;

        /**
         * \brief Definit la coordonnée x
         * 
         * Methode qui definit la coordonnée x de la case.
         * 
         * \param int x : coordonée x
         */
        void setX(int x) override;

        /**
         * \brief Definit la coordonnée y
         * 
         * Methode qui definit la coordonnée y de la case.
         * 
         * \param int y : coordonée y
         */
        void setY(int y) override;

        /**
         * \brief Renvoie la coordonnée x
         * 
         * Methode qui definit la coordonnée x de la case.
         * 
         * \return int : coordonée x
         */
        int getX() override;

        /**
         * \brief Renvoie la coordonnée y
         * 
         * Methode qui definit la coordonnée y de la case.
         * 
         * \return int : coordonée y
         */
        int getY() override;

        /**
         * \brief Definit la piece
         * 
         * Methode qui definit la piece sur la case
         * 
         * \param Piece* piece : piece à mettre sur la case 
         */
        void setPiece(Piece* piece) override;

        /**
         * \brief Renvoie la piece
         * 
         * Methode qui renvoie la piece qui est sur la case
         * 
         * \return Piece* : piece sur la case
         */
        Piece* getPiece() override;

        /**
         * \brief Supprime la case
         * 
         * Methode qui supprime la cas.
         * 
         */
        void deleteObject() override;
        
};


#endif