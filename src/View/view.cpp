#include <view.h>

View::View() : IView(){
    setModel(nullptr);
    setupTexture();
}


View::View(IModel* model) : IView(){
    setModel(model);
    setupTexture();
	this->getModel()->getWindow()->setSize(sf::Vector2u(512, 512));
}


void View::setupTexture(){
    this->createNewTexture(PieceType::PAWN,Color::WHITE,"../src/Picture/Piece/pawnWhite.png");
    this->createNewTexture(PieceType::PAWN,Color::BLACK,"../src/Picture/Piece/pawnBlack.png");

    this->createNewTexture(PieceType::ROOK,Color::WHITE,"../src/Picture/Piece/rookWhite.png");
    this->createNewTexture(PieceType::ROOK,Color::BLACK,"../src/Picture/Piece/rookBlack.png");

    this->createNewTexture(PieceType::BISHOP,Color::WHITE,"../src/Picture/Piece/bishopWhite.png");
    this->createNewTexture(PieceType::BISHOP,Color::BLACK,"../src/Picture/Piece/bishopBlack.png");
    
    this->createNewTexture(PieceType::KNIGHT,Color::WHITE,"../src/Picture/Piece/knightWhite.png");
    this->createNewTexture(PieceType::KNIGHT,Color::BLACK,"../src/Picture/Piece/knightBlack.png");

    this->createNewTexture(PieceType::QUEEN,Color::WHITE,"../src/Picture/Piece/queenWhite.png");
    this->createNewTexture(PieceType::QUEEN,Color::BLACK,"../src/Picture/Piece/queenBlack.png");

    this->createNewTexture(PieceType::KING,Color::WHITE,"../src/Picture/Piece/kingWhite.png");
    this->createNewTexture(PieceType::KING,Color::BLACK,"../src/Picture/Piece/kingBlack.png");
    
    if (!this->lightSquare.loadFromFile("../src/Picture/Board/lightSquare.png")){
        std::cout<<"error"<<std::endl;
    }
    if (!this->darkSquare.loadFromFile("../src/Picture/Board/darkSquare.png")){
        std::cout<<"error2"<<std::endl;
    }

    this->moveOn.loadFromFile("../src/Picture/Indication/moveOn.png");
    this->moveEat.loadFromFile("../src/Picture/Indication/moveEat.png");

    //fontInfo.loadFromFile("../src/Font/arial.ttf");
    //fontInfo.loadFromFile("../src/Font/Butter Layer.ttf");
	fontInfo.loadFromFile("../src/Font/Finished Sympathy.otf");
    //fontInfo.loadFromFile("../src/Font/roboclone.ttf");
    //fontInfo.loadFromFile("../src/Font/Soiled Doves.ttf");
    //fontInfo.loadFromFile("../src/Font/Wild Nature.ttf");
    textState.setFont(fontInfo);
    textState.setColor(sf::Color(50,50,50));
    textState.setStyle(sf::Text::Bold);
    textState.setCharacterSize(100);

	

	if(!fontSelect.loadFromFile("../src/Font/Butter Layer.ttf")) std::cout<<"error Load"<<std::endl;
	textSelect.setFont(fontSelect);
    
   
	
    alertCheck = sf::RectangleShape(sf::Vector2f(64,64));
    alertCheck.setFillColor(sf::Color(255,0,0,200));

	shapeSelect = sf::RectangleShape(sf::Vector2f(64,64));
	circleSelect = sf::CircleShape(8);
}

void View::createNewTexture(PieceType type, Color color, std::string filename){
    sf::Texture texture;
    if(!texture.loadFromFile(filename)){
        std::cout<< "error to load texture : "<<filename<<std::endl;
    }
    this->texturePieces[type][color] = texture;
}

sf::Texture* View::getTexture(PieceType type, Color color){
    return &this->texturePieces[type][color];
}


void View::setModel(IModel* model){
    this->model = model;
}

IModel* View::getModel(){
    return this->model;
}

