#include <factory_square.h>

ISquare* FactorySquare::create(int x,int y){
	return new Square(x,y);
}