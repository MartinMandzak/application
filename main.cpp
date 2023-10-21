#include <iostream>
#include <vector>
#include <random>

std::vector<bool> board(100,false);
std::random_device rd;

void draw_board(){	
	for(int idx=0;idx<board.size();idx++){
		if(idx%10 == 0){std::cout<<std::endl;}
		if(board[idx]){
			std::cout<<" O ";
		}else{
			std::cout<<" - ";
		}
	}
}

void generate_islands(){
	std::uniform_int_distribution<int> island_chance (0,9);
	std::cout<<island_chance(rd);
}

int main(){
	
	generate_islands();
	draw_board();

	return 0;  

}
