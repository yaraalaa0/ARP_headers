#ifndef _ARPNET_H_
#define _ARPNET_H_

#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include "/bitvector/bitvector.h"

#define IP_TABLE_LEN 3

typedef node_id uint8_t; // essentially a char, 8bit without sign (0-255)
// typedef ipv4_addr uint32_t;	// an ipv4 address is composed of 4 Bytes, aka 32 bits, (unused)
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
	node_id id;				/* the ID of the sender node */
	struct timeval recvd;	/* time instant in which the sender received the previous message */
	struct timeval sent;	/* time instant in which this message was sent */
	node_id turnLeader;		/* the ID of the actual turn leader */
	bitvector_t vis_set;	/* flags for visited nodes */
}
message_t;

#endif