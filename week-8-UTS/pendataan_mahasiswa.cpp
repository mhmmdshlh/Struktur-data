#include <iostream>
#include <string>
using namespace std;

string nilai_ke_huruf(int nilai);

struct mhs{
    int nim;
    string nama;
    char jeniskel;
    int nilai;
    string nilaihuruf;
    mhs* next;
    mhs* prev;
    mhs(string nama, int nim, char jk, int n, string nh) :nama(nama), nim(nim), jeniskel(jk), nilai(n), nilaihuruf(nh) {
        next = nullptr;
        prev = nullptr;
    }
};

struct dllist{
    mhs* head = nullptr;
    mhs* tail = nullptr;
    int jumlah = 0;
    mhs* nilai_tertinggi = nullptr;
    mhs* nilai_terendah = nullptr;

    bool empty(){
        return head == nullptr;
    }

    void tambahData(int nim, string nama, char jk, int nilai){
        string nilaihuruf = nilai_ke_huruf(nilai);
        mhs* tmp = new mhs(nama, nim, jk, nilai, nilaihuruf);
        if (head == nullptr) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tail->next;
        }
        if(!nilai_terendah) nilai_terendah = tmp;
        else{
            nilai_terendah = tmp->nilai < nilai_terendah->nilai? tmp : nilai_terendah;
        }
        if(!nilai_tertinggi) nilai_tertinggi = tmp;
        else{
            nilai_tertinggi = tmp->nilai > nilai_tertinggi->nilai? tmp : nilai_tertinggi;
        }
        jumlah++;
    }

    void lihatData(){
        if(!head){
            cout << "Data kosong!\n";
            return;
        }
        mhs* cur = head;
        cout << "NIM, Nama, Jenis Kelamin, Nilai, Nilai huruf\n";
        while(cur){
            cout << cur->nim << ", " << cur->nama << ", " << cur->jeniskel << ", " << cur->nilai << ", " << cur->nilaihuruf << endl;
            cur = cur->next;
        }
        cout << endl;
    }

    float averageNilai(){
        mhs* cur = head;
        int sum = 0;
        while(cur){
            sum += cur->nilai;
            cur = cur->next;
        }
        return sum/jumlah;
    }

    void lihatStatistik(){
        if(!head){
            cout << "Data kosong!\n";
            return;
        }
        cout << "Jumlah data: " << jumlah << " mahasiswa.\n";
        cout << "Rata-rata nilai mahasiswa: " << averageNilai() << endl;
        cout << "Nilai tertinggi: " << nilai_tertinggi->nilai << " (" << nilai_tertinggi->nama << ')' << endl;
        cout << "Nilai terendah: " << nilai_terendah->nilai << " (" << nilai_terendah->nama << ')' << endl;
    }

    void cariMahasiswa(int nim){
        if(!head){
            cout << "Data kosong!\n";
            return;
        }
        mhs* cur = head;
        while(cur && cur->nim != nim){
            cur = cur->next;
        }
        if(!cur){
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!\n";
            return;
        }
        cout << "NIM: " << cur->nim << endl;
        cout << "Nama: " << cur->nama << endl;
        cout << "Jenis kelamin: " << cur->jeniskel << endl;
        cout << "Nilai: " << cur->nilai << endl;
        cout << "Nilai huruf: " << cur->nilaihuruf << endl;
    }

    void bubble_sort(){
        if(!head && !head->next) return;
        mhs* back = tail;
        while(back != head){
            bool sorted = true;
            mhs* cur = head;
            while(cur != back){
                if(cur->nim > cur->next->nim){
                    mhs* tmp = cur->prev;
                    mhs* nxt = cur->next;
                    cur->prev = nxt;
                    cur->next = nxt->next;
                    nxt->next = cur;
                    nxt->prev = tmp;
                    if(tmp) tmp->next = nxt;
                    if(cur == head) head = nxt;
                    if(nxt == back) back = cur;
                    if(nxt == tail) tail = cur;
                    sorted = false;
                }
                else cur = cur->next;
            }
            if(sorted) break;
            back = back->prev;
        }
    }

    void selection_sort(){
        if (!head && !head->next) return;
        mhs* node = head;
        while(node->next){
            mhs* tmp = node;
            mhs* cur = node->next;
            while(cur){
                if(cur->nim < tmp->nim){
                    tmp = cur;
                }
                cur = cur->next;
            }
            if(tmp != node){
                mhs* prvtmp = tmp->prev;
                mhs* nxttmp = tmp->next;
                mhs* prvnode = node->prev;
                mhs* nxtnode = node->next;
                
                if(node == head) head = tmp;
                if(tmp == tail) tail = node;
                
                if(prvtmp == node){
                    if(nxttmp) nxttmp->prev = node;
                    if(prvnode) prvnode->next = tmp;
                    tmp->next = node;
                    tmp->prev = node->prev;
                    node->next = nxttmp;
                    node->prev = tmp;
                }
                else{
                    if(prvtmp) prvtmp->next = node;
                    if(nxttmp) nxttmp->prev = node;
                    if(prvnode) prvnode->next = tmp;
                    if(nxtnode) nxtnode->prev = tmp;
                    tmp->next = node->next;
                    tmp->prev = node->prev;
                    node->next = nxttmp;
                    node->prev = prvtmp;
                }
                node = tmp->next;
            }
            else node = node->next;
        }
    }
};

