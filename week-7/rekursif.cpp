#include <iostream>
using namespace std;

int faktorial(int n){
    if (n == 1 || n == 0) return 1;
    return n * faktorial(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << faktorial(n);

    return 0;
}
