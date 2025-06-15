#include <iostream>
using namespace std;

struct dnode {
    int id, umur, gaji;
    string nama, jabatan;

    dnode* next;
    dnode* prev;
    dnode() {
        next = prev = nullptr;
    }
};

struct dllist {
   private:
    dnode* head = nullptr;
    dnode* tail = nullptr;
    int jml = 0;
    bool sorted = false;

   public:
    void add(int id, string nama, int umur, string jabatan, int gaji) {
        dnode* tmp = new dnode;
        tmp->id = id;
        tmp->nama = nama;
        tmp->umur = umur;
        tmp->jabatan = jabatan;
        tmp->gaji = gaji;
        if (!head) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        jml++;
        sorted = false;
    }

    void print() {
        if (!head) {
            cout << "\nData kosong!\n";
            return;
        }
        dnode* cur = head;
        cout << "\nID, Nama, Umur, Jabatan, Gaji\n";
        while (cur) {
            cout << cur->id << ", " << cur->nama << ", " << cur->umur << ", " << cur->jabatan << ", " << cur->gaji << endl;
            cur = cur->next;
        }
        cout << endl;
    }

    void del(int id) {
        dnode* cur = head;
        while (cur) {
            if (cur->id == id) {
                if (cur->prev) cur->prev->next = cur->next;
                if (cur->next) cur->next->prev = cur->prev;
                if (cur == head) head = cur->next;
                if (cur == tail) tail = cur->prev;
                delete cur;
                jml--;
                sorted = false;
                cout << "\nPegawai dengan ID " << id << " berhasil dihapus!\n\n";
                return;
            }
            cur = cur->next;
        }
        cout << "\nData tidak ditemukan!\n\n";
    }

    void update(int id) {
        dnode* cur = head;
        while (cur) {
            if (cur->id == id) {
                cout << "\nID      : " << cur->id << endl;
                cout << "Nama    : " << cur->nama << endl;
                cout << "Umur    : " << cur->umur << endl;
                cout << "Jabatan : " << cur->jabatan << endl;
                cout << "Gaji    : " << cur->gaji << '\n';
                int opt;
                cout << "mau update apa? (1. id, 2. nama, 3. umur, 4. jabatan, 5. gaji): ";
                cin >> opt;
                while (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5) {
                    cout << "tidak ada di pilihan!\n";
                    cout << "mau update apa? (1. id, 2. nama, 3. umur, 4. jabatan, 5. gaji): ";
                    cin >> opt;
                }
                if (opt == 1) {
                    int data;
                    cout << "Masukkan id baru: ";
                    cin >> data;
                    cur->id = data;
                }
                else if (opt == 2) {
                    string data;
                    cout << "Masukkan nama baru: ";
                    cin >> data;
                    cur->nama = data;
                }
                else if (opt == 3) {
                    int data;
                    cout << "Masukkan umur baru: ";
                    cin >> data;
                    cur->umur = data;
                }
                else if (opt == 4) {
                    string data;
                    cout << "Masukkan jabatan baru: ";
                    cin >> data;
                    cur->jabatan = data;
                }
                else if (opt == 5) {
                    int data;
                    cout << "Masukkan gaji baru: ";
                    cin >> data;
                    cur->gaji = data;
                }
                cout << "Data berhasil diperbarui!\n\n";
                return;
            }
            cur = cur->next;
        }
        cout << "\nData tidak ditemukan!\n\n";
    }

    void binary_search(int id) {
        if (!head) {
            cout << "\nData kosong!\n";
            return;
        }
        if (!sorted) sort();
        dnode** arr = new dnode*[jml];
        dnode* cur = head;
        for (int i = 0; i < jml; i++) {
            arr[i] = cur;
            cur = cur->next;
        }
        int l = 0, r = jml - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid]->id == id) {
                cout << "\nID      : " << arr[mid]->id << endl;
                cout << "Nama    : " << arr[mid]->nama << endl;
                cout << "Umur    : " << arr[mid]->umur << endl;
                cout << "Jabatan : " << arr[mid]->jabatan << endl;
                cout << "Gaji    : " << arr[mid]->gaji << "\n\n";
                return;
            }
            else if (id < arr[mid]->id) {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        cout << "\nData tidak ditemukan!\n\n";
    }

    void sort() {
        if (!head || head == tail) return;
        dnode* cur = head;
        dnode** arr = new dnode*[jml];
        for (int i = 0; i < jml; i++) {
            arr[i] = cur;
            cur = cur->next;
        }

        // sort algoritm
        for (int i = 0; i < jml - 1; i++) {
            for (int j = 0; j < jml - i - 1; j++) {
                if (arr[j]->id > arr[j + 1]->id) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }

        for (int i = 0; i < jml; i++) {
            arr[i]->next = i < jml - 1 ? arr[i + 1] : nullptr;
            arr[i]->prev = i > 0 ? arr[i - 1] : nullptr;
        }
        head = arr[0];
        tail = arr[jml - 1];

        delete[] arr;
        sorted = true;
    }

    void stat() {
        if (!head) {
            cout << "\nData kosong!\n";
            return;
        }
        float total_gaji = 0;
        dnode* gaji_tertinggi = head;
        dnode* gaji_terendah = head;
        dnode* cur = head;
        while (cur) {
            total_gaji += cur->gaji;
            if (cur->gaji > gaji_tertinggi->gaji) gaji_tertinggi = cur;
            if (cur->gaji > gaji_terendah->gaji) gaji_terendah = cur;
            cur = cur->next;
        }
        float aver = total_gaji / jml;
        cout << "\nJumlah data: " << jml << " pegawai\n";
        cout << "gaji tertinggi: " << gaji_tertinggi->gaji << endl;
        cout << "gaji terendah: " << gaji_terendah->gaji << endl;
        cout << "rata-rata gaji: " << aver << "\n\n";
    }
};

int main() {
    dllist pegawai;
    pegawai.add(127, "budi", 30, "manager", 100);
    pegawai.add(124, "agus", 44, "security", 80);
    pegawai.add(122, "heri", 49, "CEO", 400);
    pegawai.add(125, "agus", 36, "OB", 50);

    while (true) {
        cout << "1. tambah data" << endl;
        cout << "2. lihat data" << endl;
        cout << "3. update data" << endl;
        cout << "4. hapus data" << endl;
        cout << "5. cari data" << endl;
        cout << "6. sort" << endl;
        cout << "7. lihat statistik" << endl;
        cout << "0. keluar" << endl;
        cout << "pilih menu: ";
        int opt;
        cin >> opt;
        if (opt == 1) {
            char y;
            do {
                int id;
                string nama;
                int umur;
                string jabatan;
                int gaji;
                cin >> id >> nama >> umur >> jabatan >> gaji;
                pegawai.add(id, nama, umur, jabatan, gaji);
                cout << "lagi? (y/n): ";
                cin >> y;
            } while (y == 'Y' || y == 'y');
        }
        else if (opt == 2)
            pegawai.print();
        else if (opt == 3) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            pegawai.update(id);
        }
        else if (opt == 4) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            pegawai.del(id);
        }
        else if (opt == 5) {
            int id;
            cout << "Masukkan ID: ";
            cin >> id;
            pegawai.binary_search(id);
        }
        else if (opt == 6)
            pegawai.sort();
        else if (opt == 7) {
            pegawai.stat();
        }
        else
            break;
    }

    return 0;
}
