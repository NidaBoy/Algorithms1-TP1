#include "headers/visitor.hpp"
#include "headers/bike.hpp"

Visitor::Visitor(){
	this->_alloc_bike = -1;
	this->_bikes_list_pointer = 0;
}

void Visitor::delete_memory(){
	delete []this->_bikes_prefer_list;
}

int Visitor::propose_next_bike(){
	
	int current_prior = 0;
	for(int i = 0; i < num_bikes; i++){
		if(_bikes_prefer_list[current_prior] < _bikes_prefer_list[i]){
			current_prior = i;
		}
	}

	if(_bikes_prefer_list[current_prior] == -1){
		return NO_MORE_PROPOSES;
	}

	_bikes_prefer_list[current_prior] = -1;

	if(this->_bikes[current_prior].compute_propose(this)){
		this->_alloc_bike = current_prior;
		return PROPOSAL_ACCEPTED;
	}

	return PROPOSAL_DISMISS;
}

int Visitor::get_id(){
	return this->_id;
}

int Visitor::get_alloc_bike(){
	return this->_alloc_bike;
}

int Visitor::set_prefer_list(int id, Bike *bikes, int *prefer_bikes, int num_bikes){
	this->_id = id;
	this->_num_bikes = num_bikes;
	this->_alloc_bike = -1;
	this->bikes = bikes;
	this->_bikes_prefer_list = prefer_bikes;
}