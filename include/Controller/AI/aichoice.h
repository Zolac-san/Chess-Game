#ifndef AICHOICE_H
#define AICHOICE_H

#include <piece_type.h>
#include <vector>
#include <iostream>
#include <minmaxstate.h>
#include <coordinate.h>


/**
 * \class AIChoice
 * \brief class représentant un noeud de decision de l'arbre du min-max
 * 
 * Cette classe représente un noeud dans l'arbre des decisions du min-max. Elle comporte toutes les informations sur un coup et la liste des prochian noeuds.
 * 
 */
class AIChoice{
    MinMaxState stateOfChoice;/*!< etat du noeud */
    int score;/*!< score du noeud */
    bool havePromotedPawn;/*!< boolean protion du pion */
    PieceType choicePromote;/*!< choix de la promotion */
    std::vector<AIChoice*> childs;/*!< fils du noeud */
    Coordinate startPiece;/*!< coordonnées de depart de la piece */
    Coordinate endPiece;/*!< coordonnées de fin de la piece */
    
    public:

        /**
         * \brief Constructeur
         * 
         * Constructeur de la classe AIChoice
         * 
         */
        AIChoice();

        /**
         * \brief Constructeur
         * 
         * Constructeur de la classe AIChoice
         * 
         * \param MinMaxState stateOfChoice : Etat du noeud dans le min-max ( Min ou mAx)
         * \param Coordinate startPiece : les coordonnées de la piece de depart
         * \param Coordinate endPiece : les coordonnées de la piece à l'arrivée
         */
        AIChoice(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece);
        
        /**
         * \brief Constructeur
         * 
         * Constructeur de la classe AIChoice
         * 
         * \param MinMaxState stateOfChoice : Etat du noeud dans le min-max ( Min ou mAx)
         * \param Coordinate startPiece : les coordonnées de la piece de depart
         * \param Coordinate endPiece : les coordonnées de la piece à l'arrivée
         * \param PieceType choicePromote : le type de piece choisie pour la promotion du pion
         */
        AIChoice(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece, PieceType choicePromote);
        
        /**
         * \brief Ajoute a un nouveau fils
         * 
         * Methode qui permet d'ajouter un nouveau fils au noeud.
         * 
         * \param AIChoice* childAIChoice : le fils à rajouter
         */
        void addChild(AIChoice* childAIChoice);

        /**
         * \brief Renvoie l'etat du noeud
         * 
         * Renvoie l'etat du noeud, si il est Min ou Max
         * 
         * \return MinMaxState : Min ou Max
         */
        MinMaxState getState();

        /**
         * \brief Defini le score
         * 
         * Defini le score du noeud
         * 
         * \param double score : score à mettre dans le noeud
         */
        void setScore(double score);

        /**
         * \brief Renvoie le score
         * 
         * Renvoie le score. Si le noeud a des fils il calculeras le score par rapport a ses fils
         * 
         * \return double : score du noeud 
         */
        double getScore();

        /**
         * \brief Renvoie le meilleur choix de mouvement
         * 
         * Calcul par rapport a tous les noeuds fils qu'elle est le meilleur choix de mouvement grace à l'algorithme du min max
         * 
         * \return AIChoice* : Meilleur choix de mouvement
         */
        AIChoice* getBestMove();

        /**
         * \brief Renvoie les coordonées de la case de depart
         * 
         * Methode qui renvoie les coordonnées de la case de depart
         * 
         * \return Coordinate : coordonnées de la case de depart
         */
        Coordinate getStartPiece();

        /**
         * \brief Renvoie les coordonées de la case d'arrivée
         * 
         * Methode qui renvoie les coordonnées de la case d'arrivée
         * 
         * \return Coordinate : coordonnées de la case d'arrivée
         */
        Coordinate getEndPiece();

        /**
         * \brief Renvoie un boolean s'il y a eu une promotion de pion dans ce tour
         * 
         * Methode qui renvoie un boolean s'il y a eu une promotion de pion dans ce tour
         * 
         * \return true : Si un pion a fait une promotion
         * \return false : Si un pion n'a pas fait une promotion
         */
        bool isPromotedPawn();

        /**
         * \brief Renvoie le choix de la promotion
         * 
         * Methode qui renvoie le choix de la promotion
         * 
         * \return PieceType : le choix de la protion. Si il n'y a pas eu de promotion renvoie UNKNOW
         */
        PieceType getChoicePromote();

};


#endif