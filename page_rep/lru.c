#include<stdio.h>

void main() {
    int n, f, in[90], out[90], fl[90], c[90], pf = 0, x = 1, min = 0;

    printf("Enter the length of integer string:\t");
    scanf("%d", &n);

    printf("Enter the integers:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        fl[i] = 0;
    }

    printf("Enter the number of frames:\t");
    scanf("%d", &f);

    for(int i = 0; i < f; i++) {
        out[i] = -1;
        c[i] = 0;
    }

    for(int i = 0; i < n; i++) {
        int j;
        for(j = 0; j < f; j++) {
            if(out[j] == in[i]) {
                c[j] = x++;
                break;
            }
        }

        if(j == f) {
            if(i < f) {
                out[i] = in[i];
                c[i] = x++;
            } else {
                int min_index = 0;
                for(int j = 1; j < f; j++) {
                    if(c[j] < c[min_index]) {
                        min_index = j;
                    }
                }
                out[min_index] = in[i];
                c[min_index] = x++;
            }
            pf++;
        }

        for(int j = 0; j < f; j++) {
            printf("%d\t", out[j]);
        }
        printf("\tPage faults:%d\n", pf);
    }
}