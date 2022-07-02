class Solution {
public:
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        int n=hor.size();
        long long ht=hor[0];
        
        for(int i=1;i<hor.size();i++){
            ht=max((long long)hor[i]-hor[i-1],ht);
        }
        ht=max(ht,(long long)h-hor[n-1]);
        
        long long wd=ver[0];
        n=ver.size();
        for(int i=1;i<ver.size();i++){
            wd=max((long long)ver[i]-ver[i-1],wd);
        }
        wd=max(wd,(long long)w-ver[n-1]);
        
        return ((ht%1000000007)*(wd%1000000007))%1000000007;
        
        
    }
};