#include "addresstable.h"

#define __RAND_IDX(max) (int) ((double) rand() * ( (double) max / (double) RAND_MAX ))

// the type of the message reserved to the votation
typedef struct votation_message
{
    short int counter;
    short int node[__IP_TABLE_LEN];
}
votation_t;

// (starting node) initialization of the votation message
void vote_init( votation_t* msg );

/*
    votation function: it chooses the node and write it into the message
    note that it also modifies the counter within the message.
*/
void vote_do_votation( votation_t* msg );

// check if still there are nodes which haven't voted yet
int vote_endVotation( votation_t* msg );

// chi ha vinto la pirofila? 
int vote_getWinner( votation_t* msg );