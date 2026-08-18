#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int adj_mat[5000][5000];
int in_Deg[5000], out_Deg[5000];
int main()
{
    srand(time(0));
    int n, i, j;
    long sum_In = 0, sum_Out = 0;
    clock_t start_time, end_time;
    double timeMs;

    printf("Enter vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] =  rand()% 2;
        }
    }
    for (i = 0; i < n; i++)
    {
        in_Deg[i] = 0;
        out_Deg[i] = 0;
    }
    start_time = clock();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (adj_mat[i][j] == 1)
            {
                out_Deg[i]++;
                in_Deg[j]++;
            }
        }
    }
   end_time = clock();
    for (i = 0; i < n; i++)
    {
        sum_In += in_Deg[i];
        sum_Out += out_Deg[i];
    }
    printf("Sum of In-Degrees  = %ld\n", sum_In);
    printf("Sum of Out-Degrees = %ld\n", sum_Out);
    if (sum_In == sum_Out)
        printf("Proved that, Sum of in-degrees = Sum of out-degrees\n");
    else
        printf("Sorry, Sums do not match\n");
    timeMs = ((double)(end_time - start_time) * 1000.0) / CLOCKS_PER_SEC;
    printf("Computational time = %.3f ms\n", timeMs);
    return 0;
}
