#include <iostream>
#include <string>
#include <queue>

using namespace std;

int G[53][53] ={0,}; // 2(source & sink) + 50(Max length) = 52
int visited[53] = {0,};
queue<int>q;


bool bfs(){
    visited[0] = 1;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (auto it )
    }

}




bool is_anagram(string a,string b){
    int ascii_a[128] = {0,};
    int ascii_b[128] = {0,};
    
    for (int i=0;i<a.size();i++){
        if (a[i] >= 128 || a[i] < 0) continue;
        if ('A' <= a[i] && a[i] <= 'Z') {
            ascii_a[a[i]-'A'+'a']++;
        }
        else {ascii_a[a[i]]++;}
    }
    for (int i=0;i<b.size();i++){
        if (b[i] >= 128 || b[i] < 0 ) continue;
        if ('A' <= b[i] && b[i] <= 'Z'){
            ascii_b[b[i]-'A'+'a']++;
        }
        else{ascii_b[b[i]]++;}
    }

    for (int i=0;i<128;i++){
        if (ascii_a[i]!=ascii_b[i]) return false;
    }
    return true;
}

void alphabet_mod(){
    for (int a = 'A'; a<='Z' ; a++){
        printf("%c : %d \n",a,a-'A');
    }
}

int main(){
    string a = "Ave Maria, gratia plena, Dominus tecum";
    string b = "Virgo serena, pia, munda et immaculata";
    if (is_anagram(a,b)) {
        printf("anagram!! :)");
    }
    else {
        printf("Not anagram :(\n");
    } 

    printf("\n\n");

    alphabet_mod();

    
    cin >> a;
    cin >> b;

    

}