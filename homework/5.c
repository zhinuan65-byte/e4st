#include <stdio.h>

#define MAXN 100000

int a[MAXN];
int len = 0;
void Insert(int i, int x) {
    if (i < 1) i = 1;
    if (i > len + 1) i = len + 1;
    for (int j = len; j >= i; j--) {
        a[j] = a[j - 1];
    }
    a[i - 1] = x;
    len++;
}
void DeleteByIndex(int i) {
    if (i < 1 || i > len) return;
    for (int j = i - 1; j < len - 1; j++) {
        a[j] = a[j + 1];
    }
    len--;
}
int Find(int x) {
    for (int i = 0; i < len; i++) {
        if (a[i] == x) return i + 1;
    }
    return 0;
}
int Count(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] >= x && a[i] <= y) cnt++;
    }
    return cnt;
}
void EliminateRepeat() {
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        int repeat = 0;
        for (int j = 0; j < newLen; j++) {
            if (a[i] == a[j]) {
                repeat = 1;
                break;
            }
        }
        if (!repeat) {
            a[newLen++] = a[i];
        }
    }
    len = newLen;
}
void DeleteByRange(int x, int y) {
    int newLen = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] < x || a[i] > y) {
            a[newLen++] = a[i];
        }
    }
    len = newLen;
}
int main() {
    int m;
    scanf("%d", &m);

    while (m--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int i, x;
            scanf("%d %d", &i, &x);
            Insert(i, x);
        } else if (op == 2) {
            int i;
            scanf("%d", &i);
            DeleteByIndex(i);
        } else if (op == 3) {
            int x;
            scanf("%d", &x);
            printf("%d\n", Find(x));
        } else if (op == 4) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", Count(x, y));
        } else if (op == 5) {
            EliminateRepeat();
        } else if (op == 6) {
            int x, y;
            scanf("%d %d", &x, &y);
            DeleteByRange(x, y);
        }
    }
    for (int i = 0; i < len; i++) {
        if (i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}