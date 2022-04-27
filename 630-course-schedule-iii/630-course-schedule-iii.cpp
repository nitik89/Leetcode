class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int curr=0;
        int cnt=0;
       
        priority_queue<int>pq;
        
        for(int i=0;i<courses.size();i++){
            if(curr+courses[i][0]<=courses[i][1]){
                curr+=courses[i][0];
                pq.push(courses[i][0]);
                cnt++;
            }
            else{
                if(!pq.empty()&&pq.top()>courses[i][0]){
                curr-=pq.top();
                    cnt--;
                    pq.pop();
                    if(curr+courses[i][0]<=courses[i][1]){
                        curr+=courses[i][0];
                pq.push(courses[i][0]);
                cnt++;
                    }
                }
            }
            
        }
        return cnt;
    }
};