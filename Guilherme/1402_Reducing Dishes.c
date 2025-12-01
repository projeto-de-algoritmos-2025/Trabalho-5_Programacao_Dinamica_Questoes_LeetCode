int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    for (int j = 0; j < satisfactionSize - 1; j++) {
        for (int k = 0; k < satisfactionSize - j - 1; k++) {
            if (satisfaction[k] > satisfaction[k + 1]) {
                int temp = satisfaction[k];
                satisfaction[k] = satisfaction[k + 1];
                satisfaction[k + 1] = temp;
            }
        }
    }
    int  incremento = 0, total = 0;
    for (int i = satisfactionSize - 1; i >= 0; i--){
        incremento += satisfaction[i];  
        if (incremento + total > total) {
            total += incremento;
        } else {
            break;
        }
    }
    return total;
}
