class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()){
            return 0;
        }
        if(ratings.size() <= 1){
            return 1;
        }
        vector<int> result(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++){
            if (ratings[i] > ratings[i - 1]){
                if (result[i] <= result[i - 1]){
                    result[i] = result[i - 1] + 1;
                }
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--){
            if (ratings[i] > ratings[i + 1]){
                if (result[i] <= result[i + 1]){
                    result[i] = result[i + 1] + 1;
                }
            }
        }
        int sum = 0;
        for (auto val : result)
        {
            sum += val;
        }
        return sum;
    }
};