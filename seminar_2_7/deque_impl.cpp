﻿/*
Структура "дек" для целых чисел. 
Программа должна "понимать" следующие команды:
push_front n
Добавить (положить) в начало дека новый элемент. Программа должна распечатать текущее состояние дека.
push_back n
Добавить (положить) в конец дека новый элемент. Программа должна распечатать текущее состояние дека.
pop_front
Извлечь из дека первый элемент. Программа должна вывести его значение.
pop_back
Извлечь из дека последний элемент. Программа должна вывести его значение.
front
Узнать значение первого элемента (не удаляя его). Программа должна вывести его значение.
back
Узнать значение последнего элемента (не удаляя его). Программа должна вывести его значение.
size
Вывести количество элементов в деке.
clear
Очистить дек (удалить из него все элементы) и вывести ok.
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

void printDeque(const deque<int>& deq) {
    for(const auto& elem : deq) {
        cout << elem << " ";
    }
    cout << endl;
}

void makeDeque() {
    deque<int> dequeue;
    string str;
    int n;
    while(cin >> str) {
        if(str == "push_front") {
            cin >> n;
            dequeue.push_front(n);
            printDeque(dequeue);
            continue;
        }
        if(str == "push_back") {
            cin >> n;
            dequeue.push_back(n);
            printDeque(dequeue);
            continue;
        }
        if(str == "pop_front") {
            if(dequeue.size() == 0) {
                cout << "Error. Empty deque.";
            }
            else {
                cout << dequeue.front();
                dequeue.pop_front();
            }
            cout << endl;
            continue;
        }
        if(str == "pop_back") {
            if(dequeue.size() == 0) {
                cout << "Error. Empty deque.";
            }
            else {
                cout << dequeue.back();
                dequeue.pop_back();
            }
            cout << endl;
            continue;
        }
        if(str == "front") {
            if(dequeue.size() == 0)
                cout << "Error. Empty deque.";
            else
                cout << dequeue.front();
            cout << endl;
            continue;
        }
        if(str == "back") {
            if(dequeue.size() == 0)
                cout << "Error. Empty deque.";
            else
                cout << dequeue.back();
            cout << endl;
            continue;
        }
        if(str == "size") {
            cout << dequeue.size() << endl;
            continue;
        }
        if(str == "clear") {
            dequeue.clear();
            cout << "ok\n";
            continue;
        }
        cout << "Cmd is unknown. Finished.\n";
        break;
    }
}