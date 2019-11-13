#include <factory_player.h>

IPlayer* FactoryPlayer::create(Color color,bool ai){
	return new Player(color,ai);
}