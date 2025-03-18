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
        void enqueue(int val){
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
};

string stringReverse(string s){
    string result = "";
    for(int i=s.size()-1; i>=0; i--){
        result += s[i];
    }
    return result;
}

string decToBin(int x){
    string bin = "";
    while(x>0){
        int digit = x%2;
        bin += (digit + '0');
        x /= 2;
    }
    bin = stringReverse(bin);
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
    bin = stringReverse(bin);
    for(int i=0; i<bin.size(); i++){
        int dgt = bin[i]=='0'? 0 : 1;
        result += dgt*pangkat(2, i);
    }
    return result;
}
void shiftBin(int& x, int shift){
    string bin = decToBin(x);
    string result = "";
    queue q(bin.size());
    for(int i=0; i<bin.size(); i++){
        q.enqueue(bin[i]);
    }
    for(int i=shift;i<q.size; i++){
        char temp = q.dequeue();
        q.enqueue(temp);
    }
    for(int i=0; i<q.size; i++){
        result += q.dequeue();
    }
    
    x = binToDec(result);
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
