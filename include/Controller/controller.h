#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <functional>
#include <icontroller.h>


#include <pawn.h>
#include <bishop.h>
#include <knight.h>
#include <rook.h>
#include <queen.h>
#include <king.h>
#include <model.h>
#include <thread>
#include <threadPool.h>
#include <cmath>
#include <ctime>
#include <view.h>
#include <board.h>
#include <player.h>
#include <factory_aichoice.h>
#include <factory_model.h>
#include <factory_piece.h>
#include <factory_player.h>
#include <factory_board.h>
#include <factory_view.h>
#include <factory_threadpool.h>

/**
 * \class Controller
 * \brief Classe représentant le controlleur dans l'architetcure MVC
 * 
 * Cette classe représente le controlleur dans l'architecture MVC. Il a les droit sur la vue et le model. Il peut aussi modifier le model. Cette classe gere toutes les interaction avce le joueur et le deroulement de la partie.
 * 
 */
class Controller : public IController{

    IModel* model; /*!< model du controlleur */
    IView* view; /*!< vue du controlleur */

    std::thread viewDisplay; /*!< thread de la vue */

    ThreadPool* pool; /*!<thread pool pour les differentes taches de l'ia  */

    std::clock_t startClock; /*!< timer pour l'arret de l'ia */

    /**
     * \brief Creer les pieces d'un joueur.
     * 
     * Genere et rajoute toutes les pieces de depart d'un joueur. Soit 1 roi, 1 reine, 2 fous, 2 cavaliers, 2 tours, 8 pions. 
     * 
     * \param IPlayer* player : Le joueur a qui on rajoute les pieces
     */
    void createStarterPlayer(IPlayer* player);

    /**
     * \brief Definit la position de la piece dans ses parametres et sur le plateau
     * 
     * Methode qui definit la position de la piece dans ses parametres et sur le plateau
     * 
     * \param int x : coordonnée x de la piece
     * \param int y : coordonnée y de la piece
     * \param Piece* piece : piece à placer
     */
    void setCoordinatePieceAndBoard(int x, int y, Piece* piece);

    /**
     * \brief Definit la position de la piece dans ses parametres et sur le plateau
     * 
     * Methode qui definit la position de la piece dans ses parametres et sur le plateau
     * 
     * \param Coordinate coord : coordonnées de la piece
     * \param Piece* piece : piece à placer
     */
    void setCoordinatePieceAndBoard(Coordinate coord, Piece* piece);

    /**
     * \brief Lance le thread de la vue
     * 
     * Fonction qui lance le thread de la vue
     * 
     */
    void launchView();

    /**
     * \brief Creer une copie d'un model avec le chnagement d'une piece par une nouvelle piece
     * 
     * Methode qui genere une copie du model passé en argument et modifie uen piece par une autre
     * 
     * \param IModel* modelRef : model à copier
     * \param Color color : couleur de la piece a rajouter
     * \param PieceType type : type de piece
     * \param Coordinate coord : coordonnées de la piece
     * \return IModel* : model copié
     */
    IModel* createCopyModelWithNewPiece(IModel* modelRef, Color color, PieceType type, Coordinate coord);
    
    /**
     * \brief Evalue un model
     * 
     * Evalue et donne un score au model passée en paraemetre
     * 
     * \param IModel* model : model à evaluer
     * \return double : score attribué
     */
    double evaluateModel(IModel* model);

    /**
     * \brief Etat de la recursive du Min-Max
     * 
     * Une etape dans l'algorithme du min-max.
     * 
     * \param IModel* modelCurrent : 
     * \param AIChoice* choiceTree : 
     * \param int depthCurrent : 
     * \param int depthMax : 
     */
    void nextMove(IModel* modelCurrent, AIChoice* choiceTree, int depthCurrent, int depthMax);
    
    /**
     * \brief Definit le model
     * 
     * Definit le model que le controlleur utilisera.
     * 
     * \param IModel model : model à utiliser
     */
    void setModel(IModel* model);

     /**
     * \brief Definit la vue
     * 
     * Definit la vue utilisé par le controlleur.
     * 
     * \param IView* view : vue que le controlleur utilisera
     */
    void setView(IView* view);

     /**
     * \brief Met en place le debut de partie
     * 
     * Definit tous les elements de base au deroulement de la partie tels que les piece, le numero du tour, les joueur, le plateau, etc...
     * 
     */
    void setupGame();

    /**
     * \brief Gere les inputs
     * 
     * Invoque les fonction associer a chaque input effectuer par le joueur
     * 
     */
    void input();

    /**
     * \brief Effectue les action relatif a un click
     * 
     * Mothode qui effectue les action relatif a un click. Dans le cas du jeu d'echec ce gere tous les click sur les differentes pieces
     * 
     */
    void click();

