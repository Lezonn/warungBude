void insertCustomer(char *str) {
	int index = DJB2(str);
	if(headCustomer[index]) { // cek apakah dia sudah terisi
		Customer *temp = createCustomer(str);
		tailCustomer[index]->next = temp;
		tailCustomer[index] = temp;
	} else { // cek apakah dia belum terisi
		headCustomer[index] = tailCustomer[index] = createCustomer(str);
	}
}

bool searchCust(char *name) {
    int index = DJB2(name);
    if(headCustomer[index]) {
        currCustomer = headCustomer[index];
        while(currCustomer) {
            if(!strcmp(name, currCustomer->name)) {
                return false;
            }
            currCustomer = currCustomer->next;
        }
    }
    return true;
}

void viewCustomer() {
	for(int i = 0; i < 26; i++) {
		if(headCustomer[i]) {
            printf("%d. ", i);
			currCustomer = headCustomer[i];
			while(currCustomer->next) {
				printf("%s ->", currCustomer->name);
				currCustomer = currCustomer->next;
			}
            printf("%s\n", currCustomer->name);
		}
	}
}