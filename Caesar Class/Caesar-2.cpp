/* Author: Jeff Mutethia(mutethjt)
Assignment: Caesar Cipher
Date: 01/06/20
*/

#include "Caesar.h"
#include <string>
using namespace std;

static const int maxchar = 'z';
static const int minchar = ' ';
static const int charrange = 1 + maxchar - minchar;


// Caesar constructor, accepts a single string argument as the cipher
Caesar::Caesar(string p){
    key = p;
}

// get_key: return the current cipher key
string Caesar::get_key()const{
   return key;
}
//decode: decode the string argument using the key, return decoded string
string Caesar::decode(string message)const{
    string character;
    string result;
    for(int i = 0; i < message.size(); i++){
        int value = message[i] - minchar;
        int newvalue = (value - (key[i%key.size()] - minchar)+ charrange) % charrange;
        char character = newvalue + minchar;
        result += character;
    }
    return result;
}

//encode: encode the string argument using the key, return encoded string
string Caesar::encode(string message)const{
    string character;
    string result;
    for(int i = 0; i < message.size(); i++){
        int value = message[i] - minchar;
        int newvalue = (value + (key[i%key.size()] - minchar)) % charrange;
        char character = newvalue + minchar;
        result += character;
    }
    return result;
}


