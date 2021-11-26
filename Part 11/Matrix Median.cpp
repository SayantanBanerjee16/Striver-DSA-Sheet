// PROBLEM :- https://www.interviewbit.com/problems/matrix-median/

// INTERVIEW BIT | MEDIUM | BINARY SEARCH (NESTED)

// Solution T.C. :- O(N * log(M) * log(RANGE)) S.C. O(1)

// First simulate a binary search over the number range (1 to 10^9) which can be possible median.
// Now for each binary search mid, let it be the current median.
//	Find how many elements are lesser or equal to the current median value in the matrix.
// 	Do this traversing over all the N rows linearly, and have a Binary search over each row.
// If the count is greater or equal than than MEDIAN'th element, B.S. on the left hand search space, with storing the current mid as possible ans(median).
// 		is lesser than MEDIAN'th element, B.S. on the right hand search space.


int countOfElementsLessThanOrEqualToValueInASortedRow(vector<int> &A, int M, int value){
    int low = 0;
    int high = M;
    int ans = M;

    while(low <= high){
        int mid = low + ((high - low) / 2);
        if(A[mid] > value){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return ans;

}


int countOfElementsLessThanOrEqualToValueInMatrix(vector<vector<int> > &A, int value){
    int N = A.size();
    int M = A[0].size();
    int cnt = 0;

    for(int i = 0 ; i < N ; i++){
        cnt += countOfElementsLessThanOrEqualToValueInASortedRow(A[i], M, value);
    }

    return cnt;

}

int Solution::findMedian(vector<vector<int> > &A) {

    int low = 1;
    int high = 1e9;

    int ans = high;

    int N = A.size();
    int M = A[0].size();
    int tot = N * M;
    int medianElementCount = tot / 2;

    while(low <= high){
        int midValue = low + ((high - low) / 2);
        int count = countOfElementsLessThanOrEqualToValueInMatrix(A, midValue);

        if(count > medianElementCount){
            ans = midValue;
            high = midValue - 1;
        }else{
            low = midValue + 1;
        }

    }

    return ans;

}