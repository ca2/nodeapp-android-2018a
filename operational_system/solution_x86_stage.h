#pragma once

// x86
#define ANDROID
#define VSNORD
#undef ARM
#define X86

// stage
#undef DEBUG
#undef _DEBUG
#ifdef NDEBUG
#undef NDEBUG
#endif
#define NDEBUG 1



