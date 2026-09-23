#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
};

struct Node *head = NULL;
int len = 0;

void Insert(int i, int x) {
    if (i < 1) i = 1;
    if (i > len + 1) i = len + 1;

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = x;

    if (i == 1) {
        newNode->next = head;
        head = newNode;
        len++;
        return;
    }

    struct Node *p = head;
    for (int k = 1; k < i - 1 && p != NULL; k++) {
        p = p->next;
    }

    newNode->next = (p == NULL) ? NULL : p->next;
    if (p == NULL) {
        // If insertion position is beyond list length, append to tail.
        struct Node *tail = head;
        while (tail != NULL && tail->next != NULL) tail = tail->next;
        if (tail == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        newNode->next = NULL;
    } else {
        p->next = newNode;
    }
    len++;
}

void DeleteByIndex(int i) {
    if (i < 1 || i > len || head == NULL) return;

    if (i == 1) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        len--;
        return;
    }

    struct Node *p = head;
    for (int k = 1; k < i - 1 && p->next != NULL; k++) {
        p = p->next;
    }

    struct Node *del = p->next;
    p->next = del->next;
    free(del);
    len--;
}

int Find(int x) {
    struct Node *p = head;
    int pos = 1;
    while (p != NULL) {
        if (p->val == x) return pos;
        p = p->next;
        pos++;
    }
    return 0;
}

int Count(int x, int y) {
    struct Node *p = head;
    int cnt = 0;
    while (p != NULL) {
        if (p->val >= x && p->val <= y) cnt++;
        p = p->next;
    }
    return cnt;
}

void EliminateRepeat() {
    struct Node *cur = head;
    while (cur != NULL) {
        struct Node *p = head;
        struct Node *pre = NULL;
        while (p != cur) {
            if (p->val == cur->val) {
                if (pre == NULL) {
                    head = cur;
                } else {
                    pre->next = cur;
                }
                break;
            }
            pre = p;
            p = p->next;
        }

        if (p == cur) {
            cur = cur->next;
            continue;
        }

        struct Node *del = cur;
        cur = cur->next;
        if (pre == NULL) {
            head = cur;
        } else {
            pre->next = cur;
        }
        free(del);
    }
}

void DeleteByRange(int x, int y) {
    while (head != NULL && head->val >= x && head->val <= y) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        len--;
    }

    struct Node *p = head;
    while (p != NULL && p->next != NULL) {
        if (p->next->val >= x && p->next->val <= y) {
            struct Node *temp = p->next;
            p->next = temp->next;
            free(temp);
            len--;
        } else {
            p = p->next;
        }
    }
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

    return 0;
}
