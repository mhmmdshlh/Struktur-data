#include <iostream>
using namespace std;

#define MAX 5
struct queue{
    private:
        int front, rear;
        int* items;
        ~queue(){
            delete[] items;
        }
    public:
        queue(){
            front = rear = -1;
            items = new int[MAX];
        }
        bool isEmpty(){
            return front == -1 && rear == -1;
        }
        bool isFull(){
            return rear == MAX-1;
        }
        void enqueue(int val){
            if(isFull()) return;
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                rear += 1;
            }
            items[rear] = val;
        }
        int dequeue(){
            if(isEmpty()) return -1;
            if(rear == front){
                rear = front = -1;
            }
            else{
                front += 1;
            }
            return items[front];
        }
        void print(){
            if(isEmpty()) return;
            for(int i=front; i<=rear; i++){
                cout << items[i] << ' ';
            }
            cout << '\n';
        }
};

int main(){
    queue* x = new queue;
    x->enqueue(1);
    x->enqueue(2);
    x->enqueue(3);
    x->print();
    cout << x->dequeue() << endl;
    x->dequeue();
    x->print();
    
    return 0;
}
