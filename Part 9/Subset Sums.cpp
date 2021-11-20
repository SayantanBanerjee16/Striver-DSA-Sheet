// PROBLEM :- https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// GFG | BASIC | RECURSION

// Solution :- T.C. O(2^N) S.C. O(2^N)

// Basic idea while doing any recursion based problem is, 
// Think of a particular element. Make choice to it. Proceed to call recursively to do the same task in rest of the array.

// Here, take an element, and 2 choices are -> you choose that element OR you don't choose.
// Mention the break condtion :- When you go out of array


class Solution
{
public:

    void recurse(int pos, int sum, vector<int> &arr, vector<int> &output, int N){
        
	// break condition -> when u go out of array
        if(pos == N){
            output.push_back(sum);
            return;
        }
        
	// RECURSE calls :-

	// Choose the current element
        recurse(pos + 1, sum + arr[pos], arr, output, N);

	// Ignore the current element
        recurse(pos + 1, sum, arr, output, N);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> output;
        recurse(0, 0, arr, output, N);
        return output;
    }

};