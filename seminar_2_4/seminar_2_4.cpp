#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/* Пример 1. 2 простейшие структуры */
/* Структура применяется как POD-тип данных,
структуры хранятся на стеке.
*/
struct Date {
    int year;
    int month;
    int day;
};

struct ItemInStore {
    string name;
    Date expirationDate;
    int priсe;
};

bool operator < (const ItemInStore& item1, const ItemInStore& item2) {
    Date d1 = item1.expirationDate;
    Date d2 = item2.expirationDate;
    return d1.year < d2.year
        || d1.year == d2.year && d1.month < d2.month
        || d1.year == d2.year && d1.month == d2.month && d1.day < d2.day;
}

/* Задача 1.
Заполнить магазин случайными товарами из перечня
{"товар1, товар2, товар3"}.
Для всех указать случайный не истёкший срок годности
в этом или следующем году.
Для всех сделать случайную цену в диапазоне [10;100].
Отсортировать товары магазина по возрастанию срока годности.
*/
vector<ItemInStore> example2_4_1() {
    cout << "\nExample1 started";
    const int N = 10;
    vector<ItemInStore> goods;
    cout << sizeof(goods) << "\n\n";  // ??
    vector<string> listOfGoods = {"Screwdriver", "Hammer", "Pliers"};
    Date expDate = {10, 11, 2017};

	cout << "Size of Date = " << sizeof(expDate) << "\n\n";

    for(size_t i = 0; i < N; i++) {
        expDate.year = rand() % 2 + 2017;
        expDate.month = rand() % 12 + 1;
        expDate.day = rand() % 28 + 1; //чтобы не добавлять еще условий
        goods.push_back({listOfGoods.at(rand() % 3),
                        expDate,
                        rand() % 91 + 10
        });
    }
    sort(goods.begin(), goods.end());
    
	//Print the result
    for(auto item : goods) {
        cout << item.name << " " << item.priсe << " ";
        cout << item.expirationDate.day << " ";
        cout << item.expirationDate.month << " ";
        cout << item.expirationDate.year << "\n";
    }
    return goods;
}

/* Ссылки */
/* Написать функцию, которая будет увеличивать цену
товаров из предыдущей задачи на 10%
*/
// Какую сигнатуру выбрать?
//void example2(vector<ItemInStore> v) {
//void example2(const vector<ItemInStore>& v) {
void example2_4_2(vector<ItemInStore>& goods) {
    cout << "\nExample2 started\n";
    for(ItemInStore& item : goods) {
        // Ссылка обязательно! Иначе - копия и список не поменяется
        item.priсe = (int)round(item.priсe * 1.1);
    }

    for(const auto& item : goods) {
        // Cсылка желательно, экономим память.
        // const желательно, ускоряем программу
        cout << item.name << " " << item.priсe << " ";
        cout << item.expirationDate.day << " ";
        cout << item.expirationDate.month << " ";
        cout << item.expirationDate.year << "\n";
    }
}



/*
	std::map
*/
void example2_4_3() {

    map<char, int> myMap;

    myMap['x'] = 100;
    myMap.emplace('y', 200);
    myMap.insert(pair<char, int>('z', 300));
    myMap.insert({'aa', 400}); // ошибка?  
    myMap.insert({'1', 500});
	myMap.insert({'1', 600});
	myMap.emplace('1', 700);
	myMap['1'] = 800;

    cout << "myMap contains:";
    cout << " {";
	for (auto& x : myMap) {
		cout << "\'" << x.first << "\':" << x.second << ", ";
	}
    cout << "}\n";

	cout << "count = " << myMap.count('y') << "\n";
    // map::count(key) - возвращает количество элементов, соответствующих ключу. 
	// Что может вернуть count в map?

	if (myMap.find(111) != myMap.end()) {
		cout << "Element exist!" << endl;
	} 
	else{
		cout << "No element!" << endl;
	}
}

/*
Associative containers:
	set
	multiset
	map
	multimap

Unordered associative containers:
	unordered_set
	unordered_multiset
	unordered_map
	unordered_multimap
*/

int main() {
    //example2_4_1();
    //example2_4_2(example2_4_1());
    example2_4_3();    
    return 0;
}
