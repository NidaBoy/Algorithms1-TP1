#ifndef MAP_H
#define MAP_H

class Map{

	private:
		char **_map;
		int _num_rows;
		int _num_columns;

	public:
		Map(char **map, int num_rows, int num_columns);
		int * compute_nears_visitors_bike(int bike, int num_visitors);
		void compute_cell(int row, int colum, int *result); 

};

#endif