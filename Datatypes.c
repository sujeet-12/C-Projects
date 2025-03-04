#include <stdio.h>

int main() {
    int i;
    float f;
    double d;
    char c;
    long l;
    short s;
    unsigned int ui;
    long long ll;
    
    scanf("%d %f %lf %c %ld %hd %u %lld", &i, &f, &d, &c, &l, &s, &ui, &ll);
    
    printf("%d\n", i);
    printf("%f\n", f);
    printf("%lf\n", d);
    printf("%c\n", c);
    printf("%ld\n", l);
    printf("%hd\n", s);
    printf("%u\n", ui);
    printf("%lld\n", ll);
    
    return 0;
}
