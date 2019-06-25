#include <stdio.h>

void update(int *a,int *b) {
    int sum = *a + *b;
    int abs_diff = *a - *b;
    *a = sum;
    if (abs_diff < 0) abs_diff *= -1;
    *b = abs_diff;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
