class RangeFreqQuery {
public:
map<int,vector<int>>value_to_indexes;
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            value_to_indexes[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
       auto left_itr = lower_bound(value_to_indexes[value].begin(),
                                  value_to_indexes[value].end(),
                                  left);
      // index for value which is > right 
      auto right_itr = upper_bound(value_to_indexes[value].begin(),
                                   value_to_indexes[value].end(),
                                   right);
      // ex : value 2 occurs at indexes 5, 7, 9, 10
      // for query [4,8] the left_itr => 5 and right_itr points to 9 , right-left itr = 2
      return (right_itr - left_itr);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */