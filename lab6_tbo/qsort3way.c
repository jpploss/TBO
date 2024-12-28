void sort(int *vet, int lo, int hi) {
    if (hi <= lo) return;

    int v = vet[lo];
    int lt = lo, gt = hi, i = lo;

    while (i <= gt) {
        if (vet[i] < v) {
            int aux = vet[lt]; vet[lt] = vet[i]; vet[i] = aux;
            lt++; i++;
        } 
        else if (vet[i] > v) {
            int aux = vet[gt]; vet[gt] = vet[i]; vet[i] = aux;
            gt--;
        } 
        else i++;
    }

    sort(vet, lo, lt-1);
    sort(vet, gt+1, hi);
}