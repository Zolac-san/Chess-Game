#ifndef PLAYER_H
#define PLAYER_H


#include <iplayer.h>



/**
 * \class Player
 * \brief Classe représentant un joueur
 * 
 * Cette classe représente un joueur. Elle defini les diferentes pieces que le joueur a, si c'est une ia, et sa couleur
 * 
 */
class Player : public IPlayer{

	Color color; /*!< couleur du joueur */
	bool ai; /*!< bool pour savoir si c'ets une IA */
	std::vector<Piece*> listPieces; /*!< liste des pieces du joueur */

	public:

		/**
		 * \brief Constructeur
		 * 
		 * Constructeur de la classe Player
		 * 
		 * \param Color color : couleur du joueur
		 * \param bool ai : es ce une IA
		 */
		Player(Color color,bool ai);

		/**
		 * \brief Destructeur
		 * 
		 * Destructeur de la classe Player
		 * 
		 */
		virtual ~Player();

		/**
		 * \brief Renvoie la couleur
		 * 
		 * Methode qui renvoie la couleur du joueur.
		 * 
		 * \return Color : couleur du joueur
		 */
		Color getColor() override;

		/**
		 * \brief Renvoie la liste des pieces
		 * 
		 * Methode qui renvoie la liste des pieces du joueur
		 * 
		 * \return std::vector<Piece*> : liste des pieces
		 */
		std::vector<Piece*> getAllPieces() override;

		/**
		 * \brief Renvoie la liste des pieces d'un type specifique
		 * 
		 * Methode qui renvoie la liste des pieces d'un type specifique données en parametre du joueur
		 * 
		 * \return std::vector<Piece*> : liste des pieces d'un type specifique
		 */
		std::vector<Piece*> getAllPiecesOfType(PieceType type) override;

		/**
		 * \brief Ajoute une piece
		 * 
		 * Methode qui rajoute une piece au joueur
		 * 
		 * \param Piece* piece : piece à rajouter
		 */
		void addPiece(Piece* piece) override;

		/**
		 * \brief Supprime une piece
		 * 
		 * Methode qui supprime une piece au joueur
		 * 
		 * \param Piece* piece : piece à supprimer
		 */
		void erasePiece(Piece* piece) override;

		/**
		 * \brief Definit si le joueur est une IA
		 * 
		 * Methode qui definit si le joueur est une IA
		 * 
		 * \param bool ai : true si le joueur est une ia, false sinon 
		 */
		void setAI(bool ai) override;

		/**
		 * \brief Renvoie si le joueur est une IA
		 * 
		 * Methode qui renvoie si le joueur est une IA.
		 * 
		 * \return true : le joueur est un IA
		 * \return false : le joueur n'est pas un IA
		 */
		bool isAI() override;

		/**
		 * \brief Copie le joueur
		 * 
		 * Methode qui copie le joueur et ses pieces
		 * 
		 * \return IPlayer* : copie du joueur
		 */
		IPlayer* copy() override;

		/**
		 * \brief Supprime le joueur
		 * 
		 * Methode qui supprime le joueur
		 * 
		 */
		void deleteObject() override;
};




#endif