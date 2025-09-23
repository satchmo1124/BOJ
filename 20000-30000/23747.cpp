#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x,y;
};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

//int G[1001][1001]={0,};
//int res[1001][1001] = {0,};

int **G;
bool **res;

int R,C;
int MOVE;

void DFS(Point p,int color){
    res[p.x][p.y] = 1;
    MOVE--;
    if (!MOVE) return;
    Point p_n;
    for (int i=0;i<4;i++){
        p_n.x = p.x + dx[i];
        p_n.y = p.y + dy[i];
        if (0 <= p_n.x && p_n.x < R && 0 <= p_n.y && p_n.y < C) {
                if (G[p_n.x][p_n.y] == color && !res[p_n.x][p_n.y]){
                    DFS(p_n,color);
                }    
        }
    }
}

void Ward(Point p,string S){
    int len = S.length();
    char mov;

    for (int i=0;i<len;i++){
        if (!MOVE) return;

        mov = S[i];

        if (mov == 'U') p.x--;
        else if (mov == 'D') p.x++;
        else if (mov == 'L') p.y--;
        else if (mov == 'R') p.y++;
        else{ // Ward
            if (!res[p.x][p.y]){
                //BFS(G,R,C,p);
                DFS(p,G[p.x][p.y]);
            }
        }
    }
    res[p.x][p.y] = 1;
    
    Point p_n;
    
    for (int i=0;i<4;i++){
        p_n.x = p.x + dx[i];
        p_n.y = p.y + dy[i];
        if (0 <= p_n.x && p_n.x < R && 0 <= p_n.y && p_n.y < C) {
            res[p_n.x][p_n.y] = true;
        }
    }
    return;
}

void MakeGraph(){
    string s;
    
    G = new int*[R];
    
    for (int i=0;i<R;i++){
        G[i] = new int[C];
        cin >> s;
        int len = s.length();
        for (int j=0;j<len;j++){
            G[i][j] = s[j];
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    res = new bool*[R];

    for (int i=0;i<R;i++){
        res[i] = new bool[C];
        for (int j=0;j<C;j++){
            res[i][j] = 0;
        }
    }

    MakeGraph();
    
    int hr,hc;

    cin >> hr >> hc;

    MOVE = R * C;
    
    Point start = Point({--hr,--hc});

    string S;
    cin >> S;

    Ward(start,S);

    for (int i=0;i<R;i++){
        for (int j=0;j<C;j++){
            if (res[i][j]) cout << ".";
            else cout <<"#";
        }
        cout << '\n';
    }
}



void BFS(const vector<vector<int>>&G,int R,int C,Point start){
    vector<vector<bool>>vis(R,vector<bool>(C,0));
    queue<Point>q;
    q.push(start);
    res[start.x][start.y] = vis[start.x][start.y] = 1;
    //MOVE--;
    int color = G[start.x][start.y];
    Point p,p_n;
    while(!q.empty()){
        p = q.front();
        q.pop();
        for (int i=0;i<4;i++){
            p_n.x = p.x + dx[i];
            p_n.y = p.y + dy[i];
            if (0 <= p_n.x && p_n.x < R && 0 <= p_n.y && p_n.y < C) {
                if (G[p_n.x][p_n.y] == color && !vis[p_n.x][p_n.y] && !res[p_n.x][p_n.y]){
                    vis[p_n.x][p_n.y] = res[p_n.x][p_n.y] = true;
                    //MOVE--;
                    q.push(p_n);
                }
            }
        }
    }
}

/*

W -> BFS로 불 밝히기
마지막 칸 -> 상하좌우 

1024MB = 1024 * 1024 * 1024 B = 1,073,741,824
1,000,000
*/