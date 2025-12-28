#include <cstdint>

struct frame
{
    uint64_t width, height;
    void* data;
};