#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

#define pp pair<char,int>

using namespace std;

bool cmp(const pp& a,const pp& b){
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    int N;
    cin >> N;

    vector<string>arr;
    map<char,int>m;
    string s;
    
    for (int i=0;i<N;i++){
        cin >> s;
        arr.push_back(s);
    }

    for (int i=0;i<N;i++){
        int len = arr[i].length();
        for (int j=0;j<len;j++){
            
            int shift = len - j - 1;
            char c = arr[i][j];
            int offset = pow(10,shift);

            if (m.find(c)!=m.end()){
                m[c] += offset;
            }
            else{
                m[c] = 0;
                m[c] += offset;
            }
        }
    }

    vector<pp> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp);

    int tot,idx;
    tot = idx = 0;

    for (pp& num : v){
        tot += num.second * (9-idx);
        idx++;
    }
    cout << tot;
}