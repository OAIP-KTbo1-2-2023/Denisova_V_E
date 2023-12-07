#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

int main() {
    FILE* f_in, * f_out;
    fopen_s(&f_in, "in.txt", "r");
    fopen_s(&f_out, "out.txt", "w");

    char str[500], p;
    int k = 0;
    if (!f_in , !f_out) { 
        printf("error"); 
    }
    else {
        while (fgets(str, 500, f_in) != NULL) {
            for (int i = 0; i < sizeof(str); i++) {
                if ((str[i] == ' ') || (str[i] == 0)) {
                    p = str[i - 1];
                    str[i - 1] = str[i - k];
                    str[i - k] = p;
                    k = 0;
                }
                else {
                    k++;
                }
            }
            fputs(str, f_out);
        }
    }
    printf("Program completed");
    fclose(f_in);
    fclose(f_out);
}