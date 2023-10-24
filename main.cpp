#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <windows.h>

int SIDE = 20;
int AREA = pow(SIDE,2);

std::vector<bool> board(AREA,false);
//std::random_device rd; - slow-updating seed

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //quick-updating seed
std::mt19937 random_gen(seed); //pseudo random system using a random seed	
std::uniform_int_distribution<int> island_chance(0,9); //range dist, could be float by using "real"

void draw_board(){	
	for(int idx=0;idx<AREA;idx++){
		if(idx%SIDE ==0){std::cout<<std::endl;}
		if(board[idx]){
			std::cout<<" O ";
		}else{
			std::cout<<"   ";
		}
	}
}

void generate_islands(){
	for(int idx = 0;idx<AREA;idx++){
		int chance = island_chance(random_gen);
		if(chance >=7){
			board[idx] = true;
		}
	}
}

int check_population(int idx){
	int relative_population = 0;

	if(idx-1 >=0 && board[idx-1]){
		relative_population++;
	}

	if(idx+1 < AREA && board[idx+1]){
		relative_population++;
	}
	if(idx-SIDE >=0 && board[idx-SIDE]){
		relative_population++;
	}
	if(idx+SIDE < AREA && board[idx+SIDE]){
		relative_population++;
	}
	if(idx-SIDE-1 >=0 && board[idx-SIDE-1]){
		relative_population++;
	}
	if(idx+SIDE+1 < AREA && board[idx+SIDE+1]){
		relative_population++;
	}
	if(idx-SIDE+1 >=0 && board[idx-SIDE+1]){
		relative_population++;
	}
	if(idx+SIDE-1 < AREA && board[idx+SIDE-1]){
		relative_population++;
	}
	return relative_population;
}

void game_of_life(int n_of_iterations){
	for(int n = 0;n <= n_of_iterations;n++){
		for(int idx=0;idx<AREA;idx++){
			int population = check_population(idx);
			if(board[idx]){
				if(population < 2 || population >3){
					board[idx] = false;
				}
			}else{
				if(population == 3){
					board[idx] = true;
				}
			}
		}
			draw_board();
			std::cout<<"\n\n\n";
			Sleep(250);
	}
}

int main(){

	int n = 100;
	
	generate_islands();
	draw_board();
	game_of_life(n);

	return 0;  
}
