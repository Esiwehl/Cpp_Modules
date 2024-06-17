#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdint>

template <typename T>
class Array {
	private:
		T*			_data;
		uint16_t	_size;
		
		void clear();
	
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array& operator=(const Array& other);
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;

		unsigned int size()const ;

};

template <typename T>
Array<T>::Array() : _data(nullptr), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
Array<T>::~Array() {
	clear();
}

template <typename T>
Array<T>::Array(const Array& other) : _data(new T[other._size]()), _size(other._size) {
	for (unsigned int it = 0; it < _size; it++){
		_data[it] = other._data[it];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this == &other) return *this;

	clear();

	_size = other._size;
	_data = new T[_size];
	for (unsigned int it = 0; it < _size; ++it) {
		_data[it] = other._data[it];
	}

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx){
	if (_data == nullptr || idx >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return _data[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (_data == nullptr || idx >= _size) {
		throw std::out_of_range("Index out of bounds");
	}
	return _data[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

template <typename T>
void Array<T>::clear() {
	delete[] _data;
	_data = nullptr;
	_size = 0;
}

#endif