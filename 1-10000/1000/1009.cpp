#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int a,b;
        cin >> a >> b;
        a %= 10;// 1의 자릿수
        int res = a;
        for (int i=1;i<b;i++){
            res *= a;
            res %= 10; 
        }

        if (res==0) cout << 10 << '\n';
        else cout << res << '\n';
    }
}