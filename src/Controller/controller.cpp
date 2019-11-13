#include <controller.h>

Controller::Controller(){
    this->setModel(FactoryModel::create());
	
    sf::RenderWindow* window = new sf::RenderWindow();
    this->getModel()->setWindow(window);
    this->getModel()->getWindow()->create(sf::VideoMode(512, 512), "Chess Game");
	this->pool = FactoryThreadPool::create(5);
	this->setView(FactoryView::create(this->model));
	
    this->setupGame();
    
}

void Controller::setupGame(){

    //Creation plateau de jeu
    this->getModel()->setBoard(FactoryBoard::create(8,8));


	//Creation joueur 1
    IPlayer* playerWhite = FactoryPlayer::create(Color::WHITE,false);
    createStarterPlayer(playerWhite);
    this->getModel()->addPlayer(playerWhite);
    
    //Creation joueur 2
    IPlayer* playerBlack = FactoryPlayer::create(Color::BLACK,false);
    createStarterPlayer(playerBlack);
    this->getModel()->addPlayer(playerBlack);


	this->getModel()->setMenu(true);
	viewDisplay = std::thread(&IView::displayLoop,this->getView());
	bool valid = false;
	
    sf::RenderWindow* window = this->getModel()->getWindow();
	
	while(!valid){
		sf::Event event;
		mtx.lock();
		while (window->pollEvent(event)){
        
        
			if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
				//click
				 sf::Vector2i positionMouse = sf::Mouse::getPosition(*this->getModel()->getWindow());
				 if(positionMouse.x>= 150 && positionMouse.x<= 358 && positionMouse.y>= 370 && positionMouse.y<= 470) valid = true;
				if(positionMouse.x>= 40 && positionMouse.x<= 220 && positionMouse.y >= 190 && positionMouse.y<= 255) this->getModel()->getPlayersColor(Color::WHITE)->setAI(false);
				if(positionMouse.x>= 40 && positionMouse.x<= 100 && positionMouse.y >= 280 && positionMouse.y<= 345) this->getModel()->getPlayersColor(Color::WHITE)->setAI(true);
				if(positionMouse.x>= 300 && positionMouse.x<= 480 && positionMouse.y >= 190 && positionMouse.y<= 255) this->getModel()->getPlayersColor(Color::BLACK)->setAI(false);
				if(positionMouse.x>= 300 && positionMouse.x<= 360 && positionMouse.y >= 280 && positionMouse.y<= 345) this->getModel()->getPlayersColor(Color::BLACK)->setAI(true);
			
			}
			
			

			if(event.type == sf::Event::Closed){
				this->closeApp();
				return;
			}
        
        
    	}
		mtx.unlock();
	}



    //Placement des pieces
    std::vector<Piece*> pawnWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::PAWN,Color::WHITE);
    std::vector<Piece*> pawnBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::PAWN,Color::BLACK);
    for(int x = 0; x < 8 ; x++){
        this->setCoordinatePieceAndBoard(x,6,pawnWhite[x]);
        this->setCoordinatePieceAndBoard(x,1,pawnBlack[x]);        
    }
    
    std::vector<Piece*> rookWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::ROOK,Color::WHITE);
    std::vector<Piece*> rookBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::ROOK,Color::BLACK);
    this->setCoordinatePieceAndBoard(0,7,rookWhite[0]);
    this->setCoordinatePieceAndBoard(7,7,rookWhite[1]);
    this->setCoordinatePieceAndBoard(0,0,rookBlack[0]);
    this->setCoordinatePieceAndBoard(7,0,rookBlack[1]);

    std::vector<Piece*> knightWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KNIGHT,Color::WHITE);
    std::vector<Piece*> knightBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KNIGHT,Color::BLACK);
    this->setCoordinatePieceAndBoard(1,7,knightWhite[0]);
    this->setCoordinatePieceAndBoard(6,7,knightWhite[1]);
    this->setCoordinatePieceAndBoard(1,0,knightBlack[0]);
    this->setCoordinatePieceAndBoard(6,0,knightBlack[1]);


    std::vector<Piece*> bishopWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::BISHOP,Color::WHITE);
    std::vector<Piece*> bishopBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::BISHOP,Color::BLACK);
    this->setCoordinatePieceAndBoard(2,7,bishopWhite[0]);
    this->setCoordinatePieceAndBoard(5,7,bishopWhite[1]);
    this->setCoordinatePieceAndBoard(2,0,bishopBlack[0]);
    this->setCoordinatePieceAndBoard(5,0,bishopBlack[1]);

    std::vector<Piece*> queenWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::QUEEN,Color::WHITE);
    std::vector<Piece*> queenBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::QUEEN,Color::BLACK);
    this->setCoordinatePieceAndBoard(3,7,queenWhite[0]);
    this->setCoordinatePieceAndBoard(3,0,queenBlack[0]);


    std::vector<Piece*> kingWhite = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KING,Color::WHITE);
    std::vector<Piece*> kingBlack = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KING,Color::BLACK);
    this->setCoordinatePieceAndBoard(4,7,kingWhite[0]);
    this->setCoordinatePieceAndBoard(4,0,kingBlack[0]);


    
    this->getModel()->setMenu(false);
}


void Controller::createStarterPlayer(IPlayer* player){
    for (int i = 0; i < 8; i++){
        player->addPiece(FactoryPiece::create(PieceType::PAWN));
    }
    for (int i = 0; i < 2; i++){
        player->addPiece(FactoryPiece::create(PieceType::BISHOP));
        player->addPiece(FactoryPiece::create(PieceType::KNIGHT));
        player->addPiece(FactoryPiece::create(PieceType::ROOK));
    }
    player->addPiece(FactoryPiece::create(PieceType::QUEEN));
    player->addPiece(FactoryPiece::create(PieceType::KING));
}

