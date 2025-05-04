#include <iostream>
#include <string>
using namespace std;

#define MAX 10
template <typename T>
struct Stack {
  int count;
  T* item;
  Stack() {
    count = -1;
    item = new T[MAX - 1];
  }
  ~Stack() { delete[] item; }

  bool empty() { return count == -1; }
  bool full() { return count == MAX - 1; }
  void push(T x) {
    if (full()) {
      cout << "full!\n";
    }
    else {
      count++;
      item[count] = x;
    }
  }
  T pop() {
    if (empty()) {
      exit(EXIT_FAILURE);
    }
    else {
      T tmp = item[count];
      count--;
      return tmp;
    }
  }
  T top() {
    if (empty()) {
      exit(EXIT_FAILURE);
    }
    else
      return item[count];
  }
  void print() {
    if (empty()) {
      cout << "empty!\n";
    }
    else {
      for (T i = 0; i <= count; i++) {
        cout << item[i] << ' ';
      }
      cout << '\n';
    }
  }
};

int priority(char x) {
  if (x == '^')
    return 3;
  else if (x == '*' || x == '/')
    return 2;
  else if (x == '+' || x == '-')
    return 1;
  return 0;
}

int main() {
  string s;
  cout << "infix: "; 
  getline(cin, s);
  Stack<char> st;
  string result;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') continue;
    if (isalnum(s[i]))
      result += s[i];
    else if (s[i] == '(')
      st.push(s[i]);
    else if (s[i] == ')') {
      while (st.top() != '(') {
        result += st.pop();
      }
      st.pop();
    }
    else {
      while (!st.empty() && priority(s[i]) <= priority(st.top())) {
        result += st.pop();
      }
      st.push(s[i]);
    }
  }
  while (!st.empty()) {
    result += st.pop();
  }
  cout << "postfix: " << result << '\n';
  
  return 0;
}
