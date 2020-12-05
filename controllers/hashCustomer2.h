void pushOrderCustomer(char *name, int qty) {
    currDish = headDish;
    while(currDish) {
        if(!strcmp(currDish->name, name)) {
            Order *temp = createOrderCustomer(name, qty, currDish->price);
            if(!currCustomer->headOrder) {
                currCustomer->headOrder = currCustomer->tailOrder = temp;
            } else {
                currCustomer->tailOrder->next = temp;
                temp->prev = currCustomer->tailOrder;
                currCustomer->tailOrder = temp;
            }
            break;
        }
        currDish = currDish->next;
    }
}

void popCustomerHead(char *name) {
    int idx = DJB2(name);
    if(headCustomer[idx] && headCustomer[idx] == tailCustomer[idx]) {
        headCustomer[idx] = tailCustomer[idx] = NULL;
        free(headCustomer[idx]);
    } else {
        currCustomer = headCustomer[idx]->next;
        currCustomer->prev = headCustomer[idx]->next = NULL;
        free(headCustomer[idx]);
        headCustomer[idx] = currCustomer;
    }
}

void popCustomerTail(char *name) {
    int idx = DJB2(name);
    if(headCustomer && headCustomer[idx] == tailCustomer[idx]) {
        headCustomer[idx] = tailCustomer[idx] = NULL;
        free(headCustomer[idx]);
    } else {
        currCustomer = tailCustomer[idx]->prev;
        currCustomer->next = tailCustomer[idx]->prev = NULL;
        free(tailCustomer[idx]);
        tailCustomer[idx] = currCustomer;
    }
}

void popCustomer(char *name) {
    int idx = DJB2(name);
    if(!strcmp(name, currCustomer->name)) {
        if(!headCustomer[idx]){
            return;
        } else if(!strcmp(name, headCustomer[idx]->name)) {
            popCustomerHead(name);
        } else if(!strcmp(name, tailCustomer[idx]->name)) {
            popCustomerTail(name);
        } else {
            currCustomer->next->prev = currCustomer->prev;
            currCustomer->prev->next = currCustomer->next;
            currCustomer->next = currCustomer->prev = NULL;
            free(currCustomer);
        }
    currCustomer = currCustomer->next;
    }
}