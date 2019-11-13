#ifndef MODEL_H
#define MODEL_H


#include <imodel.h>




/**
 * \class Model 
 * \brief classe représentant le model
 * 
 * Cette classe représente la du model dnas la design pattern MVC. Elle comporte toutes les données du jeu.
 * 
 */
class Model : public IModel{
    

	sf::RenderWindow* window; /*!< fenetre du jeu */
	IBoard* board; /*!< plateau de jeu */

	
	int turn; /*!< numero du tour */
	std::vector<TurnMove> listTurn; /*!< liste des mouvements de chaque tour */
	int playerToPlay; /*!< indice du joueur qui doit jouer */
	std::vector<IPlayer*> listPlayers; /*!< liste des joueurs */
	
	std::vector<Coordinate> possibleMoves; /*!< liste des moves possibles par une piece */
	Coordinate selectedSquare; /*!< coordonnées de la piece selectionnée */
	Piece* promotePawn; /*!< piece qui doit etre promu */

	StateGame stateGame; /*!< etat de la partie */
	Color colorToCheck; /*!< couleur verifie lors de l'annalyse de la defaite */
	
	bool menu; /*!< l'application est dans le menu*/
	bool finish; /*!< boolean de partie fini */
	Color winnerColor; /*!< couleur du vainqueur */
	bool closeApp; /*!< boolean de l'application qui doit etre fermée */
	
    public:

		/**
		 * \brief Constructeur
		 * 
		 * Constructeur de la classe Model
		 * 
		 */
		Model();

		/**
		 * \brief Destructeur
		 * 
		 * Destructeur de la classe 
		 * 
		 */
		~Model();

		/**
		 * \brief Renvoie toutes les pieces
		 * 
		 * Methode qui renvoie toutes les pieces du plateau
		 * 
		 * \return std::vector<Piece*> : liste des pieces
		 */
		std::vector<Piece*> getAllPiece() override;

		/**
		 * \brief Renvoie toutes les pieces d'une couleur
		 * 
		 * Methode qui renvoie toutes les pieces d'une couleur du plateau
		 * 
		 * \param Color color : couleur des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'une couleur
		 */
        std::vector<Piece*> getAllPieceColor(Color color) override;

		/**
		 * \brief Renvoie toutes les pieces d'un type
		 * 
		 * Methode qui renvoie toutes les pieces d'un type du plateau
		 * 
		 * \param PieceType type : type des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'un type
		 */
		std::vector<Piece*> getAllPieceOfType(PieceType type) override;

		/**
		 * \brief Renvoie toutes les pieces d'une couleur et d'un type
		 * 
		 * Methode qui renvoie toutes les pieces d'une couleur et d'un type du plateau
		 * 
		 * \param PieceType type : type des pieces demandées
		 * \param Color color : couleur des pieces demandées
		 * \return std::vector<Piece*> : liste des pieces d'une couleur et d'un type
		 */
		std::vector<Piece*> getAllPieceOfTypeAndColor(PieceType type,Color color) override;

		/**
		 * \brief Definit le plateau
		 * 
		 * Methode qui definit le plateau du model
		 * 
		 * \param IBoard* board : plateau à mettre dans le model
		 */
		void setBoard(IBoard* board) override;

		/**
		 * \brief Renvoie le plateau du model
		 * 
		 * Methode qui renvoie le plateau du model
		 * 
		 * \return IBoard* : plateau du model
		 */
		IBoard* getBoard() override;

		/**
		 * \brief Renvoie la liste des joueurs
		 * 
		 * Methode qui renvoie la liste des joueurs
		 * 
		 * \return std::vector<IPlayer*> : liste des joueurs
		 */
		std::vector<IPlayer*> getPlayers() override;

		/**
		 * \brief Renvoie le joueur de la couleur demandé
		 * 
		 * Methode qui renvoie le joueur de la couleur demandées
		 * 
		 * \param Color color : couleur du joueur
		 * \return IPlayer* : joueur de la couleur demandé
		 */
		IPlayer* getPlayersColor(Color color) override;

		/**
		 * \brief Ajoute un joueur
		 * 
		 * Methode qui ajoute un joueur à la liste
		 * 
		 * \param IPlayer player : joueur à rajouter
		 */
		void addPlayer(IPlayer* player) override;

		/**
		 * \brief Renvoie le nombre de joueur
		 * 
		 * Methode qui renvoie le nombre de joueur
		 * 
		 * \return int : nombre de joueur
		 */
		int getNbPlayers() override;

