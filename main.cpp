#include <iostream>
#include <vector>
#include <random>
#include <chrono>

int SIZE = 100;
std::vector<bool> board(SIZE,false);
//std::random_device rd; - slow-updating seed
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //quick-updating seed
std::mt19937 random_gen(seed);

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
	std::uniform_int_distribution<int> island_chance(0,9);
	for(int idx = 0;idx<SIZE;idx++){
		int chance = island_chance(random_gen);
		if(chance ==9){
			board[idx] = true;
		}
	}
}

int main(){
	
	generate_islands();
	draw_board();

	return 0;  

}
