// function untuk bagian dish

void pushDish(char *name, int qty, int price) {
    Dish *temp = createDish(name, qty, price);
    if(!headDish) {
        headDish = tailDish = temp;
    } else {
        temp->prev = tailDish;
        tailDish->next = temp;
        tailDish = temp;
    }
}

void popHead() {
    if(headDish && headDish == tailDish) {
        headDish = tailDish = NULL;
        free(headDish);
    } else {
        currDish = headDish->next;
        currDish->prev = headDish->next = NULL;
        free(headDish);
        headDish = currDish;
    }
}

void popTail() {
    if(headDish && headDish == tailDish) {
        headDish = tailDish = NULL;
        free(headDish);
    } else {
        currDish = tailDish->prev;
        currDish->next = tailDish->prev = NULL;
        free(tailDish);
        tailDish = currDish;
    }
}

void popDish(char *name) {
    if(!headDish) {
        return;
    } else if(!strcmp(headDish->name, name)) {
        popHead();
    } else if(!strcmp(tailDish->name, name)){
        popTail();
    } else {
        currDish->next->prev = currDish->prev;
        currDish->prev->next = currDish->next;
        currDish->next = currDish->prev = NULL;
        free(currDish);
    }
}