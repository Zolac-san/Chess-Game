CFLAGS = -std=c++11 -c -Wall -I./include/ -I./include/Model/ -I./include/Model/Board/ -I./include/Model/Board/Square/ -I./include/Model/Player/ -I./include/Model/Player/Piece/ -I./include/Model/Player/Piece/Move/ -I./include/Controller/ -I./include/Controller/AI/ -I./include/Structure/ -I./include/View/ -I./include/ThreadPool/ 

game : src/main.cpp build/Controller/icontroller.o build/Controller/AI/factory_aichoice.o build/Controller/AI/aichoice.o build/Controller/controller.o build/Controller/factory_controller.o build/View/view.o build/View/factory_view.o build/View/iview.o build/Model/imodel.o build/Model/Board/Square/isquare.o build/Model/Board/Square/factory_square.o build/Model/Board/Square/square.o build/Model/Board/factory_board.o build/Model/Board/iboard.o build/Model/Board/board.o build/Model/Player/player.o build/Model/Player/iplayer.o build/Model/Player/factory_player.o build/Model/Player/Piece/pawn.o build/Model/Player/Piece/knight.o build/Model/Player/Piece/piece.o build/Model/Player/Piece/queen.o build/Model/Player/Piece/king.o build/Model/Player/Piece/factory_piece.o build/Model/Player/Piece/Move/move_forward.o build/Model/Player/Piece/Move/composite_move.o build/Model/Player/Piece/Move/move_around_king.o build/Model/Player/Piece/Move/imove.o build/Model/Player/Piece/Move/move_diagonal.o build/Model/Player/Piece/Move/move_jump.o build/Model/Player/Piece/Move/eat_diagonal_one_case.o build/Model/Player/Piece/Move/move_castling.o build/Model/Player/Piece/Move/icomposite_move.o build/Model/Player/Piece/Move/move_two_forward_one_time.o build/Model/Player/Piece/Move/move_line.o build/Model/Player/Piece/rook.o build/Model/Player/Piece/bishop.o build/Model/factory_model.o build/Model/model.o build/ThreadPool/factory_threadpool.o build/ThreadPool/threadPool.o 
	g++ $^ -o bin/game -std=c++11 -Wall -I./include/ -I./include/Structure/ -I./include/Controller/ -I./include/Controller/AI/ -I./include/Model/ -I./include/Model/Player/ -I./include/Model/Player/Piece/ -I./include/Model/Player/Piece/Move/ -I./include/Model/Board/ -I./include/Model/Board/Square/ -I./include/ThreadPool/ -I./include/View/ -lsfml-graphics -lsfml-window -lsfml-system -pthread

build/Controller/icontroller.o : src/Controller/icontroller.cpp include/Controller/icontroller.h
	g++ src/Controller/icontroller.cpp -o build/Controller/icontroller.o $(CFLAGS)

build/Controller/AI/factory_aichoice.o : src/Controller/AI/factory_aichoice.cpp include/Controller/AI/factory_aichoice.h
	g++ src/Controller/AI/factory_aichoice.cpp -o build/Controller/AI/factory_aichoice.o $(CFLAGS)

build/Controller/AI/aichoice.o : src/Controller/AI/aichoice.cpp include/Controller/AI/aichoice.h
	g++ src/Controller/AI/aichoice.cpp -o build/Controller/AI/aichoice.o $(CFLAGS)

build/Controller/controller.o : src/Controller/controller.cpp include/Controller/controller.h
	g++ src/Controller/controller.cpp -o build/Controller/controller.o $(CFLAGS)

build/Controller/factory_controller.o : src/Controller/factory_controller.cpp include/Controller/factory_controller.h
	g++ src/Controller/factory_controller.cpp -o build/Controller/factory_controller.o $(CFLAGS)

build/View/view.o : src/View/view.cpp include/View/view.h
	g++ src/View/view.cpp -o build/View/view.o $(CFLAGS)

build/View/factory_view.o : src/View/factory_view.cpp include/View/factory_view.h
	g++ src/View/factory_view.cpp -o build/View/factory_view.o $(CFLAGS)

build/View/iview.o : src/View/iview.cpp include/View/iview.h
	g++ src/View/iview.cpp -o build/View/iview.o $(CFLAGS)

build/Model/imodel.o : src/Model/imodel.cpp include/Model/imodel.h
	g++ src/Model/imodel.cpp -o build/Model/imodel.o $(CFLAGS)


