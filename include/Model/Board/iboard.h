#ifndef IBOARD_H
#define IBOARD_H

#include <isquare.h>
#include <color.h>


/**
 * \interface IBoard
 * \brief Interface d'un plateau d'echec
 * 
 * Cette class représente l'interface d'un plateau d'echec
 * 
 */
class IBoard{
    public:

        /**
         * \brief Renvoie la longueur du plateau
         * 
         * Methode qui renvoie la longueur du plateau
         * 
         * \return int : longueur du plateau
         */
        virtual int getLength();

        /**
         * \brief Renvoie la hauteur du plateau
         * 
         * Methode qui renvoie la hauteur du plateau
         * 
         * \return int : hauteur du plateau
         */
        virtual int getHeight();

        /**
         * \brief Definit la piece sur une cellule
         * 
         * Methode qui definit la piece en parametre sur la cellule sur les coordonnées passées en argument.
         * 
         * \param int x : coordonnée x de la case
         * \param int y : coordonnée y de la case
         * \param Piece* piece : piece à placer
         */
        virtual void setSquarePiece(int x, int y, Piece* piece);

        /**
         * \brief Definit la piece sur une cellule
         * 
         * Methode qui definit la piece en parametre sur la cellule sur les coordonnées passées en argument.
         * 
         * \param Coordinate coord : coordonnées de la case
         * \param Piece* piece : piece à placer
         */
        virtual void setSquarePiece(Coordinate coord, Piece* piece);

        /**
         * \brief Renvoie la piece d'une case
         * 
         * Methode qui renvoie la piece situer sur les coordonnées passées en parametre.
         * 
         * \param int x : coordonnée x de la case
         * \param int y : coordonnée y de la case
         * \return Piece* : piece de la case
         */
        virtual Piece* getSquarePiece(int x, int y);

        /**
         * \brief Renvoie la piece d'une case
         * 
         * Methode qui renvoie la piece situer sur les coordonnées passées en parametre.
         * 
         * \param Coordonite coord : coordonnées de la case
         * \return Piece* : piece de la case
         */
        virtual Piece* getSquarePiece(Coordinate coord);

        /**
         * \brief Renvoie la case
         * 
         * Methode qui renvoie la case qui a les coordonnées passées en parametre.
         * 
         * \param int x : coordonnée x de la case
         * \param int y : coordonnée y de la case
         * \return ISquare* : case avec les coordonnées demandée 
         */
        virtual ISquare* getSquare(int x, int y);

        /**
         * \brief Renvoie la case
         * 
         * Methode qui renvoie la case qui a les coordonnées passées en parametre.
         * 
         * \param Coordinate coord : coordonnée de la case
         * \return ISquare* : case avec les coordonnées demandée 
         */
        virtual ISquare* getSquare(Coordinate coord);

        /**
         * \brief Creer le plateau de jeu
         * 
         * Methoed qui va creer le plateau de jeu en generant les differentes case
         * 
         * \param int height : hauteur du plateau
         * \param int length : longueur du plateau 
         */
        virtual void createBoard(int height, int length);

        /**
         * \brief Verifie l'existance d'une piece sur une case
         * 
         * Methoed qui verifie l'existance d'une piece sur une case ou les coordonnées sont données en parametre.
         * 
         * \param int x : coordonnée x de la case 
         * \param int y : coordonnée y de la case 
         * \return true : une piece existe sur la case
         * \return false : aucune piece sur la case
         */
        virtual bool isPiece(int x, int y);

        /**
         * \brief Verifie l'existance d'une piece sur une case
         * 
         * Methoed qui verifie l'existance d'une piece sur une case ou les coordonnées sont données en parametre.
         * 
         * \param Coordinate coord : coordonnées de la case 
         * \return true : une piece existe sur la case
         * \return false : aucune piece sur la case
         */
        virtual bool isPiece(Coordinate coord);

        /**
         * \brief Verifie si la case est attaquable
         * 
         * Methode qui verifie si la case au coordonnées passée en argument est attaquable par une autre couleur que celle passée en argument.
         * 
         * \param Coordinate coordToAttack : coordonées de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return true : la case est attaquable
         * \return false : la case est non attaquable
         */
        virtual bool isSquareCanBeAttack(Coordinate coordToAttack, Color myColor);

        /**
         * \brief Verifie si la case est attaquable
         * 
         * Methode qui verifie si la case au coordonnées passée en argument est attaquable par une autre couleur que celle passée en argument.
         * 
         * \param int x : coordonée x de la case à attaquer
         * \param int y : coordonée y de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return true : la case est attaquable
         * \return false : la case est non attaquable
         */
        virtual bool isSquareCanBeAttack(int x, int y, Color myColor);

        /**
         * \brief Renvoie la premiere piece qui peut attaquer la cellule
         * 
         * Methode qui renvoie la premiere piece qui peut attaquer la cellule passe en parametre qui n'est pas la couleur passe en argument.
         * 
         * \param Coordinate coord : coordonées de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return Piece* : premiere piece qui peut attaquer la case
         */
        virtual Piece* getPieceWhoAttackThisSquare(Coordinate coord, Color myColor);

        /**
         * \brief Verifie si la case est attaquable sans l'utilisation du roi
         * 
         * Methode qui verifie si la case au coordonnées passée en argument est attaquable par une autre couleur que celle passée en argument sans l'utilisation du roi.
         * 
         * \param Coordinate coordToAttack : coordonées de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return true : la case est attaquable
         * \return false : la case est non attaquable
         */
        virtual bool isSquareCanBeAttackWithoutKing(Coordinate coordToAttack, Color myColor);

        /**
         * \brief Compte le nombre de piece qui peuvent attaquer la case
         * 
         * Methode qui compte le nombre de piece qui peuvent attaquer la case au coordonnées passée en parametre qui on une autre couleur que celle passée en parametre.
         * 
         * \param Coordinate coordToAttack : coordonées de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return int : nombre de piece qui peuvent attaquer la case
         */
        virtual int howManyPieceCanAttack(Coordinate coordToAttack, Color myColor);

        /**
         * \brief Compte le nombre de piece qui peuvent attaquer la case
         * 
         * Methode qui compte le nombre de piece qui peuvent attaquer la case au coordonnées passée en parametre qui on une autre couleur que celle passée en parametre.
         * 
         * \param int x : coordonée x de la case à attaquer
         * \param int y : coordonée y de la case à attaquer
         * \param Color myColor : couleur qui ne peut pas attaquer la case
         * \return int : nombre de piece qui peuvent attaquer la case
         */
        virtual int howManyPieceCanAttack(int x, int y, Color myColor);

        /**
         * \brief Creer une copie
         * 
         * Creer une copie du plateau
         * 
         * \return IBoard* : copie du plateau
         */
        virtual IBoard* copy();

        /**
         * \brief Supprime le plateau
         * 
         * Methode qui supprime le plateau
         * 
         */
        virtual void deleteObject();

        

};


#endif