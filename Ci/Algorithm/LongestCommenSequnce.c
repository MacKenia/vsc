#include <stdio.h>
#include <stdlib.h>

void reverse(int **m, char *s, int r, int c)
{
    printf("%s\n", &s[1]);
    int i = r - 1;
        for (int j = c - 1; j > 0; j--)
            if (m[i][j] == m[i - 1][j - 1] + 1 && (m[i][j] != m[i - 1][j] || m[i][j] != m[j][j - 1]))
            {
                printf("%c", s[j]);
                if(!--i) break;
            }
    printf("\n");
}

int main()
{
    char s1[80], s2[80];
    int l1 = 1, l2 = 1;
    printf("sequence one: ");
    scanf("%s", &s1[1]);
    printf("sequence two: ");
    scanf("%s", &s2[1]);

    // get the length of each sequence
    for (int i = 1; s1[i] != '\0'; i++)
        l1++;
    for (int i = 1; s2[i] != '\0'; i++)
        l2++;

    // prepare the matrix
    int **dp = (int **)malloc(sizeof(int *) * l1);
    for (int i = 0; i < l1; i++)
        dp[i] = (int *)malloc(sizeof(int) * l2);

    // calculate the matrix
    for (int i = 1; i < l1; i++)
        for (int j = 1; j < l2; j++)
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
                
    printf("%d\n", dp[l1 - 1][l2 - 1]);
    reverse(dp, s2, l1, l2);
    return 0;
}
