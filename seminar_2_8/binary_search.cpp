/*
Нужно реализовать функцию приближенного бинарного поиска элемента в векторе.
Если элемент есть, вывести его.
Если элемента в векторе нет, нужно вывести наиболее близкое к данному.
Если таких несколько, выведите меньшее из них.
*/

/*
std::lower_bound
Возвращает итератор, указывающий на первый элемент из [first, last),
который не меньше заданного.
Использует operator < для сравнения 
или заданную 3-м параметром функцию.
*/

#include <iostream>
#include <vector>
#include <algorithm>

void binaryApproximateSearch() {
    std::vector<int> numbers = {2, 3, 5, 7, 7, 9, 10, 11};

    int el;
    std::cout << "Enter an element to look for: ";
    std::cin >> el;

    auto it = std::lower_bound(numbers.begin(), numbers.end(), el);
    
    if(it != numbers.begin() && *it != el &&
       abs(*(it - 1) - el) <= abs(*it - el)) {
        --it;
    }
    std::cout << *it << std::endl;

}