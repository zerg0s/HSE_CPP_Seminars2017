#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int checkString(const string& strForCheck) {
    int retValue = 1;
    vector<char> stack;
    for(const char& ch : strForCheck) {
        if(ch == '(') {
            stack.push_back('(');
        }
        if(ch == ')') {
            if(stack.size() != 0) {
                stack.pop_back();
            }
            else {
                retValue = 0;
				break;
            }
        }
    }
    if(stack.size() != 0) {
        retValue = 0;
    }
    return retValue;
}

int main_braces() {
    vector<string> test = {"", "(", ")", "aa", "(aa)", "a(adfv(asaff(sa) d) d)", "(((())))", "(()as(((", "aa)(s)", ")(", "()()"};
    vector<int> expected = {1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1};
    
    size_t i = 0;
    while (i < test.size()) {
        if(checkString(test[i]) != expected[i]) {
            cout << "Test" << i + 1 << " failed.\n";
            break;
        }
        ++i;
    }
    if(i == test.size()) {
        cout << "OK\n";
    }    
    return 0;
}

int main2() {
	main_braces();	
	return 0;
}