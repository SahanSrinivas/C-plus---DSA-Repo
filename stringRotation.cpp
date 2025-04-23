#include <iostream>
using namespace std;

int main(){
    std::string s = "abcde";
    std::string d = "eabcd";

    int count = 0;
    for(int i=0; i<s.length(); i++){
        const char first = s[0];  // Store the first character
        s.erase(0, 1);      // Remove the first character
        s.push_back(first); // Add the first character to the end
        count++;
        if(s==d){
            cout << "Matched" << endl;
            cout << count << endl;
            return 0;
        }
    }
    cout << "Not matched";
}