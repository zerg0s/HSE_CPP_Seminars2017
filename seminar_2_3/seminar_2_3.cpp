#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* ������ � ��, ��� ��� ��� ������� ����� */
void example2_3_1() {
    string str1 = "A little brown fox jumps over a lazy dog";
    str1 += " and another dog";
    // str1 = str1 * 3; - ����� �������� �� ����������
    cout << str1.size() << endl; // 56
    cout << str1.length() << endl; // 56
    cout << str1 << endl;
    reverse(str1.begin(), str1.end()); // ������ � �������� �������
    cout << str1 << endl;
    reverse(str1.begin(), str1.end());    

    str1.c_str(); //����������� ������ � ������� �������� � ����� ��.

    const string& str2 = str1; // str2 - ��������� ������ ��� ������ ������ �� str1.
    str1[0] = 'a'; // ok
    //str2[0] = 'a'; // error!
    const string zzz = "zzz";
    cout << str1.insert(1, zzz) << endl;
    cout << str1.find(zzz) << endl; // ������� ������� ��������� ��� "-1".
    cout << str1.replace(str1.find(zzz), zzz.length(), "") << endl; // replace: ������, �������, "�� ��� ������", ������� ����� �� ���������

    for(auto ch : str1) {
        ch += 1;
    }
    cout << str1 << endl; //���������� �� ������?

	if (str1 > "aaa") {
		cout << ">" << endl;
	} 
	else {
		cout << "<" << endl;
	}

}
/* 
 ���� ������, � ������� ����� h ����������� ��� ������� ��� ����.
 ���������� ������������������ ��������, ����������� ����� ������
 � ���������� ���������� ����� h � ��������������� �������.
*/
void example2_3_2() {
    string str1;
    cout << "Please enter a string containing two letters \"h\":\n";
    getline(std::cin, str1);
    int hFirstPos = str1.find('h');
    int hLastPos = str1.rfind('h');
    if(hFirstPos == -1 || hFirstPos == hLastPos) {
        cout << "Your string is not correct\n";
    }
    else {
        reverse(str1.begin() + hFirstPos + 1, str1.begin() + hLastPos);
        cout << str1 << endl;
    }
}
/*
    �������������� ����������� ����� ������ � ��������� ���������� ������� "@" ���������.
*/
void example2_3_3() {
    string str = "a @12345@ a";
	cout << str << endl;
    int atFirstPos = str.find('@');
    int atLastPos = str.rfind('@');
    string strDuplicate = str.substr(atFirstPos + 1, atLastPos - atFirstPos - 1); //������, �������
    cout << strDuplicate << endl;
	strDuplicate += strDuplicate;
    str.replace(atFirstPos + 1, strDuplicate.length() / 2, strDuplicate);
    cout << str << endl;
}
/*
   ������� �� ������ ��� ������� @.
*/
void example2_3_4() {
    string str = "@123@abcd.com@";
	cout << str << endl;
    int pos = -1;
    while((pos = str.find("@")) != -1) {
        str.replace(pos, 1, "");
    }
    cout << str << endl;
}

int main() {    
    example2_3_1();
    //example2_3_2();
    //example2_3_3();
    //example2_3_4();

    system("pause");
    return 0;
}


