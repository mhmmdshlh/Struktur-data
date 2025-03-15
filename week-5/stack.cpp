#include <iostream>
#include <string>
using namespace std;

#define MAX 10
struct Stack {
  char count;
  char* item;
  Stack() {
    count = -1;
    item = new char[MAX - 1];
  }
  ~Stack() { delete[] item; }

  bool empty() { return count == -1; }
  bool full() { return count == MAX - 1; }
  void push(char x) {
    if (full()) {
      cout << "full!\n";
    }
    else {
      count++;
      item[count] = x;
    }
  }
  char pop() {
    if (empty()) {
      exit(EXIT_FAILURE);
    }
    else {
      char tmp = item[count];
      count--;
      return tmp;
    }
  }
  char top() {
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
      for (char i = 0; i <= count; i++) {
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
  getline(cin, s);
  Stack st;
  string result;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
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
  cout << result << '\n';

  return 0;
}
