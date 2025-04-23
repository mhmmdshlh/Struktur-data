#include <iostream>
using namespace std;

struct dnode {
  int val;
  dnode *prev = nullptr;
  dnode *next = nullptr;
};

struct d_linked_list {
private:
  dnode *head = nullptr;
  dnode *tail = nullptr;

public:
  void add(int x) {
    dnode *tmp = new dnode;
    tmp->val = x;
    if (head == nullptr) {
      head = tail = tmp;
    } else {
      tail->next = tmp;
      tmp->prev = tail;
      tail = tmp;
    }
  }
  void print() {
    dnode *cur = head;
    while (cur != nullptr) {
      cout << cur->val << ' ';
      cur = cur->next;
    }
    cout << '\n';
  }
  void backward_print() {
    dnode *cur = tail;
    while (cur != nullptr) {
      cout << cur->val << ' ';
      cur = cur->prev;
    }
    cout << '\n';
  }
  void addFront(int x) {
    dnode *tmp = new dnode;
    tmp->val = x;
    if (head == nullptr) {
      head = tail = tmp;
    } else {
      tmp->next = head;
      head->prev = tmp;
      head = tmp;
    }
  }
  void delFirst() {
    if (head == nullptr) {
      return;
    }
    dnode *cur = head;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      head = head->next;
      head->prev = nullptr;
    }
    delete cur;
  }
  void delLast() {
    if (tail == nullptr) {
      return;
    }
    dnode *cur = tail;
    if (head == tail) {
      head = tail = nullptr;
    } else {
      tail = tail->prev;
      tail->next = nullptr;
    }
    delete cur;
  }
  void del(int x) {
    if (head == nullptr)
      return;
    if (x == head->val) {
      delFirst();
    } else if (x == tail->val) {
      delLast();
    } else {
      dnode *cur = head->next;
      while (cur != nullptr) {
        if (cur->val == x) {
          dnode *prev = cur->prev;
          dnode *next = cur->next;
          prev->next = next;
          next->prev = prev;
          cur->next = cur->prev = nullptr;
          delete cur;
          return;
        }
        cur = cur->next;
      }
    }
  }
  void insert(int idx, int x) {
    dnode *tmp = new dnode;
    tmp->val = x;
    dnode *cur = head;
    int i = 0;
    while (i != idx && cur != nullptr) {
      cur = cur->next;
      i++;
    }
    if (i != idx && cur == nullptr) {
      cout << "index out of range!\n";
      return;
    }
    if (idx == 0 || head == nullptr) {
      addFront(x);
      return;
    }
    if (i == idx && cur == nullptr) {
      add(x);
      return;
    }
    dnode *prev = cur->prev;
    tmp->prev = prev;
    tmp->next = cur;
    cur->prev = tmp;
    prev->next = tmp;
  }
  void reverse() {
    dnode* cur = head;
    while(cur){
        dnode* tmp = cur->next;
        cur->next = cur->prev;
        cur->prev = tmp;
        if(!tmp) head = cur;
        cur = tmp;
    }
  }
};

int main() {
  d_linked_list list;
  list.add(10);
  list.add(12);
  list.addFront(14);
  list.addFront(1);
  list.addFront(4);
  list.print();
  list.delFirst();
  list.print();
  list.del(12);
  list.print();
  list.insert(1, 9);
  list.print();
  list.reverse();
  list.print();
  return 0;
}
