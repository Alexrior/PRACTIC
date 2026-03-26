#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// --- ЗАДАНИЕ 1 и 2: Чтение и подсчет символов ---
// Мы сократили код, объединив открытие и проверку, а также сменив цикл feof на fgetc
void task1_2(const char* filename) {
    FILE *in = fopen(filename, "r");
    if (!in) { printf("Oshibka otkritiya!\n"); return; }

    int empty = 0, nonempty = 0;
    char ch;

    printf("\n--- Soderzhimoe fayla ---\n");
    while ((ch = fgetc(in)) != EOF) {
        putchar(ch);
        // "Pustye": probely, taby, uprvlyayushie (iscntrl)
        if (isspace(ch) || iscntrl(ch)) empty++;
        else nonempty++;
    }
    printf("\n-------------------------\n");
    printf("Pustykh: %d, Nepustykh: %d\n", empty, nonempty);
    fclose(in);
}

// --- ЗАДАНИЕ 3: Поиск подстроки ---
void task3(const char* filename, const char* target) {
    FILE *in = fopen(filename, "r");
    FILE *out = fopen("found.txt", "w");
    char line[256];

    if (!in || !out) return;

    while (fgets(line, sizeof(line), in)) {
        if (strstr(line, target)) {
            fputs(line, out); // Sokhryanyaem stroku v fayl
        }
    }
    printf("Rezultaty poiska v 'found.txt'\n");
    fclose(in); fclose(out);
}

// --- ЗАДАНИЕ 4: Номера страниц ---
void task4(const char* filename) {
    FILE *in = fopen(filename, "r");
    FILE *out = fopen("fixed.txt", "w");
    char line[256], pageNum[10] = "";

    if (!in || !out) return;

    while (fgets(line, sizeof(line), in)) {
        // Ischem format "- 34 -" v nachale
        if (line[0] == '-' && isdigit(line[2])) {
            int j = 0;
            for(int i=0; line[i]; i++) if(isdigit(line[i])) pageNum[j++] = line[i];
            pageNum[j] = '\0';
            continue; // Propuskaem pechat' nomera sverkhu
        }
        fputs(line, out);
        // Simvol perekhoda \f (v realnosti vstrechaetsya redko, mozhno dobavit' uslovie)
        if (strchr(line, '\f')) {
            fprintf(out, "Stranitsa: %s\n", pageNum);
        }
    }
    fclose(in); fclose(out);
    printf("Stranitsy obrabotany v 'fixed.txt'\n");
}

// --- ЗАДАНИЕ 5 и 6: Шифратор (XOR) ---
// Formula: $c' = c \oplus key[i]$
void task5_6(const char* f_in, const char* f_out, const char* key) {
    FILE *in = fopen(f_in, "rb");
    FILE *out = fopen(f_out, "wb");
    if (!in || !out) return;

    int ch, i = 0;
    int keyLen = strlen(key);

    while ((ch = fgetc(in)) != EOF) {
        fputc(ch ^ key[i % keyLen], out);
        i++;
    }
    fclose(in); fclose(out);
    printf("Fayl zakodirovan/dekodirovan v '%s'\n", f_out);
}

int main(int argc, char* argv[]) {
    // Esli zapustili s argumentami (Zadanie 6)
    if (argc >= 4) {
        task5_6(argv[1], argv[2], argv[3]);
        return 0;
    }

    // Interaktivnoe menyu dlya ostalnykh zadach
    printf("1. Prosmotr i podschet (Zad 1-2)\n2. Poisk podstroki (Zad 3)\n3. Obrabotka stranits (Zad 4)\nVash vybor: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) task1_2("test.txt");
    if (choice == 2) task3("test.txt", "hello");
    if (choice == 3) task4("test.txt");

    return 0;
}