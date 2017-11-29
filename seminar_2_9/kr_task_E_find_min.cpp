#include <iostream>
#include <map>

using namespace std;

int taskE() {
    int n, k, num;
    multimap<int, int> mapOfNumbers;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> num;
        mapOfNumbers.emplace(num, i);
    }
    cout << mapOfNumbers.begin()->first << endl;   

    for (int i = k; i < n; ++i) {
        cin >> num;
        mapOfNumbers.emplace(num, i);
        while (mapOfNumbers.begin()->second < i - k + 1) {
            mapOfNumbers.erase(mapOfNumbers.begin());
        }
        cout << mapOfNumbers.begin()->first << endl;
    }
    return 0;
}

