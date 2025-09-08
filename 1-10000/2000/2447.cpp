#include <bits/stdc++.h>
using namespace std;

char G[2187][2187];

void DnQ(int x,int y,int size){
    if (size == 1) return;
    

    size /= 3;
    DnQ(x,y,size);
    DnQ(x,y+size,size);
    DnQ(x,y+2*size,size);
    
    DnQ(x+size,y,size);
    //DnQ(x+size,y+size,size);
    for (int i = size;i<2*size;i++){
        for (int j = size;j<2*size;j++){
            G[x+i][y+j] = ' ';
        }
    }

    DnQ(x+size,y+2*size,size);

    DnQ(x+2*size,y,size);
    DnQ(x+2*size,y+size,size);
    DnQ(x+2*size,y+2*size,size);

}

int main(){
    int N;
    cin >> N;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            G[i][j] = '*';
        }
    }
    DnQ(0,0,N);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << G[i][j];
        }
        cout << '\n';
    }
}

/*
3^k + 

an = an-1 * 8 + a
a = 8^(k-1) 


*/