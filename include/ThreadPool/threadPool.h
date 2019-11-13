#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <functional>
#include <aichoice.h>
#include <imodel.h>


/**
 * \class ThreadPool
 * \brief Classe représentant un thread pool
 * 
 * Cette classe permet de realiser un thread pool pour l'execution du code min-max
 * 
 */
class ThreadPool{


    /**
     * \struct ToTreat
     * \brief Structure représentant une tache à effectuer
     * 
     * Cette structure permet de stocker les differentes informations necessaire a l'execution de la tache par un thread
     * 
     */
    struct ToTreat{
        IModel* value1; /*!< valeur1 */
        AIChoice* value2; /*!< valeur2 */
        int value3; /*!< valeur3 */
        int value4; /*!< valeur4 */
        std::function<void(IModel*,AIChoice*,int,int)> function; /*!< fonction */
    };

    std::vector<std::thread> pool; /*!< liste des thread */
    std::vector<bool> threadWork; /*!< liste des thread qui sont en cours de fonctionnement */

    std::vector<ToTreat> entry; /*!< liste des entrée à traiter */

    std::mutex mtx; /*!< mutex lié a la condition variable */
    std::condition_variable cv; /*!< condition variable pour notifier les threads d'une nouvelle valeur */

    std::mutex mtxEntry; /*!< Mutex pour gerer les entrées */

    bool finishPool; /*!< boolean pour savoir si on doit finir le thread pool */


    public:

        /**
         * \brief Constructeur
		 * 
		 * Constructeur de la classe ThreadPool
         * 
         * \param int nbThread : nombre de thread à lancer
         */
        ThreadPool(int nbThread);

        /**
         * \brief Stock la tache
         * 
         * Moethoed qui stocke la tache a executer par les threads.
         * 
         * \param IModel* value1 : IModel à utiliser
         * \param AIChoice* value2 : AIChoice à utiliser
         * \param int value3 : int à utiliser
         * \param int value4 : int à utiliser
         * \param std::function<void(IModel*,AIChoice*,int,int)> function : fonction à utiliser
         */
        void execute(IModel* value1, AIChoice* value2, int value3, int value4, std::function<void(IModel*,AIChoice*,int,int)> function);
        
        /**
         * \brief renvoie si une tache est en cours d'execution
         * 
         * Methode qui renvoie si une tache est en cours d'execution.
         * 
         * \return true : une tache ou plus est en execution
         * \return false : aucune tache s'execute
         */
        bool haveTask();

        /**
         * \brief Fonction de bouclage pour un thread
         * 
         * Methode qui permet a un thread de boucler et recupere les taches et les executer
         * 
         * \param int ind : indice du thread dans la liste
         */
        void run(int ind);

        /**
         * \brief Met fin au ThreadPool
         * 
         * Methode qui demande l'arret des differents thread et du ThreadPool.
         * 
         */
        void end();  
};


#endif