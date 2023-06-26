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




#ifndef RAINDROP_H
#define RAINDROP_H

#include "randomAddition.h"		//	ReturnVectorValue
#include <vector>				//	vector
#include <wchar.h>				//	wchar_t


class Raindrop {

public:

	sudo_rand_vec rand_vec;

	Raindrop();
	void Rainfall();
	void GenerateRaindropXCoords();
	void GenerateRaindropLength();
	void GenerateRaindropShape();

	int GetRainXLocation();
	int GetRainYLocation();
	int GetRainLength();

	char showraindrop();

	void SetMaxXLoc(int&);
	int GetMaxXLoc();

private:
	int max_x_loc = 120;	//	default number
	struct rain_data {
		int raindrop_x, raindrop_y, raindrop_length;
		char raindrop_shape = '0';

	}raindrop;

	//	char vector containing printable characters
	std::vector<wchar_t> legal_chars = {	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
		'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 
		'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'O', 'T', 'O', 'K', 'O', 'K', 'U', 'S', 'A', 'N',
		'A', 'G', 'I', 'P', 'Q', 'R', 'V', 'W', 'X', 'Y', 'Z', /*'あ', 'い', 'う', 'え', 'お', 'か', 'き',
		'く', 'け', 'こ', 'さ', 'し', 'す', 'せ', 'そ', 'た', 'ち', 'つ', 'て', 'と', 'な', 'に', 'ぬ', 'ね',
		'の', 'は', 'ひ', 'ふ', 'へ', 'ほ', 'ま', 'み', 'む', 'め', 'も', 'や', 'ゆ', 'よ', 'ら', 'り', 'る',
		'れ', 'ろ', 'わ', 'を', 'ん',*/ '!', '%', '^', '&', '*', '#', '@', '?', '|', '[]' 
	
	};
};



#endif // !RAINDROP_H
