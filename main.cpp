#include <iostream>
#include <vector>
#include <random>
#include <windows.h>
#include <chrono>
#include "ImaGen.h"
#include "opencv2/highgui/highgui.hpp" //:CLUELESS:

/*
 * https://www.geeksforgeeks.org/opencv-c-plus-plus-program-to-create-a-single-colored-blank-image/
 */

int SIDE = 200;
int AREA = pow(SIDE,2);

std::vector<bool> board(AREA,false);
//std::random_device rd; - slow-updating seed

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); //quick-updating seed
std::mt19937 random_gen(seed); //pseudo random system using a random seed	
std::uniform_int_distribution<int> island_chance(0,9); //range dist, could be float by using "real"

auto pixels = new unsigned char[SIDE*SIDE*3]; //3 for rgb
void map_output(unsigned char oneByte){ fputc(oneByte,fopen("./maps","w"));};

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



int main(){

	int n = 100;
	generate_islands();

	Mat img(SIDE,SIDE,CV_8UC3, Scalar(0,0,255));
	if(img.empty()){std::perror(ERROR);return 1;}

	return 0;  
}













