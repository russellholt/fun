#include <stdio.h>

/*
struct position {
    int left, top, width, height;
};
*/


int main() {

    int a[5][5] = {{100, 100, 100, 100, 100},
                   {100, 16, -10, 0, 100},
                   {100, -3, 17, 0, 100},
                   {100, 0, -1, 0, 100},
                   {100, 100, 100, 100, 100}};

    int width, height, left, top, i, j;
    int columns = 3, rows = 3, maxsum, sum;

    int mtop, mleft, mheight, mwidth;

    maxsum=0;

    printf("a[1][1] = %d\n", a[1][1]);

    for (width = 1; width <= rows; width++) {
        for (height = 1; height <= columns; height++) {
            printf("%d,%d = %d\n", width, height, a[width][height]);

            for (left=1; left <= columns-width + 1; left++) {
                for (top=1; top <= rows - height + 1; top++) {
                    sum=0;
                    printf(" %d,%d", left, top);

                    for (i=left; i <= left+width-1; i++) {
                        for(j=top; j <= top+height-1; j++) {
                            sum = sum + a[i][j];
                            if (sum > maxsum) {
                                maxsum = sum;
                                mleft=left;
                                mtop = top;
                                mheight=height;
                                mwidth=width;
                            }
                        }
                    }
                }
            }
            printf("\n");

        }
    }

    printf("\n\nMAX SUM: %d\n", maxsum);
    printf("at (%d, %d) %d, %d\n", mtop, mleft, mwidth, mheight);




    /*
       if we were a function.. we could:

        struct postion x = { mtop, mleft, mwidth, mheight };
        return x;
    */
}



