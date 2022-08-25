#include <iostream>
#include <stack>
#include "headers/visitor.hpp"
#include "headers/bike.hpp"

std::stack<Visitor> create_stack_visitors(Visitor *visitors);
char ** receive_map(char ** map, int rows, int columns);
int ** gale_shapley(Visitor *visitors, Bike *bikes, std::stack<Visitor> *visitors_no_bike, int num_visitors_bike);

int main(){

	int num_visitors_bike;
	int map_rows;
	int map_columns;

	std::cin >> num_visitors_bike;
	std::cin >> map_rows;
	std::cin >> map_columns;


	Visitor visitors[num_visitors_bike];
	Bike bikes[num_visitors_bike];
	std::stack<Visitor*> visitors_no_bike;

	char raw_map[map_rows][map_columns];

	raw_map = receive_map(map, map_rows, map_columns);

	Map map = Map(raw_map, map_rows, map_columns);
	
	for(int i = 0; i < num_visitors_bike; i++){
		bikes[i].set_nears_visitors(map.compute_nears_visitors_bike(i, num_visitors_bike), num_visitors_bike);
	}

	int *visitor_bikes_prefer;
	
	for(int i = 0; i < num_visitors_bike; i++){
		visitor_bikes_prefer = new int[num_visitors_bike];

		for(int j = 0; j < num_visitors_bike; j++){
			std::cin >> visitor_bikes_prefer[j];
		}
		visitors[i].set_prefer_list(i, bikes, visitor_bikes_prefer, num_visitors_bike);
	}

	create_stack_visitors(visitors);

	int **allocs = gale_shapley(visitors, bikes, visitors_no_bike, num_visitors_bike);

	for(int i = 0; i < num_visitors_bike; i++){
		std::cout << allocs[i][0] << allocs[i][1] << std::endl;
	}

	for(int i = 0; i < num_visitors_bike; i++){
		visitors[i].delete_memory();
		bike[i].delete_memory();
	}

	delete [] allocs;

	return 0;
}

char ** receive_map(char ** map, int rows, int columns){
	
	char** result = new char[rows][columns];
	for(int row = 0; row < rows, row++){
		for(int column = 0; column < columns; column++){
			std::cin >> result[row][column];
		}
	}
	return result;
}