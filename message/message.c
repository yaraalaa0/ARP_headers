#include "message.h"

// initialize the message
void msg_init( message_t* msg )
{
    msg->id = -1;
    msg->turnLeader = -1;
    
    msg->recvd.tv_sec = 0;
    msg->recvd.tv_usec = 0;
    
    msg->sent.tv_sec = 0;
    msg->sent.tv_usec = 0;

    bv_init( &msg->vis_set, iptab_len() );
}

// set receiving time time
void msg_set_recv( message_t* msg )
{
    gettimeofday( &msg->recvd, NULL );
}

// set the sending time
void msg_set_sent( message_t* msg )
{
    gettimeofday( &msg->sent, NULL );
}

// set id and turn leader
void msg_set_ids( message_t* msg, int id, int turn_leader )
{
    msg->id = id;
    msg->turnLeader = turn_leader;
}

// check if a node was already visited
int msg_visited( message_t* msg, int n )
{
    if( n > iptab_len() || n < 0 )
        return 1;
    
    if( bv_marked( &msg->vis_set, n ) )
        return 1;
    else
        return 0;
}

// mark a node as visited
void msg_mark( message_t* msg, int n )
{
    if( n > iptab_len() || n < 0 ) return;
    bv_mark( &msg->vis_set, n );
}

// check if there are unvisited nodes
int msg_all_visited( message_t* msg )
{
    return bv_all_marked( &msg->vis_set );
}