void Controller::setCoordinatePieceAndBoard(int x, int y, Piece* piece){
    this->getModel()->getBoard()->setSquarePiece(x,y,piece);
    piece->setCoordinate(x,y);
}


void Controller::setCoordinatePieceAndBoard(Coordinate coord, Piece* piece){
    this->getModel()->getBoard()->setSquarePiece(coord,piece);
    piece->setCoordinate(coord);
}


void Controller::setModel(IModel* model){
    this->model = model;
}

void Controller::setView(IView* view){
    this->view = view;
}

IModel* Controller::getModel(){
    return this->model;
}

IView* Controller::getView(){
    return this->view;
}

void Controller::input(){
    
    mtx.lock();
    sf::Event event;
    sf::RenderWindow* window = this->getModel()->getWindow();
    
    while (window->pollEvent(event)){
        
        
		if(!this->getModel()->getPlayerToPlay()->isAI() && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && !this->getModel()->isFinish() && this->getModel()->getStateGame() != StateGame::STALEMATE && this->getModel()->getStateGame() != StateGame::CHECKMATE){
			click();
		}
        
       

        if(event.type == sf::Event::Closed){
            this->closeApp();
        }
        
        
    }
	if(this->getModel()->getPlayerToPlay()->isAI() && !this->getModel()->isFinish() && this->getModel()->getStateGame() != StateGame::STALEMATE && this->getModel()->getStateGame() != StateGame::CHECKMATE){
        AI();
    }
    mtx.unlock();
}

void Controller::click(){
	

    IPlayer* playerToPlay = this->getModel()->getPlayerToPlay();

    sf::Vector2i positionMouse = sf::Mouse::getPosition(*this->getModel()->getWindow());
    std::vector<Coordinate> possibleMoves = this->getModel()->getPossibleMoves();
    IBoard* board = this->getModel()->getBoard();
    int x = std::floor(positionMouse.x/64); 
    int y = std::floor(positionMouse.y/64); 
    Coordinate posSquare = {x,y};
  
	if(this->getModel()->isPromotePawn()){
		if(posSquare.x == 8 && posSquare.y < 5){
			//On chnage la piece
			Piece* newPiece;
			if(posSquare.y == 0) newPiece = FactoryPiece::create(PieceType::PAWN, this->getModel()->getPromotePawn()->getColor(),this->getModel()->getPromotePawn()->getCoordinate());
			else if(posSquare.y == 1) newPiece = FactoryPiece::create(PieceType::BISHOP,this->getModel()->getPromotePawn()->getColor(),this->getModel()->getPromotePawn()->getCoordinate());
			else if(posSquare.y == 2) newPiece = FactoryPiece::create(PieceType::KNIGHT,this->getModel()->getPromotePawn()->getColor(),this->getModel()->getPromotePawn()->getCoordinate());
			else if(posSquare.y == 3) newPiece = FactoryPiece::create(PieceType::ROOK,this->getModel()->getPromotePawn()->getColor(),this->getModel()->getPromotePawn()->getCoordinate());
			else if(posSquare.y == 4) newPiece = FactoryPiece::create(PieceType::QUEEN,this->getModel()->getPromotePawn()->getColor(),this->getModel()->getPromotePawn()->getCoordinate());
			
            
            this->erasePiece(this->getModel()->getPromotePawn());

		
			board->setSquarePiece(newPiece->getCoordinate(),newPiece);
            this->getModel()->getPlayersColor(newPiece->getColor())->addPiece(newPiece);
			this->getModel()->setPromotePawn(nullptr);


            this->getModel()->addTurnMove({this->getModel()->getTurn(),this->getModel()->getSelectedSquare(),newPiece->getCoordinate(),PieceType::PAWN,newPiece->getColor(),newPiece->getTypePiece()});
			this->getModel()->addTurn();
			this->nextPlayer();

			checkVictory(newPiece->getColor());
		}
	}else{

	
		if(std::find(possibleMoves.begin(), possibleMoves.end(), posSquare) != possibleMoves.end()){

			Piece* pieceOnSquare = board->getSquarePiece(posSquare);
			board->setSquarePiece(posSquare,board->getSquarePiece(this->getModel()->getSelectedSquare()));
			board->setSquarePiece(this->getModel()->getSelectedSquare(),nullptr);
			board->getSquarePiece(posSquare)->setCoordinate(posSquare);

			

			//Check if move put my king into echec
			if( this->checkDefeatForOneColor(this->getModel()->getBoard()->getSquarePiece(posSquare)->getColor()) == StateGame::NOTHING){
				// coup valide
				if( pieceOnSquare != nullptr ) this->erasePiece(pieceOnSquare);
				board->getSquarePiece(posSquare)->setMoved(true);

				this->getModel()->resetPossibleMoves();

				if(board->getSquarePiece(posSquare)->getTypePiece() == PieceType::PAWN && posSquare.y == 0  && board->getSquarePiece(posSquare)->getColor() == Color::WHITE){
					this->getModel()->setPromotePawn(board->getSquarePiece(posSquare));
				}else if(board->getSquarePiece(posSquare)->getTypePiece() == PieceType::PAWN && posSquare.y == board->getHeight()-1  && board->getSquarePiece(posSquare)->getColor() == Color::BLACK){
					this->getModel()->setPromotePawn(board->getSquarePiece(posSquare));
				}else{
					if(board->getSquarePiece(posSquare)->getTypePiece() == PieceType::KING){
						if(this->getModel()->getSelectedSquare().x - posSquare.x == 2){
							board->setSquarePiece(3,posSquare.y,board->getSquarePiece(0,posSquare.y));
							board->setSquarePiece(0,posSquare.y,nullptr);
							board->getSquarePiece(3,posSquare.y)->setCoordinate(3,posSquare.y);
							board->getSquarePiece(3,posSquare.y)->setMoved(true);
						}else if (this->getModel()->getSelectedSquare().x - posSquare.x == -2){
							board->setSquarePiece(5,posSquare.y,board->getSquarePiece(7,posSquare.y));
							board->setSquarePiece(7,posSquare.y,nullptr);
							board->getSquarePiece(5,posSquare.y)->setCoordinate(5,posSquare.y);
							board->getSquarePiece(5,posSquare.y)->setMoved(true);
						}
					}
					

				

                    this->getModel()->addTurnMove({this->getModel()->getTurn(),this->getModel()->getSelectedSquare(),posSquare,board->getSquarePiece(posSquare)->getTypePiece(),board->getSquarePiece(posSquare)->getColor(),PieceType::UNKNOW});

					//PrepareNextTurn
					this->getModel()->addTurn();
					this->nextPlayer();

					checkVictory(board->getSquarePiece(posSquare)->getColor());
					
				}

				
			}
			else{
				std::cout<<"IMPOSSIBLE JE METS MON ROI EN ECHEC"<<std::endl;
				//remise avant
				board->getSquarePiece(posSquare)->setCoordinate(this->getModel()->getSelectedSquare());
				board->setSquarePiece(this->getModel()->getSelectedSquare(),board->getSquarePiece(posSquare));
				board->setSquarePiece(posSquare,pieceOnSquare);
				

			}

		
			
		}else if( board->isPiece(x,y) && board->getSquarePiece(x,y)->getColor() == playerToPlay->getColor()){

			std::vector<Coordinate> movementPieceSelected =  board->getSquarePiece(posSquare)->move(board);
			this->getModel()->setPossibleMoves(movementPieceSelected);
			this->getModel()->setSelectedSquare(posSquare);
		}else{
		
			this->getModel()->resetPossibleMoves();
		}
	}
}

