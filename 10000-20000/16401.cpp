#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    int M,N,tmp;
    cin >> M >> N;
    
    vector<int>v;
    for (int i=0;i<N;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    ll local_sum = 0;

    int l,m,h;
    l = 0;
    h = *max_element(v.begin(),v.end());

    while (l < h){
        local_sum = 0;
        m = (l + h + 1) / 2;

        for (int i = 0; i < N ;i++){
            local_sum += v[i] / m;
        }        
        if (local_sum >= M) {
            l = m;
        }
        else{
            h = m - 1;
        }
    }
    cout << l;
}