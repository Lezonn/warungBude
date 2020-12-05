bool validateName(const char *name) {
    for(int i = 0; name[i] != '\0'; i++) {
        if((name[i] < 'a' || name[i] > 'z') && name[i] != ' '){
            return true;
        }
    }
    return false;
}

bool validatePrice(int price) {
    if(price < 1000 || price > 50000) {
        return true;
    }
    return false;
}

bool validateQty(int qty) {
    if(qty < 1 || qty > 999) {
        return true;
    }
    return false;
}

bool validateDish(char *name) {
    currDish = headDish;
    while(currDish) {
        if(!strcmp(name, currDish->name)) {
            popDish(name);
            return false;
        }
        currDish = currDish->next;
    }
    return true;
}

bool validateCustomer(char *name) {
    for(int i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' ' || name[i] < 'A' || (name[i] > 'Z' && name[i] < 'a') || name[i] > 'z') return true;
    }
    return false;
}

bool validateOrder(char *name, int qty) {
    currDish = headDish;
    while(currDish) {
        if(!strcmp(name, currDish->name)) {
            if(qty >= 1 && qty <= currDish->qty){
                return false;
            }
        }
        currDish = currDish->next;
    }
    return true;
}

bool validateIdx(int idx) {
    for(int i = 0; i < 26; i++) {
        if(headCustomer[idx]) return false;
    }
    return true;
}

bool validatePayment(char *name, int idx) {
    currCustomer = headCustomer[idx];
    while(currCustomer) {
        if(!strcmp(currCustomer->name, name)) {
            int n=1;
            long long sum = 0;
            currOrder = currCustomer->headOrder;
            while(currOrder) {
                printf("[%d] %s x%d\n", n, currOrder->name, currOrder->qty);
                sum += (currOrder->price*currOrder->qty);
                currOrder = currOrder->next;
            }
            if(sum > 0) {
                printf("Total: Rp%lld\n", sum);
                popCustomer(currCustomer->name);
            } else {
                printf("No order yet..\n");
            }
            return false;
        }
        currCustomer = currCustomer->next;
    }
    return true;
}