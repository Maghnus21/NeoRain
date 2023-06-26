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




#include "EraserRain.h"


EraserRain::EraserRain() {
	eraser_rain_data.eraser_x = 5;
	eraser_rain_data.eraser_y = 0;
	eraser_rain_data.eraser_shape = ' ';
}

EraserRain::EraserRain(int& rain_x_loc) {
	eraser_rain_data.eraser_x = rain_x_loc;
	eraser_rain_data.eraser_y = 0;
	eraser_rain_data.eraser_shape = ' ';

}


void EraserRain::EraserRainFall() {
	eraser_rain_data.eraser_y++;
}

char EraserRain::EraseRainTrail() {
	return eraser_rain_data.eraser_shape;
}

int EraserRain::GetEraserRainX() {
	return eraser_rain_data.eraser_x;
}

int EraserRain::GetEraserRainY() {
	return eraser_rain_data.eraser_y;
}