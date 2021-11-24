// PROBLEM :- Given a number, find the greatest number less than the given a number which is the power of two.

// THEORY : MSB of a number in O(1) for a 32-bit integer.

// https://www.geeksforgeeks.org/find-significant-set-bit-number/

int setBitNumber(int n)
{
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n = n + 1;
    return (n >> 1);
}