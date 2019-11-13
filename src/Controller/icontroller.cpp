#include <icontroller.h>

// Fichier juste pour initialiser les fonction pour les override par la suite

IModel* IController::getModel(){
    return nullptr;
}

IView* IController::getView(){
    return nullptr;
}

void IController::start(){

}

void IController::closeApp(){

}
