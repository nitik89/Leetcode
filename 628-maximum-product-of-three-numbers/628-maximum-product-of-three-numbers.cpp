class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int mx1=INT_MIN,mx2=INT_MIN,mx3=INT_MIN;
        int mn1=INT_MAX,mn2=INT_MAX,mn3=INT_MAX;
        for(auto x:nums){
            if(mx1<=x){
                mx3=mx2;
                mx2=mx1;
                mx1=x;
            }
            else if(x>=mx2){
                mx3=mx2;
                mx2=x;
                
            }
            else if(x>=mx3){
                mx3=x;
            }
            
            if(mn1>=x){
                mn3=mn2;
                mn2=mn1;
                mn1=x;
            }
            else if(mn2>=x){
                mn3=mn2;
                mn2=x;
            }
            else if(mn3>=x){
                mn3=x;
            }
        }
        return max({mx1*mx2*mx3,mn1*mn2*mx1});
    }
};