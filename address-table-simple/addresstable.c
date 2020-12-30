#include "addresstable.h"

// the IP address table
iptab_addr_t __ip_table[ __IP_TABLE_LEN ] = 
{
	{ "127.0.0.1" },
    { "0.0.0.0" },
    { "255.255.0.255" },
};

// get the total lenght of the table
int iptab_len()
{
    return __IP_TABLE_LEN;
}

// get the IP address (as string) of a certain node
char* iptab_getaddr(int n)
{
    if( n >= __IP_TABLE_LEN || n < 0 )
        return NULL;
    else
        return __ip_table[n].ip_addr;
}

/*
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
*/
