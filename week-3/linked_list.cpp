#include <iostream>
#include <vector>
using namespace std;

struct node {
  int value;
  node *next = nullptr;
};
struct linked_list {
private:
  node *head = nullptr;
  node *tail = nullptr;

public:
  void add(int x) {
    node *tmp = new node;
    tmp->value = x;
    if (head == nullptr) {
      head = tmp;
      tail = tmp;
    } else {
      (*tail).next = tmp;
      tail = tail->next;
    }
  }
  void print() {
    node *curr = head;
    while (curr != nullptr) {
      cout << curr->value << ' ';
      curr = curr->next;
    }
    cout << endl;
  }
  void clear() {
    while (head != nullptr) {
      node *temp = head;
      head = head->next;
      delete temp;
    }
    tail = nullptr;
  }
  void del_first() {
    if (head == nullptr)
      return;
    node *curr = head;
    head = head->next;
    delete curr;
    if (tail == head)
      tail = nullptr;
  }
  void del_last() {
    if (head == nullptr)
      return;
    if (head == tail) {
      delete tail;
      head = nullptr;
      tail = nullptr;
      return;
    }
    node *curr = head;
    while (curr->next != tail) {
      curr = curr->next;
    }
    delete tail;
    curr->next = nullptr;
    tail = curr;
  }
  void del(int idx) {
    if (head == nullptr)
      return;
    if (idx < 0) {
      cout << "Index tidak boleh negatif!\n";
      return;
    }
    if (idx == 0) {
      del_first();
      return;
    }
    node *curr = head;
    int i = 1;
    while (i != idx && curr->next != nullptr) {
      curr = curr->next;
      i++;
    }
    if (curr->next == nullptr) {
      cout << "Index out of range!\n";
      return;
    }
    if (curr->next == tail) {
      delete tail;
      tail = curr;
      tail->next = nullptr;
      return;
    }
    node *next = curr->next;
    curr->next = next->next;
    delete next;
    next = nullptr;
  }
  void insert(int idx, int x) {
    if (idx < 0) {
      cout << "Index tidak boleh negatif!\n";
      return;
    }
    if (head == nullptr || idx == 0) {
      node *tmp = new node;
      tmp->value = x;
      tmp->next = head;
      head = tmp;
      if (tail == nullptr)
        tail = head;
      return;
    }
    node *curr = head;
    int i = 1;
    while (curr->next != nullptr && i != idx) {
      curr = curr->next;
      i++;
    }
    if (curr->next == nullptr) {
      add(x);
      return;
    }
    node *tmp = new node;
    tmp->value = x;
    tmp->next = curr->next;
    curr->next = tmp;
  }

// tail not updated yet

  void reverse() {
    if(!head->next) return;
    node* nxt = head->next;
    head->next = nullptr;
    while(nxt){
        node* tmp = nxt->next;
        nxt->next = head;
        head = nxt;
        nxt = tmp;
    }
  }

  int getNode(int positionFromTail) {
    node* nxt = head->next;
    node* cur = head;
    cur->next = nullptr;
    while(nxt){
        node* tmp = nxt->next;
        nxt->next = cur;
        cur = nxt;
        nxt = tmp;
    }
    int i = 0;
    while(cur){
        if(i == positionFromTail){
            return cur->value;
        }
        cur = cur->next;
        i++;
    }
    return 0;
  }

  void removeDuplicates() {
    node* cur = head;
    while(cur && cur->next){
        if(cur->value == cur->next->value){
            node* next = cur->next->next;
            delete cur->next;
            cur->next = next;
        } else{
            cur = cur->next;
        }
    }
  }

  bool has_cycle() {
    node* cur = head;
    vector<node*> traversed = {};
    while(cur){
        for(int i=0; i<traversed.size(); i++){
            if(cur->next == traversed[i]) return 1;
        }
        traversed.push_back(cur->next);
        cur = cur->next;
    }
    return 0;   
  }

};

int main() {
  linked_list list;
  list.insert(3, 2);
  list.add(19);
  list.add(9);
  list.add(1);
  list.add(10);
  list.add(30);
  list.print();
  list.del_first();
  list.print();
  list.del_last();
  list.print();
  list.insert(2, 8);
  list.print();
  list.del(1);
  list.print();
  cout << list.getNode(2);
 
  return 0;
}
