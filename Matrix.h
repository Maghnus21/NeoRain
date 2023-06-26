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



#ifndef MATRIX_H
#define MATRIX_H

#include "Raindrop.h"
#include "EraserRain.h"
#include "randomAddition.h"
#include <vector>
#include <string>
#include <thread>

class Matrix {

public:
	std::vector<Raindrop> rain;
	std::vector<EraserRain> pencil_op;

	sudo_rand_vec mat_rand_vec;

	Matrix();
	Matrix(int x, int y, float t);
	void GenerateMatrix();
	void GenerateRaindrop();
	void DestructRaindrop();
	void GenerateEraserRain(int&);
	void DestructEraserRain();
	void RaindropRandomSpawn();
	void UpdateMatrix();
	void PrintMatrix();


	int GetMatrixX() const;
	int GetMatrixY() const;
	static int GetRainDropCount();

	int GetSleeepTime();

private:
	//	specifications of matrix
	int matrix_x, matrix_y;

	//	wait time in ms
	float sleep_time;

	//	will be used to count number of current raindrops on screen
	static int rain_drop_count;
	static int eraser_rain_count;

	//	displayed matrix
	std::vector<std::vector<char>> mat;

};


#endif // !MATRIX_H
