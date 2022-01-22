// PROBLEM :- https://leetcode.com/problems/find-median-from-data-stream/

// LEETCODE | HARD | HEAPS

// Solution :- T.C. O(NlogN) S.C. O(N)

// We mantain two heaps. First one to hold first half of elements, and second one to hold second half of elements.
// FirstHalf heap is a max heap -> so that we retrive the maximum element of that heap in O(1).
// SecondHalf heap is a min heap -> so that we retrive the minimum element of that heap in O(1).

// Why these two heaps? 
// Well we are concerned with the boundary of these two heaps, as only the boundary elements contributes to the median, as they both together forms the middle elements of that moment sorted array.

// We just insert elements in such a way that, these boundaries stay intact (mantaining the size of the heaps properly), and we can find median in O(1).

class MedianFinder {
public:
    
    // first half length always equals to OR one more than the length in second half.
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    
    MedianFinder() {

    }
    
    void addNum(int num) {
        
        if(firstHalf.size() == 0){
            // Enter into first half if currently both heaps are empty, 
            firstHalf.push(num);
            
        }else if(num < firstHalf.top()){
            
            // Enter into first half when we see that the current value is less than first half max value.
            // Then shift in between heaps accordingly to adjust sizes.
            
            firstHalf.push(num);
            if(firstHalf.size() - secondHalf.size() == 2){
                int maxInFirstHalf = firstHalf.top();
                firstHalf.pop();
                secondHalf.push(maxInFirstHalf);
            } 
              
        }else{
            
            // Enter into second half if we see that the current value is equal or more than first half max value.
            // Then shift in between heaps accordingly to adjust sizes.
            
            secondHalf.push(num);
            if(secondHalf.size() > firstHalf.size()){
                int minInSecondHalf = secondHalf.top();
                secondHalf.pop();
                firstHalf.push(minInSecondHalf);
            } 
            
        }
        
    }
    
    double findMedian() {
        // when size same -> (firstHalf->max) and (secondHalf->min) contributes to Median (Even case length)
        // when size differs -> (firstHalf->max) only contributes to Median (Odd case length)
        
        if(secondHalf.size() == firstHalf.size()){
            double first = (double) firstHalf.top();
            double second = (double) secondHalf.top();
            return (first + second) / 2.0;
        }else{
            return (double) firstHalf.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
