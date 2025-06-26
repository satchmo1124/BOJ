#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int input;
    while(cin >> input){
        int cnt = 1;
        int x = 1;
        while(1){
            x %= input;
            if (x == 0){
                cout << cnt << '\n';
                break;
            }
            x = x * 10 + 1;
            cnt++;
        }
        
    }

}