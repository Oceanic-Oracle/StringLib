#include "MyString.h"

int main() {
	//Test 1
	mystr::MyString str1("Hello, ");
	str1.print();

	std::cout << std::endl;

	//Test 2
	mystr::MyString str2(str1);
	str2.print();

	std::cout << std::endl;

	//Test 3
	mystr::MyString str3("Hi");
	str1 = str3;
	str1.print();

	std::cout << std::endl;

	//Test 4
	mystr::MyString str4("Hello, ");
	mystr::MyString str5("world!");
	mystr::MyString str6;
	str6 = str4 + str5;
	str6.print();
	std::cout << std::endl;

	//Test 5
	str4 += str5;
	str4.print();

	std::cout << std::endl;

	//Test 6
	str6 = str4 + "2";
	str6.print();

	std::cout << std::endl;

	//Test 7
	str6 += "3";
	str6.print();

	std::cout << std::endl;

	//Test 8
	std::cout << str6[1] << std::endl;

	//Test 9
	str1.print(), std::cout << " ", str2.print();
	(str1 == str2) ? (std::cout << "True" << std::endl) : (std::cout << "False" << std::endl);

	//Test 10
	str1.print(), std::cout << " ", str2.print();
	(str1 != str2) ? (std::cout << "True" << std::endl) : (std::cout << "False" << std::endl);
	return 0;
}