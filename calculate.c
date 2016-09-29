#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("orig.txt", "r");
    FILE *output = fopen("output.txt", "w");
    if (!fp) {
        printf("ERROR opening input file orig.txt\n");
        exit(0);
    }
    int i = 0;
    char append[50], find[50];
    double orig_sum_a = 0.0, orig_sum_f = 0.0, orig_a, orig_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &orig_a, &orig_f);
        orig_sum_a += orig_a;
        orig_sum_f += orig_f;
    }
    fclose(fp);

//open phonebook_struct's data
    fp = fopen("struct.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file struct.txt\n");
            exit(0);
        }
    }
    double struct_sum_a = 0.0, struct_sum_f = 0.0, struct_a, struct_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &struct_a, &struct_f);
        struct_sum_a += struct_a;
        struct_sum_f += struct_f;
    }
    fclose(fp);

//open phonebook_smaz's data
    fp = fopen("smaz.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file struct.txt\n");
            exit(0);
        }
    }
    double smaz_sum_a = 0.0, smaz_sum_f = 0.0, smaz_a, smaz_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &smaz_a, &smaz_f);
        smaz_sum_a += smaz_a;
        smaz_sum_f += smaz_f;
    }
    fclose(fp);

//open phonebook_hash's data
    fp = fopen("hash.txt", "r");
    if (!fp) {
        fp = fopen("orig.txt", "r");
        if (!fp) {
            printf("ERROR opening input file hash.txt\n");
            exit(0);
        }
    }
    double hash_sum_a = 0.0, hash_sum_f = 0.0, hash_a, hash_f;
    for (i = 0; i < 100; i++) {
        if (feof(fp)) {
            printf("ERROR: You need 100 datum instead of %d\n", i);
            printf("run 'make run' longer to get enough information\n\n");
            exit(0);
        }
        fscanf(fp, "%s %s %lf %lf\n", append, find, &hash_a, &hash_f);
        hash_sum_a += hash_a;
        hash_sum_f += hash_f;
    }

    fprintf(output, "append() %lf %lf %lf %lf\n",orig_sum_a / 100.0, struct_sum_a / 100.0, hash_sum_a / 100.0, smaz_sum_a / 100.0);
    fprintf(output, "findName() %lf %lf %lf %lf", orig_sum_f / 100.0, struct_sum_f / 100.0, hash_sum_f / 100.0, smaz_sum_f / 100.0);
    fclose(output);
    fclose(fp);
    return 0;
}
