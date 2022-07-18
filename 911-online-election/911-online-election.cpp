class TopVotedCandidate {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    vector<int>time;
    TopVotedCandidate(vector<int>& per, vector<int>& tim) {
        int mx=INT_MIN,p=-1;
        for(int i=0;i<per.size();i++){
            mp[per[i]]++;
            if(mp[per[i]]>=mx){
                mx=mp[per[i]];
                p=per[i];
            }
            vec.push_back(p);
            time.push_back(tim[i]);
        }
    }
    
    int q(int t) {
        int idx=lower_bound(time.begin(),time.end(),t)-time.begin();
        // cout<<idx<<" ";
        if(time[idx]==t){
            return vec[idx];
        }
        return vec[idx-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */