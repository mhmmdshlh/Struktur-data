#include <iostream>
using namespace std;

struct Mahasiswa {
  string nama;
  int nim;
};

int main() {
  int n;
  cout << "ada berapa mahasiswa: ";
  cin >> n;
  Mahasiswa *mhs1 = new Mahasiswa[n];
  for (int i = 0; i < n; i++) {
    cin.ignore();
    cout << "Nama mahasiswa-" << i + 1 << ": ";
    getline(cin, mhs1[i].nama);
    cout << "NIM mahasiswa-" << i + 1 << ": ";
    cin >> mhs1[i].nim;
  }
  for (int i = 0; i < n; i++) {
    cout << mhs1[i].nama << ' ' << mhs1[i].nim << endl;
  }

  return 0;
}