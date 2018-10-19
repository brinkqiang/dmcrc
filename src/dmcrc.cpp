
#include "dmcrc.h"

static const uint32_t gCrc32Magic = 0xEDB88320;
static uint32_t gCrc32Table[256] = { 0 };

#define arraysize(f) (sizeof(f) / sizeof(*f))

static void CRC32TableInited() {
  if (gCrc32Table[arraysize(gCrc32Table) - 1])
    return;
  for (uint32_t i = 0; i < arraysize(gCrc32Table); ++i) {
    uint32_t c = i;
    for (size_t j = 0; j < 8; ++j) {
      if (c & 1) {
        c = gCrc32Magic ^ (c >> 1);
      } else {
        c >>= 1;
      }
    }
    gCrc32Table[i] = c;
  }
}

uint32_t UpdateCRC32(uint32_t start, const void* buf, size_t len) {
  CRC32TableInited();

  uint32_t c = start ^ 0xFFFFFFFF;
  const uint8_t* u = static_cast<const uint8_t*>(buf);
  for (size_t i = 0; i < len; ++i) {
    c = gCrc32Table[(c ^ u[i]) & 0xFF] ^ (c >> 8);
  }
  return c ^ 0xFFFFFFFF;
}

#undef arraysize