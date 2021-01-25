# INIT STEP ALGORITHM
ring approach to the votation: the message starts from the turn leader of the previous ended turn, and goes through all the nodes in the net, in sequence with respect to the ip address table.
*for each node*:
1.
the node inserts in an array its votation (the ID of the "preferred" node) using as position its ID. 
2.
then, it deliver the message to the next available node.
*previous turn leader*:
1.
this node initializes the votation message, adds its "preference", then sends to the first available node (looking into the ip addressed table)
2.
then, it waits the votation message from its previous node
3.
for computing the winner, the node scans the array and counts the votes. The winner is the one that has received much many votes than any other else
4.
finally, the previous turn leader initializes an empty normal message with the value "turnLeader" containing the node ID of the new turn leader. Obviously, this step has to be performed only if the turn leader has changed; otherwise, the turn starts.