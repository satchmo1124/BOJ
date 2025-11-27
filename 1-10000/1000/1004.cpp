#include <bits/stdc++.h>
using namespace std;

enum State{
    Out,
    In,
};

enum State GetState(int x,int y,int cx,int cy,int r){
    bool s = ((cx-x)*(cx-x) + (cy-y)*(cy-y)) < r * r; 
    return s ? In : Out;
}

bool Traverse(int x1,int y1,int x2,int y2,int cx,int cy,int r){
    enum State s1 = GetState(x1,y1,cx,cy,r);
    enum State s2 = GetState(x2,y2,cx,cy,r);
    return s1^s2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int N;
        cin >> N;
        int cnt = 0;
        for (int j=0;j<N;j++){
            int cx,cy,r;
            cin >> cx >> cy >> r;
            if (Traverse(x1,y1,x2,y2,cx,cy,r)) cnt++;
        }
        cout << cnt << '\n';
    }
}