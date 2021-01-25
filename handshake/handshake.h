#ifndef _HANDSHAKE_H_
#define _HANDSHAKE_H_

#include <string.h>
#include "../bitvector/bitvector.h"
#include "../addresstable/addresstable.h"
#include "version.h"

#define __HS_START_NODE_ID 0

// the message to be shared during the handshake
typedef struct {
    char version[__ARPNET_VER_ID_LEN];
    bitvector_t available_nodes;
}
handshake_t;

//--------------------------------------
//  UTILS FOR STARTING HANDSHAKE
//--------------------------------------

// check if a node is the starting point for the handshake
int hsh_imfirtst( char* my_ip );

// initialize the handshake message
// without setting as available the node which calls this function
void hsh_init( handshake_t* hsm );

//--------------------------------------
//  HANDSHAKE FIRST STEP
//--------------------------------------

/*
    An unmarked node is considered as unavailable
    Only the node that receives the message can mark itself as arrived.

    The address table isn't updated until the second step. 
*/

// perform the checking of the version; if the version is correct, mark the node as available
// the function returns 1 if the version is ok; 0 otherwise
int hsh_check_availability( node_id my_id, handshake_t* hsm );

//--------------------------------------
//  HANDSHAKE SECOND STEP
//--------------------------------------

// update the address table with the informations within the handshake message
void hsh_update_iptab( handshake_t* hsm );

#endif
