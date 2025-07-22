#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int>v(N,0);
    for (int i=0;i<N;i++) cin >> v[i];
    int first = v[0];
    sort(v.begin(),v.end());

    if (first == *v.begin()) cout << "ez";
    else if (first == *(v.end()-1)) cout << "hard";
    else cout << "?";

}
