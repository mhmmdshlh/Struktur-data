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

    void swap_node(mhs* node1, mhs* node2){
        if(!node1 || !node2 || node1 == node2) return;
        
        if(node1->next == node2){
            if(node1->prev) node1->prev->next = node2;
            if(node2->next) node2->next->prev = node1;

            node1->next = node2->next;
            node2->prev = node1->prev;
            node1->prev = node2;
            node2->next = node1;
        }
        else if(node2->next == node1){
            if(node2->prev) node2->prev->next = node1;
            if(node1->next) node1->next->prev = node2;
    
            node2->next = node1->next;
            node1->prev = node2->prev;
            node2->prev = node1;
            node1->next = node2;
        }
        else{
            mhs* next1 = node1->next;
            mhs* prev1 = node1->prev;
            mhs* next2 = node2->next;
            mhs* prev2 = node2->prev;

            if(prev1) prev1->next = node2;
            if(next1) next1->prev = node2;
            if(prev2) prev2->next = node1;
            if(next2) next2->prev = node1;

            node1->prev = prev2;
            node1->next = next2;
            node2->next = next1;
            node2->prev = prev1;
        }
        if(head == node1) head = node2;
        else if(head == node2) head = node1;
        if(tail == node2) tail = node1;
        else if(tail == node1) tail = node2;
    }

    void bubble_sort(){
        if(!head || head == tail) return;
        mhs* back = tail;
        while(back != head){
            bool sorted = true;
            mhs* cur = head;
            while(cur != back){
                if(cur->nim > cur->next->nim){
                    if(cur->next == back) back = cur;
                    swap_node(cur, cur->next);
                    sorted = false;
                }
                else{
                    cur = cur->next;
                } 
            }
            back = back->prev;
            if(sorted) break;
        }
    }

    void selection_sort(){
        if (!head || head == tail) return;
        mhs* curr = head;
        while(curr->next){
            mhs* min_node = curr;
            mhs* tmp = curr->next;
            while(tmp){
                if(tmp->nim < min_node->nim){
                    min_node = tmp;
                }
                tmp = tmp->next;
            }
            if(min_node != curr){
                swap_node(curr, min_node);
                curr = min_node->next;
            }
            else curr = curr->next;
        }
    }

    void insertion_sort(){
        if(!head || head == tail) return;
        mhs* cur = head->next;
        while(cur){
            mhs* p1 = cur;
            mhs* nextcur = cur->next;
            mhs* p2 = p1->prev;
            while(p2){
                if(p1->nim < p2->nim){
                    swap_node(p1, p2);
                    p2 = p1->prev;
                }
                else break;
            }
            cur = nextcur;
        }
    }

    // void shell_sort(){
    //     if(!head || head == tail) return;
    //     int gap = jumlah/2;
    //     while(gap > 0){
    //         mhs* cur = head;
    //         for(int i=0; i<gap; i++){
    //             cur = cur->next;
    //         }
    //         while(cur){
    //             mhs* curleft = cur;
    //             mhs* curright = cur;
    //             for(int i=0; i<gap; i++){
    //                 curleft = curleft->prev;
    //             }
    //             while(curleft){
    //                 if(curleft->nim > curright->nim){
    //                     swap_node(curleft, curright);
    
    //                     cur = curleft;
    
    //                     curleft = curright;
    
    //                     for(int i=0; i<gap && curleft; i++){
    //                         curleft = curleft->prev;
    //                     }
    //                 }
    //                 else break;
    //             }
    //             cur = cur->next;
    //         }
    //         gap /= 2;
    //     }
    // }

    void shell_sort(){
        if(!head || head == tail) return;
        mhs** arr = new mhs*[jumlah];
        mhs* cur = head;
        for(int i=0; i<jumlah; i++){
            arr[i] = cur;
            cur = cur->next;
        }
        
        for(int gap=jumlah/2; gap > 0; gap/=2){
            for(int i=gap; i<jumlah; i++){
                for(int j=i; j>=gap && arr[j]->nim < arr[j-gap]->nim; j-=gap){
                    mhs* tmp = arr[j];
                    arr[j] = arr[j-gap];
                    arr[j-gap] = tmp;
                }
            }
        }

        for(int i=0; i<jumlah; i++){
            arr[i]->next = i<jumlah-1? arr[i+1] : nullptr;
            arr[i]->prev = i>0? arr[i-1] : nullptr;
        }

        head = arr[0];
        tail = arr[jumlah-1];

        delete[] arr;
    }

};

int main(){
    cout << "Program Pendataan Mahasiswa\n\n";
    dllist mahasiswa;
    mahasiswa.tambahData(205, "agus", 'L', 86);
    mahasiswa.tambahData(204, "agung", 'L', 85);
    mahasiswa.tambahData(202, "asep", 'L', 80);
    mahasiswa.tambahData(203, "wati", 'P', 89);
    mahasiswa.tambahData(104, "yati", 'P', 90);
    while(true){
        cout << "1. Tambah data" << endl;
        cout << "2. Lihat data" << endl;
        cout << "3. Lihat statistik mahasiswa" << endl;
        cout << "4. Cari mahasiswa" << endl;
        cout << "5. Bubble sort" << endl;
        cout << "6. Selection sort" << endl;
        cout << "7. Insertion sort" << endl;
        cout << "8. Shell sort" << endl;
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
        else if(opt == 7){
            mahasiswa.insertion_sort();
        }
        else if(opt == 8){
            mahasiswa.shell_sort();
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
