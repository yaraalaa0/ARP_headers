//Take a look at the link shared on Trello on this topic to better understand motivations and implementation

//We split the range of random numbers from rand() into equally large "chunks" and depending on which chunk we "land in" we determine the outcome. 
//In the general case there will be some slack at the end of the range as the chunk size doesn't evenly divide the range, 
//if we roll a value in the slack we just roll again:


int rdmindex(int min , int max){
      //if we have 30 nodes , min in 0 max is 29. The function at the end will return an integer in the range 0-29
      int range = max - min +1;
      
      int chunkSize= (RAND_MAX + 1) / range;
      int endOfLastChunk=chunkSize * range;
      
      int r = rand();
      //this while is the reroll part , when the value is in a slack
      //the reroll takes care of the bias
      //probability of rerolling is:    range / (RAND_MAX + 1) 
      while(r >= endOfLastChunk){
            r = rand();
      }
      return min + r / chunkSize;
}