void Controller::start(){
    std::cout<<"--------GAME START--------"<<std::endl;
    while(!this->getModel()->isCloseApp()){
        input();
    
    }
    std::cout<<"---------GAME END---------"<<std::endl;
}


void Controller::launchView(){
    this->getView()->displayLoop();
}


void Controller::erasePiece(Piece* piece){
    this->getModel()->getPlayersColor(piece->getColor())->erasePiece(piece);
}

void Controller::nextPlayer(){
    int tmp = (this->getModel()->getPlayerToPlayIndex() + 1) % this->getModel()->getNbPlayers();
    this->getModel()->setPlayerToPlay(tmp);
}


void Controller::checkVictory(Color myColor){
    StateGame stateEnnemy = this->checkDefeatForOtherColor(myColor);

	this->getModel()->setStateGame(stateEnnemy);
	this->getModel()->setColorToCheck(this->getModel()->getOtherColor(myColor));

	if(stateEnnemy == StateGame::CHECK){
		std::cout<<"ROI "<<this->getModel()->getStringOfColor(this->getModel()->getOtherColor(myColor))<<" EN ECHEC"<<std::endl;
	}else if(stateEnnemy == StateGame::CHECKMATE){
		std::cout<<"ROI "<<this->getModel()->getStringOfColor(this->getModel()->getOtherColor(myColor))<<" ECHEC ET MAT"<<std::endl;
		this->getModel()->setFinish(true);
		this->getModel()->setWinner(myColor);
		
		
	}if(stateEnnemy == StateGame::STALEMATE){
		std::cout<<"PAT"<<std::endl;
		this->getModel()->setFinish(true);
		this->getModel()->setWinner(Color::NONE);
		
	}
}


StateGame Controller::checkDefeatForOneColor(Color color){
    Piece* king = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KING,color)[0];

    
    if(this->getModel()->getBoard()->isSquareCanBeAttack(king->getCoordinate(),king->getColor())){
        Piece* pieceAttack = this->getModel()->getBoard()->getPieceWhoAttackThisSquare(king->getCoordinate(),king->getColor());
        if(!king->move(this->getModel()->getBoard()).empty() ){
            return StateGame::CHECK;
        }else if ( this->getModel()->getBoard()->howManyPieceCanAttack(king->getCoordinate(),king->getColor()) == 1 && this->getModel()->getBoard()->isSquareCanBeAttack(pieceAttack->getCoordinate(),pieceAttack->getColor())){
            return StateGame::CHECK;
        }else if(!this->canBlockPath(king)){
            return StateGame::CHECK;
        }else{
            return StateGame::CHECKMATE;
        }

    }else if( !this->canMoveAtLeastOnePiece(color) || threeTimeSameMove(this->getModel()->getListTurnMove()) || (this->getModel()->getAllPieceColor(Color::WHITE).size() == 1 && this->getModel()->getAllPieceColor(Color::BLACK).size() == 1)){
        return StateGame::STALEMATE;
    }
    return StateGame::NOTHING;
}


