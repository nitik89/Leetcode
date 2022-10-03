class Solution {
public:
   vector<vector<string>>dp;
    string getAns(vector<int>&cost,int target,int i,int curr){
        
        if(target == curr ){
            return "";
        }
        if(target < curr || i == cost.size()){
            return "0";
        }
        
        if(dp[i][curr] != "-1"){
            return dp[i][curr];
        }
        
        string str1 = getAns(cost,target,0,curr+cost[i]); //unbounded knapsack we can use all the items again and again so we did like this
        string str2 = getAns(cost,target,i+1,curr);
        
        string temp = to_string(i+1) + str1;
        if(str1 == "0" && str2=="0" ) return dp[i][curr] = "0";
        
        else if(str1 == "0") return dp[i][curr] = str2;
        
        else if(str2 == "0") return dp[i][curr] = temp;
    
        //lexogrpihical comp of the strings
        else if(temp.size() > str2.size() ){
            return dp[i][curr] = temp;
        }
        else if(temp.size() == str2.size() ){
            return dp[i][curr] = (temp > str2 ? temp : str2);
        }
        else{
            return dp[i][curr] = str2;
        }
    }
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(10,vector<string>(target,"-1"));
     return getAns(cost,target,0,0);  
    }
};