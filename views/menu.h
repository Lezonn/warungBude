#include "../models/model.h"
#include "../controllers/utils.h"
#include "../controllers/controller.h"

int dishCount=0;

void addDish () {
    char name[64];
    int qty, price;
    do {
        printf("Insert the name of the dish [Lowercase letters]: ");
        scanf("%[^\n]", name); getchar();
    } while(validateName(name));
    
    do {
        printf("Insert the price of the dish [1000..50000]: ");
        scanf("%d", &price); getchar();
    } while(validatePrice(price));

    do {
        printf("Insert the quantity of the dish [1..999]: ");
        scanf("%d", &qty); getchar();
    } while(validateQty(qty));

    pushDish(name, qty, price);
    dishCount++;
    puts("The dish has benn added!");
    pressEnter();
    clrscr();
}

void removeDish() {
    char name[255];
    currDish = headDish;
    if(!currDish) {
        puts("No dish yet..");
        pressEnter();
    } else {
        int num=1;
        puts("Bude's Menu");
        puts("==============================================");
        printf("%-3s %-25s %-10s %-10s\n", "No.", "Name", "Quantity", "Price");
        while(currDish) {
            printf("%-2d. %-25s %03d        Rp%d\n", num, currDish->name, currDish->qty, currDish->price);
            currDish = currDish->next;
            num++;
        }
        do {
            printf("Insert dish's name to be deleted: ");
            scanf("%[^\n]", name); getchar();
        } while(validateDish(name));
        dishCount--;
        puts("The dish has been removed!");
        pressEnter();
    }
}

void addCustomer() {
    char name[32];
    do {
        printf("Insert the customer's name [Without space]: ");
        scanf("%[^\n]", name); getchar();
    } while(validateCustomer(name));
    insertCustomer(name);
    puts("Customer has been added!");
    pressEnter();
}

void searchCustomer() {
    char name[32];
    do {
        printf("Insert the customer's name to be searched: ");
        scanf("%[^\n]", name); getchar();
    } while(validateCustomer(name));
    if(!searchCust(name)) {
        printf("%s is present.\n", name);
    } else {
        printf("%s is not present.\n", name);
    }
    pressEnter();
}

void viewWarteg() {
    bool check = false;
    for(int i = 0; i < 26; i++) {
        if(headCustomer[i]) check = true;
    }
    if(check) {
        puts("Customer's List");
        viewCustomer();
    } else {
        puts("No customer yet..");
    }
    pressEnter();
}

void order() {
    char name[32], order[32];
    int amount, qty;
    bool check = false;
    for(int i = 0; i < 26; i++) {
        if(headCustomer[i]) check = true;
    }
    if(check && headDish) {
        do {
            printf("Insert the customer's name: ");
            scanf("%[^\n]", name); getchar();
        } while(searchCust(name));
        do {
            printf("Insert the amount of dish: ");
            scanf("%d", &amount); getchar();
        } while(amount < 1 || amount > dishCount);
        for(int i = 1; i <= amount; i++) {
            do {
                printf("[%d] Insert the dish's name and quantity: ", i);
                scanf("%[^x]x%d", order, &qty); getchar();
                order[strlen(order)-1] = '\0';
            } while(validateOrder(order, qty));
        }
        pushOrderCustomer(order, qty);
        puts("Order success!");
    } else if(!check) {
        printf("No customer yet..\n");
    } else {
        printf("No dish yet..\n");
    }
    pressEnter();
}

void payment() {
    char name[32];
    int idx;
    bool check = false;
    for(int i = 0; i < 26; i++) {
        if(headCustomer[i]) check = true;
    }
    if(check) {
        do {
            printf("Insert the customer's index: ");
            scanf("%d", &idx); getchar();
        } while(validateIdx(idx));
        puts("");
        do {
            scanf("%[^\n]", name); getchar();
        } while(validatePayment(name, idx));
    } else {
        printf("No customer yet..\n");
    }
    pressEnter();
}

void mainMenu() {
    int n;
    do {
        printf("System: %s\n", detectOS());
        getTime();
        puts("1. Add Dish");
        puts("2. Remove Dish");
        puts("3. Add Customer");
        puts("4. Search Customer");
        puts("5. View Warteg");
        puts("6. Order");
        puts("7. Payment");
        puts("8. Exit Warteg");
        do {
            printf(">> ");
            scanf("%d", &n);
            getchar();
        } while (n < 1 || n > 8);
        switch(n) {
            case 1:
                clrscr();
                addDish();
                clrscr();
                break;
            case 2:
                clrscr();
                removeDish();
                clrscr();
                break;
            case 3:
                clrscr();
                addCustomer();
                clrscr();
                break;
            case 4:
                clrscr();
                searchCustomer();
                clrscr();
                break;
            case 5:
                clrscr();
                viewWarteg();
                clrscr();
                break;
            case 6:
                clrscr();
                order();
                clrscr();
                break;
            case 7:
                clrscr();
                payment();
                clrscr();
                break;
            case 8:
                clrscr();
                puts("Please expand your terminal to full screen!");
                pressEnter();
                clrscr();
                splashScreen();
        }
    } while(n != 8);
}

