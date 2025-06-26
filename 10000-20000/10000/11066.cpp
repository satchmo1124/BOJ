#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 int * file;

int main(){
    int T;
    cin >> T;


    for (int i=0;i<T;i++){
        int N;
        cin >> N;
        file = new int[N+1];
        for (int i=0;i<N;i++) cin >> file[i+1];

        sort(file,&file[N+1]);

        int res = 0;

        res += (N-1) * file[1];
        for (int i=1;i<N;i++){
            res += (N-i) * file[i+1];
        }

        cout << res <<'\n';

        delete file;
    }
}