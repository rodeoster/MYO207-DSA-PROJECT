#include <stdio.h>

// İSİM SOYİSİM: Mehmet Efe Uysal
// ÖĞRENCİ NUMARASI: 2420171026
// BTK AKADEMİ SERTİFİKA BAĞLANTISI: 1kZCeJaPjb

void selectionSort(int dizi[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[min_idx])
                min_idx = j;
        }
        temp = dizi[min_idx];
        dizi[min_idx] = dizi[i];
        dizi[i] = temp;
    }
}

int binarySearch(int dizi[], int dusuk, int yuksek, int aranan) {
    while (dusuk <= yuksek) {
        int orta = dusuk + (yuksek - dusuk) / 2;
        if (dizi[orta] == aranan) return orta;
        if (dizi[orta] < aranan) dusuk = orta + 1;
        else yuksek = orta - 1;
    }
    return -1;
}

int main() {
    int dizi[] = {64, 25, 12, 22, 11};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranan, sonuc;

    selectionSort(dizi, n);
    printf("Siralanmis dizi: ");
    for (int i = 0; i < n; i++) printf("%d ", dizi[i]);
    
    printf("\nAranacak sayiyi girin: ");
    scanf("%d", &aranan);

    sonuc = binarySearch(dizi, 0, n - 1, aranan);
    if (sonuc != -1) printf("Sayi bulundu, indeksi: %d\n", sonuc);
    else printf("Sayi bulunamadi.\n");

    return 0;
}