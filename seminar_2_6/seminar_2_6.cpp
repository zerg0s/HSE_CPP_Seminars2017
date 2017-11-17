// Работа с unordered_set
#include <algorithm>
#include <iostream>
#include <map> 
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct Car {
	string name;
	long price;
	int yearOfProduction;

	Car(string _name, long _price, int _yearOfProduction) :
		name(_name), price(_price), yearOfProduction(_yearOfProduction) {}
};

// Собственная функция для вычисления хэшей на основе длин строк.
struct StringHashBySize {	
	size_t operator()(const string& str) const {
		int size = str.length();
		return hash<int>()(size);
	}
};

// Собственное ставнение строк - по длине
struct StringEqualBySize {
	bool operator()(const string& str1, const string& str2) const {
		if (str1.length() == str2.length())
			return true;
		else
			return false;
	}
};

// Hash по имени
struct StringHashByName {
	size_t operator()(const Car& car) const {
		return hash<string>()(car.name);
	}
};

// Собственное сравнение по имени
struct StringEqualByName {
	bool operator()(const Car& car1, const Car& car2) const {
		return car1.name == car2.name;
	}
};

void example1RegualOddSet() {
	unordered_set<string> names;
	names.insert("Bob");
	names.insert("Alice");
	names.insert("Tom");
	names.insert("Mark");
	names.insert("Bob");
	for (const auto& name : names) {
		cout << name << endl;
	}
}

void example2UnorderedSetOfCars() {
	unordered_set<Car, StringHashByName, StringEqualByName> cars;
	cars.emplace("bmw", 100500, 2017);
	cars.emplace("vaz", 100, 1980);
	cars.emplace("bmw", 100500, 2017);
	cars.emplace("audi", 100501, 2016);
	cars.emplace("audi", 100502, 2016);
	for (const auto& car : cars) {
		cout << car.name << " : " << car.price;		
		cout << " " << car.yearOfProduction << endl;
	}
}

void example3UnorderedMapOfCars() {
	unordered_map<string, Car, StringHashBySize, StringEqualBySize> garage;
	//unordered_map<string, Car> garage;
	garage.insert(pair<string, Car>(string("first"), {"bmw", 100500, 2017}));
	garage.insert(pair<string, Car>(string("second"), {"bmw", 100500, 2017}));
	garage.insert(pair<string, Car>(string("third"), {"vaz", 100, 1980}));
	garage.insert(pair<string, Car>(string("fourth"), {"audi", 100501, 2016}));

	for (const auto& elem : garage) {
		auto& car = elem.second;
		cout << elem.first << " : " << car.price;
		cout << " " + car.name + " ";
		cout << car.yearOfProduction << endl;
	}
}

int main0() {
	//example1RegualOddSet();	
	//example2UnorderedSetOfCars();
	example3UnorderedMapOfCars();		
	return 0;
}