#include <factory_model.h>

IModel* FactoryModel::create(){
	return new Model();
}