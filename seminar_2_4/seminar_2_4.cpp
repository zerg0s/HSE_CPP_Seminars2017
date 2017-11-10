#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

/* ������ 1. 2 ���������� ��������� */
/* ��������� ����������� ��� POD-��� ������,
��������� �������� �� �����.
*/
struct Date {
    int year;
    int month;
    int day;
};

struct ItemInStore {
    string name;
    Date expirationDate;
    int pri�e;
};

bool operator < (const ItemInStore& item1, const ItemInStore& item2) {
    Date d1 = item1.expirationDate;
    Date d2 = item2.expirationDate;
    return d1.year < d2.year
        || d1.year == d2.year && d1.month < d2.month
        || d1.year == d2.year && d1.month == d2.month && d1.day < d2.day;
}

/* ������ 1.
��������� ������� ���������� �������� �� �������
{"�����1, �����2, �����3"}.
��� ���� ������� ��������� �� ������� ���� ��������
� ���� ��� ��������� ����.
��� ���� ������� ��������� ���� � ��������� [10;100].
������������� ������ �������� �� ����������� ����� ��������.
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
        expDate.day = rand() % 28 + 1; //����� �� ��������� ��� �������
        goods.push_back({listOfGoods.at(rand() % 3),
                        expDate,
                        rand() % 91 + 10
        });
    }
    sort(goods.begin(), goods.end());
    
	//Print the result
    for(auto item : goods) {
        cout << item.name << " " << item.pri�e << " ";
        cout << item.expirationDate.day << " ";
        cout << item.expirationDate.month << " ";
        cout << item.expirationDate.year << "\n";
    }
    return goods;
}

/* ������ */
/* �������� �������, ������� ����� ����������� ����
������� �� ���������� ������ �� 10%
*/
// ����� ��������� �������?
//void example2(vector<ItemInStore> v) {
//void example2(const vector<ItemInStore>& v) {
void example2_4_2(vector<ItemInStore>& goods) {
    cout << "\nExample2 started\n";
    for(ItemInStore& item : goods) {
        // ������ �����������! ����� - ����� � ������ �� ����������
        item.pri�e = (int)round(item.pri�e * 1.1);
    }

    for(const auto& item : goods) {
        // C����� ����������, �������� ������.
        // const ����������, �������� ���������
        cout << item.name << " " << item.pri�e << " ";
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
    myMap.insert({'aa', 400}); // ������?  
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
    // map::count(key) - ���������� ���������� ���������, ��������������� �����. 
	// ��� ����� ������� count � map?

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
