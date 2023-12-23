#include <stdio.h>

int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20], vertexValues[20];

void push(int item) {
    if (top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}

int pop() {
    int k;
    if (top == -1)
        return (0);
    else {
        k = stack[top--];
        return (k);
    }
}

void add(int item) {
    if (rear == 19)
        printf("QUEUE FULL");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else
            q[++rear] = item;
    }
}

int deleteElement() {
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else {
        k = q[front++];
        return (k);
    }
}
void bfs(int s, int n) {
    int p, i;
    add(s);
    vis[s] = 1;
    while (front <= rear) {
        p = deleteElement();
        printf(" %d(%d)", p, vertexValues[p]);
        for (i = 1; i <= n; i++) {
            if (a[p][i] && !vis[i]) {
                add(i);
                vis[i] = 1;
            }
        }
    }
}

void dfs(int s, int n) {
    int i, k;
    push(s);
    vis[s] = 1;
    printf(" %d(%d) ", s, vertexValues[s]);
    while (top != -1) {
        k = stack[top];
        int flag = 0;
        for (i = 1; i <= n; i++) {
            if ((a[k][i] != 0) && (vis[i] == 0)) {
                push(i);
                vis[i] = 1;
                printf(" %d(%d) ", i, vertexValues[i]);
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            pop();
        }
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, n);
}

int main() {
    int n, i, s, ch, j;

    printf("ENTER THE NUMBER VERTICES ");
    scanf("%d", &n);

    printf("Enter values for each vertex:\n");
    for (i = 1; i <= n; i++) {
        printf("Enter value for vertex %d: ", i);
        scanf("%d", &vertexValues[i]);
    }

    printf("THE VALUES FOR EACH VERTEX ARE\n");
    for (i = 1; i <= n; i++) {
        printf(" %d(%d)", i, vertexValues[i]);
    }
    printf("\n");

    printf("Enter the adjacency matrix (1 for connected, 0 for not connected):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Is vertex %d connected to vertex %d? (1/0): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("THE ADJACENCY MATRIX IS\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    while (1) {
        for (i = 1; i <= n; i++)
            vis[i] = 0;

        printf("\nMENU");
        printf("\n1.B.F.S");
        printf("\n2.D.F.S");
        printf("\n3.EXIT");
        printf("\nENTER YOUR CHOICE");
        scanf("%d", &ch);

        if (ch == 3)
            break;
        else {
            printf("ENTER THE SOURCE VERTEX :");
            scanf("%d", &s);

            switch (ch) {
            case 1:
                bfs(s, n);
                break;
            case 2:
                dfs(s, n);
                break;
            default:
                printf("Invalid choice, please try again.\n");
            }
        }
    }
    return 0;
}
