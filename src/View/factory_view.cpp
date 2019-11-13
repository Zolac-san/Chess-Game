#include <factory_view.h>

IView* FactoryView::create(){
	return new View();
}

IView* FactoryView::create(IModel* model){
	return new View(model);
}