int main(){
    cout << "Program Pendataan Mahasiswa\n\n";
    dllist mahasiswa;
    mahasiswa.tambahData(205, "agus", 'L', 86);
    mahasiswa.tambahData(203, "agung", 'L', 85);
    mahasiswa.tambahData(202, "asep", 'L', 80);
    mahasiswa.tambahData(204, "wati", 'P', 89);
    while(true){
        cout << "1. Tambah data" << endl;
        cout << "2. Lihat data" << endl;
        cout << "3. Lihat statistik mahasiswa" << endl;
        cout << "4. Cari mahasiswa" << endl;
        cout << "5. Bubble sort" << endl;
        cout << "6. Selection sort" << endl;
        cout << "0. Keluar" << endl;
        int opt;
        cout << "pilih menu: ";
        cin >> opt;
        if(opt == 1){
            while(true){
                int nim;
                string nama;
                char jk;
                int nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan nama: ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan jenis kelamin (L/P): ";
                cin >> jk;
                cout << "Masukkan nilai: ";
                cin >> nilai;
                mahasiswa.tambahData(nim, nama, jk, nilai);
                char lagi;
                cout << "Apakah ingin menambah data lagi? (y/n): ";
                cin >> lagi;
                if(lagi != 'y') break;
            }
        }
        else if(opt == 2){
            cout << endl;
            mahasiswa.lihatData();
        }
        else if(opt == 3){
            cout << endl;
            mahasiswa.lihatStatistik();
            cout << endl;
        }
        else if(opt == 4){
            if(mahasiswa.empty()){
                cout << "Data kosong!\n";
                continue;
            } 
            int nim;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << endl;
            mahasiswa.cariMahasiswa(nim);
            cout << endl;
        }
        else if(opt == 5){
            mahasiswa.bubble_sort();
        }
        else if(opt == 6){
            mahasiswa.selection_sort();
        }
        else break;
    }

    return 0;
}


string nilai_ke_huruf(int nilai){
    if(nilai >= 86) return "A";
    else if(nilai < 86 && nilai >= 81) return "AB";
    else if(nilai < 81 && nilai >= 71) return "B";
    else if(nilai < 71 && nilai >= 66) return "BC";
    else if(nilai < 66 && nilai >= 61) return "C";
    else if(nilai < 61 && nilai >= 56) return "CD";
    else if(nilai < 56 && nilai >= 51) return "D";
    else return "E";
}
