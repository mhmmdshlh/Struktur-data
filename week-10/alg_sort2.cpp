#include <iostream>
using namespace std;

void insertion_sort(int arr[], int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j] < arr[j-1]){
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

void shell_sort(int arr[], int n){
    int gap = n/2;
    while(gap > 0){
        for(int i=gap; i<n; i++){
            for(int j=i; j>=gap; j-=gap){
                if(arr[j-gap] > arr[j]){
                    int tmp = arr[j];
                    arr[j] = arr[j-gap];
                    arr[j-gap] = tmp;
                }
            }
        }
        gap /= 2;
    }
}

int main(){
    int n = 5;
    int* a = new int[n]{3,4,1,6,2};
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    shell_sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}
