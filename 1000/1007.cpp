#include <iostream>
#include <vector>
#include <cmath>
typedef unsigned long long lli;

/*
1007인데 벡터의 길이의 합으로 구함...
원래는 합의 길이를 구해야 함 ㅇㅅㅇ 

*/

/*
class Vec
*/
class Vec {
public:
    lli x,y;
    lli len;

    Vec(lli x,lli y) {
        this->x = x; this->y = y;
        calc_len();
    }
    Vec () {
        this->x = this->y = this->len = -1;
    }
    void calc_len(){
        this->len = x*x + y*y;
    }

    static Vec add(Vec v1,Vec v2){
        return Vec(v1.x+v2.x,v1.y+v2.y); 
    }
    static Vec sub(Vec v1,Vec v2){
        return Vec(v1.x-v2.x,v1.y-v2.y);
    }
    void accum_add(Vec v) {
        this->x += v.x;
        this->y += v.y;
        calc_len();
    }
    void accum_sub(Vec v){
        this->x -= v.x;
        this->y -= v.y;
        calc_len();
    }
};


using namespace std;

vector<vector<Vec>> adj(20,vector<Vec>(20,Vec(0,0)));



Vec find_dfs(int N,int visited[],Vec p){

    Vec local_p=Vec();

    bool is_final = true;

    for (int i=0;i<N;i++){
        if (!visited[i]){
            visited[i] = 1;
            is_final = false;

            for (int j=0;j<N;j++){
                if (!visited[j]){
                    visited[j] = 1;

                    Vec new_p = find_dfs(N,visited,Vec::add(p,adj[i][j]));
                    if (local_p.len == -1 || local_p.len > new_p.len ){
                        local_p = new_p;
                    }
                    visited[j] = 0;
                }
            }
            visited[i] = 0;
        }
    }
    if (is_final) {
        return p;
    }
    return local_p;
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    cout.fixed;
    cout.precision(16);
    int T;
    cin>>T;


    for (int i=0;i<T;i++){
        int N;
        cin>>N;

        vector<Vec>P;
        Vec p;

        for (int i=0;i<N;i++){
            cin>>p.x >> p.y;
            P.push_back(p);
        }

        for (int i=0;i<N-1;i++){
            for (int j=i+1;j<N;j++){
                adj[i][j] = Vec::sub(P[i],P[j]);
                adj[j][i] = Vec::sub(P[j],P[i]);
            }
        }

        int visited[20] = {0,};
 
        Vec local_p = Vec(); 

        for (int i=0;i<N;i++){
            visited[i] = 1;
            for (int j=0;j<N;j++){
                if (i==j) continue;
                visited[j] = 1;
                Vec new_p = find_dfs(N,visited,adj[i][j]);
                if (local_p.len == -1 || local_p.len > new_p.len ){
                    local_p = new_p;
                }
                visited[j] = 0;
            }
            visited[i] = 0;
        }
        
        cout << sqrt(local_p.len)<<'\n';
       
    }
    
}