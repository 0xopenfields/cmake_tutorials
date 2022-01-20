#include <stdio.h>

#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"

int main(int argc, char** argv) {
    printf("5 + 3 = %d\n", add(5, 3));
    printf("10 - 7 = %d\n", sub(10, 7));
    printf("3 * 8 = %f\n", mul(3.f, 8.f));
    printf("13 / 3 = %f\n", div(13.f, 3.f));

    return 0;
}