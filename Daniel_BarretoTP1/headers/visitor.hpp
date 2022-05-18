#ifndef VISITOR_H
#define VISITOR_H

#include "headers/bike.hpp"

#define PROPOSE -1
#define NO_MORE_PROPOSES -1
#define PROPOSAL_ACCEPTED 1
#define PROPOSAL_DISMISS 0

class Visitor{

	private:
		int _num_bikes;
		int _alloc_bike;
		int _bikes_list_pointer;
		int *_bikes_prefer_list;
		Bike *_bikes;

	public:

		Visitor();
		void delete_memory();
		int propose_next_bike();
		int get_alloc_bike();
		int set_prefer_list(Bike *bikes, int *prefer_bikes, int num_bikes);
};

#endif