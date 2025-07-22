#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<char,int>>v;

int idx_counter = 0;



bool cmp(pair<char,int>p1,pair<char,int>p2){
    if (idx_counter == 0){
        return p1.second < p2.second;
    }
    else{
        if (p1.second == p2.second){
            int val1 = v[idx_counter].count(p1.first) ? v[idx_counter-1][p1.first] : 0;
            int val2 = v[idx_counter].count(p2.first) ? v[idx_counter-1][p2.first] : 0;

            return val1 < val2;
        }
        return p1.second < p2.second;
    }
    
}

int main(){
    int N;
    cin >> N;

    string s;
    vector<string>inputs;

    int max_length = 0;
    int len;

    for (int i=0;i<N;i++){
        cin >> s;
        inputs.push_back(s);
        len = s.length();
        if (max_length < len){
            max_length = len;
        }
    }

    v.resize(max_length);



    for (int i=0;i<N;i++){
        s = inputs[i];
        len = s.length();
        for (int j=0;j<len;j++){
            int idx = len - j - 1;
            if (v[idx].find(s[j]) != v[idx].end()){
                v[idx][s[j]]++;
            }
            else{
                v[idx][s[j]] = 1;
            }
        }
    }

    // Check

    for (int i=0;i<max_length;i++){
        for (auto iter = v[i].begin();iter!=v[i].end();iter++){
            cout << "(" <<iter->first << "," << iter->second << ") ";
        }
        cout << '\n';
    }

    

    for (int i=0;i<max_length;i++){
        idx_counter = i;
        sort(v[i].begin(),v[i].end(),cmp);
    }

    cout << '\n\n';

    for (int i=0;i<max_length;i++){
        for (auto iter = v[i].begin();iter!=v[i].end();iter++){
            cout << "(" <<iter->first << "," << iter->second << ") ";
        }
        cout << '\n';
    }



}