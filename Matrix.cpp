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



#include "Matrix.h"
#include <iostream>		//	cout
#include <vector>		// vector
#include <string>		//	string
#include <random>		//	default_random_engine, uniform_int_distribution



int Matrix::rain_drop_count = 0;
int Matrix::eraser_rain_count = 0;

Matrix::Matrix()
{
	matrix_x = 120;
	matrix_y = 30;
	sleep_time = 200;

	//	resizes matrix mat with default values above
	mat.resize(matrix_x, std::vector<char>(matrix_y, ' '));
}

Matrix::Matrix(int x, int y, float t)
{
	matrix_x = x;
	matrix_y = y + 1;
	sleep_time = t;

	//	resizes matrix mat with values above
	mat.resize(matrix_x, std::vector<char>(matrix_y, ' '));
}

void Matrix::GenerateMatrix() 
{
	//	starts raindrop
	GenerateRaindrop();
	
	UpdateMatrix();
}

void Matrix::GenerateRaindrop() {
	Raindrop rd = Raindrop();
	rd.SetMaxXLoc(matrix_x);

	rain_drop_count++;

	rain.push_back(rd);

	//	resizes rain vector to ensure stability
	rain.resize(rain_drop_count);
}

void Matrix::DestructRaindrop() {
	std::vector<Raindrop> ::iterator it;

	it = rain.begin();

	rain.erase(it);

	rain_drop_count--;

	//	resizes rain vector to ensure stability
	rain.resize(rain_drop_count);
}

void Matrix::RaindropRandomSpawn() {
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(1, 100);

	e.seed((double)time(0) + mat_rand_vec.ReturnVectorValue());

	if (u(e) > 20) {
		return;
	}
	
	GenerateRaindrop();
}

//	Updates the matrix wth the new rain drop shapes
void Matrix::UpdateMatrix() 
{
	PrintMatrix();

	int k = 0;

	for (auto& rain_d : rain) {
		//	for each rain drop, rain_d, in rain vector, get location data and store shape data in matrix using rain_d location data
		if (rain_d.GetRainYLocation() < matrix_y) {
			int tempx = rain_d.GetRainXLocation();
			int tempy = rain_d.GetRainYLocation();

			mat[tempx][tempy] = rain_d.showraindrop();

			
			rain_d.GenerateRaindropShape();

			
		}
		else {
			DestructRaindrop();

			GenerateRaindrop();
		}

		rain_d.Rainfall();

		//	if any rain drops fall a certain distance, new eraser rain is generated
		if (rain_d.GetRainYLocation() == rain_d.GetRainLength()) {
			int k = rain_d.GetRainXLocation();
			GenerateEraserRain(k);
		}

		
	}


	//	for each eraser rain in pencil_op, each one "falls" and overrides existing rain shape with whitespace
		for (auto& e_rain : pencil_op) {
			if (e_rain.GetEraserRainY() < matrix_y) {
				int tempx = e_rain.GetEraserRainX();
				int tempy = e_rain.GetEraserRainY();

				mat[tempx][tempy] = e_rain.EraseRainTrail();

				e_rain.EraserRainFall();
			}
			else {
				DestructEraserRain();
			}			
		}
	
	
	RaindropRandomSpawn();
}

//	prints matrix inn terminal
void Matrix::PrintMatrix()
{
	/*
		|	X    		|
		|				|
		|		X   	|
		|				|
		|				|
		|			X	|		<----	end of printed matrix, matrix_y-1
		-----------------
		|			X	|		<----	real end of matrix, a "safe zone" where raindrop can be destroyed
		-----------------
	
	*/

	//	prints out matrix
	for (int i = 0; i < matrix_y - 1; i++) {
		for (int j = 0; j < matrix_x; j++) {
			std::wcout << mat[j][i];
		}
		std::cout << std::endl;
	}
}


int Matrix::GetMatrixX() const
{
	return matrix_x;
}

int Matrix::GetMatrixY() const
{
	return matrix_y;
}

int Matrix::GetRainDropCount()
{
	return rain_drop_count;
}


//	generates new eraser rain
void Matrix::GenerateEraserRain(int& rain_x) {
	EraserRain x = EraserRain(rain_x);

	eraser_rain_count++;

	pencil_op.push_back(x);

	pencil_op.resize(eraser_rain_count);
}

//	destructs eraser rain
void Matrix::DestructEraserRain() {
	std::vector<EraserRain> ::iterator it;

	it = pencil_op.begin();

	pencil_op.erase(it);

	eraser_rain_count--;

	pencil_op.resize(eraser_rain_count);
}

int Matrix::GetSleeepTime() {
	return sleep_time;
}