struct Dish {
    char name[255];
    int price, qty;
    Dish *prev, *next;
}*headDish, *tailDish, *currDish;

struct Order {
    char name[255];
    int qty, price;
    Order *prev, *next;
}*newOrder, *currOrder, *delOrder;

struct Customer {
    char name[255];
    Order *headOrder, *tailOrder;
    Customer *prev, *next;    
}*headCustomer[26], *tailCustomer[26], *currCustomer;
