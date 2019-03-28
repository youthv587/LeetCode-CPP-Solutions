int countPrimes(int n)
{
  if (n <= 1) return 0;
  int count = 0;
  int *primes = (int *)malloc(sizeof(int)*(n + 3));
  for (int i = 0; i < n; i++) primes[i] = (i % 2 == 0)? 0 : 1; primes[1] = 0; primes[2] = 1;
  
  for (int i = 3; i < n; ++i)
    if (primes[i])
      for (int j = 3; i * j < n; ++j)
	primes[i*j] = 0;
  
  for (int i = 0; i < n; ++i)
    count += primes[i];
  
  return count;
}
