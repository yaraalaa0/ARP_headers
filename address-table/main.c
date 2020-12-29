#include <stdio.h>
#include <time.h>
#include "addresstable.h"

#define YES_OR_NO(question, yesorno) { printf( question ); if( yesorno ) printf( " yes!" ); else printf( " no." ); printf( "\n" ); }
#define SPACE printf( "\n----\n\n" )

int main( int argc, char** argv )
{
    // starting from a dummy address table ...

    srand(time(NULL));

    // test: table lenght
    printf( "table lenght: %d\n", iptab_len() );
    SPACE;

    // test: unmarked nodes
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    SPACE;

    // test: mark node zero
    YES_OR_NO( "is node zero marked?", iptab_visited(0) );
    printf( "marking the node 0 with address %s...\n", iptab_getaddr( 0 ) );
    iptab_mark( 0 );
    YES_OR_NO( "is node zero still marked?", iptab_visited(0) );
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    SPACE;
    
    // test: mark all the nodes, then clear the table
    YES_OR_NO( "is node zero marked?", iptab_visited(1) );
    printf( "marking the node 1 with address %s...\n", iptab_getaddr( 1 ) );
    iptab_mark( 1 );
    YES_OR_NO( "is node zero still marked?", iptab_visited(1) );
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    YES_OR_NO( "is node zero marked?", iptab_visited(2) );
    printf( "marking the node 2 with address %s...\n", iptab_getaddr( 2 ) );
    iptab_mark( 2 );
    YES_OR_NO( "is node zero still marked?", iptab_visited(2) );
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    SPACE;

    // test: clear table
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    printf( "clearing table...\n" );
    iptab_clear();
    YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    SPACE;

    // test: extract randomly a node
    for( int i=0; i<iptab_len(); i++ )
    {
        int n = iptab_rand_idx();
        iptab_mark(n);
        printf( "extracted the address number %d : %s\n", n, iptab_getaddr(n) );
        YES_OR_NO( "unmarked nodes?", iptab_unvisited_nodes() );
    }
    SPACE;

    return 0;
}