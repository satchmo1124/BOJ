#include <bits/stdc++.h>
using namespace std;

int* BinarySearch(int *start,int *end,int key){

    while (start <= end){
        int* mid = start + (end - start)/2;
        if (*mid > key) end = mid - 1;
        else if (*mid < key) start = mid + 1;
        else return mid;
    }

    return nullptr;
}

int * unique(int *start,int *end){
    sort(start,end+1);
    int size = end - start + 1;

    int arr_count = 0;
    int dup_count = 0;
    int *arr = new int[size];
    int *dup_arr = new int [size];
    
    int *ptr = start;
    while (ptr <= end){
        bool exist = false;
        for (int i=0;i<arr_count;i++){
            if (*ptr == arr[i]) {
                exist = true;
                break;
            } 
        }
        if (exist) dup_arr[dup_count++] = *ptr;
        else arr[arr_count++] = *ptr;
        
        ptr++;
    }
    int * dup_start = start + arr_count;
    memcpy(start,arr,arr_count);
    memcpy(dup_start,dup_arr,dup_count);
    return dup_start;
}


int* lower_bound(int *start, int *end,int key){
    
    while (start <= end){
        int *mid = start + (end - start) /2; 
        if (*mid < key){
            start = mid + 1;
        }
        else{
            // 크거나 "같을" 때는 오른쪽을 땡겨옴. 
            end = mid - 1; 
        }
    }
    return start;
}
int* upper_bound(int *start,int *end,int key){
    while (start <= end){
        int* mid = start + (end - start) /2;
        if (key < *mid ) {
            end = mid - 1;
        }
        else {
            /* "같을 때" 왼쪽 땡겨옴 */
            start = mid + 1;
        }
    }
    return end;
}

int main(){
    int N;
    cin >> N;
    int *arr = new int [N];
    vector<int>v;
    for (int i=0;i<N;i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    sort(v.begin(),v.end());

    v.erase(unique(v.begin(),v.end()),v.end());
    
    for (int i=0;i<N;i++){
        arr[i] = lower_bound(v.begin(),v.end(),arr[i]) -v.begin();
        cout << arr[i] << " ";
    }

}