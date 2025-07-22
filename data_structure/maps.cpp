#include <iostream>
#include <map>
using namespace std;
map<string, int> mapset;
int main(void) {

	mapset.insert({ "Alice", 100 });
	mapset.insert({ "Bob", 200 });

	if (mapset.find("Alice") != mapset.end()) 
	{
		cout << "found" << endl;
	}
	else {
		cout << "not found" << endl;
	}

	//인덱스기반 (iterator)
	for (auto iter = mapset.begin() ; iter !=  mapset.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	cout << endl;

	//범위기반  pair (element itself)
	for (auto iter : mapset) {
		cout << iter.first << " " << iter.second << endl;
	}

	return 0;
}
//출처: https://life-with-coding.tistory.com/305 [코딩젤리:티스토리]