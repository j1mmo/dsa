#ifndef DARRAY_HPP
#define DARRAY_HPP

#include <initializer_list>

#include <cstdint>
#include <cassert>

template<typename _class_type>
struct darray {
  _class_type* _data{nullptr};
  uint32_t _size{0};
  uint32_t _capacity{0};

  using _class_type_ref = _class_type&;
  using _class_type_const_ref = const _class_type&;
  using _class_type_ptr = _class_type*;
  using _class_type_const_ptr = const _class_type*;

  constexpr darray(std::initializer_list<_class_type> init) :_size(0) {
    uint32_t incomingDataLength = init.size();

    alloc(incomingDataLength);
    for(const _class_type& obj : init) {
	_data[_size++] = obj;
    }
  }
  
  constexpr darray() = default;
  template<uint32_t cArrayLength>
  constexpr darray(_class_type (&cArray)[cArrayLength]) {

    alloc(cArrayLength);
    uint32_t counter{0};
    for (; counter < cArrayLength; ++counter) {
	_data[counter] = cArray[counter];
    }
    _size = counter;
  }

  constexpr _class_type operator[](uint32_t index) const {
    assert(index < _size);
    return _data[index];
  }

  constexpr _class_type_ref operator[](uint32_t index) {
    assert(index < _size);
    return _data[index];
  }

  constexpr _class_type_ptr begin() {
    return _data;
  }

  constexpr _class_type_ptr end() {
    return _data + _size;
  }

  constexpr _class_type_const_ptr begin() const {
    return _data;
  }

  constexpr _class_type_const_ptr end() const {
    return _data + _size;
  }

  constexpr void fill(_class_type_const_ref v) {
    for (uint32_t counter{0}; counter < _size; counter++) {
	_data[counter] = v;
    }
  }

  void push(_class_type_const_ref newItem) {
    
    if (_size >= _capacity) {
	//if zero set to 2
	realloc(_capacity ? _capacity * 2 : 2);
    }
    _data[_size++] = newItem;
  }

  constexpr uint32_t size() const {
    return _size;
  }

  void clean() {
    if (_data == nullptr) {
	free(_data);
    }
  }

private:

  constexpr void alloc(uint32_t newLength) {
    _data = static_cast<_class_type*>(malloc(sizeof(_class_type) * newLength));
    _capacity = newLength;
  }
  
  constexpr void realloc(uint32_t newLength) {
    auto alloced = static_cast<_class_type*>(malloc(sizeof(_class_type) * newLength));
    copy(*this, alloced, newLength);
    free(_data);
    _data = alloced;
    _capacity = newLength;
  }

  static constexpr void
  copy(const darray<_class_type>& source, _class_type* destination, uint32_t destinationLength) {
    assert(source.size() <= destinationLength);
    uint32_t index{0};
    for(const _class_type& obj : source) {
	destination[index] = obj;
	index++;
    }
  }

  
};

#endif // DARRAY_HPP
