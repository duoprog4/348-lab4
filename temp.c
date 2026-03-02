#include <stdio.h>t
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
        if (celsius >= 10 && celsius < 20) {
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
    printf("enter temperature: ");
    int temp;
    scanf("%d", &temp);
    printf("enter temperature type: (f for fahrenheit, c for celsius, k for kelvin): ");
    char temp_type[1];
    scanf("%s", temp_type);
    printf("convert temp to : (f for fahrenheit, c for celsius, k for kelvin): ");
    char temp_convert[1];
    scanf("%s", temp_convert);
    float celsius;
    if (temp_type[0] == 'c' && temp_convert[0] == 'f') {
        printf("temperature in fahrenheit: %f", celsius_to_fahrenheit(temp));
        celsius = temp;
    } else if (temp_type[0] == 'f' && temp_convert[0] == 'c') {
        printf("temperature in celsius: %f", fahrenheit_to_celsius(temp));
        celsius = fahrenheit_to_celsius(temp);
    } else if (temp_type[0] == 'c' && temp_convert[0] == 'k') {
        printf("temperature in kelvin: %f", celsius_to_kelvin(temp));
        celsius = temp;
    } else if (temp_type[0] == 'k' && temp_convert[0] == 'c') {
        printf("temperature in celsius: %f", kelvin_to_celsius(temp));
        celsius = kelvin_to_celsius(temp);
    } else {
        printf("invalid input");
        return 0;
    }
    categorize_temperature(celsius);
     return 0;
}