#ifndef MAP_H
#define MAP_H

class Map{

	private:
		char **_map;

	public:
		Map(char **map);
		int * compute_nears_visitors_bike(int bike);

};

#endif