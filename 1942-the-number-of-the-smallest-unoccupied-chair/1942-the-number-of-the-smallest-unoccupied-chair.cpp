class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tf) {
        vector<vector<int>>vec;
        for(int i=0;i<times.size();i++){
            vector<int>temp={times[i][0],times[i][1],i};
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),[&](vector<int>&a1,vector<int>&a2){
            return a1[0]<a2[0];
        });
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<int,vector<int>,greater<int>>seats;
        int ch=0;
        for(int i=0;i<times.size();i++){
            int starttime=vec[i][0];
            // cout<<starttime<<" ";
            
            while(!pq.empty()&&pq.top().first<=starttime){
                seats.push(pq.top().second);
                pq.pop();
            }
            int per=vec[i][2];
            int end=vec[i][1];
            if(per==tf){
               if(seats.empty()){
                   return ch;
               }
                return seats.top();
            }
            if(seats.empty()){
                pq.push({end,ch});
                ch++;
            }
            else{
                pq.push({end,seats.top()});
                seats.pop();
                
            }
           
        }
        return -1;
    }
};