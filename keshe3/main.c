#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100 //˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 //˳���洢�ռ�ķ�������

typedef struct {
    char word[21]; //�洢���ʣ������� 20 ���ַ�
    int count; //���ʳ��ֵĴ���
} ElemType; //˳���Ԫ������

typedef struct {
    ElemType *elem; //�洢�ռ��ַ
    int length; //��ǰ����
    int listsize; //��ǰ����Ĵ洢����
} SqList; //˳�������

int LocateElem(SqList *L, char *s);

void InsertList(SqList *L, int i, char *s);

int PrintList(SqList *L);

char *letter(char *str);

int list(SqList *L, char *str);

//˳���ĳ�ʼ��
void InitList(SqList *L) {
    ElemType elemType[2 * LIST_INIT_SIZE];
    L->elem = elemType;
    L->length = 0;
    L->listsize = 2 * LIST_INIT_SIZE;
    for (int i = 0; i < 2 * LIST_INIT_SIZE; ++i) {
        elemType[i].count = 0;
    }
}

//˳����ϲ���ָ���ĵ���
//���ҵ������ʵĳ��ִ����� 1������ 0�����򷵻ظõ�����˳����еĲ���λ�á�
int LocateElem(SqList *L, char *s) {
    if (L->length == 0) {
        InsertList(L, 0, s);
        L->length++;
        return 0;
    }
    for (int i = 0; i < L->length; ++i) {
        int j = 0;
        int a = 0;
        char *s2 = s;
        //�����ַ�����
        while (*(s2 + a) != '\0') {
            a++;
        }
        char *p;
        p = L->elem[i].word;
        //���Ƚ��ַ�����ÿһ����ĸ
        char *s1 = s;
        while (*(s1 + j) != '\0') {
            //��Ӧ�ַ��Ƿ���ͬ
            if (*(p + j) == *(s1 + j)) {
                j++;
                continue;
            } else {
                break;
            }
        }
        //�ҵ���ͬ�����򵥴�����һ
        if (a == j) {
            L->elem[i].count++;
        } else {
            //û�ҵ���ͬ���������һ��
            if (L->length >= L->listsize) {
                //����˳�������
                ElemType e[L->listsize + LISTINCREMENT];
                for (int k = 0; k < L->length; ++k) {
                    e[k] = L->elem[k];
                }
                L->elem = e;
                L->listsize = L->listsize + LISTINCREMENT;
            }
            //����Ҫ�����ַ
            int l = list(L, s);
            //����
            InsertList(L, l, s);
            L->length++;
        }
    }
}

//��˳����ϲ����µĵ���
//Ҫ���ֵ�˳�������µ��ʵĳ��ִ���Ϊ 1.
void InsertList(SqList *L, int i, char *s) {
    //���ǵ�һ����ֱ�Ӳ���
    if (i == 0) {
        for (int j = 0; j < 21; ++j) {
            L->elem[0].word[j] = *(s + j);
        }
        L->elem[0].count++;
        //�������һ����ֱ�Ӳ���
    } else if (i == L->length - 1) {
        for (int j = 0; j < 21; ++j) {
            L->elem[L->length - 1].word[j] = *(s + j);
        }
        L->elem[L->length - 1].count++;
        //�����м������ƶ������Ȼ���ٲ���
    } else {
        for (int j = L->length - 1; j >= i; --j) {
            ElemType e;
            e = L->elem[j];
            L->elem[j + 1] = e;
        }
        //����
        for (int k = 0; k < 21; ++k) {
            L->elem[i].word[k] = *(s + k);
        }
        L->elem[L->length - 1].count++;
    }
}

//���˳����ϴ洢�ĵ���ͳ����Ϣ
//����ļ���ÿ�����ʳ��ֵĴ����Լ��ļ����ܵĵ�����(��������ļ���)��
int PrintList(SqList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%s������%d��", L->elem[i].word, L->elem[i].count);
    }
    int n = 0;
    for (int j = 0; j < L->length; ++j) {
        n = L->length * L->elem[j].count;
    }
    printf("�ܵĵ�����%d", n);
}

//���˷���ĸ�ַ�
char *letter(char *str) {
    int i = 0, j = 0;
    static char newStr[20];
    char *p, tmp;
    p = newStr;
    while (*(str + i) != '\0') {
        tmp = *(str + i);
        if ((tmp >= 'A' && tmp <= 'Z') || (tmp >= 'a' && tmp <= 'z')) {
            *(p + j) = tmp;
            j++;
        }
        i++;
    }
    return newStr;
}

//����
int list(SqList *L, char *str) {
    for (int i = 0; i < L->length; ++i) {
        char *p;
        p = L->elem[i].word;
        //�������һ����ֱ�ӷ���
        if (i == L->length - 1) {
            return L->length;
            //����һ��Ϊ���򷵻�1
        } else if (L->elem[0].count == 0) {
            return 0;
            //�����Ƚ��ַ�������˳������ַ������������˳������ַ���֮��
        } else if (strcmp(str, L->elem[i].word) > 0 &&
                   (strcmp(str, L->elem[i + 1].word) < 0 || L->elem[i + 1].count == 0)) {
            return i + 1;
        } else {
            continue;
        }
    }
}

char st[200][21];

int main() {
    //���ļ�
    FILE *fp = fopen("C:\\Users\\DELL.DESKTOP-L90URJM\\Desktop\\������ƿγ����\\History.txt", "r+");
    if (fp == NULL) {
        printf("�ļ���ʧ��");
        return 0;
    }
    //���ļ��ж�ȡ�����ַ����ַ���������
    int i = 0;
    char res;
    while (!feof(fp)) {
        fscanf(fp, "%s", st[i]);
        //printf("%s ", st[i]);
        i++;
    }
    //printf("%s ", st[100]);

    //��ʼ��
    SqList L;
    InitList(&L);
    //����
    for (int j = 0; j < 200; ++j) {
        LocateElem(&L, letter(st[j]));
    }
    PrintList(&L);

    system("pause");
    return 0;
}