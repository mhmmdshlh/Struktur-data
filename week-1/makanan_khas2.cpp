#include <iostream>
using namespace std;

void input_makanan(string makanan_khas[], int n) {
  for (int i = 0; i < n; i++) {
    getline(cin, makanan_khas[i]);
  }
}

void display_makanan(string makanan_khas[], int n) {
  for (int i = 0; i < n; i++) {
    cout << "Makanan khas-" << i + 1 << ": " << makanan_khas[i] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  string makanan_khas[n];
  cin.ignore();
  input_makanan(makanan_khas, n);
  display_makanan(makanan_khas, n);

  return 0;
}