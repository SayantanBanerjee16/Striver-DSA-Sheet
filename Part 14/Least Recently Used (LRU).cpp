// PROBLEM :- https://leetcode.com/problems/lru-cache/

// LEETCODE | MEDIUM | MAP, LIST using STL

// Solution :- T.C. O(1) on average per operation. S.C. O(Capacity)

// Logic :- Build a chain using LIST STL of C++.

// How PUT works?
//      If KEY is already present, evict that node from the list, and push the node freshly in back of list.
//      If KEY is not present,
//              If capacity is not full, push the current node in back of list.
//              If capacity is full, get the first node (LRU) from the list, delete it, and push the current node in back of list.


// How GET works?
//      If key is not present, -1.
//      If key is present, evict that node from the list, and push the node freshly in back of list.

// How this deletion of random node from list is done in O(1)?
//      When pushing the node at back of the list, get the node iterator address, and store the iterator address of the node in a map.
//      Using the node iterator address, we can delete the node from the list.

// Few code related points :-
// Declare LIST in STL                                  :-       list<int> LRU;
// List push at back                                    :-       LRU.push_back(key);
// List get front key                                   :-       LRU.front();
// List erase a node when we have the iterator address  :-       LRU.erase(it);
// List getting the last node iterator address          :-       --LRU.end();
// Creating a map to store iterator address             :-       unordered_map<int, list<int>::iterator> referenceIteratorsToList;


using namespace std;
class LRUCache {
public:
    int cache_size = 0;
    int current_size = 0;
    unordered_map<int, int> values;
    unordered_map<int, list<int>::iterator> referenceIteratorsToList;
    
    list<int> LRU;
    
    LRUCache(int capacity) {
        cache_size = capacity;
        current_size = 0;
    }
    
    int get(int key) {
        
        if (values.find(key) != values.end()) {
             // cout<<"key present\n";
            LRU.erase(referenceIteratorsToList[key]);
            LRU.push_back(key);
            referenceIteratorsToList[key] = --LRU.end();    
            return values[key];
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(values.count(key) == 1){
            // cout<<"key already present\n";
            values[key] = value;
            list<int>::iterator it = referenceIteratorsToList[key];
            LRU.erase(it);
            LRU.push_back(key);
            referenceIteratorsToList[key] = --LRU.end();
        }else{
            if(current_size < cache_size){ 
                // cout<<"not_full\n";
                current_size++;
                values[key] = value;
                LRU.push_back(key);
                referenceIteratorsToList[key] = --LRU.end();
            }
            else{
                 // cout<<"full\n";
                int least_used_key = LRU.front();
                values.erase(least_used_key);
                referenceIteratorsToList.erase(least_used_key);
                LRU.pop_front();
                
                values[key] = value;
                LRU.push_back(key);
                referenceIteratorsToList[key] = --LRU.end();
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */