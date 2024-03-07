#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <vector>
#include "tree.h"


using namespace std;

map <pair<char,char>,string> InitializeTable(){
vector<char> rows = {'G', 'M', 'Y', 'Z'}; // γραμμες του συντακτικου πινακα 
vector<char> columns = {'(', ')', 'a', 'b', '*', '+', '-', '$'};// στηλες του συντακτικου πινακα
map <pair<char,char>,string> Bambi;
 for (auto row : rows) { //αρχικοποιηση του πινακα
        for (auto col : columns) {
           Bambi [make_pair(row, col)] = "";}
 }//συμπληρωση παραγωγων
 Bambi[make_pair('G','(')]="G->(M)";
 Bambi[make_pair('M','(')]= "M->YZ";
 Bambi[make_pair('M','a')]= "M->YZ";
 Bambi[make_pair('M','b')]= "M->YZ";
 Bambi[make_pair('Y','(')]=  "Y->G";
 Bambi[make_pair('Y','a')]=  "Y->a";
 Bambi[make_pair('Y','b')]=  "Y->b";
 Bambi[make_pair('Z',')')]=  "Z->3";
 Bambi[make_pair('Z','$')]=  "Z->3";
 Bambi[make_pair('Z','*')]= "Z->*M";
 Bambi[make_pair('Z','+')]= "Z->+M";
 Bambi[make_pair('Z','-')]= "Z->-M";

return Bambi;
}

bool syntaxanalysis(map <pair<char,char>,string> Table, string input){
    stack <TreeNode*> kotes;
    TreeNode* root = new TreeNode('G');
    kotes.push(new TreeNode('$'));
    kotes.push(root);
    for (int i=0; i< input.length(); i++){
        char c = input[i];
        if (kotes.top()->data== c && c == '$'){ //εαν ειναι τερματικό συμβολο και ειναι στην κορυφη της στοίβας και ίσος με το $ τοτε εκτυπώνουμε το δέντρο
           printLevelOrder( root);
            return true;
        } 
        else if (kotes.top()->data == c ){//εαν ειναι τερματικο τοτε το συμβολο στην κορυφη της στοιβας βγαινει απο αυτην 
            kotes.pop();
        }
        else if (Table[make_pair(kotes.top()->data,c)]!= ""){//εαν ειναι μη τερματικο ελεγχουμε τον πινακα 
            i--;
            string AfterArrow = Table[make_pair(kotes.top()->data,c)].substr(Table[make_pair(kotes.top()->data,c)].find("->")+ 2);//βρισκουμε το δεξι μελος της παραγωγης
            for (char b: AfterArrow){
               kotes.top()->children.push_back(new TreeNode(b));//τοποθετουμε τους χαρακτηρες ως παιδια του κομβου
            }
            TreeNode* last = kotes.top();
             kotes.pop(); // βγαζουμε τον κομβο απο την κορυφη της στοιβας 
            if (  AfterArrow != "3" ){//προσθετουμε το δεξι μέλος αν ειναι διαφορο του ε με αναποδη σειρα 
                for (auto it = last->children.rbegin(); it != last->children.rend(); ++it) {
                    kotes.push(*it);
                }
            }
        }
        else {
          return false;
        }
    }
    return false;
}



int main() {
     string s;
    
     string str = "((a-b)*(a+b))$";
     map <pair<char,char>,string> Table = InitializeTable();
     if (syntaxanalysis(Table , str)== 1){
          cout<<"succesfully recognised\n";
     }
     else{
        cout<<"please give correct input\n";
     }
    while (true){
       
        cout<<"Give a string to test or press enter to close: ";
        getline(cin, s);
      
  

        if(s.empty()) {
            
                break;
                }
           
            
        else{
            if (syntaxanalysis(Table , s+"$")== 1){
            cout<<"succesfully recognised\n";
            }
            else{
            cout<<"please give correct input";
            }
        }
    }
     
    return 0;
}