StateGame Controller::checkDefeatForOtherColor(Color myColor){
    Color colorToCheck = this->getModel()->getOtherColor(myColor);
    return this->checkDefeatForOneColor(colorToCheck); 
}


bool Controller::canBlockPath(Piece* pieceDef){
    
    std::vector<Piece*> listOfPiece = this->getModel()->getAllPieceColor(pieceDef->getColor());
    std::vector<Coordinate> listOfRemovePiece;
    for (unsigned int i =0; i < listOfPiece.size();i++){
        if(listOfPiece[i]->getTypePiece() != KING){
            listOfRemovePiece.clear();
            std::vector<Coordinate> squarePossible = listOfPiece[i]->move(this->getModel()->getBoard());

            for (unsigned int j = 0; j < squarePossible.size(); j++){
                if(!this->getModel()->getBoard()->isPiece(squarePossible[j])){
                    listOfRemovePiece.push_back(squarePossible[j]);
                    this->getModel()->getBoard()->setSquarePiece(squarePossible[j],FactoryPiece::create(PieceType::UNKNOW,pieceDef->getColor()));
                }
            }

            bool canBeAttack = this->getModel()->getBoard()->isSquareCanBeAttackWithoutKing(pieceDef->getCoordinate(),pieceDef->getColor());
            
            for (unsigned int i = 0; i < listOfRemovePiece.size();i++){
                this->getModel()->getBoard()->setSquarePiece(listOfRemovePiece[i],nullptr);
            }

            if(!canBeAttack) return false;
        }
    }

    

        
    return true;
}




bool Controller::canBlockPath(Piece* pieceDef,IModel* model){
    
    std::vector<Piece*> listOfPiece = model->getAllPieceColor(pieceDef->getColor());
    std::vector<Coordinate> listOfRemovePiece;
    for (unsigned int i =0; i < listOfPiece.size();i++){
        if(listOfPiece[i]->getTypePiece() != KING){
            listOfRemovePiece.clear();
            std::vector<Coordinate> squarePossible = listOfPiece[i]->move(model->getBoard());

            for (unsigned int j = 0; j < squarePossible.size(); j++){
                if(!model->getBoard()->isPiece(squarePossible[j])){
                    listOfRemovePiece.push_back(squarePossible[j]);
                    model->getBoard()->setSquarePiece(squarePossible[j],FactoryPiece::create(PieceType::UNKNOW,pieceDef->getColor()));
                }
            }

            bool canBeAttack = model->getBoard()->isSquareCanBeAttackWithoutKing(pieceDef->getCoordinate(),pieceDef->getColor());

            for (unsigned int i = 0; i < listOfRemovePiece.size();i++){
                model->getBoard()->setSquarePiece(listOfRemovePiece[i],nullptr);
            }

            if(!canBeAttack) return false;
        }
    }
    

        
    return true;
}

bool Controller::canMoveAtLeastOnePiece(Color color){
    std::vector<Piece*> allPieces = this->getModel()->getAllPieceColor(color);
    for (int i = 0; i < allPieces.size(); i++){
        if(!allPieces[i]->move(this->getModel()->getBoard()).empty()) return true;
    }
    return false;
}

bool Controller::canMoveAtLeastOnePiece(Color color,IModel* model){
    std::vector<Piece*> allPieces = model->getAllPieceColor(color);
    for (int i = 0; i < allPieces.size(); i++){
        if(!allPieces[i]->move(model->getBoard()).empty()) return true;
    }
    return false;
}

bool Controller::threeTimeSameMove(std::vector<TurnMove> list){
    if( list.size() < 6 ) return false;
    if( list[list.size()-1].isReverseOf(list[list.size()-3]) && list[list.size()-2].isReverseOf(list[list.size()-4]) &&list[list.size()-3].isReverseOf(list[list.size()-5])  && list[list.size()-4].isReverseOf(list[list.size()-6])){
		return true;
	}
    return false;
}


void Controller::closeApp(){
    this->getModel()->setCloseApp(true);
    this->viewDisplay.join();
    this->getModel()->getWindow()->close();
}


