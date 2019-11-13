#ifndef IPLAYER_H
#define IPLAYER_H


#include <color.h>
#include <piece.h>
#include <piece_type.h>


/**
 * \interface IPlayer
 * \brief Interface représentant un joueur
 * 
 * Cette classe représente l'interface pour représenter un joueur
 * 
 */
class IPlayer{

	public:

		/**
		 * \brief Constructeur
		 * 
		 * Constructeur de la classe IPlayer 
		 * 
		 */
		IPlayer();

		/**
		 * \brief Destructeur
		 * 
		 * Destructeur de la classe IPlayer
		 * 
		 */
		virtual ~IPlayer(); 

		/**
		 * \brief Renvoie la couleur
		 * 
		 * Methode qui renvoie la couleur du joueur.
		 * 
		 * \return Color : couleur du joueur
		 */
		virtual Color getColor();

		/**
		 * \brief Renvoie la liste des pieces
		 * 
		 * Methode qui renvoie la liste des pieces du joueur
		 * 
		 * \return std::vector<Piece*> : liste des pieces
		 */
		virtual std::vector<Piece*> getAllPieces();

		/**
		 * \brief Renvoie la liste des pieces d'un type specifique
		 * 
		 * Methode qui renvoie la liste des pieces d'un type specifique données en parametre du joueur
		 * 
		 * \return std::vector<Piece*> : liste des pieces d'un type specifique
		 */
		virtual std::vector<Piece*> getAllPiecesOfType(PieceType type);

		/**
		 * \brief Ajoute une piece
		 * 
		 * Methode qui rajoute une piece au joueur
		 * 
		 * \param Piece* piece : piece à rajouter
		 */
		virtual void addPiece(Piece* piece);

		/**
		 * \brief Supprime une piece
		 * 
		 * Methode qui supprime une piece au joueur
		 * 
		 * \param Piece* piece : piece à supprimer
		 */
		virtual void erasePiece(Piece* piece);

		/**
		 * \brief Definit si le joueur est une IA
		 * 
		 * Methode qui definit si le joueur est une IA
		 * 
		 * \param bool ai : true si le joueur est une ia, false sinon 
		 */
		virtual void setAI(bool ai);

		/**
		 * \brief Renvoie si le joueur est une IA
		 * 
		 * Methode qui renvoie si le joueur est une IA.
		 * 
		 * \return true : le joueur est un IA
		 * \return false : le joueur n'est pas un IA
		 */
		virtual bool isAI();

		/**
		 * \brief Copie le joueur
		 * 
		 * Methode qui copie le joueur et ses pieces
		 * 
		 * \return IPlayer* : copie du joueur
		 */
		virtual IPlayer* copy();

		/**
		 * \brief Supprime le joueur
		 * 
		 * Methode qui supprime le joueur
		 * 
		 */
		virtual void deleteObject();
		
};







#endif