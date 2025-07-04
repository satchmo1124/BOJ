#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        int T;
        cin >> T;
        unordered_map<ll,int>m;

        ll element;

        for (int i=0;i<T;i++){    
            cin >> element;
            m[element]++;
        }

        int offset = T / 2;
        bool found = false;

        for (auto &[key,val] : m){
            if (val > offset) {
                found = true;
                cout << key << '\n';
                break;
            }
        }
        if (!found) cout << "SYJKGW" << '\n';
    }
}


/*

O(nlog n)

200 * 100000 * log 100000

*/