build/Model/Board/factory_board.o : src/Model/Board/factory_board.cpp include/Model/Board/factory_board.h
	g++ src/Model/Board/factory_board.cpp -o build/Model/Board/factory_board.o $(CFLAGS)

build/Model/Board/iboard.o : src/Model/Board/iboard.cpp include/Model/Board/iboard.h
	g++ src/Model/Board/iboard.cpp -o build/Model/Board/iboard.o $(CFLAGS)

build/Model/Board/board.o : src/Model/Board/board.cpp include/Model/Board/board.h
	g++ src/Model/Board/board.cpp -o build/Model/Board/board.o $(CFLAGS)

build/Model/Player/player.o : src/Model/Player/player.cpp include/Model/Player/player.h
	g++ src/Model/Player/player.cpp -o build/Model/Player/player.o $(CFLAGS)

build/Model/Player/iplayer.o : src/Model/Player/iplayer.cpp include/Model/Player/iplayer.h
	g++ src/Model/Player/iplayer.cpp -o build/Model/Player/iplayer.o $(CFLAGS)

build/Model/Player/factory_player.o : src/Model/Player/factory_player.cpp include/Model/Player/factory_player.h
	g++ src/Model/Player/factory_player.cpp -o build/Model/Player/factory_player.o $(CFLAGS)

build/Model/Player/Piece/pawn.o : src/Model/Player/Piece/pawn.cpp include/Model/Player/Piece/pawn.h
	g++ src/Model/Player/Piece/pawn.cpp -o build/Model/Player/Piece/pawn.o $(CFLAGS)

build/Model/Player/Piece/knight.o : src/Model/Player/Piece/knight.cpp include/Model/Player/Piece/knight.h
	g++ src/Model/Player/Piece/knight.cpp -o build/Model/Player/Piece/knight.o $(CFLAGS)

build/Model/Player/Piece/piece.o : src/Model/Player/Piece/piece.cpp include/Model/Player/Piece/piece.h
	g++ src/Model/Player/Piece/piece.cpp -o build/Model/Player/Piece/piece.o $(CFLAGS)

build/Model/Player/Piece/queen.o : src/Model/Player/Piece/queen.cpp include/Model/Player/Piece/queen.h
	g++ src/Model/Player/Piece/queen.cpp -o build/Model/Player/Piece/queen.o $(CFLAGS)

build/Model/Player/Piece/king.o : src/Model/Player/Piece/king.cpp include/Model/Player/Piece/king.h
	g++ src/Model/Player/Piece/king.cpp -o build/Model/Player/Piece/king.o $(CFLAGS)

build/Model/Player/Piece/factory_piece.o : src/Model/Player/Piece/factory_piece.cpp include/Model/Player/Piece/factory_piece.h
	g++ src/Model/Player/Piece/factory_piece.cpp -o build/Model/Player/Piece/factory_piece.o $(CFLAGS)

build/Model/Player/Piece/Move/move_forward.o : src/Model/Player/Piece/Move/move_forward.cpp include/Model/Player/Piece/Move/move_forward.h
	g++ src/Model/Player/Piece/Move/move_forward.cpp -o build/Model/Player/Piece/Move/move_forward.o $(CFLAGS)

build/Model/Player/Piece/Move/composite_move.o : src/Model/Player/Piece/Move/composite_move.cpp include/Model/Player/Piece/Move/composite_move.h
	g++ src/Model/Player/Piece/Move/composite_move.cpp -o build/Model/Player/Piece/Move/composite_move.o $(CFLAGS)

build/Model/Player/Piece/Move/move_around_king.o : src/Model/Player/Piece/Move/move_around_king.cpp include/Model/Player/Piece/Move/move_around_king.h
	g++ src/Model/Player/Piece/Move/move_around_king.cpp -o build/Model/Player/Piece/Move/move_around_king.o $(CFLAGS)

build/Model/Player/Piece/Move/imove.o : src/Model/Player/Piece/Move/imove.cpp include/Model/Player/Piece/Move/imove.h
	g++ src/Model/Player/Piece/Move/imove.cpp -o build/Model/Player/Piece/Move/imove.o $(CFLAGS)

build/Model/Player/Piece/Move/move_diagonal.o : src/Model/Player/Piece/Move/move_diagonal.cpp include/Model/Player/Piece/Move/move_diagonal.h
	g++ src/Model/Player/Piece/Move/move_diagonal.cpp -o build/Model/Player/Piece/Move/move_diagonal.o $(CFLAGS)

