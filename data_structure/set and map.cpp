#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int,int>m;
    m[0]++;
    m[0]++;
    cout << m[0];
}
