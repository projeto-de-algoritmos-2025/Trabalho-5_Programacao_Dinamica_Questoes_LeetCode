int minPartitions(char* n) {
    char digito = '0';
    for (int i = 0; n[i] != '\0'; i++){
        if (n[i]>digito)
            digito = n[i];
    }
    return digito -'0';
}
