class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>vec;
        vec.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            vector<int>temp(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++){
                temp[j]=vec[j-1]+vec[j];
            }
            vec=temp;
        }
        return vec;
        
    }
};