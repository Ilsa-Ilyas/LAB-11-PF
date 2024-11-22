#include <stdio.h>

struct Phone {
    int areaCode;
    int exchange;
    int number;
};

int main() {
    struct Phone myNumber = {212, 767, 8900};
    struct Phone yourNumber;

    printf("Enter your area code: ");
    scanf("%d", &yourNumber.areaCode);
    printf("Enter your exchange: ");
    scanf("%d", &yourNumber.exchange);
    printf("Enter your number: ");
    scanf("%d", &yourNumber.number);

    printf("My number is (%d) %d-%d\n", myNumber.areaCode, myNumber.exchange, myNumber.number);
    printf("Your number is (%d) %d-%d\n", yourNumber.areaCode, yourNumber.exchange, yourNumber.number);
    return 0;
}

