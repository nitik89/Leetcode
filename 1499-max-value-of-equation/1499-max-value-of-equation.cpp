class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        
        int ans=INT_MIN;
        priority_queue<vector<int>>pq;
        for(int i=0;i<points.size();i++){
            while(!pq.empty()&&abs(pq.top()[1]-points[i][0])>k){
                pq.pop();
            }
            if(!pq.empty()){
                int idx=pq.top()[2];
                int t=points[idx][1]+points[i][1]+abs(points[i][0]-points[idx][0]);
                ans=max(t,ans);
            }
            pq.push({points[i][1]-points[i][0],points[i][0],i});
        }
        return ans;
    }
};