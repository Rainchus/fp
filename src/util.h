#ifndef UTIL_H
#define UTIL_H
#include <stdint.h>
#include <mips.h>
#include <n64.h>
#include <startup.h>

/* set irq bit and return previous value */
static inline s32 set_irqf(s32 irqf) {
    u32 sr;

    __asm__("mfc0    %[sr], $12;" : [sr] "=r"(sr));
    s32 old_irqf = sr & MIPS_STATUS_IE;

    sr = (sr & ~MIPS_STATUS_IE) | (irqf & MIPS_STATUS_IE);
    __asm__("mtc0    %[sr], $12;" ::[sr] "r"(sr));

    return old_irqf;
}

static inline s32 get_irqf(void) {
    u32 sr;

    __asm__("mfc0    %[sr], $12;" : [sr] "=r"(sr));

    return sr & MIPS_STATUS_IE;
}

static inline void dcache_inv(const void *ptr, size_t len) {
    uintptr_t p = (uintptr_t)ptr & ~0xF;
    uintptr_t e = (uintptr_t)ptr + len;
    while (p < e) {
        __asm__("cache   0x11, 0x0000(%[p]);" ::[p] "r"(p));
        p += 0x10;
    }
}

static inline void dcache_wbinv(const void *ptr, size_t len) {
    uintptr_t p = (uintptr_t)ptr & ~0xF;
    uintptr_t e = (uintptr_t)ptr + len;
    while (p < e) {
        __asm__("cache   0x15, 0x0000(%[p]);" ::[p] "r"(p));
        p += 0x10;
    }
}

static inline void dcache_wb(const void *ptr, size_t len) {
    uintptr_t p = (uintptr_t)ptr & ~0xF;
    uintptr_t e = (uintptr_t)ptr + len;
    while (p < e) {
        __asm__("cache   0x19, 0x0000(%[p]);" ::[p] "r"(p));
        p += 0x10;
    }
}

/* safe (non-signaling) nan check */
static inline _Bool is_nan(f32 f) {
    u32 exp_mask = 0b01111111100000000000000000000000;
    u32 sig_mask = 0b00000000011111111111111111111111;
    union {
        u32 w;
        f32 f;
    } pun;
    pun.f = f;
    return (pun.w & exp_mask) == exp_mask && (pun.w & sig_mask) != 0;
}

static inline void maybe_init_gp(void) {
#ifndef NO_GP
    init_gp();
#endif
}

#ifdef NDEBUG
#define PRINTF(...) ((void)0)
#else
#define PRINTF(...) (osSyncPrintf(__VA_ARGS__))
#endif

#define ARRAY_LENGTH(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

#endif
