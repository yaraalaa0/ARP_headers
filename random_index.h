
//We split the range of random numbers from rand() into equally large "chunks" and depending on which chunk we "land in" we determine the outcome. 
//In the general case there will be some slack at the end of the range as the chunk size doesn't evenly divide the range, 
//if we roll a value in the slack we just roll again:


int rdmindex(int min , int max){
      int range = max - min +1;
      
      int chunkSize= (RAND_MAX + 1) / range;
      int endOfLastChunk=chunkSize * range;
      
      int r = rand();
      while(r >= endOfLastChunk){
            r = rand();
      }
      return min + r / chunkSize;
}
