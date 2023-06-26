/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⡀⣴⡦⢲⣂⣇⣇⣴⣾⡶⢤⣄⠀⠀⠀⠀
⠀⠀⢀⠶⣭⡾⠛⡿⠿⣿⣟⢿⡿⡛⠻⢶⣋⣶⠄⣀
⠀⠰⣧⠞⠁⠀⠀⠀⠸⣿⣿⠄⠀⡇⠀⠀⢈⣷⡛⠁
⢸⠸⠥⠦⢀⠀⠀⠡⢀⠀⠀⣀⠄⠀⣀⣴⡛⠓⠄⠁
⠀⠀⠀⠀⠚⠭⡛⠖⡶⠶⠶⢶⠶⡯⠙⡔⠐⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠁⠑⠘⠀⠘⠓⠈⠁⠀⠀⠀⠀⠀

Maghnus O Donnell
*/



#include "Raindrop.h"
#include "Matrix.h"				//	max_x_loc
#include "randomAddition.h"		//	ReturnVectorValue
#include <random>				//	default_random_engine, uniform_int_distribution




Raindrop::Raindrop() {
	GenerateRaindropXCoords();
	GenerateRaindropShape();
	GenerateRaindropLength();
}

void Raindrop::Rainfall() {

	raindrop.raindrop_y++;
}

void Raindrop::GenerateRaindropXCoords() {
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(1, max_x_loc-1);

	e.seed((double)time(0) + rand_vec.ReturnVectorValue());

	raindrop.raindrop_x = u(e);
	raindrop.raindrop_y = 0;
}

void Raindrop::GenerateRaindropLength() {
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(8, 25);

	

	e.seed((double)time(0) + rand_vec.ReturnVectorValue());

	raindrop.raindrop_length = u(e);
}

void Raindrop::GenerateRaindropShape() {
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(0, legal_chars.size() - 1);

	e.seed((double)time(0) + rand_vec.ReturnVectorValue());
	float e_random_output = u(e);
	
	float random_output = u(e);
	float percent_chance = 10;
	float change_chance = random_output/percent_chance;		//

	
	//	small chance for rain shape to remain the same
	if (e_random_output > change_chance){
		raindrop.raindrop_shape = legal_chars[u(e)];
	}
}

int Raindrop::GetRainLength() {
	return raindrop.raindrop_length;
}

char Raindrop::showraindrop() {
	return raindrop.raindrop_shape;
}

int Raindrop::GetRainXLocation() {
	return raindrop.raindrop_x;
}

int Raindrop::GetRainYLocation() {
	return raindrop.raindrop_y;
}

int Raindrop::GetMaxXLoc() {
	return max_x_loc;
}

void Raindrop::SetMaxXLoc(int& value) {
	max_x_loc = value;
	GenerateRaindropXCoords();
}

