// PROBLEM :- https://www.interviewbit.com/problems/distinct-numbers-in-window/

// INTERVIEW BIT | MEDIUM | MAP 

// Solution :- T.C. O(NlogB) S.C. O(B)

// Store the array freq in a map. (window - wise)
// For each window, check the number of elements in the map. That will be the answer for that window.
// While deleting the leftmost element during window switching, if the freq of that element is equals 0, erase that element from the map.

vector<int> Solution::dNums(vector<int> &arr, int B) {

    int N = arr.size();

    if(B > N){
        return {};
    }

    map<int, int> freq;

    for(int i = 0 ; i < B - 1 ; i++){
        freq[arr[i]]++;
    }

    vector<int> ans;

    for(int i = B - 1 ; i < N ; i++){
        freq[arr[i]]++;
        ans.push_back(freq.size());
        int toDelete = arr[i - (B - 1)];
        freq[toDelete]--;
        if(freq[toDelete] == 0){
            freq.erase(toDelete);
        }
    }

    return ans;

}
