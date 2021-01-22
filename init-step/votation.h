#ifndef _VOTATION_H_
#define _VOTATION_H_
#include "address-table/addresstable.h"

// the type of the message reserved to the votation
typedef struct votation_message
{
    node_id voted_node;
}
votation_t;

// (starting node) initialization of the votation message
void vote_init( votation_t* msg );

/*
    votation function: it generates a random node_id among the
	existing ones, adds it to the previous value inserted and 
	computes the modulo by the number of nodes (table length).
	Since we have a sum of *len* values between 0 and *len*,
	all modulo *len* (performing the modulo at the end or at each
	step is mathematically equivalent, but by doing it at each step
	we can spare space)
*/
void vote_do_votation( votation_t* msg );

// 
node_id vote_getWinner( votation_t* msg );

#endif _VOTATION_H_