#include <iostream>
#include <stack>
#include <string>

using namespace std;

void recognizeExpression(const string& expression) {
    stack<char> charStack;
    string move;

    for (char ch : expression) { //checks if character is x or y
        if (ch == 'x') {
            charStack.push('x'); //places x on stack
            move+= "Push 'x'\n";
           // cout << move;
        } else if (ch == 'y') {
            if (!charStack.empty()) { //checks if stack is empty or not 
                charStack.pop(); //delete object from the stack 
                move+= "Delete 'x'\n";
              //  cout << move;
            } else {
                move+= "Not acceptable: more 'y' than 'x'\n"; //number of x < number of y
                cout << move;
                return;
            }
        }
    } //ch goes to the next letter 

    if (charStack.empty()) { //checks if the stack is empty or not 
        move+= "The expression is acceptable\n"; //number of x = number of y
    } else {
        move+= "The expression is not acceptable: more 'x' than 'y' Invalid expression : there are more 'x' than 'y'\n"; //number of x > number of y
    }

    cout << move;
}

int main() {
    string expression;
    string s;//program waits for input before closing
    cout << "Please insert a row of the following characters: 'x' and 'y' ";
    getline(cin,expression);

    recognizeExpression(expression); //takes the combination that the user inputed and calls recognizeExpression
    getline(cin,s);//takes anything and closes
    return 0;
}
