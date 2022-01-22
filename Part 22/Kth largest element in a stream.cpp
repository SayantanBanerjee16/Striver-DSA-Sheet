// PROBLEM :- https://leetcode.com/problems/kth-largest-element-in-a-stream/

// LEETCODE | EASY | HEAP

// Solution :- T.C. O(NlogK) S.C. O(K)

// We need to find out the Kth largest element when we view them in sorted order.
// We mantain a Min Heap of Size K.
// Upon entering a value into the heap, if the heap size is greater than the K, we pop the minimum out.

// So after every operation, the top of the Min Heap returns us the Kth largest element in a stream.

class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K = -1;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0 ; i < nums.size() ; i++){
            minHeap.push(nums[i]);
            if(minHeap.size() > K){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > K){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */