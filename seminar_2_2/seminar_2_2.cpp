#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void example0() {
	float a = 123456789;
	float b = 123456788;
	std::cout << std::fixed << a << std::endl;    // ? 
	std::cout << std::fixed << b << std::endl;   // ?? 
	std::cout << "a - b = " << a - b << std::endl; // ??? 

	double c = 123456789;
	double d = 123456788;
	std::cout << std::fixed << c << std::endl;    // ? 
	std::cout << std::fixed << d << std::endl;   // ?? 
	std::cout << "c - d = " << c - d << std::endl; // ??? 
}

/* ������ 1. ������ � ������ � ���.  */
void example1() {
	//  ������ -  "�����" ������������ ������ ������ #(Py Vs C++) ������ - ��� �� ������!
	// #include <vector>
	vector<int> v1; // �������� ������, ������ ������ ������.
	vector<long> v2 = { 1, 3, 4 }; // ��� ��� - ����������� �������������
	v1.push_back(42); //�������� � �����
	v1.push_back(41); //�������� � �����

	// ������ ������� ����� ���� foreach
	for (auto i : v1) {
		cout << i << endl;
	}
	// ����� ������� ����� ������� ��������
	for (size_t i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << endl;  // ���
		cout << v1[i] << endl; // ��� ���
	}
}
/* ������ 1.  ��� ���������� ������� ���������� ����� ���� ��� ������ � 
�������� ��������� */
void example2() {
	vector<vector<int>> matrix;
	size_t size = 0;
	cout << "Enter size (n*n): ";
	cin >> size;
	int sumOdd = 0;
	int sumEven = 0;
	for (size_t i = 0; i < size; ++i) {
		matrix.push_back(vector<int>());
		for (size_t j = 0; j < size; ++j)
		{
			matrix.at(i).push_back(rand() % 10); // rand() - random number from 0 to RAND_MAX
			cout << matrix.at(i).at(j) << "\t";
			if (matrix[i][j] % 2 == 0) {
				sumEven += matrix[i][j];
			}
			else {
				sumOdd += matrix[i][j];
			}
		}
		cout << "\n";
	}
	cout << "Sum of even elements: " << sumEven << endl;
	cout << "Sum of odd elements: " << sumOdd << endl;
}

/* ������ 2.  ��� ���������� ������� ������������� �������� ������ ������, 
������� �� � �������� ������� */
void example3() {
	size_t size;
	cout << "Enter size (n*n): ";
	std::cin >> size;
	std::vector<std::vector<int>> matrix;
	matrix.reserve(size);
	for (size_t i = 0; i < size; ++i) {
		matrix.push_back(std::vector<int>());
		matrix.back().reserve(size);
		for (size_t j = 0; j < size; ++j) {
			matrix.back().push_back(rand() % 10);
			std::cout << matrix.back().back() << "\t";
			//std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}

	// Sort row elements
	std::cout << "\n\n Sorted:\n";
	for (size_t i = 0; i < size; ++i) {
		std::sort(matrix.at(i).begin(), matrix.at(i).end());
		for (size_t j = 0; j < size; ++j) {
			std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}

	// Reverse row elements
	std::cout << "\n\n Reversed:\n";
	for (size_t i = 0; i < size; ++i) {
		std::reverse(matrix.at(i).begin(), matrix.at(i).end());
		for (size_t j = 0; j < size; ++j) {
			std::cout << matrix.at(i).at(j) << "\t";
		}
		std::cout << "\n";
	}
}

int main() {
	//example0();
	//example1();
	example2();
	//example3();
	return 0;
}