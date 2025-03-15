#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string makanan_khas[n];
  cin.ignore();
  for (int i = 0; i < n; i++) {
    getline(cin, makanan_khas[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << "Makanan khas-" << i + 1 << ": " << makanan_khas[i] << endl;
  }

  return 0;
}