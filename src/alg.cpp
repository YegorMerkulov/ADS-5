// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"
int getPriori(char operation) {
  switch (operation) {
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
    std::string rez(str, 0, num);
    for (auto it = str.begin() + num; it != str.end();) {
        rez += ' '; rez += *it++;;
    }
    return rez;
}      
std::string infx2pstfx(std::string inf) {
  std::string rezult;
  TStack<char, 100> stack11;
  for (auto& operation : inf) {
        int priori = getPriori(operation);
        if (priori == -1) {
            rezult += operation;
        } else {
            if (stack11.get() < priori || priori == 0 || stack11.isEmpty()) {
                stack11.push(operation);
            } else if (operation == ')') {
                char summa = stack11.get();
                while (getPriori(summa) >= priori) {
                    rezult += summa;
                    stack11.pop();
                    summa = stack11.get();
                }
                stack11.pop();
            } else {
                char summa = stack11.get();
                while (getPriori(summa) >= priori) {
                    rezult += summa;
                    stack11.pop();
                    summa = stack11.get();
                }
                stack11.push(operation);
            }
        }
    }
    while (!stack11.isEmpty()) {
        rezult += stack11.get();
        stack11.pop();
    }
    rezult = spases(rezult);
    return rezult;
}

int vashislenia(const int& x, const int& y, const int& op) {
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

int eval(std::string post) {
    TStack<int, 100> stack12;
    std::string number = "";
    for (int i = 0; i < post.size(); i++) {
        if (getPriori(post[i]) == -1) {
            if (post[i] == ' ') {
                continue;
            } else if (isdigit(post[i + 1])) {
                number += post[i];
                continue;
            } else {
                number += post[i];
                stack12.push(atoi(number.c_str()));
                number = "";
            }
        } else {
            int y = stack12.get();
            stack12.pop();
            int x = stack12.get();
            stack12.pop();
            stack12.push(vashislenia(x, y, post[i]));
        }
    }
    return stack12.get();
}


  
      
      
      
      