void Controller::AI(){
	
    if(this->getModel()->getStateGame() == StateGame::CHECKMATE ||this->getModel()->getStateGame() == StateGame::STALEMATE  ) return;
	
    startClock = std::clock();
    
    //Racine du choix ( pointeur car j'adore les pointeur)
    AIChoice* root = FactoryAIChoice::create();

	


    //Model Copie
    IModel* modelCopy = this->getModel()->copy();
	

    pool->execute(modelCopy,root,0,99, std::bind(&Controller::nextMove,this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

	mtx.unlock();

    while(pool->haveTask()) std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::this_thread::sleep_for(std::chrono::milliseconds(200));

	mtx.lock();

    AIChoice* bestMove = root->getBestMove();

	Piece* start = this->getModel()->getBoard()->getSquarePiece(bestMove->getStartPiece());
	Piece* end = this->getModel()->getBoard()->getSquarePiece(bestMove->getEndPiece());
	if(end != nullptr) this->getModel()->getPlayersColor(end->getColor())->erasePiece(end);
	this->getModel()->getBoard()->setSquarePiece(bestMove->getEndPiece(),start);
	this->getModel()->getBoard()->setSquarePiece(bestMove->getStartPiece(),nullptr);
	start->setCoordinate(bestMove->getEndPiece());
	start->setMoved(true);
   

	if(bestMove->isPromotedPawn()){
        
		Piece* newPiece = nullptr;
		if(bestMove->getChoicePromote() == PieceType::QUEEN){
			newPiece = FactoryPiece::create(PieceType::QUEEN,start->getColor(),start->getCoordinate());
		}else if(bestMove->getChoicePromote() == PieceType::ROOK){
			newPiece = FactoryPiece::create(PieceType::ROOK,start->getColor(),start->getCoordinate());
		}else if(bestMove->getChoicePromote() == PieceType::BISHOP){
			newPiece = FactoryPiece::create(PieceType::BISHOP,start->getColor(),start->getCoordinate());
		}else if(bestMove->getChoicePromote() == PieceType::KNIGHT){
			newPiece = FactoryPiece::create(PieceType::KNIGHT,start->getColor(),start->getCoordinate());
		}

		this->getModel()->getBoard()->setSquarePiece(bestMove->getEndPiece(),newPiece);
		this->getModel()->getPlayersColor(start->getColor())->erasePiece(start);
		this->getModel()->getPlayersColor(start->getColor())->addPiece(newPiece);
		

	}


	
		if(start->getTypePiece() == PieceType::KING){
			if(bestMove->getStartPiece().x - bestMove->getEndPiece().x == 2){
				this->getModel()->getBoard()->setSquarePiece(3,start->getCoordinate().y,this->getModel()->getBoard()->getSquarePiece(0,start->getCoordinate().y));
				this->getModel()->getBoard()->setSquarePiece(0,start->getCoordinate().y,nullptr);
				this->getModel()->getBoard()->getSquarePiece(3,start->getCoordinate().y)->setCoordinate(3,start->getCoordinate().y);
				this->getModel()->getBoard()->getSquarePiece(3,start->getCoordinate().y)->setMoved(true);
			}else if (bestMove->getStartPiece().x - bestMove->getEndPiece().x == -2){
				this->getModel()->getBoard()->setSquarePiece(5,start->getCoordinate().y,this->getModel()->getBoard()->getSquarePiece(7,start->getCoordinate().y));
				this->getModel()->getBoard()->setSquarePiece(7,start->getCoordinate().y,nullptr);
				this->getModel()->getBoard()->getSquarePiece(5,start->getCoordinate().y)->setCoordinate(5,start->getCoordinate().y);
				this->getModel()->getBoard()->getSquarePiece(5,start->getCoordinate().y)->setMoved(true);
			}
		}

        if(bestMove->isPromotedPawn()) this->getModel()->addTurnMove({this->getModel()->getTurn(),bestMove->getStartPiece(),bestMove->getEndPiece(),PieceType::PAWN,start->getColor(), bestMove->getChoicePromote()});
        else this->getModel()->addTurnMove({this->getModel()->getTurn(),bestMove->getStartPiece(),bestMove->getEndPiece(),start->getTypePiece(),start->getColor(),PieceType::UNKNOW});
		
        this->getModel()->addTurn();
		this->nextPlayer();

		checkVictory(start->getColor());


}

void Controller::nextMove(IModel* modelCurrent, AIChoice* choiceTree, int depthCurrent, int depthMax){

	//choiceTree->setScore(evaluateModel(modelCurrent));
    
    if (depthCurrent == depthMax || (( std::clock() - startClock ) / (double) CLOCKS_PER_SEC) > 1 ){

        AIChoice* nextAIChoice = new AIChoice();
        nextAIChoice->setScore(evaluateModel(modelCurrent));
        choiceTree->addChild(nextAIChoice);
        if(modelCurrent != nullptr) delete modelCurrent;
        return;
    }


    bool needToPass = true;
    std::vector<Piece*> allPieceColor = modelCurrent->getAllPieceColor(modelCurrent->getPlayerToPlay()->getColor());

	Piece* king = modelCurrent->getAllPieceOfTypeAndColor(PieceType::KING,modelCurrent->getPlayerToPlay()->getColor())[0];
    
    
    if(modelCurrent->getBoard()->isSquareCanBeAttack(king->getCoordinate(),king->getColor())){
        
        Piece* pieceAttack = modelCurrent->getBoard()->getPieceWhoAttackThisSquare(king->getCoordinate(),king->getColor());
        if( !((!king->move(modelCurrent->getBoard()).empty()) || ( modelCurrent->getBoard()->howManyPieceCanAttack(king->getCoordinate(),king->getColor()) == 1 && modelCurrent->getBoard()->isSquareCanBeAttack(pieceAttack->getCoordinate(),pieceAttack->getColor())) || (this->canBlockPath(king,modelCurrent) ) )){
            //Echec et mat
			AIChoice* nextAIChoice = FactoryAIChoice::create();
            if(this->getModel()->getPlayerToPlay()->getColor() == modelCurrent->getPlayerToPlay()->getColor()) nextAIChoice->setScore(-9999999);
            else nextAIChoice->setScore(evaluateModel(modelCurrent));
			
			choiceTree->addChild(nextAIChoice);
            needToPass =false;
            
        }

    }else if(!this->canMoveAtLeastOnePiece(king->getColor(),modelCurrent) || this->threeTimeSameMove(modelCurrent->getListTurnMove()) || (modelCurrent->getAllPieceColor(Color::WHITE).size() == 1 && modelCurrent->getAllPieceColor(Color::BLACK).size() == 1)){
        //exquo donc ca peut etre une bonne voie si on a aucun chan,ve de gagner
        AIChoice* nextAIChoice = FactoryAIChoice::create();
        nextAIChoice->setScore(evaluateModel(modelCurrent));
        choiceTree->addChild(nextAIChoice);
        needToPass = false;
        
    }
   
    if(needToPass){

        for (unsigned int indPiece = 0; indPiece < allPieceColor.size(); indPiece++){

            std::vector<Coordinate> movePiecePossible = allPieceColor[indPiece]->move(modelCurrent->getBoard());
            for(unsigned int indMove = 0 ; indMove < movePiecePossible.size(); indMove++){
                
                IModel* modelCopy = modelCurrent->copy();
             
                Piece* pieceStart = modelCopy->getBoard()->getSquarePiece(allPieceColor[indPiece]->getCoordinate());
                Piece* pieceEnd = modelCopy->getBoard()->getSquarePiece(movePiecePossible[indMove]);
                if(pieceEnd != nullptr) modelCopy->getPlayersColor(pieceEnd->getColor())->erasePiece(pieceEnd);


                

                modelCopy->getBoard()->setSquarePiece(movePiecePossible[indMove],pieceStart);
                modelCopy->getBoard()->setSquarePiece(pieceStart->getCoordinate(),nullptr);
                pieceStart->setCoordinate(movePiecePossible[indMove]);
                pieceStart->setMoved(true);

                modelCopy->resetPossibleMoves();
                //Fonction checkDefaeatForOneolor implement directly , see later if create fonction (because we need to pass imodle to arg)


                Piece* king = modelCopy->getAllPieceOfTypeAndColor(PieceType::KING,pieceStart->getColor())[0];
                if(!modelCopy->getBoard()->isSquareCanBeAttack(king->getCoordinate(),king->getColor())){
                    //Mon roi ne se fait  pas attaquer move possible
                    if(pieceStart->getTypePiece() == PieceType::PAWN && pieceStart->getCoordinate().y == 0  && pieceStart->getColor() == Color::WHITE){
                        //recreer chaque modele avec les differentes piece
                        AIChoice* nextAIChoice = nullptr;

                        IModel* modelCopyQueen = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::QUEEN,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::QUEEN);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyQueen->addTurnMove({modelCopyQueen->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::QUEEN});
                        modelCopyQueen->addTurn();
                        modelCopyQueen->setPlayerToPlay((modelCopyQueen->getPlayerToPlayIndex() + 1) % modelCopyQueen->getNbPlayers());
                        pool->execute(modelCopyQueen,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                        IModel* modelCopyRook = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::ROOK,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::ROOK);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyRook->addTurnMove({modelCopyRook->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::ROOK});
                        modelCopyRook->addTurn();
                        modelCopyRook->setPlayerToPlay((modelCopyRook->getPlayerToPlayIndex() + 1) % modelCopyRook->getNbPlayers());
                        pool->execute(modelCopyRook,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                        IModel* modelCopyBishop = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::BISHOP,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::BISHOP);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyBishop->addTurnMove({modelCopyBishop->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::BISHOP});
                        modelCopyBishop->addTurn();
                        modelCopyBishop->setPlayerToPlay((modelCopyBishop->getPlayerToPlayIndex() + 1) % modelCopyBishop->getNbPlayers());
                        pool->execute(modelCopyBishop,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));



                        IModel* modelCopyKnight = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::KNIGHT,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::KNIGHT);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyKnight->addTurnMove({modelCopyKnight->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::KNIGHT});
                        modelCopyKnight->addTurn();
                        modelCopyKnight->setPlayerToPlay((modelCopyKnight->getPlayerToPlayIndex() + 1) % modelCopyKnight->getNbPlayers());
                        pool->execute(modelCopyKnight,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                        

                    }else if(pieceStart->getTypePiece() == PieceType::PAWN && pieceStart->getCoordinate().y == modelCopy->getBoard()->getHeight()-1  && pieceStart->getColor() == Color::BLACK){
                        //recreer chaque modele avec les differentes piece
                       AIChoice* nextAIChoice = nullptr;

                        IModel* modelCopyQueen = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::QUEEN,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::QUEEN);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyQueen->addTurnMove({modelCopyQueen->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::QUEEN});
                        modelCopyQueen->addTurn();
                        modelCopyQueen->setPlayerToPlay((modelCopyQueen->getPlayerToPlayIndex() + 1) % modelCopyQueen->getNbPlayers());
                        pool->execute(modelCopyQueen,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                        IModel* modelCopyRook = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::ROOK,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::ROOK);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyRook->addTurnMove({modelCopyRook->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::ROOK});
                        modelCopyRook->addTurn();
                        modelCopyRook->setPlayerToPlay((modelCopyRook->getPlayerToPlayIndex() + 1) % modelCopyRook->getNbPlayers());
                        pool->execute(modelCopyRook,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                        IModel* modelCopyBishop = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::BISHOP,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::BISHOP);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyBishop->addTurnMove({modelCopyBishop->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::BISHOP});
                        modelCopyBishop->addTurn();
                        modelCopyBishop->setPlayerToPlay((modelCopyBishop->getPlayerToPlayIndex() + 1) % modelCopyBishop->getNbPlayers());
                        pool->execute(modelCopyBishop,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));



                        IModel* modelCopyKnight = createCopyModelWithNewPiece(modelCopy,pieceStart->getColor(),PieceType::KNIGHT,pieceStart->getCoordinate());
                        nextAIChoice = FactoryAIChoice::create( (choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(),PieceType::KNIGHT);
                        choiceTree->addChild(nextAIChoice);
                        modelCopyKnight->addTurnMove({modelCopyKnight->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), PieceType::PAWN, pieceStart->getColor(),PieceType::KNIGHT});
                        modelCopyKnight->addTurn();
                        modelCopyKnight->setPlayerToPlay((modelCopyKnight->getPlayerToPlayIndex() + 1) % modelCopyKnight->getNbPlayers());
                        pool->execute(modelCopyKnight,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));


                    }else{
                        if(pieceStart->getTypePiece() == PieceType::KING){
                            if(movePiecePossible[indMove].x - pieceStart->getCoordinate().x == 2){
                                modelCopy->getBoard()->setSquarePiece(3,pieceStart->getCoordinate().y,modelCopy->getBoard()->getSquarePiece(0,pieceStart->getCoordinate().y));
                                modelCopy->getBoard()->setSquarePiece(0,pieceStart->getCoordinate().y,nullptr);
                                modelCopy->getBoard()->getSquarePiece(3,pieceStart->getCoordinate().y)->setCoordinate(3,pieceStart->getCoordinate().y);
                                modelCopy->getBoard()->getSquarePiece(3,pieceStart->getCoordinate().y)->setMoved(true);
                            }else if (movePiecePossible[indMove].x - pieceStart->getCoordinate().x == -2){
                                modelCopy->getBoard()->setSquarePiece(5,pieceStart->getCoordinate().y,modelCopy->getBoard()->getSquarePiece(7,pieceStart->getCoordinate().y));
                                modelCopy->getBoard()->setSquarePiece(7,pieceStart->getCoordinate().y,nullptr);
                                modelCopy->getBoard()->getSquarePiece(5,pieceStart->getCoordinate().y)->setCoordinate(5,pieceStart->getCoordinate().y);
                                modelCopy->getBoard()->getSquarePiece(5,pieceStart->getCoordinate().y)->setMoved(true);
                            }
                        }

                        AIChoice* nextAIChoice = FactoryAIChoice::create((choiceTree->getState()== MinMaxState::MAX?MinMaxState::MIN:MinMaxState::MAX), allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate());
                        choiceTree->addChild(nextAIChoice);

                        modelCopy->addTurnMove({modelCopy->getTurn(),allPieceColor[indPiece]->getCoordinate(),pieceStart->getCoordinate(), pieceStart->getTypePiece(), pieceStart->getColor(),PieceType::UNKNOW});

                        //PrepareNextTurn
                        modelCopy->addTurn();
                        int tmp = (modelCopy->getPlayerToPlayIndex() + 1) % modelCopy->getNbPlayers();
                        modelCopy->setPlayerToPlay(tmp);
                        pool->execute(modelCopy,nextAIChoice,depthCurrent+1,depthMax,std::bind(&Controller::nextMove,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3,std::placeholders::_4));

                        //reexecfonction grace pool thread
                            
                    }
                }

                    
            }
        }
    }
    if(modelCurrent != nullptr) delete modelCurrent;
}

