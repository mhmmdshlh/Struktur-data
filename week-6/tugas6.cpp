#include <iostream>
using namespace std;

struct queue{
        int front, rear, size;
        char* items;
        queue(int k){
            size = k;
            front = rear = -1;
            items = new char[k];
        }
        ~queue(){
            delete[] items;
        }
        bool isEmpty(){
            return front == -1 && rear == -1;
        }
        bool isFull(){
            return (rear+1)%size == front;
        }
        void enqueue(char val){
            if(isFull()) return;
            if(isEmpty()){
                front = rear = 0;
            }
            else{
                rear = (rear + 1)%size;
            }
            items[rear] = val;
        }
        char dequeue(){
            if(isEmpty()) return '0';
            char item = items[front];
            if(rear == front){
                rear = front = -1;
            }
            else{
                front = (front+1)%size;
            }
            return item;
        }
        void print(){
            if(isEmpty()) return;
            for(int i=front; i!=rear; i=(i+1)%size){
                cout << items[i] << ' ';
            }
            cout << items[rear] << '\n';
        }
        string getItem(){
            if(isEmpty()) return "";
            string item = "";
            for(int i=front; i!=rear; i=(i+1)%size){
                item += items[i];
            }
            item += items[rear];
            return item;
        }
};

string decToBin(int x){
    if (x == 0) return "0";
    string bin = "";
    while (x > 0) {
        char digit = x % 2 == 0 ? '0' : '1';
        bin = digit + bin;
        x /= 2;
    }
    return bin;
}
int pangkat(int n, int a){
    int result=1;
    while(a>0){
        result *= n;
        a--;
    }
    return result;
}
int binToDec(string bin){
    int result = 0;
    for(int i=0; i<bin.size(); i++){
        int dgt = bin[i]=='0'? 0 : 1;
        result += dgt*pangkat(2, bin.size()-1-i);
    }
    return result;
}
void shiftBin(int& x, int shift){
    if (x == 0) return;
    string bin = decToBin(x);
    while(shift < 0) shift+=bin.size();
    shift = shift % bin.size();
    queue q(bin.size());
    for(int i=0; i<bin.size(); i++){
        int idx = ((i-shift + bin.size()) % bin.size());
        q.enqueue(bin[idx]);
    }
    x = binToDec(q.getItem());
}

int main(){
    int x, shift;
    cout << "Masukkan bilangan desimal: ";
    cin >> x;
    cout << "Masukkan jumlah shift: ";
    cin >> shift;
    shiftBin(x, shift);
    cout << "Bilangan desimal setelah shift: " << x << endl;    

    return 0;
}
