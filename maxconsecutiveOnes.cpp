#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1,1,0,1,1,1,1,1,0,0,0,0,1};
    int current_count = 0;
    int max_count = 0;

    for (auto &i:vec) {
        if (i==1) {
            current_count++;
            max_count = max(current_count,max_count);
        }else
            current_count = 0;
    }
    cout << max_count << endl;
}