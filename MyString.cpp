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
	MyString& MyString::operator=(const char* other) 
	{
		if (this->_data != nullptr) { delete[] this->_data; }
		this->_size = strlen(other);
		this->_data = new char[this->_size + 1];
		for (size_t i = 0; i < _size; ++i) 
		{
			this->_data[i] = other[i];
		}
		this->_data[_size] = '\0';
		return *this;
	}
	MyString MyString::operator+(const MyString& other) const
	{
		size_t temp_size = this->_size + other._size;
		char* temp_data = new char[temp_size + 1];
		for (size_t i = 0; i < this->_size; ++i) 
		{
			temp_data[i] = this->_data[i];
		}
		for (size_t i = 0; i < other._size; ++i) 
		{
			temp_data[i + this->_size] = other._data[i];
		}
		temp_data[temp_size] = '\0';
		MyString result(temp_data);
		delete[] temp_data;
		return result;
	}
	MyString MyString::operator+(const char* other) const 
	{
		size_t temp_size = this->_size + strlen(other);
		char* temp_data = new char[temp_size + 1];
		for (size_t i = 0; i < this->_size; ++i)
		{
			temp_data[i] = this->_data[i];
		}
		for (size_t i = 0; i < strlen(other); ++i)
		{
			temp_data[i + this->_size] = other[i];
		}
		temp_data[temp_size] = '\0';
		MyString result(temp_data);
		delete[] temp_data;
		return result;
	}
	MyString& MyString::operator+=(const MyString& other) 
	{
		size_t temp_size = this->_size + other._size;
		char* temp_data = new char[temp_size + 1];
		for (size_t i = 0; i < this->_size; ++i) 
		{
			temp_data[i] = this->_data[i];
		}
		for (size_t i = 0; i < other._size; ++i)
		{
			temp_data[i + this->_size] = other._data[i];
		}
		temp_data[temp_size] = '\0';
		delete[] this->_data;
		_data = temp_data;
		this->_size = temp_size;
		return *this;
	}
	MyString& MyString::operator+=(const char* other) 
	{
		size_t temp_size = this->_size + strlen(other);
		char* temp_data = new char[temp_size + 1];
		for (size_t i = 0; i < this->_size; ++i)
		{
			temp_data[i] = this->_data[i];
		}
		for (size_t i = 0; i < strlen(other); ++i)
		{
			temp_data[i + this->_size] = other[i];
		}
		temp_data[temp_size] = '\0';
		delete[] this->_data;
		_data = temp_data;
		this->_size = temp_size;
		return *this;
	}
	bool MyString::operator==(const MyString& other) const 
	{
		if (this->_size != other._size) 
		{
			return false;
		}
		else 
		{
			for (size_t i = 0; i < this->_size; ++i) 
			{
				if (this->_data[i] != other._data[i]) { return false; }
			}
		}
		return true;
	}
	bool MyString::operator==(const char* other) const
	{
		if (this->_size != strlen(other))
		{
			return false;
		}
		else
		{
			for (size_t i = 0; i < this->_size; ++i)
			{
				if (this->_data[i] != other[i]) { return false; }
			}
		}
		return true;
	}
	bool MyString::operator!=(const MyString& other) const 
	{
		if (this->_size != other._size)
		{
			return true;
		}
		else
		{
			for (size_t i = 0; i < this->_size; ++i)
			{
				if (this->_data[i] != other._data[i]) { return true; }
			}
		}
		return false;
	}
	bool MyString::operator!=(const char* other) const 
	{
		if (this->_size != strlen(other))
		{
			return true;
		}
		else
		{
			for (size_t i = 0; i < this->_size; ++i)
			{
				if (this->_data[i] != other[i]) { return true; }
			}
		}
		return false;
	}
	char& MyString::operator[](const size_t& size) const
	{
		return this->_data[size];
	}
	char& MyString::at(const size_t& size)
	{
		if (size >= 0 && size < this->_size) { return this->_data[size]; }
		else { throw std::out_of_range("Index out of range"); }
	}
	size_t MyString::get_size() const
	{
		return this->_size;
	}
	void MyString::print() const 
	{
		for (size_t i = 0; i < _size; ++i) 
		{
			std::cout << _data[i];
		}
	}
}