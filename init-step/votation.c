#include "votation.h"

// (starting node) initialization of the votation message
void vote_init( votation_t* msg )
{
    msg->counter = iptab_len();
    for( int i=0; i<iptab_len(); i++ )
        msg->node[i] = 0;
}

/*
    votation function: it chooses the node and write it into the message
    note that it also modifies the counter within the message.
*/
void vote_do_votation( votation_t* msg )
{
    int n = __RAND_IDX( iptab_len() );
    msg->node[n] ++;
    msg->counter --;
}

// check if still there are nodes which haven't voted yet
int vote_endVotation( votation_t* msg )
{
    return ( msg->counter == 0 );
}

// which is the lucky node?
int vote_getWinner( votation_t* msg )
{
    int max = msg->node[0];
    int node = 0;

    for( int i=1; i<iptab_len(); i++)
    {
        if(( max < msg->node[i] ) || ( max == msg->node[i] && (rand() >= RAND_MAX / 2) )) 
        {
            max = msg->node[i];
            node = i;
        }
    }

    return node;
}