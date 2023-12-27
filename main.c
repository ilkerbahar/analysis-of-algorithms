#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 @brief Iki integer degeri degistirir.
 
  @param a Birinci integer deger
  @param b Ikinci integer deger
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 @brief Bir diziyi rastgele karistirir.

  @param arr Karistirilacak dizi
  @param n Dizi uzunlugu
 */
void arrayRandomizer(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}



/**
 @brief QuickSort siralama algoritmasinin bolme islemi.
 @brief 
 * @param arr Siralanacak dizi
 * @param low Dizinin düsük sinir indeksi
 * @param high Dizinin yüksek sinir indeksi
 *
 * @return Bölüm noktasinin indeksi
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Son elemani pivot olarak seç
    int i = (low - 1); // Küçük elemanlarin son indeksi

    for (int j = low; j < high; j++) {
        
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * QuickSort algoritmasi ile bir diziyi siralar.
 *
 * @param arr Siralanacak dizi
 * @param low Dizinin düsük sinir indeksi
 * @param high Dizinin yüksek sinir indeksi
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Diziyi böler ve bölüm noktasini alir
        int pi = partition(arr, low, high);

        // Bölünmüs diziyi iki alt diziye sirayla siralar
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Anahtar ve kilit sayisini girin: ");
    scanf("%d", &n);

    int *keys = (int *)malloc(n * sizeof(int));
    int *locks = (int *)malloc(n * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        keys[i] = rand() % 100 + 1;
        locks[i] = keys[i];
    }
    arrayRandomizer(locks, n);
    arrayRandomizer(keys, n);

    printf("Anahtarlar:\n");
    for (int i = 0; i < n; i++) {
        printf("Anahtar %d buyuklugu %d\n", i + 1, keys[i]);
    }
    quickSort(keys, 0, n - 1);

    printf("Kilitler:\n");
    for (int i = 0; i < n; i++) {
        printf("Kilit %d buyuklugu %d\n", i + 1, locks[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (keys[i] == locks[j]) {
                printf("Anahtar %d buyuklugu:%d ve Kilit %d ile eslesiyor.\n", i + 1, keys[i], j + 1);
            }
        }
    }

    free(keys);
    free(locks);

    return 0;
}

