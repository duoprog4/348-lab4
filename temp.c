#include <stdio.h>
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
void categorize_temperature(float celsius) {
        if (celsius < 0) {
            printf("freezing, stay indoors");
        }
        if (celsius >= 0 && celsius < 10) {
            printf("cold, wear a jacket");
        }
        if (celsius >= 10 && celsius < 25) {
            printf("comfortable, have fun!");
        }
        if (celsius >= 25 && celsius < 35) {
            printf("Hot, wear something cool");
        }
        if (celsius >= 35) {
            printf("extreme heat, stay indoors");
        }
}
int main() {
    int loop = 1;

    while (loop) {

    printf("enter temperature: ");
    float temp;
    if (scanf(" %f", &temp) != 1){
        printf("invalid input, enter a number\n");
        while (getchar() != '\n');
        continue;
    }
    float celsius;
    printf("enter temperature type: (f for fahrenheit, c for celsius, k for kelvin): ");
    char temp_type;
    scanf(" %c", &temp_type);
    if (temp_type == 'c') {
        celsius = temp;
    } else if (temp_type == 'f') {
        celsius = fahrenheit_to_celsius(temp);
    } else if (temp_type == 'k') {
        celsius = kelvin_to_celsius(temp);
        if (temp < 0) {
            printf("invalid input, kelvin cannot be negative\n");
            while (getchar() != '\n');
            continue;
        }
    } else {
        printf("not a valid temp unit\n");
        while (getchar() != '\n');
        continue;
    }
    printf("convert temp to : (f for fahrenheit, c for celsius, k for kelvin): ");
    char temp_convert;
    scanf(" %c", &temp_convert);
    if (temp_type == temp_convert){
        printf("invalid input, cant convert to same unit\n");
        while (getchar() != '\n');
        continue;
    }
    if (temp_convert == 'c') {
        printf("temperature in celsius: %.2f\n", celsius);
    } else if (temp_convert == 'f') {
        printf("temperature in fahrenheit: %.2f\n", celsius_to_fahrenheit(celsius));
    } else if (temp_convert == 'k') {
        printf("temperature in kelvin: %.2f\n", celsius_to_kelvin(celsius));
    } else {
        printf("not a valid temp unit");
        while (getchar() != '\n');
        continue;
    }
    categorize_temperature(celsius);
    loop=0;
}
    return 0;
}