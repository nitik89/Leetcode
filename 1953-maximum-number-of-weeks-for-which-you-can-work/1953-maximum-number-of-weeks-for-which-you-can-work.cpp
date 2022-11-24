class Solution {
public:
    long long numberOfWeeks(vector<int>& m) {
        long long mx=*max_element(m.begin(),m.end());
        long long sum=0;
        for(auto x:m){
            sum+=x;
        }
        long long res=(sum-mx);
        return min(2*res+1,sum);
    }
};