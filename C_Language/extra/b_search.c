#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*FCMP)(void*, void*);
#define   BASE(i)   ((char *)base + (i)*size)
#define   NAME_SIZE   20

void bsort(void* base, int nelem, int size, FCMP fcmp);
int b_search(void* key, void* base, int nelem, FCMP fcmp);
int fcmp1(void* a, void* b);
int fcmp2(void* a, void* b);
int swap(void* dest, void* src, int size);


int main()
{
    int score[] = { 78, 23, 86, 33, 98, 42 };
    char name[][NAME_SIZE] = { "yang", "lee", "kim", "park", "kang" };
    int i, rst, s_score;
    char s_name[NAME_SIZE];

    FCMP fcmp[] = { fcmp1, fcmp2 };

    printf("Before Sort....\n");
    for (i = 0; i < sizeof(score) / sizeof(int); i++)
        printf("%d ", score[i]);
    printf("\n\n");

    bsort(score, sizeof(score) / sizeof(int), sizeof(int), fcmp[0]);

    printf("After Sort....\n");
    for (i = 0; i < (sizeof(score) / sizeof(int)); i++)
        printf("%d ", score[i]);
    printf("\n\n");

    while (1)
    {
        printf("\nSearch Score ==> ");
        scanf("%d", &s_score); getchar();
        if (s_score == -1) break;
        rst = b_search(&s_score, &score[0], sizeof(score) / sizeof(int), fcmp[0]);
        if (rst != -1) printf("%d data ==> index %d\n", s_score, rst);
        else printf("no %d data!!\n", s_score);
    }


    printf("============================================\n");
    printf("Before Sort....\n");
    for (i = 0; i < sizeof(name) / NAME_SIZE; i++)
        printf("%s ", name[i]);
    printf("\n\n");

    bsort(name, sizeof(name) / NAME_SIZE, NAME_SIZE, fcmp[1]);

    printf("After Sort....\n");
    for (i = 0; i < sizeof(name) / NAME_SIZE; i++)
        printf("%s ", name[i]);
    printf("\n\n");

    while (1)
    {
        printf("\nSearch Name ==> ");
        fgets(s_name, NAME_SIZE, stdin);
        s_name[strlen(s_name) - 1] = '\0';
        if (s_name[0] == '\0') break;
        rst = b_search(&s_name, &name[0], sizeof(name) / (sizeof(char) * NAME_SIZE), fcmp[1]);///
        if (rst != -1) printf("%s data ==> index %d\n", s_name, rst);
        else printf("no %s data!!\n", s_name);
    }

    return 0;
}

void bsort(void* base, int nelem, int size, FCMP fcmp)
{   // fcmp1,2 ���ؼ� �ؾ���.
    int step, cmp, change;
    int rst;
    if (fcmp == fcmp1)
    {
        for (step = 1; step <= nelem - 1; step++) {
            change = 0;
            for (cmp = 1; cmp <= nelem - step; cmp++) {
                if (fcmp(BASE(cmp - 1), BASE(cmp)) > 0) {
                    swap(BASE(cmp - 1), BASE(cmp), size);
                    change = 1;
                }
            }
            if (change == 0) break;
        }
    }

    if (fcmp == fcmp2)
    {
        for (step = 1; step <= nelem - 1; step++) {
            change = 0;
            for (cmp = 1; cmp <= nelem - step; cmp++) {
                if (fcmp(BASE(cmp - 1), BASE(cmp)) > 0) {
                    swap(BASE(cmp - 1), BASE(cmp), size);
                    change = 1;
                }
            }
            if (change == 0) break;
        }
    }
}

int fcmp1(void* a, void* b)
{
    return ((*(int*)a) == (*(int*)b)) ? 0 : // ������ 0 
        ((*(int*)a) > (*(int*)b)) ? 1 : -1; // a ���� �� ũ�� 1 �ƴϸ� -1
}

int fcmp2(void* a, void* b)
{
    return strcmp((char*)a, (char*)b); // a�� �ռ���   ��� ��ȯ
}

int b_search(void* key, void* base, int nelem, FCMP fcmp)
{
    int l, h, m, rst;
    l = 0;
    h = nelem - 1;
    char temp[NAME_SIZE];
    char temp_[NAME_SIZE];

    //#define   BASE(i)   ((char *)base + (i)*size)
    int size;
    if (fcmp == fcmp1) { size = sizeof(int); }
    else { size = sizeof(char) * NAME_SIZE; }
    while (l <= h)
    {

        m = (l + h) / 2;
        rst = fcmp(key, BASE(m));
        if (rst == 0) return m;

        else if (rst < 0) h = m - 1;//Ű ���� �� �۴� -> ���� �������� ã�ƾ���.

        else l = m + 1;// key ���� ��  -> ū �������� ã�ƾ���.
    }

    return -1;
}



int swap(void* dest, void* src, int size)
{
    // �ڷ����� �ٲ� ������ 
    void* temp = malloc(size); // �޸� �Ҵ��� �������.

    if (temp == NULL)
        return -1;

    memcpy(temp, dest, size);
    memcpy(dest, src, size);
    memcpy(src, temp, size);

    free(temp);
    return 1;

}
