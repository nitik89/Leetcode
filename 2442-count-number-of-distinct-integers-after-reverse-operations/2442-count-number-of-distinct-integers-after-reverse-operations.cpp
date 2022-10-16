class Solution {
public:
    int rev(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}
 
    int countDistinctIntegers(vector<int>& nums) {
        vector<int>vec;
        unordered_map<int,int>mp;
        for(auto x:nums){
            int y=rev(x);
            vec.push_back(y);
            mp[y]++;
        }
        for(auto x:nums){
            mp[x]++;
        }
      
        return mp.size();
    }
};