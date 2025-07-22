#include <iostream>
#include <algorithm>
using namespace std;

int sqr[4];

void Conv(int arr[1024][1024],int size){
    if (size == 2) return;

    size /= 2;

    int x,y;
    for (int x_off=0;x_off<size; x_off++){
        x = x_off * 2;

        for (int y_off=0;y_off<size;y_off++){
            y = y_off * 2;
           
            int r,c;
            
            for (int i=0;i<2;i++){
                r = x + i;
                for (int j=0;j<2;j++){
                    c = y + j;
                    sqr[i*2+j] = arr[r][c];
                }
            }
            sort(sqr,sqr+4);
            arr[x_off][y_off] = sqr[2];
        }
    }
    Conv(arr,size);
}

int main(){
    int N;
    cin >> N;

    int arr[1024][1024];


    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }
    Conv(arr,N);

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            sqr[i*2+j] = arr[i][j];
        }
    }
    sort(sqr,sqr+4);

    cout << sqr[2];

}