#include "addresstable.h"

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
int iptab_mark(int n)
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
int iptab_visited(int n)
{
    if( n >= __IP_TABLE_LEN || n < 0 )
        return -1;
    
    return ( __ip_table[n].visited );
}

// get the IP address (as string) of a certain node
char* iptab_getaddr(int n)
{
    if( n >= __IP_TABLE_LEN || n < 0 )
        return NULL;
    else
        return __ip_table[n].ip_addr;
}

// get randomly an unmarked node of the list
int iptab_rand_idx()
{
    if( __remaining_ip_addr == 0 ) return -1;

    // try to take randomly an index
    int i = __RAND_IDX( __IP_TABLE_LEN );
    if( __ip_table[i].visited )
    {
        // if the selected node is already visited, return the first avalable
        i = 0;
        while( __ip_table[i].visited ) i++;
    }

    return i;
}

