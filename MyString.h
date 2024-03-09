#pragma once

#include <iostream>

namespace mystr
{
	class MyString
	{
	public:
		MyString();
		MyString(const char* str);
		MyString(const MyString& str);
		~MyString();
		MyString& operator=(const MyString& other);
		MyString& operator+(const MyString& other);
		MyString& operator+=(const MyString& other);
		size_t get_size() const;
		void print() const;
	private:
		char* _data;
		size_t _size;
	};
}
