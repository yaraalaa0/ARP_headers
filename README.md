
# Libraries

## Compiling

Since all headers are - correctly - divided into many directories, and since the executable will be probably run from a 
different directory altogether, the best way to include libraries is in the form "/dir/name.h", where "dir" is relative to
the origin of "/ARP_headers"
```
	#include "/init-step/votation.h"
	#include "/bitvector/bitvector.h"
```

While the executable should be compiled with

```
	gcc my_prog.c -o my_prog -I/ARP_headers
	gcc my_prog.c -o my_prog -I/../ARP_headers
```
And so on, depending on the relative location of such folders with respect to the compiled file.
> see https://caligari.dartmouth.edu/doc/ibmcxx/en_US/doc/complink/ref/ruoptiu.htm

## Things to FIX

We should decide first of all if we have to keep in the IP_table the flag defining
if a node has already been visited or not. This info might be redundant, since that's
contained in the message structure as well, and it's hard to actually (and not very useful)
having to update that value locally each time.

**NOTICE:** each node that isn't a turn leader has no idea of how many messages it will 
still receive before having to go back to the VOTATION phase (it could be visited 10,
0 or any inbetween number of times): to detect that we should have a special msg,
of the same type as the ones containing informations, but with some sort of flag
that indicates that a new round has to start. This pasrticular message will have
to be sent to all nodes in the net (using once again the "chain" would be optimal),
so that they can stop waiting for a message to reply to and participate in the new
votation step.

## First handshake

The first handshake is the moment before the definition of the first ever Turn Leader,
where the net should check if all nodes are reachable and if all are up-to-date with
the last versione of the header file. This could be simply done by sending - once again -
a message around the ring of nodes. Such message should contain at least a bitvector 
("unreachable") and numeric field ("version").
> The actual implementation of the versioning depends on how deep we want things to be.
	We could easily set for a mere integer, incrementing each time a new version is
	released. Or we could do even more and properly generate an hash string from the
	headers content at run time, and check if the one computed locally by each node is
	equal to the one passed rfom ZERO (and assumed to be up-to-date).

The check would go as follows:

- as always the node ZERO would kick the ball, by first sending a message to the node with
	id '1', initializing to 0's the bitvector "unreachable" (aka, all nodes assumed reachable)
	and "version" to the ID of its header's version;
- each time a node tries to send a message to the next one in the "ring" it will first check if 
	the connection failed (connect() returned a negative value): in that case it will mark that
	node as "unreachable" (unreachable[next_node_id] = 1) and try to send the message to the
	next one in the table, repeating until a node is reachable (or it comes back to itself, in
	which case it throws an error);
- each time a node receives a message in this phase it first checks if its version corresponds
	to the one of ZERO. If that's not the case it marks itself as "unreachable", updating the
	bitvector contained in the message. It then tries to send the updated message to the 
	following node in the ring;

Note that once such message comes back to the ZERO node it should be sent once again along the
ring, since the complete state of the net will be expresssed in the "unreachable" field of the
message only after all nodes had a chance to record their status/ the status of their neighbors.
For this second trip
- each time a node receives a message it updates its *local* ip_table by copying the "unreachable"
	field contained in the received message, in order to have a copy of which nodes are actually
	active part of the net at the moment.
- it then simply sends this message to the next *reachable* node from the table just updated.

#### NOTES

This approach requires:
- using "address-table.h" instead of "simple-address-table.h", modifying the "logic" behind the
	field "target_reached" with "target_unreachable", signifying not a target already visited in
	the current round-trip but a target not-reachable in general (while, if I'm not wrong, the 
	already written functions should be fully compatible with this new use-case);
- generating a new type of message, with at least the two fields mentioned: it should be however
	noted that, technically, the standard "message" structure (the one used to communicate times
	in the "main" loops of the program) could be repurposed for this (since it already has a 
	bitvector and plenty of numerical fields), even though that might cause some confusion if not
	aptly "masked" by library-functions;