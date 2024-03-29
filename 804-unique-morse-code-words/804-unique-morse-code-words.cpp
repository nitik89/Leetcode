class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>vec={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string>mp;
        for(auto x:words){
            string temp="";
            for(auto y:x){
                temp+=vec[y - 'a'];
            }
            mp.insert(temp);
        }
        return mp.size();
    }
};