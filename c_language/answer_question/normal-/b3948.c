#include <stdio.h>
#include <stdlib.h>
int compare(int question[][4], int answer[][4],int x,int y);

int main() {
    int n;
    scanf("%d", &n);

    int (*question)[4] = malloc((size_t)n * sizeof(int[4]));
    int (*answer)[4] = malloc((size_t)n * sizeof(int[4]));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &question[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &answer[i][j]);
        }
    }

    for (int x = 0; x < n; x++) {
        int sum = 0;
        for (int y = 0; y < n; y++) {
            int index = x + y;
            if (index >= n) {
                index -= n;
            }
            sum += compare(question, answer, index, y);
        }
        if (x != n - 1) {
            printf("%d ", sum);
        } else {
            printf("%d", sum);
        }
    }

    free(question);
    free(answer);
    return 0;
}

int compare(int question[][4], int answer[][4], int x, int y) {
    int score = 6;
    int finish=0;
    for (int i = 0; i < 4; i++) {
        if (answer[y][i] == 1) {
            finish = 1;
        }
        if (question[x][i] == 0 && answer[y][i] == 1) {
            return 0;
        } else if (question[x][i] == 1 && answer[y][i] == 0) {
            score = 3;
        }
    }
    if (finish == 0) {
        return 0;
    }
    return score;
}