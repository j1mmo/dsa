#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <initializer_list>
#include <cassert>

template<typename _class_type, uint32_t _size>
struct array {
  static_assert(_size != 0);
  _class_type _data[_size];

  using _class_type_ref = _class_type&;
  using _class_type_const_ref = const _class_type&;
  using _class_type_ptr = _class_type*;
  using _class_type_const_ptr = const _class_type*;

  constexpr array(std::initializer_list<_class_type> init) {
    uint32_t i = 0;

    for (const auto& val : init) {
        if (i >= _size) break;
        _data[i++] = val;
    }

    for (; i < _size; ++i) {
        _data[i] = _class_type{};
    }
  }
  constexpr array() = default;
  template<uint32_t cArrayLength>
  constexpr array(_class_type (&cArray)[cArrayLength]) {
    static_assert(cArrayLength <= _size);
    
    for (uint32_t counter{0}; counter < cArrayLength; ++counter) {
	_data[counter] = cArray[counter];
    }

    for (uint32_t i = cArrayLength; i < _size; i++) {
	_data[i] = _class_type{};
    }
  }

  constexpr _class_type operator[](uint32_t index) const {
    assert(index < _size);
    return _data[index];
  }

  constexpr _class_type_ref operator[](uint32_t index) {
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

  constexpr uint32_t size() const {
    return _size;
  }

};

#endif // ARRAY_HPP
