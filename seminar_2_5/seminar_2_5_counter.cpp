/*
"Считалочка"
Вокруг считающего стоит N человек, из которых выделен первый, а остальные занумерованы по часовой стрелке числами от 2 до N.
Считающий, начиная с кого-то, ведет счет до M. Человек на котором остановился счет, выходит из круга.
Счет продолжается со следующего человека и так до тех пор, пока не останется один человек.
Определить номер оставшегося человека, если известно M и то, что счет начинался с первого человека;
*/
#include <iostream>
#include <vector>
#include <algorithm>    // std::find_if_not

using namespace std;

int getWinner(const vector<int>& v) {
    if(count(v.begin(), v.end(), 0) == v.size() - 1) {
        int k = *find_if_not(v.begin(), v.end(), [](int i) {return i == 0; });
        return k;
    }
    return 0;
}
void countTask(int n, int m) {
    vector<int> people;
    int numPrevious = 0;
    int numWin = -1; 

    for(int i = 1; i <= n; ++i) {
        people.push_back(i);
    }
    
	int curPos = 1;

    while((numWin = getWinner(people)) == 0) {
        for(int i = 1; i < m; ++i) { //   Отсчитываем m человек, начиная с countPos 
            while(people.at(curPos % n) == 0) {
                curPos = (curPos + 1) % n;
            }
            curPos = (curPos + 1) % n;
        }
        while(people.at(curPos % n) == 0) {
            curPos = (curPos + 1) % n;
        }
        
        people.at(curPos % n) = 0;

        while(people.at(curPos % n) == 0) {
            curPos = (curPos + 1) % n;
        }
    };
    cout << "The last in game is  " << numWin << endl;
}
int main() {
    countTask(10, 10);    
    return 0;
}