#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <errno.h>

bool hasDuplicateDigits(int num) {
    int digitCount[10] = {0};

    while (num > 0) {
        int digit = num % 10;
        if (digitCount[digit] > 0) {
            return true;
        }
        digitCount[digit]++;
        num /= 10;
    }

    return false;
}

bool isValidNumber(char *str) {
    while (*str) {
        if (*str < '0' || *str > '9') {
            return false;
        }
        str++;
    }
    return true;
}

bool isWithinIntRange(char *str) {
    errno = 0;
    int val = (int)strtol(str, NULL, 10);
    return !(errno == ERANGE && (val == INT_MAX || val == INT_MIN));
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        printf("Please provide numbers as command line arguments.\n");
        return 1;
    }

    int count = 0;

    for (int i = 1; i < argc; i++) {
        if (!isValidNumber(argv[i])) {
            printf("Invalid input: '%s' is not a valid number.\n", argv[i]);
            continue;
        }

        if (!isWithinIntRange(argv[i])) {
            printf("Input '%s' is not within the range of int.\n", argv[i]);
            continue;
        }

        int num = atoi(argv[i]);
        if (!hasDuplicateDigits(num)) {
            count++;
        }
    }

    printf("The number of numbers without duplicate digits is: %d\n", count);

    return 0;
}