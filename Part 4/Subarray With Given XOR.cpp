// PROBLEM :- https://www.interviewbit.com/problems/subarray-with-given-xor/

// INTERVIEWBIT | MEDIUM | HASHING - XOR PROPERTY

// Solution :- T.C. O(N) S.C O(N)

// Let's say Array[I...J] have XOR B.
//           Array[0...I] have XOR X.
//           Array[0...J] have XOR Y.

// While prefix-traversing and checking at location J,
//           X ^ Y = B (observe this mathematically)
//           X ^ Y ^ Y = B ^ Y (doing both side XOR Y)
//           X = B ^ Y

// We know both B and Y, so we will also know X. 
// Thus all the locations which have XOR value at that point X, would contribute to initial points I.

// So build up a map, store the count of prefix-XOR.
// Then prefix-traverse the array, and find the counts of all locations which would contribute to ans in the current location.


int Solution::solve(vector<int> &A, int B) {

    int xorr = 0;
    unordered_map<int, int> cnt;

    cnt[xorr] = 1;

    int ans = 0;

    for(int i = 0 ; i < A.size() ; i++){
        xorr ^= A[i];
        int find = xorr ^ B;

        if(cnt.count(find) == 1){
            ans += cnt[find];
        }

        cnt[xorr]++;

    }

    return ans;

}