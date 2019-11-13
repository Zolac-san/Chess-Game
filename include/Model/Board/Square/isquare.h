#ifndef ISQUARE_H
#define ISQUARE_H




#include <coordinate.h>


class Piece;

/**
 * \interface ISquare
 * \brief Interface représentant une cellule d'un plateau d'echec
 * 
 * Cette classe représente l'interface d"une cellule d'un plateau d'echec
 * 
 */
class ISquare{
    public:

        /**
         * \brief Renvoie les coordonnées
         * 
         * Renvoie les coordonées de la case
         * 
         * \return Coordinate : coordonnées
         */
        virtual Coordinate getCoordinate();

        /**
         * \brief Definit la coordonnée x
         * 
         * Methode qui definit la coordonnée x de la case.
         * 
         * \param int x : coordonée x
         */
        virtual void setX(int x);

        /**
         * \brief Definit la coordonnée y
         * 
         * Methode qui definit la coordonnée y de la case.
         * 
         * \param int y : coordonée y
         */
        virtual void setY(int y);

        /**
         * \brief Renvoie la coordonnée x
         * 
         * Methode qui definit la coordonnée x de la case.
         * 
         * \return int : coordonée x
         */
        virtual int getX();

        /**
         * \brief Renvoie la coordonnée y
         * 
         * Methode qui definit la coordonnée y de la case.
         * 
         * \return int : coordonée y
         */
        virtual int getY();

        /**
         * \brief Definit la piece
         * 
         * Methode qui definit la piece sur la case
         * 
         * \param Piece* piece : piece à mettre sur la case 
         */
        virtual void setPiece(Piece* piece);

        /**
         * \brief Renvoie la piece
         * 
         * Methode qui renvoie la piece qui est sur la case
         * 
         * \return Piece* : piece sur la case
         */
        virtual Piece* getPiece();

        /**
         * \brief Supprime la case
         * 
         * Methode qui supprime la case.
         * 
         */
        virtual void deleteObject();
        
};


#endif