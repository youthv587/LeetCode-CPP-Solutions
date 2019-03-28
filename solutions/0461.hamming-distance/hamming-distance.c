int hammingDistance(int x, int y) {
    int n = 0;
    for(int i = 0; i < 31; i++){
      if((x & 1) != (y & 1)) n++; 
        x >>= 1;
        y >>= 1;
    }
    return n;
}