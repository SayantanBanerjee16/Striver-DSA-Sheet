// Problem :- Find XOR of all numbers between 1 to N in O(1)

// https://www.geeksforgeeks.org/calculate-xor-1-n/

int computeXOR(int n)
{
   
  if (n % 4 == 0)
    return n;
 
  if (n % 4 == 1)
    return 1;
 
  if (n % 4 == 2)
    return n + 1;
 
  return 0;
}