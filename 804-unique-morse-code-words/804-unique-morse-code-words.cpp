class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int>mp;
        for(auto x:words){
            string temp="";
            for(auto y:x){
                temp+=vec[y - 'a'];
            }
            mp[temp]++;
        }
        return mp.size();
    }
};