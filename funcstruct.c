#include <stdio.h>

struct Point {
    int x, y;
};

struct Point getOrigin() {
    struct Point p;
    p.x = 0;
    p.y = 0;
    return p;
}

int main() {
    struct Point origin = getOrigin();
    printf("Origin: (%d, %d)\n", origin.x, origin.y);
    return 0;
}
