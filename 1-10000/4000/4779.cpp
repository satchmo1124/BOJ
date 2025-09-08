#include <bits/stdc++.h>

using namespace std;

void cantor(int *v,int start,int end){
    if (start == end) return;
    int offset = (end - start + 1) / 3;

    int next = start + offset;

    for (int i = next ;i < next + offset ;i++) v[i] = 0;
    cantor(v,start,start+offset-1);
    cantor(v,end-offset+1,end);
}

int main(){
    int N;
    while (cin >> N){
        int len = pow(3,N);
        int *v = new int [len];
        for (int i=0;i<len;i++) v[i] = 1;
        cantor(v,0,len-1);
        for (int i=0;i<len;i++){
            v[i] == 1 ? (cout << '-') : (cout << ' ');
        }

        cout << '\n';
   }
    return 0;
}