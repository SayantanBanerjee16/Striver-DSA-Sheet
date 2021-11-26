// PROBLEM :- https://www.interviewbit.com/problems/allocate-books/

// INTERVIEW-BIT | MEDIUM | BINARY SEARCH

// Solution :- T.C. O(Nlog(Range)) S.C. O(1) Range :- Sum of all elements in the array

// We are finding an optimal page division where all students take at max that amount of pages.
// Or in other words, find out how many students would require to fit into current page division.
// When a page division is valid? --> The total students formed are <= given students.

// Now simulate a B.S. iteration based on the range of available pages.
// How to reduce search space?
// If valid -> store the result and search in left hand search space for a better solution.
// Else     -> search in right hand search space for a better solution.

int isPossible(vector<int> &A, int pages, int students) {
    int cnt = 0;
    int sumAllocated = 0; 
    for(int i = 0;i<A.size();i++) {
        if(sumAllocated + A[i] > pages) {
            cnt++; 
            sumAllocated = A[i];
            if(sumAllocated > pages) return false; 
        }
        else {
            sumAllocated += A[i];
        }
    }
    if(cnt < students) return true; 
    return false; 
}


int Solution::books(vector<int> &A, int B) {

    if(B > A.size()) return -1; 
    int low = A[0]; 
    int high = 0;

    for(int i = 0;i<A.size();i++) {
        high = high + A[i]; 
        low = min(low, A[i]); 
    }

    int res = -1; 

    while(low <= high) {
        int mid = (low + high) >> 1; 
        if(isPossible(A, mid, B)) {
            res = mid; 
            high = mid - 1; 
        }
        else {
            low = mid + 1; 
        }
    }
    return res; 

}
