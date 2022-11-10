

#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;

/*

		Method for splitting a string.

		Returns a vector of strings.

*/
vector<string> split(const string &s, char delimiter) {
  stringstream ss(s);
  string item;
  vector<string> result;
  while (getline(ss, item, delimiter)) {
    result.push_back(item);
  }
  return result;
}

bool checkNum(string n) {
  bool isTrue;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '0' || n[i] == '1' || n[i] == '2' || n[i] == '3' || n[i] == '4' || n[i] == '5' || n[i] == '6' || n[i] == '7' || n[i] == '8' || n[i] == '9') {
      isTrue = true;
    } else {
      return false;
    }
  }
  return true;
}


int setValue(string st) {
  int val;
  if (st == "(") {
    return 1;
  } else if (st == "+" || st == "-") {
    return 2;
  } else if (st == "*" || st == "/") {
    return 3;
  } else if (st == "^") {
    return 4;
  }
  return 0;
}

int pow(int n, int e) {
  if (e == 0) {
    return 1;
  } else if (e == 1) {
    return n;
  } else {
    return n * pow(n, e-1);
  }
}

// write function that assigns opperands to a certain value and implement it into the code when an opperand is seen

int main() {
	/*
		Example Code for reading input into vector.
  */
	string a;
  cout << "Please enter a valid numeric Infix epression: ";
	getline(cin, a);

	vector<string> b = split(a, ' ');

	for(int i = 0; i < b.size(); i++){
		cout << b[i] << endl;
	}



  cout << "output:" << endl;
  stack<string> opperands;
  vector<string> output;
  stack<int> postfix;


  for (int i = 0; i < b.size(); i++) {
		if (checkNum(b[i]) == true) {
      cout << b[i];
      output.push_back(b[i]);
    } else if (opperands.empty() == true) {
      opperands.push(b[i]);
    } else if (b[i] == "+" || b[i] == "-" || b[i] == "^" || b[i] == "*" || b[i] == "/") {
      if (setValue(opperands.top()) < setValue(b[i])) {
        opperands.push(b[i]);
      } else {

        while (opperands.empty() == false) {
          if (setValue(opperands.top()) >= setValue(b[i])) {
            cout << opperands.top();
          	output.push_back(opperands.top());
          	opperands.pop();
          } else {
						break;
					}

        }
        opperands.push(b[i]);
      }
    } else if (b[i] == "(") {
      opperands.push(b[i]);
    } else if (b[i] == ")") {
      while (opperands.top() != "(") {
        cout << opperands.top();
        output.push_back(opperands.top());// ?
        opperands.pop();
      }
      opperands.pop();
    }
  }
  while (opperands.empty() == false) {
    cout << opperands.top();
    output.push_back(opperands.top());
    opperands.pop();
  }
  cout << endl;
  cout << "output vector: " << endl;
  for (int i = 0; i < output.size(); i++) {
    cout << output[i];
  }
  cout << endl;

  int exp;
  for (int i = 0; i < output.size(); i++) {
    if (checkNum(output[i]) == true) {
      postfix.push(stoi(output[i]));
    } else {
      vector<int>lol;
      lol.push_back(postfix.top());
      postfix.pop();
      lol.push_back(postfix.top());
      postfix.pop();
      // for (int i = 0; i < lol.size(); i++){
      if (output[i] == "+") {
        int sum = lol[0] + lol[1];
        postfix.push(sum);
      }
      if (output[i] == "-") {
        int minus = lol[1] - lol[0];
        postfix.push(minus);
      }
      if (output[i] == "*") {
        int multi = lol[0] * lol[1];
        postfix.push(multi);
      }
      if (output[i] == "/") {
        int div = lol[1] / lol[0];
        postfix.push(div);
      }
      if (output[i] == "^") {
        exp = pow(lol[1], lol[0]);
        postfix.push(exp);
        }
      }
    }
  cout << "The value of that expression is: " << postfix.top() << endl;
  }
    
