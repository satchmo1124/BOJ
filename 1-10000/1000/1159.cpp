#include <bits/stdc++.h>
using namespace std;

int main(){
    int alphabet[26] = {0,};
    int N;
    cin >> N;
    string s;
    for (int i=0;i<N;i++){
        cin >> s;
        alphabet[s[0]-'a']++;
    }
    bool gg = true;
    char c;
    for (int i=0;i<26;i++){
        if (alphabet[i] >=5){
            gg = false;
            c = i + 'a';
            cout << c;
        }
    }
    if (gg){
        cout << "PREDAJA";
    }
}