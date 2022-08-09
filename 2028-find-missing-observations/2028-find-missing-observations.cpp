class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum=(n+m)*(mean);
        int sum1=0;
        for(auto x:rolls){
            sum1+=x;
        }
        int left=sum-sum1;
        // cout<<left<<" ";
        int sv=left/n;
        if(left>6*n||left<0||sv==0){
            return {};
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(sv);
            left-=sv;
        }
        if(left>0){
          double v=(left/n+1);
            // cout<<v<<" ";
            for(int i=0;i<ans.size();i++){
                ans[i]+=v;
                left-=v;
                if(left==0){
                    break;
                }
            }
        }
        return ans;
    }
};