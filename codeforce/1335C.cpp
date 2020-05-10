#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    int t; cin >> t;
    vector<int> ans;
    while(t--){
        int n; cin >> n;
        int ans_t;
        map<int, int> my_map;
        vector<int> skills;
        for(int i = 0;i < n;i++){
            int value; cin >> value;
            skills.push_back(value);
        }
        if(n == 1){
            ans_t = 0;
        }
        else{
            for(int i = 0;i < n;i++){
                if(my_map.find(skills[i]) != my_map.end()){
                    my_map[skills[i]] += 1;
                }
                else{
                    my_map.insert(pair<int, int>(skills[i], 1));
                }
            }
            int team_1 = 0, team_2 = 0, max_dup = 0;
            for(auto itr = my_map.begin();itr != my_map.end();itr++){
                if(itr->second == 1){
                    ++team_1;
                }
                else{
                    ++team_2;
                    max_dup = max(max_dup, itr->second);
                }
            }
            if(team_2 == 0){
                ans_t = 1;
            }
            else{
                team_1 = team_1 + (team_2 - 1);
                if(max_dup - team_1 > 1){
                    team_1 = team_1 + 1;
                }
                ans_t = min(team_1, max_dup);
            }
        }
        ans.push_back(ans_t);
    }
    for(auto x: ans){
        cout << x << endl;
    }
}