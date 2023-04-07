// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int getP(char o) {
  switch (o) {
    case ('('):
      return 0;
      break;
    case (')'):
      return 1;
      break;
    case ('+'):
      return 2;
      break;
    case ('-'):
      return 2;
      break;
    case ('*'):
      return 3;
      break;
    case ('/'):
      return 3;
      break;
    default:
      return -1;
      break;
  }
}
std::string spases(const std::string& str) {
    if (2 >= str.length()) return str;
    int num = 2 - str.length() % 2;
    std::string rz(str, 0, num);
    for (auto it = str.begin() + num; it != str.end();) {
        rz += ' '; rz += *it++;;
    }
    return rz;
}
std::string infx2pstfx(std::string inf) {
  std::string r;
    TStack<char, 100> stack11;
    for (auto& o : inf) {
        int p = getP(o);
        if (p == -1) {
            r += o;
        } else {
            if (stack11.get() < p|| p == 0 || stack11.isEmpty()) {
                stack11.push(o);
            } else if (o == ')') {
                char sum = stack11.get();
                while (getP(sum) >= p) {
                    r += sum;
                    stack11.pop();
                    sum = stack11.get();
                }
                stack11.pop();
            } else {
                char sum = stack11.get();
                while (getP(sum) >= p) {
                    r += sum;
                    stack11.pop();
                    sum = stack11.get();
                }
                stack11.push(o);
            }
        }
    }
    while (!stack11.isEmpty()) {
        r += stack11.get();
        stack11.pop();
    }
    r = spases(r);
    return r;
}

int sht(const int& x, const int& y, const int& op) {
    switch (op) {
    case'+': return x + y;
    case'-': return x - y;
    case'*': return x * y;
    case'/': return x / y;
    default:
        break;
    }
    return 0;
}
return std::string("");
}

int eval(std::string pref) {
  int eval(std::string post) {
    TStack<int, 100> stack12;
    std::string n = "";
    for (int i = 0; i < post.size(); i++) {
        if (getP(post[i]) == -1) {
            if (post[i] == ' ') {
                continue;
            } else if (isdigit(post[i + 1])) {
                n += post[i];
                continue;
            } else {
                n += post[i];
                stack12.push(atoi(n.c_str()));
                n = "";
            }
        } else {
            int y = stack12.get();
            stack12.pop();
            int x = stack12.get();
            stack12.pop();
            stack12.push(sht(x, y, post[i]));
        }
    }
    return stack12.get();
}
  return 0;
}
