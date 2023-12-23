#include <stdio.h>

struct poly
{
    int coef;
    int expo;
} p1[50], p2[50], p3[50], temp;

int main()
{
    int i, j, k, op, num1, num2, c;

    while (1)
    {
        printf("\n\n1.READ POLYNOMIAL 1\n2.READ POLYNOMIAL 2\n3.DISPLAY POLYNOMIAL 1\n4.DISPLAY POLYNOMIAL 2\n5.DISPLAY POLYNOMIAL SUM\n6.EXIT\n\nENTER THE CHOICE : ");
        scanf("%d", &op);
        printf("\n\n");

        switch (op)
        {
        case 1:
            // Read poly 1
            printf("Enter the number of terms in POLYNOMIAL 1 : ");
            scanf("%d", &num1);
            for (i = 0; i < num1; i++)
            {
                printf("Enter coefficient %d : ", i + 1);
                scanf("%d", &p1[i].coef);
                printf("Enter exponent    %d : ", i + 1);
                scanf("%d", &p1[i].expo);
            }
            // Sort poly 1
            for (i = 0; i < num1 - 1; i++)
            {
                for (j = 0; j < num1 - i - 1; j++)
                {
                    if (p1[j].expo < p1[j + 1].expo)
                    {
                        temp = p1[j];
                        p1[j] = p1[j + 1];
                        p1[j + 1] = temp;
                    }
                }
            }
            break;

        case 2:
            // Read poly 2
            printf("Enter the number of terms in POLYNOMIAL 2 : ");
            scanf("%d", &num2);
            for (i = 0; i < num2; i++)
            {
                printf("Enter coefficient %d : ", i + 1);
                scanf("%d", &p2[i].coef);
                printf("Enter exponent    %d : ", i + 1);
                scanf("%d", &p2[i].expo);
            }
            // Sort poly 2
            for (i = 0; i < num2 - 1; i++)
            {
                for (j = 0; j < num2 - i - 1; j++)
                {
                    if (p2[j].expo < p2[j + 1].expo)
                    {
                        temp = p2[j];
                        p2[j] = p2[j + 1];
                        p2[j + 1] = temp;
                    }
                }
            }
            break;

        case 3:
            // Display poly 1
            for (i = 0; i < num1; i++)
            {
                printf("%dx^%d", p1[i].coef, p1[i].expo);
                if (i < num1 - 1)
                    printf(" + ");
            }
            break;

        case 4:
            // Display poly 2
            for (i = 0; i < num2; i++)
            {
                printf("%dx^%d", p2[i].coef, p2[i].expo);
                if (i < num2 - 1)
                    printf(" + ");
            }
            break;

        case 5:
            // Calculate and display poly sum
            i = j = k = c = 0;
            while (i < num1 && j < num2)
            {
                if (p1[i].expo == p2[j].expo)
                {
                    p3[k].expo = p1[i].expo;
                    p3[k].coef = p1[i].coef + p2[j].coef;
                    i++;
                    j++;
                    k++;
                    c++;
                }
                else if (p1[i].expo > p2[j].expo)
                {
                    p3[k].coef = p1[i].coef;
                    p3[k].expo = p1[i].expo;
                    i++;
                    k++;
                    c++;
                }
                else
                {
                    p3[k].coef = p2[j].coef;
                    p3[k].expo = p2[j].expo;
                    k++;
                    j++;
                    c++;
                }
            }
            while (i < num1)
            {
                p3[k].coef = p1[i].coef;
                p3[k].expo = p1[i].expo;
                i++;
                k++;
                c++;
            }
            while (j < num2)
            {
                p3[k].coef = p2[j].coef;
                p3[k].expo = p2[j].expo;
                k++;
                j++;
                c++;
            }
            printf("\n\nResultant Polynomial : \n\n");
            for (k = 0; k < c; k++)
            {
                printf("%dx^%d", p3[k].coef, p3[k].expo);
                if (k < c - 1)
                    printf(" + ");
            }
            break;

        case 6:
            return 0;

        default:
            printf("\nEnter valid option !\n");
            break;
        }
    }
}
