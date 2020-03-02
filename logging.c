void addLog(char message[], char ip[]){
    char ts[1000];
    time_t t = time(NULL);
    struct tm * p = localtime(&t);
    strftime(ts, 1000, "%T-%D", p);
    FILE *json;
    json = fopen("/var/www/html/chat.json","a+");
    ip[strcspn(ip, "\r\n")] = 0;
    fprintf(json,"%s @ %s: %s", ip, ts, message);
    fclose(json);
}
