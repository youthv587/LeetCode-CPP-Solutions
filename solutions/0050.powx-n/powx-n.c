double myPow(double x, int n) {
  double p = 1.0;
  if(n < 0){
    if(n==INT_MIN)  
      return 1.0 / (myPow(x,INT_MAX)*x);  
    else  
      return 1.0 / myPow(x,-n);
  }
  if(n == 0)
    return 1.0;
  for(; n > 0; x *= x, n >>= 1)
    if(n & 1)
      p *= x;
  return p;
}