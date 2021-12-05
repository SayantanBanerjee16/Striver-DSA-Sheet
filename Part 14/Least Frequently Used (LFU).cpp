// https://leetcode.com/problems/lfu-cache/

// LEETCODE | HARD | MAP, LIST using STL

// Solution :- T.C. O(logN) on average per operation. S.C. O(Capacity)

// Logic :- Build a MAP of chain using LIST based on frequency.

// How PUT works?
//      If KEY is already present, update the frequency of the key in the FREQ LIST MAP. 
//      Delete the Node from the previous freq list in the map, and insert into the current freq list.

//      If KEY is not present,
//              If capacity is not full, push the current node in freq = 1 list in the map. 
//              If capacity is full, get the first node from the freq list map which have lowest freq. Delete it, and  push the current node in freq = 1 list in the map. 


// How GET works?
//      If key is not present, -1.
//      If key is present, update the frequency of the key in the FREQ LIST MAP. 
//      Delete the Node from the previous freq list in the map, and insert into the current freq list.

class LFUCache {
public:
    
    unordered_map<int, int> valuesOfKeys;
    unordered_map<int, int> freqOfKeys;
    unordered_map<int, list<int>::iterator> referenceListIteratorsOfKeys;
    
    map<int, list<int>> freqList;
    
    int cur_size = 0;
    int cap  = 0;
    
    LFUCache(int capacity) {
        cap = capacity;
        cur_size = 0;
    }
    
    int get(int key) {
        if(valuesOfKeys.count(key) == 1){
            
            // key present, return it. Also update frequency.
            
            int cur_freq = freqOfKeys[key];
            freqOfKeys[key]++;
            int val = valuesOfKeys[key];
            freqList[cur_freq].erase(referenceListIteratorsOfKeys[key]);
            
            if(freqList[cur_freq].size() == 0){
                freqList.erase(cur_freq);
            }
            
            freqList[cur_freq + 1].push_back(key);
            referenceListIteratorsOfKeys[key] = --freqList[cur_freq + 1].end();
            
            return val;
        }else{
            
            // key not present
            
            return -1;
        }
    }
    
    void put(int key, int value) {
        
        if(cap == 0)
            return;
        
        if(valuesOfKeys.count(key) == 1){
            
            // key present, update it. Also update frequency.
            
            int cur_freq = freqOfKeys[key];
            freqOfKeys[key]++;
            valuesOfKeys[key] = value;
            freqList[cur_freq].erase(referenceListIteratorsOfKeys[key]);
            
            if(freqList[cur_freq].size() == 0){
                freqList.erase(cur_freq);
            }
            
            freqList[cur_freq + 1].push_back(key);
            referenceListIteratorsOfKeys[key] = --freqList[cur_freq + 1].end();
            
        }else{
            
            if(cur_size == cap){
                // capacity full. Evict LFU.
                
                int top = freqList.begin()->first;
                int least_frequent_key = freqList[top].front();
                freqList[top].erase(referenceListIteratorsOfKeys[least_frequent_key]);
                
                if(freqList[top].size() == 0){
                    freqList.erase(top);
                }
                
                referenceListIteratorsOfKeys.erase(least_frequent_key);
                valuesOfKeys.erase(least_frequent_key);
                freqOfKeys.erase(least_frequent_key);
                
            }else{
                // capacity not full. 
                cur_size++;
            }
            
            // New key to be added
            freqOfKeys[key] = 1;
            valuesOfKeys[key] = value;
            freqList[1].push_back(key);
            referenceListIteratorsOfKeys[key] = --freqList[1].end();
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */