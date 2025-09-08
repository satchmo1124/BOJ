#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string>v;
    string s;

    for (int i=0;i<N;i++){
        cin >> s;
        v.push_back(s);
    }
    int len = s.length();
    bool is_eq;

    s.clear();

    for(int j=0;j<len;j++){
        char c = v[0][j];
        is_eq = true;
        for (int i=1;i<N;i++){
            if (c != v[i][j]) {
                is_eq = false;
                break;  
            }
        }
        if (!is_eq){
            s.push_back('?');
        }
        else{
            s.push_back(c);
        }
    }
    cout << s;
}