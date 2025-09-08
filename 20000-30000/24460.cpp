#include <bits/stdc++.h>
using namespace std;

int G[1024][1024] = {0,};
int N;

int DnQ(int G[][1024],int x,int y,int size){
    int arr[4];
    if (size == 2){
        for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                arr[i*2+j] = G[x+i][y+j];
            }
        }
        sort(arr,arr+4);
        return arr[1];
    }

    

    size /= 2;
    arr[0] = DnQ(G,x,y,size);
    arr[1] = DnQ(G,x+size,y,size);
    arr[2] = DnQ(G,x,y+size,size);
    arr[3] = DnQ(G,x+size,y+size,size);
    sort(arr,arr+4);

    return arr[1];
}


int main(){
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> G[i][j];
        }
    }
    if (N == 1){
        cout << G[0][0];
        return 0;
    }

    cout << DnQ(G,0,0,N);
}