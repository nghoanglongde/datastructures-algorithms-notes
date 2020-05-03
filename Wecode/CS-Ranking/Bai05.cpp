#include<bits/stdc++.h>
// bài này sub được có 40đ, vẫn chưa hiểu mình sai case nào hic :(

using namespace std;

struct PROBS{
    int solanthuchien;
    int time;
    int sodoihoanthanh;
    int solantancong;
};
struct TEAM{
    string name;
    PROBS problems[1002];
    int sobaidagiai;
    int tongthoigian;
};

void cut_str(string s, TEAM &team, int nums_prob){
    vector<string> v;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        v.push_back(token);
    }
    team.name = v[0];
    int sobaidagiai = 0, tongthoigian = 0;
    int i = 0;
    for(int k = 1;k < v.size() - 1;k++){
        int solanthuchien = stoi(v[k]);
        int thoigian = stoi(v[k + 1]);
        PROBS new_probs;
        new_probs.solanthuchien = solanthuchien;
        new_probs.sodoihoanthanh = 0;
        new_probs.solantancong = 0;
        if(thoigian == 0){
            new_probs.time = 0;
        }
        else{
            tongthoigian = tongthoigian + ((20 * 60 * (solanthuchien - 1)) + thoigian);
            ++sobaidagiai;
            new_probs.time = round((((20 * 60 * (solanthuchien - 1)) + thoigian) * 1.0 )/60.0);
        }
        team.problems[i] = new_probs;
        ++i;
        k = k + 1;
    }
    team.sobaidagiai = sobaidagiai;
    team.tongthoigian = round((tongthoigian * 1.0)/60.0);
}
bool funcsortsobaidagiai(const TEAM &x, const TEAM &y){
    if((x.sobaidagiai > y.sobaidagiai) || (x.sobaidagiai == y.sobaidagiai && x.tongthoigian <= y.tongthoigian)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int nums_team, nums_prob; 
    cin >> nums_team >> nums_prob;
    TEAM list_team[nums_team + 1];

    cin.ignore(1000,'\n');
    for(int i = 1;i <= nums_team;i++){
        string data; getline(cin, data);
        cut_str(data, list_team[i], nums_prob);
    }
    sort(list_team + 1, list_team + nums_team + 1, funcsortsobaidagiai);

    list_team[0].problems[0].sodoihoanthanh = list_team[0].problems[0].solantancong = 0;
    
    for(int i = 1;i <= nums_team;i++){
        cout << list_team[i].name << " ";
        for(int j = 0;j < nums_prob;j++){
            if(list_team[i].problems[j].time != 0){
                list_team[i].problems[j].sodoihoanthanh = list_team[i - 1].problems[j].sodoihoanthanh + 1;
            }
            else{
                list_team[i].problems[j].sodoihoanthanh = list_team[i - 1].problems[j].sodoihoanthanh;
            }
            list_team[i].problems[j].solantancong = list_team[i - 1].problems[j].solantancong + list_team[i].problems[j].solanthuchien;
            cout << list_team[i].problems[j].solanthuchien << "," << list_team[i].problems[j].time << " ";
        }
        cout << list_team[i].sobaidagiai << "," << list_team[i].tongthoigian << endl;
    }
    for(int i = 0;i < nums_prob;i++){
        cout << list_team[nums_team].problems[i].sodoihoanthanh << "," << list_team[nums_team].problems[i].solantancong << " ";
    }

}