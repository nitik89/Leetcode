class Solution {
public:
    int ans=INT_MIN;
    void getAns(string s,int k,int val,int po,int i){
        if(i==s.size()){
            if(val<=k){
                // cout<<val<<" ";
            ans=max(ans,po);
            }
            return;
        }
        if(s[i]=='1'){
            
            if(val+pow(2,po)<=k){
            getAns(s,k,val+pow(2,po),po+1,i+1);
            }
            else{
            getAns(s,k,val,po,i+1);
            }
        }
        else{
             if(val<=k){
            getAns(s,k,val,po+1,i+1);
            }
            
        }
    }
    int longestSubsequence(string s, int k) {
        reverse(s.begin(),s.end());
        getAns(s,k,0,0,0);
        return ans;
    }
};