
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

**NOTICE:** each node that isn't a turn leader
	has no idea of how many messages it will 
	still receive before having to go back to
	the VOTATION phase (it could be visited 10,
	0 or any inbetween number of times): to
	detect that we should have a special msg,
	of the same type as the ones containing 
	informations, but with some sort of flag
	that indicates that a new round has to
	start. This pasrticular message will have
	to be sent to all nodes in the net (using
	once again the "chain" would be optimal),
	so that they can stop waiting for a message
	to reply to and participate in the new
	votation step.