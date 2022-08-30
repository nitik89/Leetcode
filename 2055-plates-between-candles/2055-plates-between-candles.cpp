class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n=s.size();
        vector<int>pre(n,-1);
        vector<int>suff(n,n);
        vector<int>pres(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='|'){
                pre[i]=i;
                pres[i]+=((i-1)>=0?pres[i-1]:0)+1;
            }
            else{
                pre[i]=i-1>=0?pre[i-1]:pre[i];
                pres[i]+=((i-1)>=0?pres[i-1]:0);
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='|'){
                suff[i]=i;
            }
            else{
                suff[i]=i+1<n?suff[i+1]:suff[i];
            }
        }
        // for(auto x:pres){
        //     cout<<x<<" ";
        // }
        vector<int>ans;
        for(auto x:q){
            int x1=x[0],y1=x[1];
           int a=suff[x1],b=pre[y1];
            if(a>y1||b<x1){
                ans.push_back(0);
            }
            else{
                int t=(b-a)-(pres[b]-pres[a]);
                ans.push_back(t);
            }
        }
        return ans;
        
    }
};