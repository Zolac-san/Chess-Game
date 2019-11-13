#include <factory_controller.h>

IController* FactoryController::create(){
	return new Controller();
}