IModel* Controller::createCopyModelWithNewPiece(IModel* modelRef, Color color, PieceType type, Coordinate coord){
    IModel* modelCopy = modelRef->copy();
    modelCopy->getPlayersColor(color)->erasePiece(modelCopy->getBoard()->getSquarePiece(coord));
    Piece* newPiece = nullptr;
    if(type == PieceType::QUEEN){
        newPiece = FactoryPiece::create(PieceType::QUEEN,color,coord);
    }else if(type == PieceType::ROOK){
        newPiece = FactoryPiece::create(PieceType::ROOK,color,coord);
    }else if(type == PieceType::BISHOP){
        newPiece = FactoryPiece::create(PieceType::BISHOP,color,coord);
    }else if(type == PieceType::KNIGHT){
        newPiece = FactoryPiece::create(PieceType::KNIGHT,color,coord);
    }
    modelCopy->getPlayersColor(color)->addPiece(newPiece);
    modelCopy->getBoard()->setSquarePiece(coord,newPiece);
    return modelCopy;
}


double Controller::evaluateModel(IModel* model){
    
    Color myColor = this->getModel()->getPlayerToPlay()->getColor();
    int height = model->getBoard()->getHeight();
    int length = model->getBoard()->getLength();

	double score = 0;
    std::vector< std::vector<double> > pawnBoardWhite {
        {0,0,0,0,0,0,0,0},
        {5,5,5,5,5,5,5,5},
        {1,1,2,3,3,2,1,1},
        {0.5,0.5,1,2.5,2.5,1,0.5,0.5},
        {0,0,0,2,2.5,0,0,0},
        {0.5,-0.5,-1,0,0,-1,-0.5,0.5},
        {0.5,1,1,-2,-2,1,1,0.5},
        {0,0,0,0,0,0,0,0}
        
    };

    std::vector< std::vector<double> > bishopBoardWhite {
        {-2,-1,-1,-1,-1,-1,-1,-2},
        {-1,0,0,0,0,0,0,-1},
        {-1,0,0.5,1,1,0.5,0,-1},
        {-1,0.5,0.5,1,1,0.5,0.5,-1},
        {-1,0,1,1,1,1,0,-1},
        {-1,1,1,1,1,1,1,-1},
        {-1,0.5,0,0,0,0,0.5,-1},
        {-2,-1,-1,-1,-1,-1,-1,-2}
        
    };

    std::vector< std::vector<double> > knightBoardWhite {
        {-5,-4,-3,-3,-3,-3,-4,-5},
        {-4,-2,0,0,0,0,-2,-4},
        {-3,0,1,1.5,1.5,1,0,-3},
        {-3,0.5,1.5,2,2,1.5,0.5,-3},
        {-3,0,1.5,2,2,1.5,0,-3},
        {-3,0.5,1,1.5,1.5,1,0.5,-3},
        {-4,-2,0,0.5,0.5,0,-2,-4},
        {-5,-4,-3,-3,-3,-3,-4,-5}
        
    };

    std::vector< std::vector<double> > rookBoardWhite {
        {0,0,0,0,0,0,0,0},
        {0.5,1,1,1,1,1,1,0.5},
        {-0.5,0,0,0,0,0,0,-0.5},
        {-0.5,0,0,0,0,0,0,-0.5},
        {-0.5,0,0,0,0,0,0,-0.5},
        {-0.5,0,0,0,0,0,0,-0.5},
        {-0.5,0,0,0,0,0,0,-0.5},
        {0,0,0,0.5,0.5,0,0,0}
        
    };

    std::vector< std::vector<double> > queenBoardWhite {
        {-2,-1,-1,-0.5,-0.5,-1,-1,-2},
        {-1,0,0,0,0,0,0,-1},
        {-1,0,0.5,0.5,0.5,0.5,0,-1},
        {-0.5,0,0.5,0.5,0.5,0.5,0,-0.5},
        {0,0,0.5,0.5,0.5,0.5,0,-0.5},
        {-1,0.5,0.5,0.5,0.5,0.5,0,-1},
        {-1,0,0.5,0,0,0,0,-1},
        {-2,-1,-1,-0.5,-0.5,-1,-1,-2}
        
    };

    std::vector< std::vector<double> > kingBoardWhite {
        {-3,-4,-4,-5,-5,-4,-4,-3},
        {-3,-4,-4,-5,-5,-4,-4,-3},
        {-3,-4,-4,-5,-5,-4,-4,-3},
        {-3,-4,-4,-5,-5,-4,-4,-3},
        {-2,-3,-3,-4,-4,-3,-3,-2},
        {-1,-2,-2,-2,-2,-2,-2,-1},
        {2,2,0,0,0,0,2,2},
        {2,3,1,0,0,1,3,2} 
    };
    
    double colorMult = 1;
    if(myColor == Color::BLACK) colorMult = -1;

    std::vector<Piece*> myOwnPiece = model->getAllPieceColor(Color::WHITE);
	for (unsigned int i = 0; i < myOwnPiece.size();i++){
		
		switch(myOwnPiece[i]->getTypePiece()){
			case PieceType::KING:
				score += 900 * colorMult + 900 * colorMult * kingBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			case PieceType::QUEEN:
				score += 90 * colorMult + 90 * colorMult * queenBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			case PieceType::ROOK:
				score += 50 * colorMult + 50 * colorMult * rookBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			case PieceType::BISHOP:
				score += 30 * colorMult + 30 * colorMult * bishopBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			case PieceType::KNIGHT:
				score += 30 * colorMult + 30 * colorMult * knightBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			case PieceType::PAWN:
				score += 10 * colorMult + 10 * colorMult * pawnBoardWhite[myOwnPiece[i]->getCoordinate().y][myOwnPiece[i]->getCoordinate().x];
				break;
			default:
				break;	
		}
		

	}


	std::vector<Piece*> myEnnemyPiece = model->getAllPieceColor(Color::BLACK);
	for (unsigned int i = 0; i < myEnnemyPiece.size();i++){
		
		switch(myEnnemyPiece[i]->getTypePiece()){
			case PieceType::KING:
				score += -900 * colorMult - 900 * colorMult * kingBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			case PieceType::QUEEN:
				score += -90 * colorMult - 90 * colorMult * queenBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			case PieceType::ROOK:
				score += -50 * colorMult - 50 * colorMult * rookBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			case PieceType::BISHOP:
				score += -30 * colorMult - 30 * colorMult * bishopBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			case PieceType::KNIGHT:
				score += -30 * colorMult - 30 * colorMult * knightBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			case PieceType::PAWN:
				score += -10 * colorMult - 10 * colorMult * pawnBoardWhite[height-1-myEnnemyPiece[i]->getCoordinate().y][length-1-myEnnemyPiece[i]->getCoordinate().x];
				break;
			default:
				break;	
		}
		

	}


	//coef de survie
	std::vector<Piece*> listMyPiece = model->getAllPieceColor(myColor);
	int nbCanBeAttack = 0;
	for(int i = 0 ; i < listMyPiece.size();i++){
		if(model->getBoard()->isSquareCanBeAttack(listMyPiece[i]->getCoordinate(),myColor)){
			switch(listMyPiece[i]->getTypePiece()){
				case PieceType::KING:
					score -= 2700;
				case PieceType::QUEEN:
					score -= 270;
					break;
				case PieceType::ROOK:
					score -= 150;
					break;
				case PieceType::BISHOP:
					score -= 90;
					break;
				case PieceType::KNIGHT:
					score -= 90;
					break;
				case PieceType::PAWN:
					score -= 30;
					break;
				default:
					break;	
			}
			if(model->getBoard()->isSquareCanBeAttack(listMyPiece[i]->getCoordinate(),model->getOtherColor(myColor))){
				//elle est defendu
				switch(listMyPiece[i]->getTypePiece()){
					case PieceType::KING:
						score -= 0;
					case PieceType::QUEEN:
						score += 30;
						break;
					case PieceType::ROOK:
						score += 90;
						break;
					case PieceType::BISHOP:
						score += 150;
						break;
					case PieceType::KNIGHT:
						score += 150;
						break;
					case PieceType::PAWN:
						score += 270;
						break;
					default:
						break;	
				}
			}

		}
	}
	
	return score;
    
}