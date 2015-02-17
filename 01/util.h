#define sbi(x,y) x |= 1 << y
#define cbi(x,y) x &= ~(1 << y)
#define is_high(x,y) (x & _BV(y)) == 1 << y
#define tbi(x,y) x ^= 1 << y
