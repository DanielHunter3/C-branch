#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Math {
    double x, y
};

double math_operations(struct Math object, char* string)
{
    if (strcmp(string, "+") == 0) return object.x + object.y;
    else if (strcmp(string, "-") == 0) return object.x - object.y;
    else if (strcmp(string, "*") == 0) return object.x * object.y;
    else if (strcmp(string, "/") == 0)
    {
        if (object.y == 0.0) exit(1);
        else return object.x / object.y;
    }
    else if (strcmp(string, "^") == 0) return pow(object.x, object.y);
    else exit(1);
    return 0.0;
}

 bool in_massive(char *vec[], int size, char *symbal)
{
    for (int i = 0; i < size; i++) if (strcmp(vec[i], symbal) == 0) return true;
    return false;
}

double main()
{
    double x, y;
    char string[10] = "";
    char *vector[] = {"+", "-", "*", "/", "^"};

    printf("Enter a first number: ");
    scanf("%lf", &x);
    printf("Enter a math operation: ");
    scanf("%s", string);

    bool is_bool = in_massive(vector, sizeof(vector) / sizeof(vector[0]) + 1, string);
    if (is_bool == false) return 0;

    printf("Enter a second number: ");
    scanf("%lf", &y);

    struct Math math = {x, y};
    printf("%lf", math_operations(math, string));
    return 0;
}
