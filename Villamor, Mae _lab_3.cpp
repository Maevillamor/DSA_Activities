#include <iostream>
#include <cctype>  // For isdigit()
using namespace std;

char stack[20];
int top = -1;
string stackOutput = "";

void push(char val) {
    stack[++top] = val;
    stackOutput += val;
}

char pop() {
    stackOutput.erase(stackOutput.size() - 1, 1);
    char val = stack[top--];
    return val;
}

char peek() {
    return stack[top];
}

int checkLevel(char operation) {
    if (operation == '(' || operation == ')') {
        return 0;
    } else if (operation == '^') {
        return 3;
    } else if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '+' || operation == '-') {
        return 1;
    }
    return -1;
}

void convertToPostfix(string input) {
    string output = "";

    cout << "| Input | Stack | Output |" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < input.length(); i++) {

        cout << "| " << input[i] << "     | " << stackOutput << "    | " << output << "    |" << endl;
        cout << "------------------------" << endl;

        // If it's a digit, add to output
        if (isdigit(input[i])) {
            output += input[i];
        }
        // If it's an opening parenthesis, push to stack
        else if (input[i] == '(') {
            push(input[i]);
        }
        // If it's a closing parenthesis, pop until opening parenthesis
        else if (input[i] == ')') {
            while (top >= 0 && peek() != '(') {
                output += pop();
            }
            pop(); // Pop '('
        }
        // If it's an operator, handle precedence
        else {
            while (top >= 0 && checkLevel(peek()) >= checkLevel(input[i])) {
                output += pop();
            }
            push(input[i]);
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0) {
        output += pop();
    }

    cout << "Postfix expression: " << output << endl;
}

int main() {
    string input = "(2+3)-5*4/5";
    convertToPostfix(input);

    return 0;
}
