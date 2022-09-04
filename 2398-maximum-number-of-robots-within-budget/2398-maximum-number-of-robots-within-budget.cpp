class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
         set<long long,greater<long long> > st;
        int s=0,e=0;
        long long sum=0;
        int ans=0;
        int n=ct.size();
        while(e<n){
            sum+=rc[e];
            st.insert(ct[e]);
            while(s<e&&((*st.begin()+(long long)(e-s+1)*sum)>budget)){
                sum-=rc[s];
                st.erase(ct[s]);
                s++;
                
            }
            long long t=(*st.begin()+(e-s+1)*sum);
            if(t<=budget){
                ans=max(e-s+1,ans);
            }
            e++;
            
        }
        return ans;
    }
};