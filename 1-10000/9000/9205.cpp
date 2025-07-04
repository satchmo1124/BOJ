#include <iostream>
#define abs(a,b) ((a)>(b) ? (a-b) : (b-a))
using namespace std;

struct Point{
    int x;
    int y;
};


/*
0 : 집
1 ~  N : 편의점
N+1 : 펜타 
*/
int N;

Point * node;

int edge[102][102] = {0,};
int visited[102] = {0,};

bool happy = false;

void DFS(int n){
    if (n==N+1) {
        happy = true;
        return;
    }

    visited[n] = 1;
    for (int i=0;i<=N+1;i++){
        if (!visited[i] && edge[n][i] == 1){
            DFS(i);
        }
    }
}


int main(){
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N;

        node =  new Point[N+2];


        Point p;

        for (int i=0;i<=N+1;i++){
            cin >> p.x >> p.y;
            node[i] = p;
        }

        if (node[0].x == node[N+1].x && node[0].y == node[N+1].y ) {
            cout << "happy" << '\n';
            continue;
        }

        Point p1,p2;

        for (int i=0;i<=N+1;i++){
            p1 = node[i];
            for (int j=0;j<=N+1;j++){
                if (i==j) continue;
                p2 = node[j];
                int length = abs(p1.x,p2.x) + abs(p1.y,p2.y);
                if (length <= 1000 || length == 0) {
                    edge[i][j] = edge[j][i] = 1;
                }
            }
        }

        happy = false;

        DFS(0);
        if (happy) cout << "happy" << '\n';
        else cout << "sad" << '\n';

        for (int i=0;i<=N+1;i++){
            visited[i] = 0;
            for (int j=0;j<=N+1;j++){
                edge[i][j] = edge[j][i] = 0;
            }
        }
    }
}