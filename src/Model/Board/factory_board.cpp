#include <factory_board.h>

IBoard* FactoryBoard::create(){
	return new Board();
}

IBoard* FactoryBoard::create(int height, int length){
	return new Board(height,length);
}