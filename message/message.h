#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <time.h>
#include <sys/time.h>
#include <limits.h>
#include "bitvector/bitvector.h"
#include "addresstable/addresstable.h"

#define __RAND_IDX(max) (int) ((double) rand() * ( (double) max / (double) RAND_MAX ))

// format of the message shared with the nodes of the network
typedef struct message
{
	node_id id;				/* the ID of the sender node */
	node_id turnLeader;		/* the ID of the actua turn leader */
	struct timeval recvd;	/* time instant in which the sender received the previous message */
	struct timeval sent;	/* time instant in which this message was sent */
	bitvector_t vis_set;	/* flags for visited nodes */
}
message_t;

// initialize the message
void msg_init( message_t* msg );

// set the receiving time
void msg_set_recv( message_t* msg );

// set the sending time
void msg_set_sent( message_t* msg );

// set id and turn leader
void msg_set_ids( message_t* msg, node_id id, node_id turn_leader );

// check if a node was already visited
int msg_visited( message_t* msg, node_id n );

// returns the number of visited nodes
int msg_numberVisited( message_t* msg);

// mark a node as visited
void msg_mark( message_t* msg, node_id n );

// check if all the nodes are visited
int msg_all_visited( message_t* msg );

// choose randomly an unvisited node, without marking the returned index within the message
node_id msg_rand( message_t* msg );

#endif