		/**
		 * \brief Renvoie le numero du tour
		 * 
		 * Methode qui renvoie le numero du tour
		 * 
		 * \return int : numero du tour
		 */
		int getTurn() override;

		/**
		 * \brief Renvoie le joueur qui doit jouer
		 * 
		 * Methode qui renvoie le joueur qui doit jouer
		 * 
		 * \return IPlayer* : 
		 */
		IPlayer* getPlayerToPlay() override;

		/**
		 * \brief Definit le joueur qui doit jouer
		 * 
		 * Methode qui definit le joueur qui doit jouer
		 * 
		 * \param int numPlayerToPlat : indice du joueur qui doit jouer
		 */
		void setPlayerToPlay(int numPlayerToPlat) override;

		/**
		 * \brief Renvoie l'indice du joueur qui doit jouer
		 * 
		 * Methode qui renvoie l'indice du joueur qui doit jouer
		 * 
		 * \return int : l'indice du joueur
		 */
		int getPlayerToPlayIndex() override;

		/**
		 * \brief Definit la fenetre
		 * 
		 * Methode qui definit la fenetre du jeu
		 * 
		 * \param sf::RenderWindow* window : fenetre à assigner au model
		 */
		void setWindow(sf::RenderWindow* window) override;

		/**
		 * \brief Renvoie la fenetre
		 * 
		 * Methode qui renvoie la fenetre du jeu
		 * 
		 * \return sf::RenderWindow* : fenetre du jeu
		 */
		sf::RenderWindow* getWindow() override;

		/**
		 * \brief Definit le tour
		 * 
		 * Methode qui definit le numero du tour
		 * 
		 * \param int newTurn : le nouveau numero du tour
		 */
		void setTurn(int newTurn) override;

		/**
		 * \brief Incremente le tour de 1
		 * 
		 * Methode qui incremente le tour de 1
		 * 
		 */
		void addTurn() override;

		/**
		 * \brief Ajoute un nouveau tour de jeu
		 * 
		 * Methode qui rajoute un nouveau tour de jeu dans la liste
		 * 
		 * \param TurnMove newMove : le tour a rajouter
		 */
		void addTurnMove(TurnMove newMove) override;

		/**
		 * \brief Renvoie la liste des differents tours de jeu
		 * 
		 * Methode qui renvoie la liste des differents tours de jeu.
		 * 
		 * \return std::vector<TurnMove> : la liste des differents tours de jeu
		 */
		std::vector<TurnMove> getListTurnMove() override;

		/**
		 * \brief Definit la liste des deplacements possibles
		 * 
		 * Methode qui definit la liste des deplacements possibles ( par une piece )
		 * 
		 * \param std::vector<Coordinate> coord : liste des deplacements possibles 
		 */
		void setPossibleMoves(std::vector<Coordinate> coord) override;

		/**
		 * \brief Renvoie la liste des deplacements possible
		 * 
		 * Methode qui renvoie la liste des deplacements possible ( par une piece )
		 * 
		 * \return std::vector<Coordinate> : liste des deplacements possible
		 */
		std::vector<Coordinate> getPossibleMoves() override;

		/**
		 * \brief Reinitialise la liste des deplacements possible
		 * 
		 * Methode qui reinitialise la liste des deplacements possible
		 * 
		 */
		void resetPossibleMoves() override;

		/**
		 * \brief Definit les coordonnées de la case seletionné
		 * 
		 * Methode qui definit les coordonnées de la case selectionné (par le joueur )
		 * 
		 * \param Coordinate coord : coordonnées de la case 
		 */
		void setSelectedSquare(Coordinate coord) override;

		/**
		 * \brief Renvoie les coordonnées de la case selectionné
		 * 
		 * Methode qui renvoie les coordonnées de la case selectionné (par le joueur )
		 * 
		 * \return Coordinate : coordonnées de la case selectionné
		 */
		Coordinate getSelectedSquare() override;

		/**
		 * \brief Renvoie la couleur opposée
		 * 
		 * Methode qui renvoie la couleur opposée
		 * 
		 * \param Color myColor : la couleur choisie
		 * \return Color : la couleur qui n'est pas la couleur choisie
		 */
		Color getOtherColor(Color myColor) override;

		/**
		 * \brief Renvoie la version ecrite de la couleur
		 * 
		 * Methode qui transforme la couleur en sa version texte
		 * 
		 * \param Color color : couleur qui doit etre convertie
		 * \return std::string : la couleur en texte
		 */
		std::string getStringOfColor(Color color) override;

