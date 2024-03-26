#include <iostream>

int intLength(int num) {
    int length = 0;
    // Keep dividing the number by 10 until it becomes zero
    while (num != 0) {
        num /= 10; // Divide by 10
        length++; // Increment the length counter
    }
    return length;
}

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char* dest, const char* src) {
    int destLen = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

int stringCompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void substring(const char* str, char* sub, int start, int length) {
    int i = 0;
    while (i < length && str[start + i] != '\0') {
        sub[i] = str[start + i];
        i++;
    }
    sub[i] = '\0';
}

int stringSearch(const char* str, const char* substr) {
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    for (int i = 0; i <= strLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == subLen) {
            return i; // Substring found at index i
        }
    }
    return -1; // Substring not found
}

int stringToInt(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Handling leading whitespace
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Handling sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Converting characters to integer
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return sign * result;
}

void intToString(int num, char* str) {
    int length = intLength(num);
    int i = 0;

    // Handle negative numbers
    if (num < 0) {
        str[i++] = '-';
        num = -num;
    }

    // Convert digits to characters
    while (length > 0) {
        str[i++] = '0' + (num % 10);
        num /= 10;
        length--;
    }
    str[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    return 0;
}