/* NAME       : ADITHYADEV
 * CLASS      : S3 DS
 * ROLL NO    : 5
 * DATE       : 19/09/2023
 * EXPERIMENT : 1 */
 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int op = 0, i, j, k;
    int row1 = 0, colo1 = 0, row2 = 0, colo2 = 0;
    int a[20][20], atup[20][20], b[20][20], btup[20][20];
    int atuptrans[20][20], btuptrans[20][20], sumtup[20][20];
    int nonzero1 = 0, nonzero2 = 0;

    while (op == 0 || op == 1 || op == 2 || op == 3 || op == 4 || op == 5)
    {
        printf("\n1. ENTER MATRIX 1 & 2\n2. PRINT MATRIX 1 & 2\n3. PRINT MATRIX 1 & 2 - TUPLE FORM\n4. PRINT MATRIX 1 & 2 - TRANSPOSE\n5. PRINT MATRIX 1 + 2 - ADDITION\n6. EXIT\n\nEnter the choice : ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:

            printf("\nMATRIX 1 : \n");
            printf("Enter the number of rows    : ");
            scanf("%d", &row1);
            printf("Enter the number of colomns : ");
            scanf("%d", &colo1);

            k = 1;
            for (i = 0; i < row1; i++)
            {
                for (j = 0; j < colo1; j++)
                {
                    printf("Enter the element [%d][%d] : ", i, j);
                    scanf("%d", &a[i][j]);
                    if (a[i][j] != 0)
                    {
                        nonzero1++;
                        atup[k][0] = i;
                        atup[k][1] = j;
                        atup[k][2] = a[i][j];
                        k++;
                    }
                }
            }

            atup[0][0] = row1;
            atup[0][1] = colo1;
            atup[0][2] = nonzero1;

            printf("\nMATRIX 2 : \n");
            printf("Enter the number of rows    : ");
            scanf("%d", &row2);
            printf("Enter the number of colomns : ");
            scanf("%d", &colo2);

            k = 1;
            for (i = 0; i < row2; i++)
            {
                for (j = 0; j < colo2; j++)
                {
                    printf("Enter the element [%d][%d] : ", i, j);
                    scanf("%d", &b[i][j]);
                    if (b[i][j] != 0)
                    {
                        nonzero2++;
                        btup[k][0] = i;
                        btup[k][1] = j;
                        btup[k][2] = b[i][j];
                        k++;
                    }
                }
            }

            btup[0][0] = row2;
            btup[0][1] = colo2;
            btup[0][2] = nonzero2;

            break;

        case 2:

            printf("\nMATRIX 1 : \n\n");
            for (i = 0; i < row1; i++)
            {
                for (j = 0; j < colo1; j++)
                {
                    printf("%d\t", a[i][j]);
                }
                printf("\n");
            }

            printf("\nMATRIX 2 : \n\n");
            for (i = 0; i < row2; i++)
            {
                for (j = 0; j < colo2; j++)
                {
                    printf("%d\t", b[i][j]);
                }
                printf("\n");
            }
            break;

        case 3:

            printf("\nMATRIX 1 - TUPLE FORM : \n\n");
            for (i = 0; i <= nonzero1; i++)
            {
                printf("%d\t%d\t%d\n", atup[i][0], atup[i][1], atup[i][2]);
            }

            printf("\nMATRIX 2 - TUPLE FORM : \n\n");
            for (i = 0; i <= nonzero2; i++)
            {
                printf("%d\t%d\t%d\n", btup[i][0], btup[i][1], btup[i][2]);
            }
            break;

        case 4:

            atuptrans[0][0] = atup[0][1];
            atuptrans[0][1] = atup[0][0];
            atuptrans[0][2] = atup[0][2];
            k = 1;

            for (i = 0; i < atup[0][1]; i++)
            {
                for (j = 1; j <= atup[0][2]; j++)
                {
                    if (atup[j][1] == i)
                    {
                        atuptrans[k][0] = atup[j][1];
                        atuptrans[k][1] = atup[j][0];
                        atuptrans[k][2] = atup[j][2];
                        k++;
                    }
                }
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d\t", atuptrans[i][j]);
                }
                printf("\n");
            }

            printf("\n\n");

            btuptrans[0][0] = btup[0][1];
            btuptrans[0][1] = btup[0][0];
            btuptrans[0][2] = btup[0][2];
            k = 1;

            for (int i = 0; i < btup[0][1]; i++)
            {
                for (int j = 1; j <= btup[0][2]; j++)
                {
                    if (btup[j][1] == i)
                    {
                        btuptrans[k][0] = btup[j][1];
                        btuptrans[k][1] = btup[j][0];
                        btuptrans[k][2] = btup[j][2];
                        k++;
                    }
                }
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("%d\t", btuptrans[i][j]);
                }
                printf("\n");
            }
            break;

        case 5:
            i = 1;
            j = 1;
            k = 1;

            if (atup[0][0] != btup[0][0] || atup[0][1] != btup[0][1])
            {
                printf("MATRIX ADDITION NOT POSSIBLE ! \n");
            }

            sumtup[0][0] = atup[0][0];
            sumtup[0][1] = atup[0][1];

            while (i <= atup[0][2] && j <= btup[0][2])
            {
                if (atup[i][0] < btup[j][0] || (atup[i][0] == btup[j][0] && atup[i][1] < btup[j][1]))
                {
                    sumtup[k][0] = atup[i][0];
                    sumtup[k][1] = atup[i][1];
                    sumtup[k][2] = atup[i][2];
                    i++;
                    k++;
                }
                else if (atup[i][0] > btup[j][0] || (atup[i][0] == btup[j][0] && atup[i][1] > btup[j][1]))
                {
                    sumtup[k][0] = btup[j][0];
                    sumtup[k][1] = btup[j][1];
                    sumtup[k][2] = btup[j][2];
                    j++;
                    k++;
                }
                else
                {
                    if ((atup[i][2] + btup[j][2]) != 0)
                    {
                        sumtup[k][0] = atup[i][0];
                        sumtup[k][1] = atup[i][1];
                        sumtup[k][2] = atup[i][2] + btup[j][2];
                        i++;
                        j++;
                        k++;
                    }
                    else
                    {
                        i++;
                        j++;
                    }
                }
            }

            while (i <= atup[0][2])
            {
                sumtup[k][0] = atup[i][0];
                sumtup[k][1] = atup[i][1];
                sumtup[k][2] = atup[i][2];
                i++;
                k++;
            }
            while (j <= btup[0][2])
            {
                sumtup[k][0] = btup[j][0];
                sumtup[k][1] = btup[j][1];
                sumtup[k][2] = btup[j][2];
                j++;
                k++;
            }

            sumtup[0][2] = k - 1;
            printf("\nMATRIX SUM : \n\n");
            for (i = 0; i < k; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    printf("%d\t", sumtup[i][j]);
                }
                printf("\n");
            }
            break;
        
        case 6:
            exit(0);
        }
    }
    return 0;
}
