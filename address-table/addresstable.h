#ifndef _ADDRESSTABLE_SIMPLE_H_
#define _ADDRESSTABLE_SIMPLE_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
//include <limits.h>

#define __IP_TABLE_LEN 3

#define __NOD_AVAILABLE 1
#define __NOD_NOT_AVAILABLE 0

typedef uint8_t node_id; // essentially a char, 8bit without sign (0-255)

// the entry of the address table
typedef struct iptab
{
    char ip_addr[15];
    short ip_avail;
    // other infos?
}
iptab_addr_t;

// ------------------------
//  BASIC OPERATIONS
// ------------------------

// the table is an 'extern' array of (string) IP addresses
extern iptab_addr_t __ip_table[ __IP_TABLE_LEN ];

// get the total lenght of the table
int iptab_len();

// get the IP address (as string) of a certain node
// return NULL is the address is wrong or the node is no longer available
char* iptab_getaddr(node_id n);

// get the ID of a certain node given its IP address
int iptab_get_ID_of(char* ip);

// get the ID of the next available node in the table (in order)
node_id iptab_get_next( node_id my );

// get the ID of the previous node in the table (in order)
node_id iptab_get_prev( node_id my );

// ------------------------
//  OPS ON "AVAILABLE" FLAG
// ------------------------

// check if a node is available (0 if it is not)
int iptab_is_available(node_id n);

// mark a node as unavailable
// 0 is returned if the operation is done
int iptab_set_unavailable(node_id n);

// set the node as available
// 0 is returned if the operation is done
int iptab_set_available(node_id n);

// reset all the flags "available" as "not" (default state)
void iptab_reset_flags();

#endif