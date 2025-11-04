#include<iostream>
#include<stack>
using namespace std;

// Function to reverse a string using stack
void reverse(string str){
    stack<char> s;

    // Push all characters of the string onto the stack
    for(int i = 0; i < str.length(); i++){
        s.push(str[i]);
    }

    // Pop characters from the stack and print them (reversed order)
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main(){
    string str = "bhavya";
    reverse(str);
    return 0;
}