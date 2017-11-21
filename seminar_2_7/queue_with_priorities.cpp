/*
Требуется простая релизация очереди с приоритетами.
clear — сделать очередь с приоритетами пустой.
add n — добавить в очередь с приоритетами число n. 
extract — достать из очереди с приоритетами максимальное значение.
*/

/*
Определено в заголовочном файле <queue>
template<class T, class Container = std::vector<T>,
class Compare = std::less<typename Container::value_type>> class priority_queue;

Очередь с приоритетом - это тип контейнера, 
который позволяет достичь константной скорости доступа к максимальному 
(или минимальному, в зависимости от реализации Compare) элементу.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional> //std::greater
#include <string>

using namespace std;

void makePriorityQueue() {
    string com;
    priority_queue<int, vector<int>, less<int>> myQueue;
    while(cin >> com) {
        if(com == "extract") {
            if(!myQueue.empty()) {
                std::cout << myQueue.top() << "\n"; //доступ к максимальному элементу
                myQueue.pop();
            }
            else {
                std::cout << "Error, empty Queue\n";
            }
			continue;
        }
        if(com == "add") {
            size_t num;
            std::cin >> num;
            myQueue.push(num);
			continue;
        }
        if(com == "clear") {
            while(!myQueue.empty()) {
                myQueue.pop();
            }
			std::cout << "ok";
			continue;
        }
		cout << "Cmd is unknown. Finished.\n";
		break;
    }
}
// Реализовать очередь с приоритетами для точек по степени удаленности от начала координат.
// Высший приоритет у точки, самой близкой к началу координат.