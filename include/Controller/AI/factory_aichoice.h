#ifndef FACTORY_AICHOICE_H
#define FACTORY_AICHOICE_H

#include <aichoice.h>

/**
 * \brief Factory AIChoice
 * 
 * Factory permettant de creer un noued d'arbre 
 * 
 */
class FactoryAIChoice{
	public:

		/**
		 * \brief Creer un noeud
		 * 
		 * Fonction qui creer un noeud
		 * 
		 * \return AIChoice* : noeud
		 */
		static AIChoice* create();

		/**
		 * \brief Creer un noeud
		 * 
		 * Fonction qui creer un noeud
		 * 
		 * \param MinMaxState stateOfChoice : Etat de l'arbre
		 * \param Coordinate startPiece : Coordonnée de depart de la piece deplacée
		 * \param Coordinate endPiece : Coordonnée final de la piece deplacée
		 * \return AIChoice* : noeud
		 */
		static AIChoice* create(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece);
		
		/**
		 * \brief Creer un noeud
		 * 
		 * Fonction qui creer un noeud
		 * 
		 * \param MinMaxState stateOfChoice : Etat de l'arbre
		 * \param Coordinate startPiece : Coordonnée de depart de la piece deplacée
		 * \param Coordinate endPiece : Coordonnée final de la piece deplacée
		 * \param PieceType choicePromote : Piece choisie lors de la promotion
		 * \return AIChoice* : noeud
		 */
		static AIChoice* create(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece, PieceType choicePromote);

};



#endif