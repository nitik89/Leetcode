class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
       int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[j][1]>=intervals[i][0]){
                intervals[j][1]=max(intervals[i][1],intervals[j][1]);
            }
            else{
                j++;
                intervals[j]=intervals[i];
            }
        }
        int k=0;
        vector<vector<int>>ans;
        while(k<=j){
            ans.push_back({intervals[k][0],intervals[k][1]});
            k++;
        }
        return ans;
    }
};