build/Model/Player/Piece/Move/move_jump.o : src/Model/Player/Piece/Move/move_jump.cpp include/Model/Player/Piece/Move/move_jump.h
	g++ src/Model/Player/Piece/Move/move_jump.cpp -o build/Model/Player/Piece/Move/move_jump.o $(CFLAGS)

build/Model/Player/Piece/Move/eat_diagonal_one_case.o : src/Model/Player/Piece/Move/eat_diagonal_one_case.cpp include/Model/Player/Piece/Move/eat_diagonal_one_case.h
	g++ src/Model/Player/Piece/Move/eat_diagonal_one_case.cpp -o build/Model/Player/Piece/Move/eat_diagonal_one_case.o $(CFLAGS)

build/Model/Player/Piece/Move/move_castling.o : src/Model/Player/Piece/Move/move_castling.cpp include/Model/Player/Piece/Move/move_castling.h
	g++ src/Model/Player/Piece/Move/move_castling.cpp -o build/Model/Player/Piece/Move/move_castling.o $(CFLAGS)

build/Model/Player/Piece/Move/icomposite_move.o : src/Model/Player/Piece/Move/icomposite_move.cpp include/Model/Player/Piece/Move/icomposite_move.h
	g++ src/Model/Player/Piece/Move/icomposite_move.cpp -o build/Model/Player/Piece/Move/icomposite_move.o $(CFLAGS)

build/Model/Player/Piece/Move/move_two_forward_one_time.o : src/Model/Player/Piece/Move/move_two_forward_one_time.cpp include/Model/Player/Piece/Move/move_two_forward_one_time.h
	g++ src/Model/Player/Piece/Move/move_two_forward_one_time.cpp -o build/Model/Player/Piece/Move/move_two_forward_one_time.o $(CFLAGS)

build/Model/Player/Piece/Move/move_line.o : src/Model/Player/Piece/Move/move_line.cpp include/Model/Player/Piece/Move/move_line.h
	g++ src/Model/Player/Piece/Move/move_line.cpp -o build/Model/Player/Piece/Move/move_line.o $(CFLAGS)

build/Model/Player/Piece/rook.o : src/Model/Player/Piece/rook.cpp include/Model/Player/Piece/rook.h
	g++ src/Model/Player/Piece/rook.cpp -o build/Model/Player/Piece/rook.o $(CFLAGS)

build/Model/Player/Piece/bishop.o : src/Model/Player/Piece/bishop.cpp include/Model/Player/Piece/bishop.h
	g++ src/Model/Player/Piece/bishop.cpp -o build/Model/Player/Piece/bishop.o $(CFLAGS)

build/Model/factory_model.o : src/Model/factory_model.cpp include/Model/factory_model.h
	g++ src/Model/factory_model.cpp -o build/Model/factory_model.o $(CFLAGS)

build/Model/model.o : src/Model/model.cpp include/Model/model.h
	g++ src/Model/model.cpp -o build/Model/model.o $(CFLAGS)

build/ThreadPool/factory_threadpool.o : src/ThreadPool/factory_threadpool.cpp include/ThreadPool/factory_threadpool.h
	g++ src/ThreadPool/factory_threadpool.cpp -o build/ThreadPool/factory_threadpool.o $(CFLAGS)

build/ThreadPool/threadPool.o : src/ThreadPool/threadPool.cpp include/ThreadPool/threadPool.h
	g++ src/ThreadPool/threadPool.cpp -o build/ThreadPool/threadPool.o $(CFLAGS)


build/Model/Board/Square/isquare.o : src/Model/Board/Square/isquare.cpp include/Model/Board/Square/isquare.h
	g++ src/Model/Board/Square/isquare.cpp -o build/Model/Board/Square/isquare.o $(CFLAGS)

build/Model/Board/Square/factory_square.o : src/Model/Board/Square/factory_square.cpp include/Model/Board/Square/factory_square.h
	g++ src/Model/Board/Square/factory_square.cpp -o build/Model/Board/Square/factory_square.o $(CFLAGS)

build/Model/Board/Square/square.o : src/Model/Board/Square/square.cpp include/Model/Board/Square/square.h
	g++ src/Model/Board/Square/square.cpp -o build/Model/Board/Square/square.o $(CFLAGS)
	
clean:
	find . -type f -name '*.o' -delete
