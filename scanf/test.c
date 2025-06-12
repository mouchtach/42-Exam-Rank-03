#include <stdio.h>

int main() {
    int test_count = 0;
    int passed_count = 0;

    printf("=== Testing ft_scanf ===\n\n");

    // Test 1: Basic integer
    {
        printf("Test %d: Basic integer\n", ++test_count);
        int num;
        printf("Enter an integer (e.g., 42): ");
        int ret = ft_scanf("%d", &num);
        if (ret == 1) {
            printf("PASS: Scanned %d (return value %d)\n", num, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan integer (return value %d)\n", ret);
        }
    }

    // Test 2: Negative integer
    {
        printf("\nTest %d: Negative integer\n", ++test_count);
        int num;
        printf("Enter a negative integer (e.g., -123): ");
        int ret = ft_scanf("%d", &num);
        if (ret == 1) {
            printf("PASS: Scanned %d (return value %d)\n", num, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan negative integer (return value %d)\n", ret);
        }
    }

    // Test 3: Character
    {
        printf("\nTest %d: Character\n", ++test_count);
        char c;
        printf("Enter a character (e.g., 'A'): ");
        int ret = ft_scanf("%c", &c);
        if (ret == 1) {
            printf("PASS: Scanned '%c' (return value %d)\n", c, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan character (return value %d)\n", ret);
        }
    }

    // Test 4: String
    {
        printf("\nTest %d: String\n", ++test_count);
        char str[100];
        printf("Enter a string (e.g., \"hello\"): ");
        int ret = ft_scanf("%s", str);
        if (ret == 1) {
            printf("PASS: Scanned \"%s\" (return value %d)\n", str, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan string (return value %d)\n", ret);
        }
    }

    // Test 5: Mixed types
    {
        printf("\nTest %d: Mixed types\n", ++test_count);
        int num;
        char c;
        char str[100];
        printf("Enter an integer, character, and string (e.g., \"42 X hello\"): ");
        int ret = ft_scanf("%d%c%s", &num, &c, &str);
        if (ret == 3) {
            printf("PASS: Scanned %d, '%c', \"%s\" (return value %d)\n", num, c, str, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan all values (return value %d)\n", ret);
        }
    }

    // Test 6: Whitespace handling
    {
        printf("\nTest %d: Whitespace handling\n", ++test_count);
        int num1, num2;
        printf("Enter two integers separated by spaces (e.g., \"10    20\"): ");
        int ret = ft_scanf("%d%d", &num1, &num2);
        if (ret == 2) {
            printf("PASS: Scanned %d and %d (return value %d)\n", num1, num2, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan both integers (return value %d)\n", ret);
        }
    }

    // Test 7: Invalid input
    {
        printf("\nTest %d: Invalid input\n", ++test_count);
        int num;
        printf("Enter non-numeric input when expecting integer (e.g., \"abc\"): ");
        int ret = ft_scanf("%d", &num);
        if (ret == 0) {
            printf("PASS: Correctly failed to scan (return value %d)\n", ret);
            passed_count++;
        } else {
            printf("FAIL: Incorrectly scanned invalid input (return value %d)\n", ret);
        }
    }

    // Test 8: Partial match
    {
        printf("\nTest %d: Partial match\n", ++test_count);
        int num;
        char c;
        printf("Enter valid integer then invalid character (e.g., \"123 X\"): ");
        int ret = ft_scanf("%d%c", &num, &c);
        if (ret == 1) {
            printf("PASS: Correctly scanned only the integer (return value %d)\n", ret);
            passed_count++;
        } else {
            printf("FAIL: Unexpected return value %d\n", ret);
        }
    }

    // Test 9: Character with whitespace
    {
        printf("\nTest %d: Character with whitespace\n", ++test_count);
        char c;
        printf("Enter a space followed by a character (e.g., \" X\"): ");
        int ret = ft_scanf("%c", &c);
        if (ret == 1) {
            printf("PASS: Scanned '%c' (should get space character) (return value %d)\n", c, ret);
            passed_count++;
        } else {
            printf("FAIL: Couldn't scan character (return value %d)\n", ret);
        }
    }

    // Test 10: Empty string
    {
        printf("\nTest %d: Empty string input\n", ++test_count);
        char str[100];
        printf("Press Enter without typing anything: ");
        int ret = ft_scanf("%s", str);
        if (ret == 0) {
            printf("PASS: Correctly handled empty input (return value %d)\n", ret);
            passed_count++;
        } else {
            printf("FAIL: Incorrectly scanned empty input (return value %d)\n", ret);
        }
    }

    printf("\n=== Test Results ===\n");
    printf("Tests passed: %d/%d\n", passed_count, test_count);

    return 0;
}