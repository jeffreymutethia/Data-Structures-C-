//In this file, use the Ceasar class from the library you just created to 
// interact with the user.  You may reuse code you wrote for the 
// previous assignment here if you think it would be useful, but the 
// current application MUST use the new object-oriented library interface 
// to do encoding and decoding.

#include "Caesar.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    string message, key, answer;
    cout << "(e)crypt, (d)crypt: " << endl;
    getline(cin,answer);
    
    cout << "Enter Message:" << endl;
    getline(cin,message);
    
    cout << "Enter Key:" << endl;
    getline(cin,key);
    
    Caesar key2(key);
    
    if(answer == "e") cout << key2.encode(message) << endl;
    else cout << key2.decode(message) << endl;
}


