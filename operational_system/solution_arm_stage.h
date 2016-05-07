#pragma once

// arm
#define ANDROID
#define VSNORD
#define ARM
#undef X86

// stage
#undef DEBUG
#undef _DEBUG
#ifdef NDEBUG
#undef NDEBUG
#endif
#define NDEBUG 1



