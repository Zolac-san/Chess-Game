#include <factory_aichoice.h>

AIChoice* FactoryAIChoice::create(){
	return new AIChoice();
}

AIChoice* FactoryAIChoice::create(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece){
	return new AIChoice(stateOfChoice,startPiece, endPiece);
}

AIChoice* FactoryAIChoice::create(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece, PieceType choicePromote){
	return new AIChoice(stateOfChoice, startPiece, endPiece, choicePromote);
}
