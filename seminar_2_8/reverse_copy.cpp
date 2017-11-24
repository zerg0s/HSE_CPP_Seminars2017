/*
Вам надо написать свою реализацию стандартного алгоритма reverse_copy. 
Заголовок функции должен быть таким:
template <typename InIter, typename OutIter>
OutIter reverse_copy(InIter first, InIter last, OutIter out);
Функция должна копировать в обратном порядке элементы последовательность 
[first; last) в последовательность, начинающуюся с out.
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

namespace myStd {
    template <typename It, typename Out>
    Out reverse_copy(It first, It last, Out out) {
        auto it = last;
        while(it != first) {
            --it;
            *out = *it;
            ++out;
        }
        return out;
    }
}

void reverseCopy() {
    vector<int> numbers = {1, 2, 2, 3, 4, 5};
    vector<int> result(numbers.size(), -1); // заполнить вектор "-1"
    
    myStd::reverse_copy(numbers.begin(), numbers.end(), result.begin());

    for(const auto& i : result) {
        cout << i << ' ';
    }
    cout << endl;
}