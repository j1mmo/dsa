#ifndef STRING_HPP
#define STRING_HPP

#include <cstdint>
#include <cstdlib>
#include <cassert>

#include <cstdio>
#include <algorithm>

struct string {
  struct allocated_storage {
    char * _data_ptr;
    uint32_t _capacity;
  };

  using small_storage = char[sizeof(allocated_storage)];

  union storage {
    allocated_storage _alloc;
    small_storage _small;
  };

  storage _storage {._small = small_storage{}};
  uint32_t _size = 0;
  bool _small_storage = true;

  
  constexpr string::allocated_storage alloc(uint32_t length, const char * data) {
    auto* alloced = static_cast<char*>(malloc(length + 1));
    strcpy(data, length, alloced);
    return {alloced, length};
  }

  ~string() {
    if (!_small_storage) {
	free(_storage._alloc._data_ptr);
    }
  }

  constexpr string() = default;
  constexpr string(const char *data)
    : _size{length(data)}
  {
    if (_size < sizeof(small_storage)) {
	strcpy(data, data + _size + 1, _storage._small);
    } else {
	_storage._alloc = alloc(_size, data);
	_small_storage = false;
    }
  }

  constexpr char operator[](const uint32_t index) const {
    assert(index < _size);
    const char* ptr = data();
    return ptr[index];
  }

  char& operator[](const uint32_t index) {
    assert(index < _size);
    char* ptr = data();
    return ptr[index];
  }

  string& operator=(const string& other) {
    string temp(other);

    char* ptr = data();
    char* tempPtr = temp.data();
    std::swap(ptr, tempPtr);
    std::swap(_size, temp._size);
    
    return *this;
  }
  constexpr string(const string& other) :
    _size(other._size),
    _small_storage(other._small_storage) {
    if (_small_storage) {
	strncpy(_storage._small, other.data(), _size);
    } else {
	char* ptr = static_cast<char*>(malloc(_size + 1));
	strncpy(ptr, other.data(), _size);
	_storage._alloc = {ptr, other._storage._alloc._capacity};
    }
  }
  
  [[nodiscard]] constexpr char* data() noexcept {
    if (_small_storage) {
	return _storage._small;
    } else {
	return _storage._alloc._data_ptr;
    }
  }

  [[nodiscard]] constexpr const char* data() const noexcept {
    if (_small_storage) {
	return _storage._small;
    } else {
	return _storage._alloc._data_ptr;
    }
  }

  constexpr const uint32_t size() const {
    return _size;
  }

  constexpr char* strcpy(char* destination, const char* source) {
    char* start = destination;

    while (*source != '\0') {
	*destination = *source;
	++destination;
	++source;
    }

    *destination = '\0';

    return start;
  }

  constexpr void copy(const string& source, string& destination) {
    for(int i = 0; i < source.size(); i++) {
	destination[i] = source[i];
    }
  }
  
  constexpr char* strncpy(char* dest, const char* src, uint32_t len) {
    for (uint32_t i = 0; i < len; ++i) {
	dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
  }
  
  constexpr char* strcpy(const char* source, const uint32_t length, char* destination) {

    for (uint32_t counter{0}; counter < length && source[counter] != '\0'; counter++) {
	destination[counter] = source[counter];
    }
    destination[length] = '\0';
    return destination;
  }
  
  constexpr char* strcpy(const char* sourceStart, const char* sourceEnd, char* destination) {

    for (uint32_t start{0}; (sourceStart + start) != sourceEnd && sourceStart[start] != '\0'; start++) {
	destination[start] = sourceStart[start];
    }
    return destination;
  }
  
  constexpr uint32_t length(const char * string) {
    uint32_t counter{0};
    for(; string[counter] != '\0'; counter++) {}
    return counter;
  }
};

#endif // STRING_HPP
