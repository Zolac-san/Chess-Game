#include <aichoice.h>


AIChoice::AIChoice(){
    this->stateOfChoice = MinMaxState::MAX;
    this->startPiece = {0,0};
    this->endPiece = {0,0};
    this->havePromotedPawn = false;
    this->choicePromote = PieceType::UNKNOW;
}



AIChoice::AIChoice(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece){
    this->stateOfChoice = stateOfChoice;
    this->startPiece = startPiece;
    this->endPiece = endPiece;
    this->havePromotedPawn = false;
    this->choicePromote = PieceType::UNKNOW;
}



AIChoice::AIChoice(MinMaxState stateOfChoice,Coordinate startPiece, Coordinate endPiece, PieceType choicePromote){
    this->stateOfChoice = stateOfChoice;
    this->startPiece = startPiece;
    this->endPiece = endPiece;
    this->havePromotedPawn = true;
    this->choicePromote = choicePromote;
}



void AIChoice::addChild(AIChoice* childAIChoice){
    this->childs.push_back(childAIChoice);
}


MinMaxState AIChoice::getState(){
    return this->stateOfChoice;
}



void AIChoice::setScore(double score){
    this->score = score;
}



double AIChoice::getScore(){
    if(this->childs.empty()) return score;
    double maxObtain = this->childs[0]->getScore();

    int neg = this->stateOfChoice == MinMaxState::MAX?1:-1;

    for(unsigned int i=1; i < this->childs.size(); i++){
        double theScore = this->childs[i]->getScore();
        if(neg * theScore > neg * maxObtain){
            maxObtain = theScore;
        }
    }
    return maxObtain;
}



AIChoice* AIChoice::getBestMove(){
    
    double maxObtain = this->childs[0]->getScore();
    
    AIChoice* bestChoice = this->childs[0];
    for(unsigned int i=1; i < this->childs.size(); i++){
        double theScore = this->childs[i]->getScore();
        if(theScore>maxObtain){
            maxObtain = theScore;
            bestChoice = this->childs[i];
        }
    }
    return bestChoice;
}


Coordinate AIChoice::getStartPiece(){
    return this->startPiece;
}


Coordinate AIChoice::getEndPiece(){
    return this->endPiece;
}


bool AIChoice::isPromotedPawn(){
    return this->havePromotedPawn;
}



PieceType AIChoice::getChoicePromote(){
    return this->choicePromote;
}