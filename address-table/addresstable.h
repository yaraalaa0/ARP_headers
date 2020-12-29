#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define __IP_TABLE_LEN 3
#define __RAND_IDX(max) (int) ((double) rand() * ( (double) max / (double) INT_MAX ))

#define __VISITED 1
#define __NOT_VISITED 0

// the entry of the address table
typedef struct iptab
{
    char ip_addr[15];
    int visited;
}
iptab_addr_t;

// the table is an 'extern' array of (string) IP addresses
extern iptab_addr_t __ip_table[ __IP_TABLE_LEN ];
extern int __remaining_ip_addr;

// clear the markers
void iptab_clear();

// get the total lenght of the table
int iptab_len();

// are still unmarked nodes? return how many nodes aren't marked
int iptab_unvisited_nodes();

// mark a node as visited; it returns the new number of remaining nodes or -1 on error
int iptab_mark(int n);

// check if a node is already marked; it returns -1 when the index isn't correct
// return 1 is the node is marked, 0 if it is unmarked
int iptab_visited(int n);

// get the IP address (as string) of a certain node
// return NULL is the address is wrong
char* iptab_getaddr(int n);

// get randomly an unmarked node of the list
// it returns -1 if there aren't available nodes
int iptab_rand_idx();