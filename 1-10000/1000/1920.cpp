#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(vector<int>&V,int N,int key){
    int start = 0 , end = N-1;
    
    while(start <= end){
        int mid = (start + end) /2;
        if (V[mid] > key) end = mid - 1;
        else if (V[mid] < key) start = mid + 1;
        else return true;       
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int N,M,tmp;
    cin >> N;
    vector<int>V;
    for (int i=0;i<N;i++){
        cin >> tmp; V.push_back(tmp);
    }
    sort(V.begin(),V.end());
    cin >> M;
    for (int i=0;i<M;i++){
        cin >> tmp;
        if (BinarySearch(V,N,tmp)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}

/*
1 2 3 4 5
*/