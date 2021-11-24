// PROBLEM :- https://practice.geeksforgeeks.org/problems/power-set4302/1#

// GFG | EASY | BITS MANIPULATION

// Solution :- T.C. O(2^N) and S.C. O(N * 2 ^ N)

// generate all the binaries from 1 to 2^N - 1.
// in each binary configuration, for examle let it be 010010, include those position from the string which has a bit set in the current configuration.
// once the current string generated, include in the output vector.


class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    
		    int n = s.length();
		    vector<string> output;
		    
		    for(int i = 1 ; i < (1 << n) ; i++){
		        int num = i;
		        string temp = "";
		        for(int j = 0 ; j < n ; j++){
		            if((1 << j) & num){
		                temp += s[j];
		            }
		        }
		        output.push_back(temp);
		    }
		    
		    sort(output.begin(), output.end());
		    return output;
		}
};