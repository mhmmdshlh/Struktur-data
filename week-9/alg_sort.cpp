#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n){
    int m = n;
    while(n > 1){
        bool issorted = true;
        for(int i=0; i<n-1; i++){
            if(arr[i] > arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                issorted = false;
            }
        }
        if(issorted) break;
        for(int i=0; i<m; i++){
            cout << arr[i] << ' ';
        }
        cout << endl;
        n-=1;
    }
}

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int k=i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }

        if(arr[k] < arr[i]){
            int tmp = arr[k];
            arr[k] = arr[i];
            arr[i] = tmp;
        }
    }
}

int main(){
    int n = 5;
    int* a = new int[n]{3,4,1,6,2};
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    selection_sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    
    return 0;
}
