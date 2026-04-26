#ifndef STACK_ALLOCATOR_HPP
#define STACK_ALLOCATOR_HPP

#include <cstdint>
#include <cstddef>

struct stack_allocator
{
  uint32_t* root_marker_ = nullptr;
  uint32_t* end_marker_ = nullptr;
  size_t total_size_{0};

  explicit stack_allocator(uint32_t stack_size_bytes);
  void* alloc(uint32_t size_bytes);

  uint32_t* get_marker() const;

  void free_to_marker(uint32_t* previous_marker);
  void clear();
  void destroy();
};

#endif // STACK_ALLOCATOR_HPP
