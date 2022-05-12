class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       sort(intervals.begin(),intervals.end());
        int res=0;
        vector<vector<int>>ans;
        int n=intervals.size();
      
        for(int i=1;i<n;i++){
            if(intervals[res][1]>=intervals[i][0]){
                vector<int>temp;
                
                intervals[res][1]=max(intervals[res][1],intervals[i][1]);
                
            }
            else{
                res++;
                intervals[res]=intervals[i];
                
                
            }
        }
    
        int i=0;
        while(i<=res){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};