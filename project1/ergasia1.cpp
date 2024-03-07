#include <iostream>
#include <stack>
#include <string>

using namespace std;

void recognizeExpression(const string& expression) {
    stack<char> charStack;
    string move;

    for (char ch : expression) { //ελέγχει αν ο χαρακτήρας είναι x ή y
        if (ch == 'x') {
            charStack.push('x'); //τοποθέτει x στην στοίβα
            move+= "push 'x'\n";
           // cout << move;
        } else if (ch == 'y') {
            if (!charStack.empty()) { //ελέγχει αν η στοίβα δεν είναι άδια ή όχι
                charStack.pop(); //διαγράφει στοίχειο άπο τη στοίβα
                move+= "delete'x'\n";
               // cout << move;
            } else {
                move+= "invalid: there are more 'y' than 'x'\n"; //αριθμόςx < αριθμόςy
                cout << move;
                return;
            }
        }
    } //το ch πάει στο επόμενο γράμμα

    if (charStack.empty()) { //ελέγχει αν η στοίβα είναι άδια ή όχι
        move+= "valid argument\n"; //αριθμόςx = αριθμόςy
    } else {
        move+= "invalid: more'x' than 'y'\n"; //αριθμόςx > αριθμόςy
    }

    cout << move;
}

int main() {
    string expression;
    string s;//το προγραμμα θα περιμενει για input πριν τερματισει
    cout << "give us a string of 'x' and'y': ";
    //cin >> expression;
    getline(cin,expression);
    recognizeExpression(expression); //παίρνει τον συνδιασμό που έβαλε ο χρήστης και καλεί την recognizeExpression
    getline(cin,s);
    return 0;
}
