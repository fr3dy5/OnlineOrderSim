#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SHIRT_PRICE 19.99
#define SHOE_PRICE 49.99
#define PANTS_PRICE 29.99

#define USA_STD_COST 5.99
#define USA_EXP_COST 9.99
#define MEX_STD_COST 7.99
#define MEX_EXP_COST 12.99
#define CAN_STD_COST 6.99
#define CAN_EXP_COST 11.99

#define USA_TAX 0.08
#define MEX_TAX 0.16
#define CAN_TAX 0.12

float tax_rate(char *ship_dest) {
    if (ship_dest[0] == 'u' || ship_dest[0] == 'U') {
        return USA_TAX;
    } else if (ship_dest[0] == 'm' || ship_dest[0] == 'M') {
        return MEX_TAX;
    } else if (ship_dest[0] == 'c' || ship_dest[0] == 'C') {
        return CAN_TAX;
    } return 0.0f;
}

float shipping(char *ship_dest, char *ship_meth) {
    if ((ship_dest[0] == 'u' || ship_dest[0] == 'U') && (ship_meth[0] == 's' || ship_meth[0] == 'S')) {
        return USA_STD_COST;
    } else if ((ship_dest[0] == 'm' || ship_dest[0] == 'M') && (ship_meth[0] == 's' || ship_meth[0] == 'S')) {
        return MEX_STD_COST;
    } else if ((ship_dest[0] == 'c' || ship_dest[0] == 'C') && (ship_meth[0] == 's' || ship_meth[0] == 'S')) {
        return CAN_STD_COST;
    } else if ((ship_dest[0] == 'u' || ship_dest[0] == 'U') && (ship_meth[0] == 'e' || ship_meth[0] == 'E')) {
        return USA_EXP_COST;
    } else if ((ship_dest[0] == 'm' || ship_dest[0] == 'M') && (ship_meth[0] == 'e' || ship_meth[0] == 'E')) {
        return MEX_EXP_COST;
    } else if ((ship_dest[0] == 'c' || ship_dest[0] == 'C') && (ship_meth[0] == 'e' || ship_meth[0] == 'E')) {
        return CAN_EXP_COST;
    }   return 0.0f; 
}

//float tax = 0;
//float final_cost = 0;

int main(void) {
    
    char userInput[20];  // Array to store user input for clothing type
    int shirtQuantity = 0, shoeQuantity = 0, pantsQuantity = 0;  // Variables to store quantities of each clothing item
    char ship_dest[20];
    char destination[20] = "";
    char method[20] = "";
    char ship_meth[20];
    float tax = 0;
    float final_cost = 0;


    do {
        printf("Enter the type of clothing needed (shirt, shoes, pants).\n");
        printf("Type 'exit' to quit and proceed to shipping details.\n");
        scanf("%s", userInput);
        

            switch (userInput[0])
            {
                case 's':
                    if (strcmp(userInput, "shirt") == 0) {
                        printf("Enter the quantity of shirts needed: ");
                        scanf("%d", &shirtQuantity);
                        printf("Clothing item 'shirt' successfully added to your cart.");
                    }
                    else if (strcmp(userInput, "shoes") == 0) {
                        printf("Enter the quantity of shoes needed: ");
                        scanf("%d", &shoeQuantity);
                        printf("Clothing item 'shoes' successfully added to your cart.");
                    }
                    else {
                        printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
                    }
                    break;
                    
                case 'p':
                    if (strcmp(userInput, "pants") == 0) {
                        printf("Enter the quantity of pants needed: ");
                        scanf("%d", &pantsQuantity);
                        printf("Clothing item 'pants' successfully added to your cart.");
                    }
                    else {
                        printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
                    }
                    break;
                /*default:
                    (strcmp(userInput, "exit") != 0); 
                    // If user input is not a valid clothing type or 'exit', display an error message and continue the loop
                    printf("Invalid clothing type. Please enter 'shirt', 'shoes', or 'pants'.\n");
                    break;*/
            } 
    }      
    while (strcmp(userInput, "exit") != 0);  // Repeat the loop until user enters 'exit'

    printf("Enter the shipping destination (USA, Mexico, Canada):\n");
    scanf("%19s", ship_dest);
    printf("Enter the shipping method (standard, expedited):\n");
    scanf("%19s", ship_meth);

    float totalCost = (shirtQuantity * SHIRT_PRICE) + (shoeQuantity * SHOE_PRICE) + (pantsQuantity * PANTS_PRICE);
    printf("Total Cost:$%.2f\n", totalCost);

   /* printf("Enter the shipping destination (USA, Mexico, Canada):%s\n", ship_dest);
    scanf("%s", &ship_dest[20]);
    printf("Enter the shipping method (standard, expedited):%s\n", ship_meth);
    scanf("%s", &ship_meth[20]);*/

    if ((strcmp(ship_dest, "USA") == 0) || ((strcmp(ship_dest, "usa") == 0))) {
        strcpy(destination, "USA");
    }
    else if ((strcmp(ship_dest, "Canada") == 0) || ((strcmp(ship_dest, "canada") == 0))) {
        strcpy(destination, "Canada");
    }
    else if ((strcmp(ship_dest, "Mexico") == 0) || ((strcmp(ship_dest, "mexico") == 0))) {
        strcpy(destination, "Mexico");
    }
    else {
        printf("Invalid shipping destination. Defaulting to USA standard shipping.\n");
        strcpy(destination, "USA");
    };

    if ((strcmp(ship_meth, "standard")) == 0) {
        strcpy(method, "standard");
    }
    else {
        strcpy(method, "expedited");
    }

    float ship_cost = shipping(ship_dest, ship_meth);
    float subtotal = (totalCost + shipping(ship_dest, ship_meth));
    //method[0] = toupper(ship_meth[0]);
    //destination[0] = toupper(ship_dest[0]);
    tax = totalCost * tax_rate(ship_dest);
    final_cost = subtotal + tax;

    // Display the formatted bill
    printf("\nClothing Item\tQuantity\tPrice\t\tTotal\n");
    printf("-------------------------------------------------------\n");
    printf("Shirts\t\t%d\t\t$%.2f\t\t$%.2f\n", shirtQuantity, SHIRT_PRICE, shirtQuantity * SHIRT_PRICE);
    printf("Shoes\t\t%d\t\t$%.2f\t\t$%.2f\n", shoeQuantity, SHOE_PRICE, shoeQuantity * SHOE_PRICE);
    printf("Pants\t\t%d\t\t$%.2f\t\t$%.2f\n", pantsQuantity, PANTS_PRICE, pantsQuantity * PANTS_PRICE);
    printf("-------------------------------------------------------\n");
    printf("Subtotal:\t\t\t\t\t$%.2f\n", subtotal);
    printf("Shipping Destination: %s\n", destination);
    printf("Shipping Method: %s to %s\n", method, destination);
    printf("Shipping Cost:\t\t\t\t\t$%.2f\n", ship_cost);
    printf("Tax (%.2f%%):\t\t\t\t\t$%.2f\n", tax_rate(ship_dest), tax);
    printf("-------------------------------------------------------\n");
    printf("Total Cost (including tax and shipping):\t$%.2f\n", final_cost);

    return 0;  // Indicate successful program execution
}
