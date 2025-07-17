#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<int>v;

    int tmp;
    for (int i=0;i<N;i++) {
        cin >> tmp;
        v.push_back(tmp);
    }

    int res = 0;
    for (int i=0;i<N;i++){

        int local = 0;
        for (int j=i+1;j<N;j++){
            if (v[i] >= v[j]) local ++;
            else break;
        }
        if (res < local) res = local;
    }
    cout << res;

}
