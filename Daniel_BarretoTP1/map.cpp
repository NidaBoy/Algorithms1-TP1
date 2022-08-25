#include "headers/map.hpp"
#include <cstdio>

Map::Map(char **map, int num_rows, int num_columns){
	this->_map_rows = num_rows;
	this->_map_columns = num_columns;
	this->_map = map;
}

int Map::compute_nears_visitors_bike(int bike, int num_visitors){
	
	int *result = new int[num_visitors]; 
	for(int i = 0; i < this->_num_rows; i++){
		for(int j = 0; j < this->_num_columns; j++){
			if(this->_map[i][j] == sprintf("%d", bike)){
				compute_cell(bike, i + 1, j, result);
				compute_cell(bike, i - 1, j, result);
				compute_cell(bike, i, j + 1, result);
				compute_cell(bike, i, j - 1, result);
				break;
			}
		}
	}

}
void Map::compute_cell(int bike, int row, int colum, int *result){

	if((row > this->_num_rows - 1) || (colum > this->_num_columns - 1)){
		return;
	}

	if(this->_map[row][colum] == '-'){
		return;
	}

	if(this->_map[row][colum] == '*'){

	}

	if(this->)

	if(int(this->_map[row][colum]) == bike){

	}

}