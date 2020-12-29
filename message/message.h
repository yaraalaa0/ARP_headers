#include <time.h>
#include <sys/time.h>
#include "bitvector.h"
#include "addresstable.h"

// format of the message shared with the nodes of the network
typedef struct message
{
	int id;					/* the ID of the sender node */
	int turnLeader;			/* the ID of the actua turn leader */
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
void msg_set_ids( message_t* msg, int id, int turn_leader );

// check if a node was already visited
int msg_visited( message_t* msg, int n );

// mark a node as visited
void msg_mark( message_t* msg, int n );

// check if all the nodes are visited
int msg_all_visited( message_t* msg );