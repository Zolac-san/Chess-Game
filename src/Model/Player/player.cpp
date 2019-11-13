#include <player.h>

Player::Player(Color color, bool ai){
	this->color = color;
	this->ai = ai;
}

Player::~Player(){
	listPieces.clear();
}

Color Player::getColor(){
	return this->color;
}


std::vector<Piece*> Player::getAllPieces(){
	return this->listPieces;
}


std::vector<Piece*> Player::getAllPiecesOfType(PieceType type){
	std::vector<Piece*> outputListPiece;

	for (unsigned int i = 0; i < listPieces.size() ;i++){
		if (listPieces[i]->getTypePiece() == type) outputListPiece.push_back(listPieces[i]);
	}

	return outputListPiece;
}

void Player::addPiece(Piece* piece){
	piece->setColor(color);
	listPieces.push_back(piece);
}

void Player::erasePiece(Piece* piece){
	int index = 0;
	for (unsigned int i = 0; i < listPieces.size();i++){
		if (listPieces[i]->getCoordinate() == piece->getCoordinate() && listPieces[i]->getTypePiece() == piece->getTypePiece()) index = i;
	}
	listPieces.erase(listPieces.begin()+index);

}

IPlayer* Player::copy(){
	IPlayer* playerCopy = new Player(this->getColor(),this->isAI());
	for(unsigned int i = 0; i < this->listPieces.size(); i++){
		playerCopy->addPiece(this->listPieces[i]->copy());
	}
	return playerCopy;
}

void Player::deleteObject(){
	delete this;
}


void Player::setAI(bool ai){
    this->ai = ai;
}


bool Player::isAI(){
    return this->ai;
}