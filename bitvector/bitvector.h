#include <stdio.h>
#include <limits.h>

#define RIGHT_BITMASK(var, len) { var = 0; for(int j=0; j<(len); j++) var += (1 << j); }
#define BIT(pos) 1 << pos

#define BITVECT_32BIT unsigned int
#define BITVECT_64BIT unsigned long
#define BITVECT_128BIT unsigned long long

/*
	=== BIT VECTOR ===
*/
// bit vector type ( just 'int' if IP_TABLE_LEN <= 32 )
typedef struct bitvector
{
    int len;            /* the real lenght of the bit vector */
    BITVECT_64BIT v;     /* '1' for available nodes, '0' for visited nodes */
}
bitvector_t;

// initialization of a bit vector
int bv_init( bitvector_t* bv, int len );

// it sets all the bits of the vector to one
void bv_clear( bitvector_t* bv );

// check if a node is marked
int bv_marked( bitvector_t* bv, int pos );

// mark a node as visited
void bv_mark( bitvector_t* bv, int pos );

// check if at least one node is available
int bv_all_marked( bitvector_t* bv );