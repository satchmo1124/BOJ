#include <iostream>
#include <algorithm>
#include <vector>

#define max(a,b) ( ((a)>(b)) ? (a) : (b) ) 

#define ll long long 
using namespace std;

vector<ll>dp;
vector<bool>last;
vector<int>v;

int main(){
    int N;
    cin >> N;

    dp.resize(N+1,0);
    last.resize(N+1,false);
    v.resize(N+1,-1001);

    bool all_neg = true;

    for (int i=1;i<=N;i++) {
        cin >> v[i];
        if (v[i] >= 0) all_neg = false;
        last[i] = false;
        dp[i] = -1001;
    }

    if (all_neg) {
        sort(v.begin(),v.end());
        cout << v[N];
        return 0;
    }


    dp[1] = v[1];
    ll local_sum = 0;
    
    if (dp[1] > 0 ) {
        local_sum = dp[1];
        last[1] = true;
    }

    for (int i=2;i<=N;i++){
        local_sum += v[i];
        if (v[i] >=0 ){
            if (last[i-1]) {
                last[i] = true;
                dp[i] = dp[i-1] + v[i];
            }
            else{
                if (dp[i-1] <= local_sum) {
                    dp[i] = local_sum;
                    last[i] = true;
                }
                else{
                    dp[i] = dp[i-1];
                    last[i] = false;
                }                
            }
        }
        else{
            // v[i] < 0
            if (local_sum < 0 ) local_sum = 0;
            last[i] = false;
            dp[i] = dp[i-1];
            
        }
    }
    cout << dp[N];
}