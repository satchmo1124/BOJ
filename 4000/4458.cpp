#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin>>N;
    string s;
    getline(cin,s);
    // 제한자는 default로 엔터, 제한자 저장 X.

    for (int i=0;i<N;i++){
        getline(cin,s);
        if ('a'<=s[0] && s[0]<='z') s[0] += 'A'-'a';
        cout << s<<'\n';
    }
}



/*

    for (int i=0;i<N;i++){
        string s;
        if (i==N-1){
            cin >> s;
        }
        else{
            getline(cin,s);
        }
        bool is_whitespaced = false;
        for (int j=0;j<s.length();j++){
            if ('a' <= s[j] && s[j] <= 'z'){
                if (j==0){
                    s[j] += 'A' - 'a';
                }
                else if (is_whitespaced){
                    s[j] += 'A' - 'a';
                    is_whitespaced = false;
                }
            }
            if (s[j] == ' '){
                is_whitespaced = true;
            }
            if (s[j] != ' '){
                is_whitespaced = false;
            }
        }
        cout << s << '\n';
    }


*/