
#include "init-step/votation.h"
#include "misc/random_index.h"

/* (starting node) initialization of the votation message
	simply put the 0 node as the voted one, the node calling
	this function should always call vote_do_votation immediately
	after to insert its choice
*/
void vote_init( votation_t* msg )
{
    msg->voted_node = 0;
}

/*
    votation function: it chooses the node and write it into the message
    note that it also modifies the counter within the message.
*/
void vote_do_votation( votation_t* msg )
{
	int len = iptab_len();
    node_id n = rdmindex(0, len);
    msg->voted_node = (msg->voted_node + n) % len;
}

// which is the lucky node?
node_id vote_getWinner( votation_t* msg )
{
    return msg->voted_node;
}

