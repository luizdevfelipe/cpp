#include <stdio.h>

int main(void) {
    int n[] = {5, 1};

    printf("%p\n", &n[0]);
    printf("%p\n", &n[1]);
}