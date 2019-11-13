#ifndef IMODEL_H
#define IMODEL_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iboard.h>
#include <iplayer.h>
#include <state_game.h>
#include <turnmove.h>


/**
 * \interface IModel 
 * \brief Interface du model
 * 
 * Cette classe représente l'interface du model dnas la design pattern MVC
 * 
 */
class IModel{
    
    public:
	
		/**
		 * \brief Renvoie toutes les pieces
		 * 
		 * Methode qui renvoie toutes les pieces du plateau
		 * 
		 * \return std::vector<Piece*> : liste des pieces
		 */
		virtual std::vector<Piece*> getAllPiece();

		/**
		 * \brief Renvoie toutes les pieces d'une couleur
		 * 
		 * Methode qui renvoie toutes les pieces d'une couleur du plateau
		 * 
		 * \param Color color : couleur des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'une couleur
		 */
        virtual std::vector<Piece*> getAllPieceColor(Color color);

		/**
		 * \brief Renvoie toutes les pieces d'un type
		 * 
		 * Methode qui renvoie toutes les pieces d'un type du plateau
		 * 
		 * \param PieceType type : type des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'un type
		 */
		virtual std::vector<Piece*> getAllPieceOfType(PieceType type);

		/**
		 * \brief Renvoie toutes les pieces d'une couleur et d'un type
		 * 
		 * Methode qui renvoie toutes les pieces d'une couleur et d'un type du plateau
		 * 
		 * \param PieceType type : type des pieces demandées
		 * \param Color color : couleur des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'une couleur et d'un type
		 */
		virtual std::vector<Piece*> getAllPieceOfTypeAndColor(PieceType type,Color color);

		/**
		 * \brief Definit le plateau
		 * 
		 * Methode qui definit le plateau du model
		 * 
		 * \param IBoard* board : plateau à mettre dans le model
		 */
		virtual void setBoard(IBoard* board);

		/**
		 * \brief Renvoie le plateau du model
		 * 
		 * Methode qui renvoie le plateau du model
		 * 
		 * \return IBoard* : plateau du model
		 */
		virtual IBoard* getBoard();

		/**
		 * \brief Renvoie la liste des joueurs
		 * 
		 * Methode qui renvoie la liste des joueurs
		 * 
		 * \return std::vector<IPlayer*> : liste des joueurs
		 */
		virtual std::vector<IPlayer*> getPlayers();

		/**
		 * \brief Renvoie le joueur de la couleur demandé
		 * 
		 * Methode qui renvoie le joueur de la couleur demandées
		 * 
		 * \param Color color : couleur du joueur
		 * \return IPlayer* : joueur de la couleur demandé
		 */
		virtual IPlayer* getPlayersColor(Color color);

		/**
		 * \brief Ajoute un joueur
		 * 
		 * Methode qui ajoute un joueur à la liste
		 * 
		 * \param IPlayer player : joueur à rajouter
		 */
		virtual void addPlayer(IPlayer* player);

		/**
		 * \brief Renvoie le nombre de joueur
		 * 
		 * Methode qui renvoie le nombre de joueur
		 * 
		 * \return int : nombre de joueur
		 */
		virtual int getNbPlayers();

		/**
		 * \brief Renvoie le numero du tour
		 * 
		 * Methode qui renvoie le numero du tour
		 * 
		 * \return int : numero du tour
		 */
		virtual int getTurn();

		/**
		 * \brief Renvoie le joueur qui doit jouer
		 * 
		 * Methode qui renvoie le joueur qui doit jouer
		 * 
		 * \return IPlayer* : 
		 */
		virtual IPlayer* getPlayerToPlay();

		/**
		 * \brief Definit le joueur qui doit jouer
		 * 
		 * Methode qui definit le joueur qui doit jouer
		 * 
		 * \param int numPlayerToPlat : indice du joueur qui doit jouer
		 */
		virtual void setPlayerToPlay(int numPlayerToPlat);

