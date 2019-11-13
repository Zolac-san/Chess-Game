#include <model.h>


Model::Model(){


	this->playerToPlay = 0;
	this->turn = 1;
	this->board = nullptr;
	this->closeApp = false;
}

Model::~Model(){
	

	for (unsigned int i = 0 ; i < listPlayers.size() ; i++) listPlayers[i]->deleteObject();

	listPlayers.clear();
	board->deleteObject();
	
	if (promotePawn != nullptr) delete promotePawn;
	this->possibleMoves.clear();
	this->listTurn.clear();


}



std::vector<Piece*> Model::getAllPiece(){
	std::vector<Piece*> outputPiece;
	for (unsigned int i =0; i < listPlayers.size();i++){
		std::vector<Piece*> tmp = listPlayers[i]->getAllPieces();
		for (unsigned int j=0 ; j < tmp.size();j++){
			outputPiece.push_back(tmp[j]);
		}
	}
	return outputPiece;
}


std::vector<Piece*> Model::getAllPieceColor(Color color){
	return this->getPlayersColor(color)->getAllPieces();
}


std::vector<Piece*> Model::getAllPieceOfType(PieceType type){
	std::vector<Piece*> outputPiece;
	for (unsigned int i =0; i < listPlayers.size();i++){
		std::vector<Piece*> tmp = listPlayers[i]->getAllPiecesOfType(type);
		for (unsigned int j=0 ; j < tmp.size();j++){
			outputPiece.push_back(tmp[j]);
		}
	}
	return outputPiece;
}



std::vector<Piece*> Model::getAllPieceOfTypeAndColor(PieceType type,Color color){	
	return getPlayersColor(color)->getAllPiecesOfType(type);
}

IBoard* Model::getBoard(){
	return this->board;
}


void Model::setBoard(IBoard* board){
	this->board = board;
}


std::vector<IPlayer*> Model::getPlayers(){
	return this->listPlayers;
}


IPlayer* Model::getPlayersColor(Color color){
	for (unsigned int i = 0; i < listPlayers.size();i++){
		if (listPlayers[i]->getColor() == color) return listPlayers[i];
	}
	return nullptr;
}


void Model::addPlayer(IPlayer* player){
	listPlayers.push_back(player);
}


int Model::getNbPlayers(){
	return this->listPlayers.size();
}


int Model::getTurn(){
	return this->turn;
}

void Model::setTurn(int newTurn){
	this->turn = newTurn;
}

void Model::addTurn(){
	this->setTurn(this->getTurn()+1);
}

IPlayer* Model::getPlayerToPlay(){
	return this->listPlayers[playerToPlay];
}


void Model::setPlayerToPlay(int numPlayerToPlat){
	this->playerToPlay = numPlayerToPlat;
}

void Model::setWindow(sf::RenderWindow* window){
	this->window = window;
}


sf::RenderWindow* Model::getWindow(){
	return this->window;
}


void Model::setPossibleMoves(std::vector<Coordinate> listCoord){
	this->possibleMoves = listCoord;
}

std::vector<Coordinate> Model::getPossibleMoves(){
	return this->possibleMoves;
}

void Model::resetPossibleMoves(){
	this->possibleMoves.clear();
}


void Model::setSelectedSquare(Coordinate coord){
	this->selectedSquare = coord;
}


Coordinate Model::getSelectedSquare(){
	return this->selectedSquare;
}


int Model::getPlayerToPlayIndex(){
	return this->playerToPlay;
}


Color Model::getOtherColor(Color myColor){
	for (unsigned int i = 0; i < listPlayers.size();i++){
		if (listPlayers[i]->getColor() != myColor) return listPlayers[i]->getColor();
	}
	return Color::NONE;
}


std::string Model::getStringOfColor(Color color){
	switch(color){
		case Color::NONE : return "Incolore";
		case Color::WHITE : return "Blanc";
		case Color::BLACK : return "Noir";
		default: return "";
	}
	return "";
}

void Model::setFinish(bool finish){
	this->finish = finish;
}

bool Model::isFinish(){
	return this->finish;
}


void Model::setPromotePawn(Piece* promotePawn){
	this->promotePawn = promotePawn;
}


Piece* Model::getPromotePawn(){
	return this->promotePawn;
}


bool Model::isPromotePawn(){
	return this->getPromotePawn() != nullptr;
}

void Model::setWinner(Color winnerColor){
	this->winnerColor = winnerColor;
}


Color Model::getWinner(){
	return this->winnerColor;
}


void Model::setStateGame(StateGame stateGame){
	this->stateGame = stateGame;
}

StateGame Model::getStateGame(){
	return this->stateGame;
}

void Model::setColorToCheck(Color colorToCheck){
	this->colorToCheck = colorToCheck;
}

Color Model::getColorToCheck(){
	return this->colorToCheck;
}

void Model::setCloseApp(bool closeApp){
	this->closeApp = closeApp;
}

bool Model::isCloseApp(){
	return this->closeApp;
}

IModel* Model::copy(){
	IModel* modelCopy = new Model();
	modelCopy->setPlayerToPlay(this->getPlayerToPlayIndex());
	modelCopy->setTurn(this->getTurn());
	
	for (unsigned int i = 0 ; i < this->listPlayers.size(); i++){
		modelCopy->addPlayer(this->listPlayers[i]->copy());
	}

	modelCopy->setBoard(this->getBoard()->copy());
	// On relie les piece du board et des players
	
	std::vector<Piece*> allPieceCopy = modelCopy->getAllPiece();
	for (unsigned int i = 0 ; i<allPieceCopy.size();i++){
		modelCopy->getBoard()->setSquarePiece(allPieceCopy[i]->getCoordinate(),allPieceCopy[i]);
	}


	for (unsigned int i = 0 ; i < this->listTurn.size(); i++){
		modelCopy->addTurnMove(this->listTurn[i]);
	}


	modelCopy->setWindow(nullptr);

	modelCopy->setFinish(this->isFinish());
	modelCopy->setWinner(this->getWinner());
	
	modelCopy->setStateGame(this->getStateGame());
	modelCopy->setColorToCheck(this->getColorToCheck());

	modelCopy->setCloseApp(this->isCloseApp());

	return modelCopy;




}

void Model::deleteObject(){
	delete this;
}



void Model::addTurnMove(TurnMove newMove){
	this->listTurn.push_back(newMove);
}


std::vector<TurnMove> Model::getListTurnMove(){
	return this->listTurn;
}

void Model::setMenu(bool menu){
	this->menu = menu;
}

bool Model::isMenu(){
	return this->menu;
}