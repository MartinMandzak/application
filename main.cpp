#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int SIZE = 100;
std::vector<bool> board(SIZE,false);
//std::random_device rd; - slow-updating seed
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //quick-updating seed
std::mt19937 random_gen(seed); //pseudo random system using a random seed	
std::uniform_int_distribution<int> island_chance(0,9); //range dist, could be float by using "real"

void draw_board(){	
	for(int idx=0;idx<SIZE;idx++){
		if(idx%10 == 0){std::cout<<std::endl;}
		if(board[idx]){
			std::cout<<" O ";
		}else{
			std::cout<<" - ";
		}
	}
}

void generate_islands(){


	for(int idx = 0;idx<SIZE;idx++){
		int chance = island_chance(random_gen);
		if(chance ==9){
			board[idx] = true;
		}
	}
}

void game_of_life(int n_of_iterations){
	for(int n = 0;n < n_of_iterations;n++){
		generate_islands();
		draw_board();
		std::cout<<"\n\n\n";
	}
}

int main(){

	int n = 10;
	
	generate_islands();
	draw_board();

	return 0;  
}
