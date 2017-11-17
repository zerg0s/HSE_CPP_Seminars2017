#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

void printStack(const vector<int>& st) {
    for(const auto& num : st) {
        cout << num;
    }
    cout << endl;
}

void permutations(int allNumbers, vector<int>& exclusions) {
    int count = allNumbers;
    if(exclusions.size() == allNumbers) {
        printStack(exclusions);
    }
    for(int i = 1; i <= count; ++i) {
        if(find(exclusions.begin(), exclusions.end(), i) == exclusions.end()) {
            exclusions.push_back(i);
            permutations(count, exclusions);
            exclusions.pop_back();
        }
    }
}

int main3() {
    int size = 0;
    cin >> size;
    vector<int> numbers = vector<int>();
    for(int i = 1; i <= size; ++i) {
        numbers.push_back(i);
        permutations(size, numbers);
        numbers.clear();  
    }    
    return 0;
}
