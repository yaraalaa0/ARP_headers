# INIT STEP
here is some code to attach to the shared header regarding to the *first step* of each turn: choose the turn leader. 

## ALGORITHM FOR CHOOSING THE TURN LEADER
I'm providing to you just the basic standard tools for performing all the operations; the rest is up to you, as long as it works.
1.  the last turn leader sends to its next node (see the table) a particular type of message with its votation; the votation step is started.
2.  the i-th node first of all fills (using a standard function) its preference (random choice) in the votation message
3.  then looks at the counter in the message: if the counter reaches the zero,the node sends the message to the turn leader; otherwise, the message is delivered to the (i+1)-th node which still has to notify its preference.
4.  during the votation, the starting node waits for a message from its previous; when it receives again the message, it chooses the winner by looking at the message, and then sends the official message to this node, which becomes the actual turn leader; this node understand to be the turn leader because it sees its number in the field *turnLeader* of the message_t message.
