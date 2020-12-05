Dish *createDish(char *name, int qty, int price) {
    Dish *newDish = (Dish*)malloc(sizeof(Dish));
    strcpy(newDish->name, name);
    newDish->price = price;
    newDish->qty = qty;
    newDish->next = newDish->prev = NULL;
    return newDish;
}

Customer *createCustomer(char *name) {
	Customer *temp = (Customer*)malloc(sizeof(Customer));
	strcpy(temp->name, name);
	temp->next = temp->prev = NULL;
    temp->headOrder = temp->tailOrder = NULL;
	return temp;
}

Order *createOrderCustomer(char *name, int qty, int price) {
    Order *newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->name, name);
    newOrder->qty = qty;
    newOrder->price = price;
    newOrder->prev = newOrder->next = NULL;
    return newOrder;
}
