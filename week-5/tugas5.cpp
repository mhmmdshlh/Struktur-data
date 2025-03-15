#include <iostream>
using namespace std;

typedef struct mhs
{
    string nama;
    int nim;
    mhs* next;
    mhs* prev;
    mhs(string nama, int nim) :nama(nama), nim(nim) {
        next = nullptr;
        prev = nullptr;
    }
} Mahasiswa;

struct list {
    mhs* head = nullptr;
    mhs* tail = nullptr;

    void add(string nama, int nim) {
        mhs* tmp = new mhs(nama, nim);
        if (head == nullptr) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tail->next;
        }
    }
    void cetakNim() {
        mhs* cur = head;
        while (cur != nullptr) {
            cout << cur->nim << '\n';
            cur = cur->next;
        }
    }
    void b_cetakNama() {
        mhs* cur = tail;
        while (cur != nullptr) {
            cout << cur->nama << '\n';
            cur = cur->prev;
        }
    }
};

struct stack {
    list* items;
    stack() {
        items = new list;
    }
    ~stack() {
        while (!empty()) {
            pop();
        }
        delete items;
    }
    bool empty() {
        return items->head == nullptr;
    }
    void push(string nama, int nim) {
        items->add(nama, nim);
    }
    int pop() {
        if (empty()) {
            return -1;
        }
        mhs* tmp = items->tail;
        int nimVal = tmp->nim;
        if (items->tail == items->head){
            items->tail = items->head = nullptr;
        }
        else {
            items->tail = items->tail->prev;
            items->tail->next = nullptr;
        }
        delete tmp;
        return nimVal;
    }
};

int main() {
    stack* mhs = new stack;
    mhs->push("ya'kub qamaruddin D biazah", 3440);
    mhs->push("khalid kashmiri", 3441);
    mhs->push("khidir karawita", 3442);
    mhs->push("ismail ahmad kanabawi", 3443);
    mhs->push("usman abdul jalil sisha", 3444);
    mhs->push("muhammad sumbul", 3445);
    mhs->pop();
    mhs->items->cetakNim();
    mhs->items->b_cetakNama();

    return 0;
}
