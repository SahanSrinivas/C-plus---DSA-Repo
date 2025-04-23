// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
using namespace std;

class isomorphicStrings {
public:
    bool isoString() {
        const string s = "liiiiiiii";
        const string t = "siiiiiiii";

        if (s.length() != t.length()) return false;

        unordered_map<char, char> s_t;
        unordered_map<char, char> t_s;

        for(int i = 0; i < s.length(); i++) {
            // Check if s[i] already has a mapping
            if(s_t.find(s[i]) != s_t.end()) {
                if(s_t[s[i]] != t[i]) return false;
            }
            // Check if t[i] already has a mapping
            else if(t_s.find(t[i]) != t_s.end()) {
                if(t_s[t[i]] != s[i]) return false;
            }
            // If neither has a mapping, create new mappings
            else {
                s_t[s[i]] = t[i];
                t_s[t[i]] = s[i];
            }
        }
        return true;
    }
};


int main(){
    isomorphicStrings iS;
    if(!iS.isoString()){
        cout << "Strings are not Isomorphic";
    }else{
        cout << "Strings are isomorphic";
    }
}