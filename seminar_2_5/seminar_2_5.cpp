#include <algorithm>
#include <iostream>
#include <map> 
#include <string>
#include <vector>

using namespace std;

void printTail(const vector<string>& strings, size_t n) {
    if(n > strings.size()) {
        n = strings.size();
    }
    for(size_t i = strings.size() - n; i < strings.size(); ++i) {
        cout << strings[i] << endl;
    }
}

void krTaskD() {
    string str1 = "";
    getline(cin, str1);
    int tail = 10;
    if(str1.find("-n") != -1) {
        if(str1.size() > 3) {
            tail = stoi(str1.substr(2));
        }
    }
    vector<string> items;
    while(getline(cin, str1)) {
        //для тестирования, сin не прерывается пустым вводом.
        if (str1 == " ") break;
        items.push_back(str1);
    }
    printTail(items, tail);
}

void example1_tuples() {
    tuple<int, double, string, int> tup{0, 3.14, "hello", 2};
    cout << get<1>(tup) << "\n"; // 3.14
	cout << get<double>(tup) << "\n"; // 3.14
}
struct Car {
    string name;
    long price;
    int yearOfProduction;
};
bool sortByPrice(const Car& car1, const Car& car2) {
    return car1.price < car2.price;
}
void example2CustomSort() {
    vector<Car> garage;
    garage.push_back({"Audi", 100500, 2017});
    garage.push_back({"Bmw", 100501, 2016});
    garage.push_back({"Bently", 100900, 2017});
    garage.push_back({"UAZ", 666, 2015});
    // сортировка с помощью вспомогательной функции
    sort(garage.begin(), garage.end(), sortByPrice);
    for (size_t i = 0; i < garage.size(); ++i) {
        cout << garage[i].price;
        cout << " " + garage[i].name + " ";
        cout << garage[i].yearOfProduction << endl;
    }
    // сортировка с помощью lambda-функции
    sort(garage.begin(), garage.end(), [](Car& car1, Car& car2)->bool {
        return car1.yearOfProduction < car2.yearOfProduction;
    });
    cout << "\nWith lambda:\n";
    for (size_t i = 0; i < garage.size(); ++i) {
        cout << garage[i].price;
        cout << " " + garage[i].name + " ";
        cout << garage[i].yearOfProduction << endl;
    }
    //вопрос: а как еще, не пользуясь функцией или лямбда функцией 
    //"научить" std::sort сортировать объекты собственных типов?
}

// Работа с unordered_set
#include <unordered_set>

// Собственная функция для вычисления хэшей на основе длин строк.
// Обратите внимание на способ ее оформления - тип с определенным оператором()
struct StringHashBySize {
    // На засыпку: что значит последний const?
    size_t operator()(const string& str) const {
        int size = str.length();
        return hash<int>()(size);
    }
};

// Собственное ставнение строк - по длине
struct StringEqualBySize {
    bool operator()(const string& str1, const string& str2) const {
		if (str1.length() == str2.length()) {
			return true;
		}
		else {
			return false;
		}
    }
};

void example3UnorderedSet() {
    // Объявление сета с собственными функциями определения уникальности элемента
    unordered_set<string, StringHashBySize, StringEqualBySize> setOfStrs;

    setOfStrs.insert("First");
    setOfStrs.insert("second");

    // Будет ли добавлено? 
    setOfStrs.insert("third");
    setOfStrs.insert("second");
    setOfStrs.insert("five");

	for (const string& s : setOfStrs) {
		cout << s << endl;
	}
}

// Задача:
// Попробуйте сложить в unordered_map Автомобили, представленные структурой Car.

int main25(){
    //krTaskD(); // Contest result - OK
    //example1_tuples();
    //example2CustomSort();
    example3UnorderedSet();    
    return 0;
}