		/**
		 * \brief Definit la fin de partie
		 * 
		 * Methode qui definit si une partie est terminée ou non
		 * 
		 * \param bool finish : fin de partie
		 */
		void setFinish(bool finish) override;

		/**
		 * \brief Renvoie si la partie est finie ou non
		 * 
		 * Methode qui renvoie si la partie est finie ou non
		 * 
		 * \return true : la partie est finie
		 * \return false : la partie est en cours
		 */
		bool isFinish() override;

		/**
		 * \brief Copie le model
		 * 
		 * Methode qui copie le model
		 * 
		 * \return IModel* : copie du model
		 */
		IModel* copy() override;

		/**
		 * \brief Definit la piece qui doit etre promue
		 * 
		 * Methode qui definit la piece qui doit etre promue
		 * 
		 * \param Piece* promotePawn : piece qui doit etre promu
		 */
		void setPromotePawn(Piece* promotePawn) override;

		/**
		 * \brief Renvoie la piece qui doit etre promue
		 * 
		 * Methode qui renvoie la piece qui doit etre promue
		 * 
		 * \return Piece* : la piece qui doit etre promue
		 */
		Piece* getPromotePawn() override;

		/**
		 * \brief Verifie si une piece est en cours de promotion
		 * 
		 * Methode qui verifie si une piece est en cours de promotion
		 * 
		 * \return true : une piece est encours de promotion
		 * \return false : aucun piece en cours de promotion
		 */
		bool isPromotePawn() override;

		/**
		 * \brief Definit la couleur vainqueur
		 * 
		 * Methode qui definit la couleur du vainqueur
		 * 
		 * \param Color color : couleur du vainqueur
		 */
		void setWinner(Color color) override;

		/**
		 * \brief Renvoie la couleur du vainqueur
		 * 
		 * Methode qui renvoie la couleur du vainqueur
		 * 
		 * \return Color : couleur du vainqueur
		 */
		Color getWinner() override;

		/**
		 * \brief Definit l'etat de la partie
		 * 
		 * Methode qui definit l'etat de la partie
		 * 
		 * \param StateGame stateGame : l'etat de la partie
		 */
		void setStateGame(StateGame stateGame) override;

		/**
		 * \brief Renvoie l'etat de la partie
		 * 
		 * Methode qui renvoie l'etat de la partie
		 * 
		 * \return StateGame : l'etat de la partie
		 */
		StateGame getStateGame() override;

		/**
		 * \brief Definit la couleur pour laquel la verification de defaite a été fait
		 * 
		 * Methode qui definit la couleur pour laquel la verification de defaite a été fait
		 * 
		 * \param Color colorToCheck : couleur pour laquel la verification de defaite a été fait
		 */
		void setColorToCheck(Color colorToCheck) override;

		/**
		 * \brief Renvoie la couleur pour laquel la verification de defaite a été fait
		 * 
		 * Methode qui renvoie la couleur pour laquel la verification de defaite a été fait
		 * 
		 * \return Color : couleur pour laquel la verification de defaite a été fait
		 */
		Color getColorToCheck() override;

		/**
		 * \brief Definit si l'application doit se fermer
		 * 
		 * Methode qui definit si l'application doit se fermer
		 * 
		 * \param bool closeApp : si l'application doit se fermer
		 */
		void setCloseApp(bool closeApp) override;

		/**
		 * \brief Verifie si l'application doit etre fermer 
		 * 
		 * Methode qui verifie si l'application doit etre fermé
		 * 
		 * \return true : l'application doit se fermer
		 * \return false : l'application doit rester ouverte
		 */
		bool isCloseApp() override;

		/**
		 * \brief Supprime le model
		 * 
		 * Methode qui supprime le model
		 * 
		 */
		void deleteObject() override;

		/**
		 * \brief Definit si l'application doit etre dans le menu
		 * 
		 * Methode qui definit si l'application doit etre dans le menu
		 * 
		 * \param bool menu : si l'application doit etre dans le menu
		 */
		void setMenu(bool menu) override;

		/**
		 * \brief Verifie si l'application est dans le menu de selection 
		 * 
		 * Methode qui verifie si l'application est dans le menu de selection 
		 * 
		 * \return true : l'application est dans le menu
		 * \return false : l'application n'est pas dans le menu
		 */
		virtual bool isMenu() override;
};

#endif





