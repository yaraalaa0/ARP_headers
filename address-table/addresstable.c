#include "addresstable/addresstable.h"
#include "misc/random_index.h"

// the IP address table
int __remaining_ip_addr = __IP_TABLE_LEN;
iptab_addr_t __ip_table[ __IP_TABLE_LEN ] = 
{
	{
        "127.0.0.1",
        __NOT_VISITED
    },
    {
        "0.0.0.0",
        __NOT_VISITED
    },
    {
        "255.255.0.255",
        __NOT_VISITED
    },
};

// clear the markers
void iptab_clear()
{
    for( int i=0; i<__IP_TABLE_LEN; i++ )
        __ip_table[i].visited = __NOT_VISITED;
    
    __remaining_ip_addr = __IP_TABLE_LEN;
}

// get the total lenght of the table
int iptab_len()
{
    return __IP_TABLE_LEN;
}

// are still unmarked nodes? return 1 if not all nodes are been visited
int iptab_unvisited_nodes()
{
    return ( __remaining_ip_addr > 0 );
}

// mark a node as visited
int iptab_mark(node_id n)
{
    if( __remaining_ip_addr == 0 )
        return -1;
    if( n >= __IP_TABLE_LEN || n < 0 )
        return -1;

    //mark the node
    __ip_table[n].visited = __VISITED;
    __remaining_ip_addr --;

    return __remaining_ip_addr;
}

// check if a node is already marked
int iptab_visited(node_id n)
{
    if( n >= __IP_TABLE_LEN || n < 0 )
        return -1;
    
    return ( __ip_table[n].visited );
}

// get the IP address (as string) of a certain node
char* iptab_getaddr(node_id n)
{
    if( n >= __IP_TABLE_LEN || n < 0 )
        return NULL;
    else
        return __ip_table[n].ip_addr;
}

// get randomly an unmarked node of the list
node_id iptab_rand_idx()
{
	node_id unvisited_nodes[__IP_TABLE_LEN];
	int len_unv_nodes=0;
	
    if( __remaining_ip_addr == 0 ) return -1;
	
	/*
		Generate a new table containing exclusively the node_id (so not the entire address)
		of the unvisited nodes, in order to directly search for a random among them, without
		the problem of reiterating in case of a random node already being visited.
	*/
	for(int i=0; i< __IP_TABLE_LEN; i++){
		if (!__ip_table[i].visited){
			unvisited_nodes[len_unv_nodes++] = (node_id)i;
		}
		
	}
	// We're already sure that there's at least one available node, since the check
	// has been made in the beginning.
    return unvisited_nodes[rdmindex(0, len_unv_nodes)];
}