void View::displayLoop(){

    sf::Sprite sprite;
	
    while(!this->getModel()->isCloseApp()){
        mtx.lock();
		

        if(this->getModel()->isCloseApp()) break;
		sf::RenderWindow* window = this->getModel()->getWindow();
		window->clear(sf::Color(30,30,30));

		if(this->getModel()->isMenu()){
			
			this->shapeSelect.setSize(sf::Vector2f(256,512));
			this->shapeSelect.setFillColor(sf::Color::White);
			this->shapeSelect.setPosition(0,0);
			window->draw(this->shapeSelect);
			this->shapeSelect.setFillColor(sf::Color::Black);
			this->shapeSelect.setPosition(256,0);
			window->draw(this->shapeSelect);
			
			
			textSelect.setFont(fontInfo);
			textSelect.setString(sf::String("WHITE"));
			textSelect.setColor(sf::Color::Black);
			textSelect.setStyle(sf::Text::Bold);
    		textSelect.setCharacterSize(80);
			textSelect.setPosition(30,50);
			window->draw(textSelect);
			
			textSelect.setColor(sf::Color::White);
			textSelect.setString("BLACK");
			textSelect.setPosition(275,50);
			window->draw(textSelect);

			textSelect.setCharacterSize(100);
			textSelect.setColor(sf::Color(60,60,60));
			textSelect.setString("DONE");
			textSelect.setPosition(150,370);
			window->draw(textSelect);


			textSelect.setFont(fontSelect);
			textSelect.setCharacterSize(60);

			textSelect.setColor(sf::Color::Black);
			textSelect.setString("Player");
			textSelect.setPosition(40,190);
			window->draw(textSelect);
			textSelect.setString("AI");
			textSelect.setPosition(40,280);
			window->draw(textSelect);
			
			textSelect.setColor(sf::Color::White);
			textSelect.setString("Player");
			textSelect.setPosition(300,190);
			window->draw(textSelect);
			textSelect.setString("AI");
			textSelect.setPosition(300,280);
			window->draw(textSelect);

			this->circleSelect.setFillColor(sf::Color::Black);
			if(this->getModel()->getPlayersColor(Color::WHITE)->isAI()) this->circleSelect.setPosition(15,313);
			else this->circleSelect.setPosition(15,223);
			window->draw(this->circleSelect);
			this->circleSelect.setFillColor(sf::Color::White);
			if(this->getModel()->getPlayersColor(Color::BLACK)->isAI()) this->circleSelect.setPosition(275,313);
			else this->circleSelect.setPosition(275,223);
			window->draw(this->circleSelect);

		}else{

			

			IBoard* board = this->getModel()->getBoard();
			
			

			if(this->getModel()->isPromotePawn()){
				
				window->setSize(sf::Vector2u(576, 512));
				sf::FloatRect visibleArea(0, 0, 576, 512);
				window->setView(sf::View(visibleArea));
				window->clear(sf::Color(30,30,30));
				for ( int type = PieceType::PAWN ; type != PieceType::KING; type++ )
				{
					PieceType typeP = static_cast<PieceType>(type);
					sprite.setPosition(board->getLength()*64,(type-1)*64);
					sprite.setTexture(*this->getTexture(typeP, this->getModel()->getPromotePawn()->getColor()));
					window->draw(sprite);
				}
			}else{
				window->setSize(sf::Vector2u(512, 512));
				sf::FloatRect visibleArea(0, 0, 512, 512);
				window->setView(sf::View(visibleArea));
			}

			//On separe la recherche et l'affichage pour un plsu jolie affichage
			Coordinate coordCellCheck = {-1,-1};
			if(this->getModel()->getStateGame() == StateGame::CHECK || this->getModel()->getStateGame() == StateGame::CHECKMATE){
				
			coordCellCheck = this->getModel()->getAllPieceOfTypeAndColor(PieceType::KING,this->getModel()->getColorToCheck())[0]->getCoordinate();     

			}

			for(int x = 0; x < board->getLength();x++){
				for(int y = 0; y <board->getHeight();y++){
					sprite.setPosition(x*64,y*64);
					
					if ((x+y)%2 == 0) sprite.setTexture(lightSquare);
					else sprite.setTexture(darkSquare);
					window->draw(sprite);

					if(coordCellCheck.x == x && coordCellCheck.y == y){
						alertCheck.setPosition(sf::Vector2f(coordCellCheck.x*64,coordCellCheck.y*64));
						window->draw(alertCheck);
					}


					if(board->isPiece(x,y)){
						Piece* piece = board->getSquarePiece(x,y);
						sprite.setTexture(*this->getTexture(piece->getTypePiece(), piece->getColor()));
						window->draw(sprite);
					}


				}
			}

			std::vector<Coordinate> tmp = this->getModel()->getPossibleMoves();
			for (unsigned int i = 0 ; i < tmp.size();i++){

				if (board->isPiece(tmp[i])) sprite.setTexture(moveEat);
				else sprite.setTexture(moveOn);

				sprite.setPosition(tmp[i].x*64,tmp[i].y*64);
				window->draw(sprite);
			}

			if(this->getModel()->getStateGame() == StateGame::STALEMATE){
				//affiche pat
				textState.setString("STALEMATE");
				textState.setPosition(40,190);
				window->draw(textState);
			}else if(this->getModel()->getStateGame() == StateGame::CHECKMATE){
				//affiche Echec et mat
				textState.setString("CHECKMATE");
				textState.setPosition(25,190);
				window->draw(textState);
			}
		
			
			
		}
		
		window->display();
		mtx.unlock();
		
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

    mtx.unlock();
}


