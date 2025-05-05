#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

// Node structure for stack
struct Node {
    char data;
    Node* next;
};

// Stack class using singly linked list
class Stack {
public:
    Node* top;

    Stack() { top = nullptr; }
    
    void push(char x) {
        Node* temp = new Node();
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    char pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        char x = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return x;
    }

    char peek() {
        return (top) ? top->data : -1;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Pop '('
        } else {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    Stack s;
    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string infix;
    int choice;

    do {
        cout << "\nMenu:\n1. Get Infix\n2. Convert Infix\n3. Evaluate Postfix\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                if (infix.empty()) {
                    cout << "No infix expression entered!\n";
                } else {
                    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
                }
                break;
            case 3:
                if (infix.empty()) {
                    cout << "No infix expression entered!\n";
                } else {
                    string postfix = infixToPostfix(infix);
                    cout << "Evaluated Result: " << evaluatePostfix(postfix) << endl;
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}

