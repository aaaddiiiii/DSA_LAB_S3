#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coeff;
    int exp;
    struct node *next;
} node;

node *head1 = NULL;
node *head2 = NULL;
node *head3 = NULL;

void insert(node **head, int coeff, int exp) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->coeff = coeff;
    new_node->exp = exp;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else if ((*head)->exp < exp) {
        new_node->next = *head;
        *head = new_node;
    } else {
        node *temp = *head;
        while (temp->next != NULL && temp->next->exp > exp)
            temp = temp->next;
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

void read_poly(node **head, int n) {
    int coeff, exp;
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &coeff);
        printf("Enter the exponent: ");
        scanf("%d", &exp);
        insert(head, coeff, exp);
    }
}

void print_poly(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

void multiply_poly(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != NULL) {
        temp2 = head2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void add_poly(node *head1, node *head2) {
    node *temp1 = head1;
    node *temp2 = head2;
    int coeff, exp;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            coeff = temp1->coeff + temp2->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            coeff = temp1->coeff;
            exp = temp1->exp;
            insert(&head3, coeff, exp);
            temp1 = temp1->next;
        } else {
            coeff = temp2->coeff;
            exp = temp2->exp;
            insert(&head3, coeff, exp);
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        coeff = temp1->coeff;
        exp = temp1->exp;
        insert(&head3, coeff, exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        coeff = temp2->coeff;
        exp = temp2->exp;
        insert(&head3, coeff, exp);
        temp2 = temp2->next;
    }
}

void add_like_terms(node **head) {
    node *temp1 = *head;
    node *temp2 = NULL;
    int coeff, exp;

    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->exp == temp2->exp) {
                coeff = temp1->coeff + temp2->coeff;
                exp = temp1->exp;
                temp1->coeff = coeff;
                temp1->exp = exp;
                temp2->coeff = 0;
                temp2->exp = 0;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

int main() {
    int n1, n2;
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Enter the first polynomial\n");
        printf("2. Enter the second polynomial\n");
        printf("3. Display the first polynomial\n");
        printf("4. Display the second polynomial\n");
        printf("5. Multiply and display the product\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms in the first polynomial: ");
                scanf("%d", &n1);
                printf("Enter the first polynomial:\n");
                read_poly(&head1, n1);
                break;

            case 2:
                printf("Enter the number of terms in the second polynomial: ");
                scanf("%d", &n2);
                printf("Enter the second polynomial:\n");
                read_poly(&head2, n2);
                break;

            case 3:
                printf("The first polynomial is: ");
                print_poly(head1);
                break;

            case 4:
                printf("The second polynomial is: ");
                print_poly(head2);
                break;

            case 5:
                multiply_poly(head1, head2);
                add_like_terms(&head3);
                printf("The product of the two polynomials is: ");
                print_poly(head3);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}

