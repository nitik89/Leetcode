class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>vec(26,0);
        for(auto x:s){
            vec[x - 'a']++;
        }
        int idx=0;
        for(auto x:s){
           
            if(vec[x - 'a'] == 1){
                return idx;
            }
            idx++;
        }
        return -1;
    }
};