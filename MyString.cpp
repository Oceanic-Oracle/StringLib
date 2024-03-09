#include "MyString.h"

namespace mystr {
	MyString::MyString() : _data(nullptr), _size(0){}
	MyString::MyString(const char* str) : _data(nullptr), _size(0) 
	{
		this->_size = strlen(str);
		this->_data = new char[_size + 1];

		for (size_t i = 0; i < _size; ++i)
		{
			this->_data[i] = str[i];
		}
		this->_data[_size] = '\0';
	}
	MyString::MyString(const MyString& other) 
	{
		this->_size = other._size;
		this->_data = new char[_size + 1];
		for (size_t i = 0; i < _size; ++i) 
		{
			this->_data[i] = other._data[i];
		}
		this->_data[_size] = '\0';
	}
	MyString::~MyString() 
	{
		delete[] this->_data;
	}
	MyString& MyString::operator=(const MyString& other) 
	{
		if(this->_data != nullptr) { delete[] this->_data; }		
		this->_size = other._size;
		this->_data = new char[_size + 1];
		for (size_t i = 0; i < _size; ++i) 
		{
			this->_data[i] = other._data[i];
		}
		this->_data[_size] = '\0';
		return *this;
	}
	MyString& operator+(const MyString& other) 
	{
		//TODO: ÍÀÏÈØÈ ÊÎÄ
	}
	MyString& MyString::operator+=(const MyString& other) 
	{
		size_t temp_size = this->_size + other._size;
		char* temp = new char[temp_size + 1];
		for (size_t i = 0; i < this->_size; ++i) 
		{
			temp[i] = this->_data[i];
		}
		for (size_t i = 0; i < other._size; ++i)
		{
			temp[i + this->_size] = other._data[i];
		}
		temp[temp_size] = '\0';
		delete[] this->_data;
		this->_data = new char[temp_size + 1];
		for (size_t i = 0; i < temp_size; ++i) 
		{
			this->_data[i] = temp[i];
		}
		_data[temp_size] = '\0';
		delete[] temp;
		this->_size = temp_size;
		return *this;
	}
	size_t MyString::get_size() const
	{
		return _size;
	}
	void MyString::print() const 
	{
		for (size_t i = 0; i < _size; ++i) 
		{
			std::cout << _data[i];
		}
	}
}