#ifndef VIEW_H
#define VIEW_H

#include <iview.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <map>
#include <mutex>


extern std::mutex mtx;

/**
 * \class View
 * \brief Classe représentant une vue dans le pattern design MVC
 * 
 * Cette classe représente une vue dans le pattren design MVC. Elle comporte les different les moyen d'afficher, textures , poilice d'ecriture.
 * 
 */
class View : public IView{
    IModel* model; /*!< model utilisé par la vue */
    sf::Window* window; /*!< fenetre d'affichage */

    std::map<PieceType, std::map<Color,sf::Texture>> texturePieces; /*!< dictionnaire des textures */
    sf::Texture lightSquare; /*!< texture case claire */
    sf::Texture darkSquare; /*!< texture case foncée */
    sf::Texture moveOn; /*!< texture indicateur move possible */
    sf::Texture moveEat; /*!< texture indicateur manger possible */

    sf::RectangleShape alertCheck; /*!< rectangle pour signaler un echec pour un roi */

	sf::Font fontInfo; /*!< font du texte */
    sf::Text textState; /*!< texte de victoire ou null */
    
    
    sf::RectangleShape shapeSelect; /*!< rectangle pour decorer */
    sf::CircleShape circleSelect;/*!< cercle pour montrer la selection */
	sf::Font fontSelect; /*!< font du texte de selection*/
    sf::Text textSelect; /*!< texte de selection */


    /**
     * \brief Genere les textures
     * 
     * Methode qui genere les differentes texture qu'utilisera la vue 
     * 
     */
    void setupTexture();

    /**
     * \brief Creer une nouvelle texture
     * 
     * Methode qui creer une texture en chargeant un fichier passée en paramètre. L'ajoute a sa liste en fonction de sa couleur et du type de la piece
     * 
     * \param PieceType type : type de la piece
     * \param Color color : couleur de la piece
     * \param std::string filename : image à utiliser
     */
    void createNewTexture(PieceType type, Color color, std::string filename);


    /**
     * \brief Renvoie la texture correspondante
     * 
     * Methoed qui renvoie la texture correspondante au type de la piece et a la couleur de la piece.
     * 
     * \param PieceType type : type de la piece
     * \param Color color : couleur de la pice
     * \return sf::Texture* : texture demandée
     */
    sf::Texture* getTexture(PieceType type, Color color);


    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe View
         * 
         */
        View();

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe View 
         * 
         * \param IModel* model : model qu'utuilisera la vue pour les données
         */
        View(IModel* model);

        /**
         * \brief Definit le model
         * 
         * Methode qui definit le model qu'utilisera la vue.
         * 
         * \param IModel* model : model que la vue utilisera. 
         */
        void setModel(IModel* model) override;
        
        /**
         * \brief Renvoie le model
         * 
         * Methode qui renvoie le model utilisée par la vue
         * 
         * \return IModel* : model utilisé
         */
        IModel* getModel() override;

        /**
         * \brief Affiche les informations
         * 
         * Methode qui affiche les differents element dans la fenetre
         * 
         */
        void displayLoop() override;
        
};




#endif
