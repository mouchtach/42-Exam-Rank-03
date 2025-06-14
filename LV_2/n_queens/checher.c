#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_solution(int *queens, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queens[i] == queens[j] || abs(i - j) == abs(queens[i] - queens[j])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n); // Read board size (first line)
    getchar(); // Consume newline

    int *queens = malloc(n * sizeof(int));
    if (!queens) {
        fprintf(stderr, "Memory error\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), stdin)) {
        int idx = 0;
        char *token = strtok(line, " ");
        while (token && idx < n) {
            queens[idx++] = atoi(token);
            token = strtok(NULL, " ");
        }

        if (idx != n) {
            fprintf(stderr, "Invalid input format\n");
            continue;
        }

        if (is_valid_solution(queens, n)) {
            printf("✅ Valid: ");
        } else {
            printf("❌ Invalid: ");
        }
        for (int i = 0; i < n; i++) {
            printf("%d ", queens[i]);
        }
        printf("\n");
    }

    free(queens);
    return 0;
}