    /**
     * \brief Efface une piece
     * 
     * Effcae un piece aussi bien dans la liste des joueur que du plateau.
     * 
     * \param Piece* piece : piece à effacer
     */
    void erasePiece(Piece* piece);

    /**
     * \brief Passe au joueur suivant
     * 
     * Methode qui permet de changer de joueur. On passe au joueur suivant.
     * 
     */
    void nextPlayer();

    /**
     * \brief Verifie une victoire
     * 
     * Verifie les differents moyens de gagner et le rajoute dans l'etat du model
     * 
     * \param Color myColor : couleur pour laquelle on doit verifier la victoire
     */
    void checkVictory(Color myColor);

    /**
     * \brief Verifie si on peut bloquer le chemin
     * 
     * verifie si on peut bloquer le chemin pour que le piece en argument puisse en pas se faire manger.
     * 
     * \param Piece* pieceDef : piece à defendre
     * \return true : si on peut bloquer le chemin
     * \return false : si on ne peut pas bloquer le chemin
     */
    bool canBlockPath(Piece* pieceDef);

    /**
     * \brief Verifie si on peut bloquer le chemin
     * 
     * verifie si on peut bloquer le chemin pour que le piece en argument puisse en pas se faire manger dans le model passé en argument.
     * 
     * \param Piece* pieceDef : piece à defendre
     * \param IModel* model : model à utiliser pour la verification
     * \return true : si on peut bloquer le chemin
     * \return false : si on ne peut pas bloquer le chemin
     */
    bool canBlockPath(Piece* pieceDef,IModel* model);

    /**
     * \brief Verifie si un deplacement est encore possible
     * 
     * Methode qui defini si le joueur peut encore deplacer une piece ou non
     * 
     * \param Color color : couleur du joueur à verifier 
     * \return true : Le joueur peut encore deplacer une piece
     * \return false : Le pjoueur n'a plus de piece a deplacer
     */
    bool canMoveAtLeastOnePiece(Color color);

    /**
     * \brief Verifie si un deplacement est encore possible
     * 
     * Methode qui defini si le joueur peut encore deplacer une piece ou non
     * 
     * \param Color color : couleur du joueur à verifier 
     * \param IModel* model : model à utiliser
     * \return true : Le joueur peut encore deplacer une piece
     * \return false : Le pjoueur n'a plus de piece a deplacer
     */
    bool canMoveAtLeastOnePiece(Color color, IModel* model);

    /**
     * \brief Verifie la defaite
     * 
     * Verifie la defaite pour la couleur passée en argument.
     * 
     * \param Color color : couleur qu'on doit verifier
     * \return StateGame : etat du plateau par rapport a cette couleur
     */
    StateGame checkDefeatForOneColor(Color color);

    /**
     * \brief Verifie la defaite pour l'autre couleur
     * 
     * Verifie la defaite pour la couleur inverse que celle passée  en argument.
     * 
     * \param Color color : couleur qu'on doit verifier
     * \return StateGame : etat du plateau par rapport a cette couleur
     */
    StateGame checkDefeatForOtherColor(Color myColor);

    /**
     * \brief Verifie si les 6 dernier mouvement sont juste les memes.
     * 
     * Verifie si les 6 derniers mouvement effectue. Elle verifie si les pieces ne font pas des va et viens.
     * 
     * \param std::vector<TurnMove> list : liste des mouvement effectue
     * \return true : les mouvement sont des va et viens
     * \return false : aucune logique dans les mouvements
     */
    bool threeTimeSameMove(std::vector<TurnMove> list);

    /**
     * \brief Lance l'IA
     * 
     * Permetde lancer la reflection de l'IA sur l'alforithme du min-max
     * 
     */
    void AI();

    public:

        /**
         * \brief Constructeur
         * 
         * Constructeur de la classe Controller
         * 
         */
        Controller();

        /**
         * \brief Renvoie le model
         * 
         * Renvoie le model utiliser par le controlleur.
         * 
         * \return IModel* : model utilisé par le controlleur 
         */
        IModel* getModel() override;

        /**
         * \brief Renvoie la vue
         * 
         * Renvoie la vue utilisé par le controlleur
         * 
         * \return IView* : vue utilisé par le controlleur
         */
        IView* getView() override;

        /**
         * \brief demarre le jeu
         * 
         * Demarre le jeu et effectue une boucle infini jusqu'a ce que la fenetre soit fermé
         * 
         */
        void start() override;

        
        /**
         * \brief Ferme l'application
         * 
         * Ferme la fenetre, met fin au thread pool et a la vue, et sort de la boucle infini genere par la fonction start
         * 
         */
        void closeApp() override;

        
};


#endif