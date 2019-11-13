#include <imodel.h>

std::vector<Piece*> IModel::getAllPiece(){
	return std::vector<Piece*>();
}

std::vector<Piece*> IModel::getAllPieceColor(Color color){
	return std::vector<Piece*>();
}

std::vector<Piece*> IModel::getAllPieceOfType(PieceType type){
	return std::vector<Piece*>();
}

std::vector<Piece*> IModel::getAllPieceOfTypeAndColor(PieceType type,Color color){
	return std::vector<Piece*>();
}

void IModel::setBoard(IBoard* board){
	
}

IBoard* IModel::getBoard(){
	return nullptr;
}

std::vector<IPlayer*> IModel::getPlayers(){
	return std::vector<IPlayer*>();
}

IPlayer* IModel::getPlayersColor(Color color){
	return nullptr;
}

void IModel::addPlayer(IPlayer* player){
	
}

int IModel::getNbPlayers(){
	return 0;
}

int IModel::getTurn(){
	return 0;
}


IPlayer* IModel::getPlayerToPlay(){
	return nullptr;
}

void IModel::setPlayerToPlay(int numPlayerToPlat){
	
}

int IModel::getPlayerToPlayIndex(){
	return 0;
}

void IModel::setWindow(sf::RenderWindow* window){
	
}

sf::RenderWindow* IModel::getWindow(){
	return nullptr;
}

void IModel::setTurn(int newTurn){
	
}

void IModel::addTurn(){
	
}

void IModel::setPossibleMoves(std::vector<Coordinate> coord){
	
}

std::vector<Coordinate> IModel::getPossibleMoves(){
	return std::vector<Coordinate>();
}

void IModel::resetPossibleMoves(){
	
}

void IModel::setSelectedSquare(Coordinate coord){
	
}

Coordinate IModel::getSelectedSquare(){
	return Coordinate();
}

Color IModel::getOtherColor(Color myColor){
	return Color::NONE;
}

std::string IModel::getStringOfColor(Color color){
	return "";
}

void IModel::setFinish(bool finish){
	
}

bool IModel::isFinish(){
	return false;
}


void IModel::setPromotePawn(Piece* promotePawn){
	
}

Piece* IModel::getPromotePawn(){
	return nullptr;
}

bool IModel::isPromotePawn(){
	return false;
}

void IModel::setWinner(Color color){
	
}

Color IModel::getWinner(){
	return Color::NONE;
}


void IModel::setStateGame(StateGame stateGame){
	
}

StateGame IModel::getStateGame(){
	return StateGame::NOTHING;
}

void IModel::setColorToCheck(Color colorToCheck){
	
}

Color IModel::getColorToCheck(){
	return Color::NONE;
}

void IModel::setCloseApp(bool closeApp){
	
}

bool IModel::isCloseApp(){
	return false;
}

//Copy All except winodw becose it's a unique thing
IModel* IModel::copy(){
	return nullptr;
}

void IModel::deleteObject(){

}

void IModel::addTurnMove(TurnMove newMove){

}

std::vector<TurnMove> IModel::getListTurnMove(){
	return std::vector<TurnMove>();
}

void IModel::setMenu(bool menu){

}

bool IModel::isMenu(){
	return false;
}