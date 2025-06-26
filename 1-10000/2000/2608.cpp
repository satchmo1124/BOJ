#include <iostream>
#include <string>
using namespace std;
/*

기호	I	V	X	L	C	D	M
값	    1	5	10	50	100	500	1000


*/

int rom_to_num ['X'+1];


pair<int,string> roman(string s1,string s2){
    int a,b,c;
    a = b = 0;


    for (int i=0;i<s1.length();i++){
        c = s1[i];
        a += rom_to_num[c];
    }

    for (int i=0;i<s2.length();i++){
        c = s2[i];
        b += rom_to_num[c];
    }

    int res = a + b;

    return make_pair(res,"for debugging");
}


int main(){
    string s1,s2;
    cin >> s1;
    cin >> s2;

    rom_to_num['l'] = 1;
    rom_to_num['V'] = 5;
    rom_to_num['X'] = 10;
    rom_to_num['L'] = 50;
    rom_to_num['C'] = 100;
    rom_to_num['D'] = 500;
    rom_to_num['M'] = 1000;


    int res;
    string s;


    make_pair(res,s) = roman(s1,s2);

    cout << res << '\n' << s;
}