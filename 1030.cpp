#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll X,Y;
vector<vector<ll>>arr(50,vector<ll>(50,0));

/*
[x_s,x_e) * [y_s,y_e) : 직사각형 영역이 속한 정사각형 영역  
x_s,y_s,r
*/
void Dnq(ll s,ll N,ll K,ll r1,ll r2,ll c1,ll c2,ll x_s,ll y_s){
    
    // 어떤 직사각형 영역이 들어왔을 때, 해당 직사각형을 정사각형 프렉텔 범위로 분할해 각각의 함수 내에서 값 구하기

   

    ll R = pow(N,s); // 정사각형 영역의 한 변 길이
    ll r = R / N; // 작은 프렉탈 정사각형의 한 변 길이


    ll start_offset,end_offset;
    start_offset = ((N - K) / 2) * r;
    end_offset = ((N + K) / 2) * r;

    if (s == 1){
        for (int i=r1;i<=r2;i++){
            for (int j=c1;j<=c2;j++){
                 if (x_s + start_offset <= i && i < x_s + end_offset && 
                y_s + start_offset <= j && j < y_s + end_offset){
                    arr[i-X][j-Y] = 1;
                }
            }
        }  
        return;
    }

    vector<ll>x_b;
    vector<ll>y_b;

    x_b.push_back(r1);
    y_b.push_back(c1);
    
    for (ll i=r1+1;i<=r2;i++) if ((i-x_s) % r == 0) x_b.push_back(i);
    for (ll j=c1+1;j<=c2;j++) if ((j-y_s) % r == 0) y_b.push_back(j);

    ll x,y;
    ll frac_x,frac_y; // 분할된 사각형의 시작점이 위치한 정사각형의 시작점
    for (int i=0;i<(int)x_b.size();i++){
        for (int j=0;j<(int)y_b.size();j++){
            x = x_b[i]; y = y_b[j]; // 분할된 사각형의 시작점
            ll tmp_x = x, tmp_y = y; // 분할 사각형의 끝점
            tmp_x++; tmp_y++;
            while(tmp_x % r !=0 && tmp_y % r != 0 && tmp_x <= r2 && tmp_y <= c2){ tmp_x++; tmp_y++; }
            while(tmp_x % r !=0 && tmp_x <= r2){ tmp_x++;}
            while(tmp_y % r !=0 && tmp_y <= c2){ tmp_y++;}
            tmp_x--; tmp_y--;

            frac_x = x_s + ((x-x_s) / r) * r; frac_y = y_s + ((y-y_s) / r) * r;
            if (x_s + start_offset <= x && x < x_s + end_offset && 
                y_s + start_offset <= y && y < y_s + end_offset){
                    for (ll r=x-X;r<=tmp_x-X;r++){
                        for (ll c=y-Y;c<=tmp_y-Y;c++){
                            arr[r][c] = 1;
                        }
                    }
                }
            Dnq(s-1,N,K,x,tmp_x,y,tmp_y,frac_x,frac_y);
        }
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll s,N,K,r1,r2,c1,c2;
    cin >> s >> N >> K >> r1 >> r2 >> c1 >> c2;

    X = r1; Y = c1;
    if (s != 0) Dnq(s,N,K,r1,r2,c1,c2,0,0);
    for (int i=r1-X;i<=r2-X;i++){
        for (int j=c1-Y;j<=c2-Y;j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}



/*
128mb = 33554432
128MB = 128 * 1024(KB) = 128 * 1024 * 1024 (B) = 128 * 1024 * 1024 / 4 (int) = 3,554,432

array 메모리 = N ^ 2s <= 8 ^20 = 2^60 (B) = 2 ^ 60 / 4 = 2 ^ 58 =  288,230,376,151,711,744


R1 ≤ R2 ≤ R1 + 49
C1 ≤ C2 ≤ C1 + 49

아이디어 : 
구헤야할 범위는 고작 50 * 50 임.
그러면 걸쳐져 있는 정사각형 단위만 파악해 계산 ㄱㄱ.

*/

/*
void DnQ(ll s,ll N,ll K,ll r1,ll r2,ll c1,ll c2){
    if (s == 0) return;
    
    ll offset = pow(N,s-1);

    vector<ll>x_b;
    vector<int>y_b;

    x_b.push_back(r1);
    y_b.push_back(c1);
    
    for (ll r=r1+1;r<r2;r++) if (r % offset == 0) x_b.push_back(r);    
    for (ll c=c1+1;c<c2;c++) if (c % offset == 0) y_b.push_back(c);    

    x_b.push_back(r2);    
    y_b.push_back(c2);


    ll start,end;
    start = ((N - K) / 2) * offset;
    end = ((N + K) / 2) * offset;

    ll x_s,x_e,y_s,y_e;

        
    
    for (auto x = x_b.begin();x!=x_b.end()-1;x++){
        for (auto y = y_b.begin();y!=y_b.end()-1;y++){
            x_s = *x; x_e = *(x+1);
            y_s = *y; y_e = *(y+1);

            if (start <= x_s && x_e <= end && start <= y_s && y_e <= end){
                for (int i=x_s-r1;i<x_e-r1;i++){
                    for (int j=y_s-c1;j<y_e-c1;j++){
                        arr[i][j] = 1;
                    }
                }
            }
            else{
                DnQ(s-1,N,K,x_s,x_e-1,y_s,y_e-1);
            }
        }
    }
    
}


*/