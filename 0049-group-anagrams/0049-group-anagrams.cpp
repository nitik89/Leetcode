class Solution {
public:
   // Solution 2
    // Using count sort, TC: O(N * m)
    string countSort(string str) {
        vector<int> chars(26, 0);
        string result;
        
        for(const char& c: str)
            ++chars[c - 'a'];
        for(const int& freq: chars)
            result += to_string(freq) + ',';
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagram_groups;
        // traverse through the words and add the word to the 
        // anagram group where it belongs.
        // To decide the anagram, we sort the word and use it as key
        for(const string& word: strs) {
            string anagram_word = countSort(word);
            anagram_groups[anagram_word].emplace_back(word);
        }
        
        // add the anagram groups
        vector<vector<string>> result;
        for(auto it = anagram_groups.begin(); it != anagram_groups.end(); it++) {
            result.emplace_back(move(it->second));
        }
        return result;
    
}
};