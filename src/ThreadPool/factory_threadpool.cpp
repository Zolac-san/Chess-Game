#include <factory_threadpool.h>

ThreadPool* FactoryThreadPool::create(int nbThread){
	return new ThreadPool(nbThread);
}