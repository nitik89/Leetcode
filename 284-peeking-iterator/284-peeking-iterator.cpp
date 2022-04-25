/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    queue<int>q;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    for(auto x:nums){
            q.push(x);
        }
	    
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(q.empty()){
            return -1;
        }
        return q.front();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	        if(q.empty()){
            return -1;
        }
        int x=q.front();
        q.pop();
        return x;
	}
	
	bool hasNext() const {
	    return q.size()>0;
	}
};