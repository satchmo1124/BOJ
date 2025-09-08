#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {1,-1,2,-2,2,-2,1,-1};

int BFS(vector<vector<int>>&G,int L,Point start,Point end){
    
    queue<Point>q;
    q.push(start);

    int level = 0;
    Point next;

    while(!q.empty()){
        int size = q.size();
        level++;
        for (int i=0;i<size;i++){
            Point u = q.front();
            q.pop();
            for (int j=0;j<8;j++){
                next.x = u.x + dx[j];
                next.y = u.y + dy[j];

                if (0 <= next.x && next.x < L && 0 <= next.y && next.y < L && !G[next.x][next.y]){
                    G[next.x][next.y] = 1;
                    if (next.x == end.x && next.y == end.y){
                        return level;
                    }
                    q.push(next);
                }
            }
        }
    }
    return level;
}

int main(){
    int T,L;
    Point start,end;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> L;
        vector<vector<int>>G(L,vector<int>(L,0));
        
        cin >> start.x >> start.y;
        cin >> end.x >> end.y;

        if (start.x == end.x && start.y == end.y) {
            cout << 0 <<'\n';
            continue;
        }

        cout << BFS(G,L,start,end) << '\n';
    }
}