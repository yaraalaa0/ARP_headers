#include <stdlib.h>

//Take a look at the link shared on Trello on this topic to better understand motivations and implementation
//We split the range of random numbers from rand() into equally large "chunks" and depending on which chunk we "land in" we determine the outcome. 
//In the general case there will be some slack at the end of the range as the chunk size doesn't evenly divide the range, 
//if we roll a value in the slack we just roll again
int rdmindex(int min , int max);