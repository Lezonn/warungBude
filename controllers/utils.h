const char* detectOS() {
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}

unsigned long DJB2(char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % 26;
}

void getTime() {
    struct tm* now;
    time_t t = time(NULL);
    now = localtime(&t);
    const char* day[7] = {
                            "Mon", "Tue", "Wed",
                            "Thu", "Fri", "Sat", "Sun"
    };

    const char* month[12] = {
                              "Jan", "Feb", "Mar",
                              "Apr", "May", "Jun",
                              "Jul", "Aug", "Sep",
                              "Oct", "Nov", "Dec"
    };
    printf("%s %s %d %02d:%02d:%02d %d\n", 
        day[now->tm_wday-1], month[now->tm_mon],
        now->tm_mday, now->tm_hour, now->tm_min,
        now->tm_sec, now->tm_year + 1900);
}

void clrscr() {
    system("cls||clear");
}

void pressEnter() {
    printf("Press enter to continue..."); getchar();
}

void splashScreen() {
    char splash[256];
    FILE *fp = fopen("../views/splash-screen.txt", "r");
    while(!feof(fp)) {
        fscanf(fp, "%[^\n]\n", splash);
        for(int i = 1; splash[i] != '\0'; i++) {
            printf("%c", splash[i]);
        }
        puts("");
    }
    fclose(fp);
}