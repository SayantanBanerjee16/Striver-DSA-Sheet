class Solution{
    
    public:
    
    // PROBLEM :- https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
    
    // GFG | EASY | INTERVALS SORTING
    
    // Solution :- T.C. O(NlogN) S.C. O(N)
    
    // Build up the intervals 2D vector.
    // Sort with end times as initial sorting criteria. Lesser end times placed in front of higher end times.
    // Now choose an interval. Mark its end time.
    // Choose the next interval only if its start time is higher than previous end time.
    // Greedily repeat the process.
    
    int maxMeetings(int start[], int end[], int N)
    {
        vector<vector<int>> times;
        for(int i = 0 ; i < N ; i++){
            times.push_back({start[i], end[i]});
        }
        
        sort(times.begin(), times.end(), [](vector<int> &v1, vector<int> &v2){
        
            return v1[1] < v2[1];
            
        });
        
        int endOfPrev = times[0][1];
        
        int ans = 1;
        
        for(int i = 1 ; i < N ; i++){
            int start = times[i][0];
            if(start > endOfPrev){
                ans++;
                endOfPrev = times[i][1];
            }
        }
        
        return ans;
        
    }
};