		/**
		 * \brief Renvoie l'indice du joueur qui doit jouer
		 * 
		 * Methode qui renvoie l'indice du joueur qui doit jouer
		 * 
		 * \return int : l'indice du joueur
		 */
		virtual int getPlayerToPlayIndex();

		/**
		 * \brief Definit la fenetre
		 * 
		 * Methode qui definit la fenetre du jeu
		 * 
		 * \param sf::RenderWindow* window : fenetre à assigner au model
		 */
		virtual void setWindow(sf::RenderWindow* window);

		/**
		 * \brief Renvoie la fenetre
		 * 
		 * Methode qui renvoie la fenetre du jeu
		 * 
		 * \return sf::RenderWindow* : fenetre du jeu
		 */
		virtual sf::RenderWindow* getWindow();

		/**
		 * \brief Definit le tour
		 * 
		 * Methode qui definit le numero du tour
		 * 
		 * \param int newTurn : le nouveau numero du tour
		 */
		virtual void setTurn(int newTurn);

		/**
		 * \brief Incremente le tour de 1
		 * 
		 * Methode qui incremente le tour de 1
		 * 
		 */
		virtual void addTurn();

		/**
		 * \brief Ajoute un nouveau tour de jeu
		 * 
		 * Methode qui rajoute un nouveau tour de jeu dans la liste
		 * 
		 * \param TurnMove newMove : le tour a rajouter
		 */
		virtual void addTurnMove(TurnMove newMove);

		/**
		 * \brief Renvoie la liste des differents tours de jeu
		 * 
		 * Methode qui renvoie la liste des differents tours de jeu.
		 * 
		 * \return std::vector<TurnMove> : la liste des differents tours de jeu
		 */
		virtual std::vector<TurnMove> getListTurnMove();

		/**
		 * \brief Definit la liste des deplacements possibles
		 * 
		 * Methode qui definit la liste des deplacements possibles ( par une piece )
		 * 
		 * \param std::vector<Coordinate> coord : liste des deplacements possibles 
		 */
		virtual void setPossibleMoves(std::vector<Coordinate> coord);

		/**
		 * \brief Renvoie la liste des deplacements possible
		 * 
		 * Methode qui renvoie la liste des deplacements possible ( par une piece )
		 * 
		 * \return std::vector<Coordinate> : liste des deplacements possible
		 */
		virtual std::vector<Coordinate> getPossibleMoves();

		/**
		 * \brief Reinitialise la liste des deplacements possible
		 * 
		 * Methode qui reinitialise la liste des deplacements possible
		 * 
		 */
		virtual void resetPossibleMoves();

		/**
		 * \brief Definit les coordonnées de la case seletionné
		 * 
		 * Methode qui definit les coordonnées de la case selectionné (par le joueur )
		 * 
		 * \param Coordinate coord : coordonnées de la case 
		 */
		virtual void setSelectedSquare(Coordinate coord);

		/**
		 * \brief Renvoie les coordonnées de la case selectionné
		 * 
		 * Methode qui renvoie les coordonnées de la case selectionné (par le joueur )
		 * 
		 * \return Coordinate : coordonnées de la case selectionné
		 */
		virtual Coordinate getSelectedSquare();

		/**
		 * \brief Renvoie la couleur opposée
		 * 
		 * Methode qui renvoie la couleur opposée
		 * 
		 * \param Color myColor : la couleur choisie
		 * \return Color : la couleur qui n'est pas la couleur choisie
		 */
		virtual Color getOtherColor(Color myColor);

		/**
		 * \brief Renvoie la version ecrite de la couleur
		 * 
		 * Methode qui transforme la couleur en sa version texte
		 * 
		 * \param Color color : couleur qui doit etre convertie
		 * \return std::string : la couleur en texte
		 */
		virtual std::string getStringOfColor(Color color);

		/**
		 * \brief Definit la fin de partie
		 * 
		 * Methode qui definit si une partie est terminée ou non
		 * 
		 * \param bool finish : fin de partie
		 */
		virtual void setFinish(bool finish);

