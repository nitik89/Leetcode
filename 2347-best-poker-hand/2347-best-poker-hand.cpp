class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int a=1;
        char c=suits[0];
        for(int i=1;i<suits.size();i++){
            if(suits[i]!=c){
                a=0;
                break;
            }
        }
        if(a==1){
            return "Flush";
        }
        unordered_map<int,int>mp;
        for(int i=0;i<ranks.size();i++){
            mp[ranks[i]]++;
        }
        for(auto x:mp){
            if(x.second>=3){
                return "Three of a Kind";
            }
        }
         for(auto x:mp){
            if(x.second==2){
                return "Pair";
            }
        }
        return "High Card";
    }
};