class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long>mp;
        long long track=0;
        for(int i=0;i<tasks.size();i++){
           
            if(mp.find(tasks[i])==mp.end()){
                
                mp[tasks[i]]=track;
                track++;
            }
            else{
                // cout<<i<<" "<<track<<"\n";
                //check for insertions
               
                long long vals=track-mp[tasks[i]]-1;
               long long t=max(0LL,space-vals);
                // cout<<t<<" "<<tasks[i]<<"\n";
                track+=t;
               
                mp[tasks[i]]=track;
                track++;
                
                
            }
        }
        return track;
    }
};