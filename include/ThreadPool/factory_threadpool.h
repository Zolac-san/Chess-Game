#ifndef FACTORY_THREADPOOL_H
#define FACTORY_THREADPOOL_H

#include <threadPool.h>

/**
 * \brief Factory Threadpool
 * 
 * Factory permettant de creer un thread pool
 * 
 */
class FactoryThreadPool{
	public:
		/**
		 * \brief Creer un threadpool
		 * 
		 * Fonction qui creer un threadpool 
		 * 
		 * \param int nbThread : nombre de thread dans le threadpool
		 * \return ThreadPool* : threadpool
		 */
		static ThreadPool* create(int nbThread);
};

#endif