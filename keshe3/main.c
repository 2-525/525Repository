#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 100 //顺序表存储空间的初始分配量
#define LISTINCREMENT 10 //顺序表存储空间的分配增量

typedef struct {
    char word[21]; //存储单词，不超过 20 个字符
    int count; //单词出现的次数
} ElemType; //顺序表元素类型

typedef struct {
    ElemType *elem; //存储空间基址
    int length; //当前长度
    int listsize; //当前分配的存储容量
} SqList; //顺序表类型

int LocateElem(SqList *L, char *s);

void InsertList(SqList *L, int i, char *s);

int PrintList(SqList *L);

char *letter(char *str);

int list(SqList *L, char *str);

//顺序表的初始化
void InitList(SqList *L) {
    ElemType elemType[2 * LIST_INIT_SIZE];
    L->elem = elemType;
    L->length = 0;
    L->listsize = 2 * LIST_INIT_SIZE;
    for (int i = 0; i < 2 * LIST_INIT_SIZE; ++i) {
        elemType[i].count = 0;
    }
}

//顺序表上查找指定的单词
//若找到，单词的出现次数增 1，返回 0，否则返回该单词在顺序表中的插入位置。
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
        //计算字符长度
        while (*(s2 + a) != '\0') {
            a++;
        }
        char *p;
        p = L->elem[i].word;
        //待比较字符串的每一个字母
        char *s1 = s;
        while (*(s1 + j) != '\0') {
            //对应字符是否相同
            if (*(p + j) == *(s1 + j)) {
                j++;
                continue;
            } else {
                break;
            }
        }
        //找到相同单词则单词数加一
        if (a == j) {
            L->elem[i].count++;
        } else {
            //没找到相同单词则插入一个
            if (L->length >= L->listsize) {
                //增长顺序表容量
                ElemType e[L->listsize + LISTINCREMENT];
                for (int k = 0; k < L->length; ++k) {
                    e[k] = L->elem[k];
                }
                L->elem = e;
                L->listsize = L->listsize + LISTINCREMENT;
            }
            //返回要插入地址
            int l = list(L, s);
            //插入
            InsertList(L, l, s);
            L->length++;
        }
    }
}

//在顺序表上插入新的单词
//要求按字典顺序有序。新单词的出现次数为 1.
void InsertList(SqList *L, int i, char *s) {
    //若是第一个则直接插入
    if (i == 0) {
        for (int j = 0; j < 21; ++j) {
            L->elem[0].word[j] = *(s + j);
        }
        L->elem[0].count++;
        //若是最后一个则直接插入
    } else if (i == L->length - 1) {
        for (int j = 0; j < 21; ++j) {
            L->elem[L->length - 1].word[j] = *(s + j);
        }
        L->elem[L->length - 1].count++;
        //若在中间则先移动后面的然后再插入
    } else {
        for (int j = L->length - 1; j >= i; --j) {
            ElemType e;
            e = L->elem[j];
            L->elem[j + 1] = e;
        }
        //插入
        for (int k = 0; k < 21; ++k) {
            L->elem[i].word[k] = *(s + k);
        }
        L->elem[L->length - 1].count++;
    }
}

//输出顺序表上存储的单词统计信息
//输出文件中每个单词出现的次数以及文件中总的单词数(可输出到文件中)。
int PrintList(SqList *L) {
    for (int i = 0; i < L->length; ++i) {
        printf("%s出现了%d次", L->elem[i].word, L->elem[i].count);
    }
    int n = 0;
    for (int j = 0; j < L->length; ++j) {
        n = L->length * L->elem[j].count;
    }
    printf("总的单词数%d", n);
}

//过滤非字母字符
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

//排序
int list(SqList *L, char *str) {
    for (int i = 0; i < L->length; ++i) {
        char *p;
        p = L->elem[i].word;
        //若是最后一个则直接返回
        if (i == L->length - 1) {
            return L->length;
            //若第一个为空则返回1
        } else if (L->elem[0].count == 0) {
            return 0;
            //若待比较字符串大于顺序表中字符串，将其放入顺序表中字符串之后
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
    //打开文件
    FILE *fp = fopen("C:\\Users\\DELL.DESKTOP-L90URJM\\Desktop\\程序设计课程设计\\History.txt", "r+");
    if (fp == NULL) {
        printf("文件打开失败");
        return 0;
    }
    //从文件中读取所有字符到字符串数组中
    int i = 0;
    char res;
    while (!feof(fp)) {
        fscanf(fp, "%s", st[i]);
        //printf("%s ", st[i]);
        i++;
    }
    //printf("%s ", st[100]);

    //初始化
    SqList L;
    InitList(&L);
    //过滤
    for (int j = 0; j < 200; ++j) {
        LocateElem(&L, letter(st[j]));
    }
    PrintList(&L);

    system("pause");
    return 0;
}