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
	mystr::MyString str6();
	str6 = str3 + str5;
	str6.print();
	std::cout << std::endl;

	//Test 5
	str4 += str5;
	str4.print();

	return 0;
}