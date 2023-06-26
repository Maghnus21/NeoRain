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


#include "Matrix.h"		//	matrix, GenerateMatrix, GetSleepTime, UpdateMatrix
#include <chrono>		//	milliseconds
#include <cstdlib>      // system
#include <io.h>         // _setmode()
#include <fcntl.h>      // _setmode()


int main() {
	//	error with fcntl.h library. 
	//_setmode(_fileno(stdout), _O_U16TEXT);

	std::system("COLOR 02");
	
	Matrix m = Matrix();
	m.GenerateMatrix();
	int screen_sleep_time = m.GetSleeepTime();

	while (1) 
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(screen_sleep_time));
		system("CLS");
		m.UpdateMatrix();
	}
	

	
	return 0;
}