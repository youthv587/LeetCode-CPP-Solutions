int findComplement(int num) {
    int n = 0;
    while((num & 2147483648) == 0){
	    n++; num <<= 1;
      }
    num >>= n;
    return ~num;
}