		/**
		 * \brief Renvoie si la partie est finie ou non
		 * 
		 * Methode qui renvoie si la partie est finie ou non
		 * 
		 * \return true : la partie est finie
		 * \return false : la partie est en cours
		 */
		virtual bool isFinish();

		/**
		 * \brief Copie le model
		 * 
		 * Methode qui copie le model
		 * 
		 * \return IModel* : copie du model
		 */
		virtual IModel* copy();

		/**
		 * \brief Definit la piece qui doit etre promue
		 * 
		 * Methode qui definit la piece qui doit etre promue
		 * 
		 * \param Piece* promotePawn : piece qui doit etre promu
		 */
		virtual void setPromotePawn(Piece* promotePawn);

		/**
		 * \brief Renvoie la piece qui doit etre promue
		 * 
		 * Methode qui renvoie la piece qui doit etre promue
		 * 
		 * \return Piece* : la piece qui doit etre promue
		 */
		virtual Piece* getPromotePawn();

		/**
		 * \brief Verifie si une piece est en cours de promotion
		 * 
		 * Methode qui verifie si une piece est en cours de promotion
		 * 
		 * \return true : une piece est encours de promotion
		 * \return false : aucun piece en cours de promotion
		 */
		virtual bool isPromotePawn();

		/**
		 * \brief Definit la couleur vainqueur
		 * 
		 * Methode qui definit la couleur du vainqueur
		 * 
		 * \param Color color : couleur du vainqueur
		 */
		virtual void setWinner(Color color);

		/**
		 * \brief Renvoie la couleur du vainqueur
		 * 
		 * Methode qui renvoie la couleur du vainqueur
		 * 
		 * \return Color : couleur du vainqueur
		 */
		virtual Color getWinner();

		/**
		 * \brief Definit l'etat de la partie
		 * 
		 * Methode qui definit l'etat de la partie
		 * 
		 * \param StateGame stateGame : l'etat de la partie
		 */
		virtual void setStateGame(StateGame stateGame);

		/**
		 * \brief Renvoie l'etat de la partie
		 * 
		 * Methode qui renvoie l'etat de la partie
		 * 
		 * \return StateGame : l'etat de la partie
		 */
		virtual StateGame getStateGame();

		/**
		 * \brief Definit la couleur pour laquel la verification de defaite a été fait
		 * 
		 * Methode qui definit la couleur pour laquel la verification de defaite a été fait
		 * 
		 * \param Color colorToCheck : couleur pour laquel la verification de defaite a été fait
		 */
		virtual void setColorToCheck(Color colorToCheck);

		/**
		 * \brief Renvoie la couleur pour laquel la verification de defaite a été fait
		 * 
		 * Methode qui renvoie la couleur pour laquel la verification de defaite a été fait
		 * 
		 * \return Color : couleur pour laquel la verification de defaite a été fait
		 */
		virtual Color getColorToCheck();

		/**
		 * \brief Definit si l'application doit se fermer
		 * 
		 * Methode qui definit si l'application doit se fermer
		 * 
		 * \param bool closeApp : si l'application doit se fermer
		 */
		virtual void setCloseApp(bool closeApp);

		/**
		 * \brief Verifie si l'application doit etre fermer 
		 * 
		 * Methode qui verifie si l'application doit etre fermé
		 * 
		 * \return true : l'application doit se fermer
		 * \return false : l'application doit rester ouverte
		 */
		virtual bool isCloseApp();

		/**
		 * \brief Supprime le model
		 * 
		 * Methode qui supprime le model
		 * 
		 */
		virtual void deleteObject();

		/**
		 * \brief Definit si l'application doit etre dans le menu
		 * 
		 * Methode qui definit si l'application doit etre dans le menu
		 * 
		 * \param bool menu : si l'application doit etre dans le menu
		 */
		virtual void setMenu(bool menu);

		/**
		 * \brief Verifie si l'application est dans le menu de selection 
		 * 
		 * Methode qui verifie si l'application est dans le menu de selection 
		 * 
		 * \return true : l'application est dans le menu
		 * \return false : l'application n'est pas dans le menu
		 */
		virtual bool isMenu();
};

#endif