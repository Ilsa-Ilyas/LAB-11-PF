#include <stdio.h>
#include <string.h>

struct Invoice {
    char partNumber[20];
    char partDescription[100];
    int quantity;
    float pricePerItem;
};

float calculateInvoiceAmount(struct Invoice inv) {
    if (inv.quantity < 0) inv.quantity = 0;
    if (inv.pricePerItem < 0) inv.pricePerItem = 0;
    return inv.quantity * inv.pricePerItem;
}

int main() {
    struct Invoice inv = {"1234", "Hammer", 5, 25.5};
    printf("Part Number: %s\nDescription: %s\nQuantity: %d\nPrice per Item: %.2f\n",
           inv.partNumber, inv.partDescription, inv.quantity, inv.pricePerItem);
    printf("Invoice Amount: %.2f\n", calculateInvoiceAmount(inv));

    return 0;
}