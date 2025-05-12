#include <iostream>
using namespace std;

void quick_sort(int arr[], int n){
    if(n < 2) return;
    int i = 0;
    int j = 1;
    while(j<n){
        if(arr[j] < arr[0]){
            swap(arr[j], arr[++i]);
        }
        j++;
    }
    swap(arr[0], arr[i]);

    quick_sort(arr, i);
    quick_sort(arr + i + 1, n - i - 1);
}

void merge_sort(int arr[], int n){
    if(n < 2) return;
    int mid = n/2;
    int* left = new int[mid];
    int* right = new int[n-mid];

    for(int i=0; i<mid; i++) left[i] = arr[i];
    for(int j=mid; j<n; j++) right[j-mid] = arr[j];

    merge_sort(left, mid);
    merge_sort(right, n-mid);

    // int i=0, r=0;
    // for(int l=0; l<mid; l++){
    //     while(r<n-mid){
    //         if(right[r] < left[l]){
    //             arr[i++] = right[r++];
    //         }
    //         else break;
    //     }
    //     arr[i++] = left[l];
    // }
    // while(r<n-mid){
    //     arr[i++] = right[r++];
    // }

    int i = 0, l = 0, r = 0;
    while (l < mid && r < n - mid) {
        if (left[l] <= right[r]) arr[i++] = left[l++];
        else arr[i++] = right[r++];
    }

    while (l < mid) arr[i++] = left[l++];
    while (r < n - mid) arr[i++] = right[r++];

    delete[] left;
    delete[] right;
}

int main(){
    int n = 5;
    int* a = new int[n]{3,4,1,6,2};
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;
    merge_sort(a, n);
    for(int i=0; i<n; i++){
        cout << a[i] << ' ';
    }


    return 0;
}
