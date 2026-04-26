#include "include/stack_allocator.hpp"
#include <cstdlib>

stack_allocator::stack_allocator(uint32_t stack_size_bytes)
  : total_size_(stack_size_bytes)
{
  root_marker_ = (uint32_t*)malloc(stack_size_bytes);
  end_marker_  = root_marker_;
}

void* stack_allocator::alloc(uint32_t size_bytes)
{
  size_t alignment = alignof(uintptr_t);
  uintptr_t currentPtr = reinterpret_cast<uintptr_t>(end_marker_);
  uintptr_t mask = alignment - 1;
  uintptr_t misalignment = currentPtr & mask;
  uintptr_t adjustment = (misalignment == 0) ? 0 : (alignment - misalignment);

  if (end_marker_ + adjustment + size_bytes > end_marker_ + total_size_) {
      return nullptr; // Out of memory
  }

  uint8_t* alignedPtr = (uint8_t*) end_marker_ + adjustment;
  end_marker_ = (uint32_t*)alignedPtr + size_bytes;
  return alignedPtr;
}


uint32_t* stack_allocator::get_marker() const
{
  return end_marker_;
}

void stack_allocator::free_to_marker(uint32_t* previous_marker)
{
  if (previous_marker >= root_marker_ && previous_marker <= end_marker_) {
      end_marker_ = previous_marker;
  }
}

void stack_allocator::clear()
{
  end_marker_ = root_marker_;
}

void stack_allocator::destroy()
{
  free(root_marker_);
}
