#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N,X;
    cin >> N >> X;

    int alpha = (X - 1000 * N) / 4000;

    vector<int>diff;

    int a,b;

    int tot = 0;

    for (int i=0;i<N;i++){
        cin >> a >> b;
        tot += b;
        diff.push_back(a-b);
    }
    sort(diff.begin(),diff.end(),greater<int>());

    for (int i=0;i<alpha;i++){
        if (diff[i] < 0){
            break;
        }
        tot += diff[i];
    }

    cout << tot;
    
}