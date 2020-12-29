#include <time.h>
#include <sys/time.h>
#include "bitvector.h"

#define IP_TABLE_LEN 3


/*
	=== IP ADDRESS TABLE ===
*/
// the table is an 'extern' array
extern char ip_table[IP_TABLE_LEN][15];

/*
	=== MESSAGE ===
*/// format of the message shared with the nodes of the network
typedef struct message
{
	int id;					/* the ID of the sender node */
	struct timeval recvd;	/* time instant in which the sender received the previous message */
	struct timeval sent;	/* time instant in which this message was sent */
	node_id turnLeader;		/* the ID of the actua turn leader */
	bitvector_t vis_set;	/* flags for visited nodes */
}
message_t;