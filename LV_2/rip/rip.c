#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// دالة مساعدة لفحص إذا كانت السلسلة من الأقواس صحيحة
int isValid(char *s) {
    int balance = 0;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
            return 0; // غير صحيح
        }
    }
    return (balance == 0); // صحيح فقط إذا كان التوازن صفر
}

// دالة لعرض جميع الاحتمالات
void printAllCombinations(char *current, int pos, int n, int open, int close) {
    // إذا وصلنا إلى طول السلسلة الكامل
    if (pos == 2 * n) {
        current[pos] = '\0'; // ننهي السلسلة
        if (isValid(current)) { // نتحقق إذا كانت التركيبة صحيحة
            printf("%s\n", current);
        }
        return;
    }

    // إذا كان بإمكاننا إضافة قوس مفتوح '('
    if (open < n) {
        current[pos] = '(';
        printAllCombinations(current, pos + 1, n, open + 1, close);
    }

    // إذا كان بإمكاننا إضافة قوس مغلق ')'
    if (close < open) {
        current[pos] = ')';
        printAllCombinations(current, pos + 1, n, open, close + 1);
    }
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("الاستخدام: %s \"سلسلة_الأقواس\"\n", argv[0]);
        return 1;
    }
    char *input = argv[1];
    int open = 0, close = 0;

    // نعد عدد الأقواس المفتوحة والمغلقة في المدخل
    for (int i = 0; input[i]; i++) {
        if (input[i] == '(') {
            open++;
        } else if (input[i] == ')') {
            close++;
        } else {
            printf("خطأ: المدخل يجب أن يحتوي فقط على '(' و ')'\n");
            return 1;
        }
    }

    // نتحقق أن عدد الأقواس متساو
    if (open != close) {
        printf("خطأ: عدد الأقواس المفتوحة يجب أن يساوي المغلقة\n");
        return 1;
    }

    int totalPairs = open;
    char *combination = malloc(2 * totalPairs + 1); // نخصص مكان للسلسلة

    printf("جميع الترتيبات الصحيحة الممكنة:\n");
    printAllCombinations(combination, 0, totalPairs, 0, 0);

    free(combination); // نحرر الذاكرة
    return 0;
}