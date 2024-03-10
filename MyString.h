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
		MyString& operator=(const char* other);
		MyString operator+(const MyString& other) const;
		MyString operator+(const char* other) const;
		MyString& operator+=(const MyString& other);
		MyString& operator+=(const char* other);
		bool operator==(const MyString& other) const;
		bool operator==(const char* other) const;
		bool operator!=(const MyString& other) const;
		bool operator!=(const char* other) const;
		char& operator[](const size_t &size) const;
		char& at(const size_t& size);
		size_t get_size() const;
		void print() const;
	private:
		char* _data;
		size_t _size;
	};
}
