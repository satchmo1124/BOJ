#include <bits/stdc++.h>
using namespace std;

int main(){
    int tot = 0;
    string s;
    for (int i=0;i<8;i++){
        cin >> s;
        for (int j=0;j<8;j++){
            bool is_white = !((i + j) % 2); 
            if (is_white && s[j] == 'F') tot++;
        }
    }
    cout<<tot;
}