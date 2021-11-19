// PROBLEM :- https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

// GFG | EASY | INTERVALS ARRAY

// Solution 1 :- T.C. :- O(max(N,Range))   S.C. :- O(Range) where Range -> Constraints of Arrival and Departure

// Create a whole range of constraints over arrival and departure.
// While taking care of one interval, mark its arrival and departure as +1 and -1 in the range array.
// Finally take prefix sum.
// And maximum overlapping intervals = max value in the whole range.

class Solution{
    public:
    
    int findPlatform(int arr[], int dep[], int n)
    {
        
        int maxRange = 2400;
    	
    	vector<int> timeStamp(maxRange, 0);
    	
    	for(int i = 0 ; i < n ; i++){
    	    int start = arr[i];
    	    int end = dep[i];
    	    timeStamp[start]++;
    	    timeStamp[end + 1]--;
    	}
    	
    	int ans = timeStamp[0];
    	
    	for(int i = 1 ; i < maxRange ; i++){
    	    timeStamp[i] += timeStamp[i - 1];
    	    ans = max(ans, timeStamp[i]);
    	}
    	
    	return ans;
    	
    }
};

// Solution 2 :- T.C. :- O(NlogN)   S.C. :- O(N)

// Extension from previous solution. Previously we were using up all the locations inside the range.
// Now we are only checking at the point of interest, i.e, the timestamps where a train has arrived or departured.
// Only store these timestamps in a vector marking their STATE. State 0 means arrival and State 1 means departure.
// Rest logic remains same as of Solution 1.
// And maximum intervals = max value in the whole range.

// Note that :- Solution 1 is more optimal if we are dealing with range constraints smaller than N (size of array).

class Solution{
    public:
    
    int findPlatform(int arr[], int dep[], int n)
    {
        
        vector<vector<int>> timeStamps; // (arr[0], arr[1]) -> (time , state) -> state 0 means arrival, state 1 means departure
        
        for(int i = 0 ; i < n ; i++){
            timeStamps.push_back({arr[i], 0});
            timeStamps.push_back({dep[i], 1}); 
        }
        
        sort(timeStamps.begin(), timeStamps.end());
        
        int ans = 0;
        
        int prefixCnt = 0;
        
        for(int i = 0 ; i < timeStamps.size() ; i++){
            int state = timeStamps[i][1];
            if(state == 0){ // arrival
                prefixCnt++;
            }else if(state == 1){ // departure
                prefixCnt--;
            }
            ans = max(ans, prefixCnt);
        }
        
        return ans;
    }
};
