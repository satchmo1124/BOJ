#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int>v(N,0);
    for (int i=0;i<N;i++)  cin >> v[i];

    int tot;
    cin >> tot;
    
    int sum = accumulate(v.begin(),v.end(),0);
    
    if (sum <= tot) {
        cout << *max_element(v.begin(),v.end());
        return 0;
    }
    
    int l,m,h,local_sum;
    l = 0;
    h = tot;

    while (l < h){
        m = (l + h + 1)/2;
        local_sum = 0;

        for (int i=0;i<N;i++){
            if (m <= v[i]) local_sum += m;
            else local_sum += v[i];
        }


        if (local_sum <= tot){
            l = m;
        }
        else{
            h = m - 1;
        }
    }
    cout << l;
}
