// based on http://burtleburtle.net/bob/rand/smallprng.html
// by Bob Jenkins, effectively CC0

#include <stdint.h>

typedef uint32_t u4;
typedef struct jsf_ctx { u4 a; u4 b; u4 c; u4 d; } jsf_ctx;

#define rot(x,k) (((x)<<(k))|((x)>>(32-(k))))

u4 jsf_val( jsf_ctx *x ) {
    u4 e = x->a - rot(x->b, 27);
    x->a = x->b ^ rot(x->c, 17);
    x->b = x->c + x->d;
    x->c = x->d + e;
    x->d = e + x->a;
    return x->d;
}

void jsf_init( jsf_ctx *x, u4 seed ) {
    u4 i;
    x->a = 0xf1ea5eed, x->b = x->c = x->d = seed;
    for (i=0; i<20; ++i) {
        (void)jsf_val(x);
    }
}
