#ifndef _ARPNET_H_
#define _ARPNET_H_

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

/**
 * initialize server connection without accept a client
 */
void server_init(int portno);

/**
 * function to accept a client
 **/
int accept_client();

/**
 * function to connect client to server specifying IP address and port num
 */
int client_connection(char *IPaddr, int portno);

#endif