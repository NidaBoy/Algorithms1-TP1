#include "headers/visitor.hpp"
#include "headers/bike.hpp"

Bike::Bike(){
	this->_alloc_visitor = -1;
}

// ******************** Avaliar funções delete **********************
void Bike::delete_memory(){
	delete [] this->_rank_visitors;
}

int Bike::get_alloc_visitor(){
	return this->_alloc_visitor;
}

int Bike::compute_propose(Visitor * visitor){

	if(this->_alloc_visitor == -1){
		this->_alloc_visitor = visitor->get_id();
		return PROPOSAL_ACCEPTED;
	
	}else if(this->_rank_visitors[_alloc_visitor] < this->_rank_visitors[visitor->get_id()]){
		this->_alloc_visitor = visitor->get_id();
		return PROPOSAL_ACCEPTED;
	}
	return PROPOSAL_DISMISS;
}

void Bike::set_nears_visitors(int * nears_visitors, int num_visitors){
	this->_num_visitors = num_visitors;
	this->_rank_visitors = new int[num_visitors];
	
	for(int i = 0; i < num_visitors; i++){
		this->_rank_visitors[nears_visitors[i]] = i;
	}
}