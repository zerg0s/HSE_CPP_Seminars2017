#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* —троки и всЄ, что про них полезно знать */
void example2_3_1() {
    string str1 = "A little brown fox jumps over a lazy dog";
    str1 += " and another dog";
    // str1 = str1 * 3; - така€ операци€ не определена
    cout << str1.size() << endl; // 56
    cout << str1.length() << endl; // 56
    cout << str1 << endl;
    reverse(str1.begin(), str1.end()); // строка в обратном пор€дке
    cout << str1 << endl;
    reverse(str1.begin(), str1.end());    

    str1.c_str(); //ѕреобразует строку к массиву символов в стиле —и.

    const string& str2 = str1; // str2 - доступна€ только дл€ чтени€ ссылка на str1.
    str1[0] = 'a'; // ok
    //str2[0] = 'a'; // error!
    const string zzz = "zzz";
    cout << str1.insert(1, zzz) << endl;
    cout << str1.find(zzz) << endl; // ѕозици€ первого вхождени€ или "-1".
    cout << str1.replace(str1.find(zzz), zzz.length(), "") << endl; // replace: откуда, сколько, "на что мен€ть", размеры могут не совпадать

    for(auto ch : str1) {
        ch += 1;
    }
    cout << str1 << endl; //помен€етс€ ли строка?

	if (str1 > "aaa") {
		cout << ">" << endl;
	} 
	else {
		cout << "<" << endl;
	}

}
/* 
 ƒана строка, в которой буква h встречаетс€ как минимум два раза.
 –азверните последовательность символов, заключенную между первым
 и последнием по€влением буквы h в противоположном пор€дке.
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
    ѕродублировать заключенную между первым и последним вхождением символа "@" подстроку.
*/
void example2_3_3() {
    string str = "a @12345@ a";
	cout << str << endl;
    int atFirstPos = str.find('@');
    int atLastPos = str.rfind('@');
    string strDuplicate = str.substr(atFirstPos + 1, atLastPos - atFirstPos - 1); //откуда, сколько
    cout << strDuplicate << endl;
	strDuplicate += strDuplicate;
    str.replace(atFirstPos + 1, strDuplicate.length() / 2, strDuplicate);
    cout << str << endl;
}
/*
   ”далить из строки все символы @.
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


