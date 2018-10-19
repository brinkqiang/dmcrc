
#ifndef __DMCRC_H_INCLUDE__
#define __DMCRC_H_INCLUDE__

#include <dmtypes.h>
#include <string>

uint32_t UpdateCRC32(uint32_t initial, const void* buf, size_t len);

inline uint32_t GetCRC32(const void* buf, size_t len) {
  return UpdateCRC32(0, buf, len);
}

inline uint32_t GetCRC32(const std::string& str) {
  return GetCRC32(str.c_str(), str.size());
}

#endif // __DMCRC_H_INCLUDE__
