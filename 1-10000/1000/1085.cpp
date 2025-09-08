#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;
    
    int arr1[4] = {x,y,w,h};
    int arr2[4] = {0,0,x,y};

    int min = 1001;

    for (int i=0;i<4;i++){
        int diff = arr1[i] - arr2[i];
        if (min > diff) min = diff;
    }
    cout << min;

}