#include <iplayer.h>

// Fichier juste pour initialiser les fonction pour les override par la suite

IPlayer::IPlayer(){

}

IPlayer::~IPlayer(){

}

Color IPlayer::getColor(){
    return Color::NONE;
}

std::vector<Piece *> IPlayer::getAllPieces(){
    return std::vector<Piece *>();
}

std::vector<Piece *> IPlayer::getAllPiecesOfType(PieceType type){
    return std::vector<Piece *>();
}

void IPlayer::addPiece(Piece *piece){

}

void IPlayer::erasePiece(Piece *piece){

}

IPlayer* IPlayer::copy(){
    return nullptr;
}

void IPlayer::deleteObject(){
    
}

void IPlayer::setAI(bool ai){
    
}


bool IPlayer::isAI(){
    return false;
}