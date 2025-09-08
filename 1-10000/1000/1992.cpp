#include <bits/stdc++.h>
using namespace std;

void QuadTree(int **arr,int x,int y,int size){
    bool is_one = true;
    bool is_zero = true;
    bool chk = true;

    int r,c;

    for (int i=0;i<size;i++){
        r = x + i;
        if (!chk) break;

        for (int j=0;j<size;j++){
            c = y + j;
            if (arr[r][c] == 1) is_zero = false;
            if (arr[r][c] == 0) is_one = false;

            chk = is_zero || is_one;
            if (!chk) break;
        }
    }    

    if (chk){
        if (is_zero) cout << 0;
        else cout << 1;
        return;
    }

    cout << "(";
    
    int len = size / 2;

    QuadTree(arr,x,y,len);
    QuadTree(arr,x,y+len,len);
    QuadTree(arr,x+len,y,len);
    QuadTree(arr,x+len,y+len,len);

    cout << ")";
}

int main(){
    int N;
    cin >> N;
    int **arr = new int*[N];
    for (int i=0;i<N;i++) arr[i] = new int [N];
    
    string s;
    for (int i=0;i<N;i++){
        cin >> s;
        for (int j=0;j<N;j++){
            arr[i][j] = s[j]-'0';
        }
    }
    QuadTree(arr,0,0,N);

    for (int i=0;i<N;i++){
        delete [] arr[i];
    }
    delete arr;
}