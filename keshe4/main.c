#include <stdio.h>
#include <string.h>

typedef char VertexType;
typedef int Adjmatrix;

#define MVNum 4 //��󶥵���
#define MaxDis 10000 //������
typedef struct {
    VertexType vexs[MVNum]; //�������飬���ͼٶ�Ϊ char ��
    Adjmatrix arcs[MVNum][MVNum]; //�ڽӾ��󣬼ٶ�Ϊ int �� }
} MGraph; //ͼ���ڽӾ���洢����

int judge(char *arr, char s);

void Dijkstra(MGraph *M, int s);

void InitGraph(MGraph *M, int l);

//��ʼ�� lΪ�������
void InitGraph(MGraph *M, int l) {
    //��ʼ��������Ϣ
    for (int i = 0; i < l; ++i) {
        printf("�����붥����Ϣ");
        char s;
        scanf("%s", &s);
        M->vexs[i] = s;
    }
    //��ʼ������߳���
    for (int j = 0; j < l; ++j) {
        char s1 = M->vexs[j];
        for (int i = 0; i < l; ++i) {
            if (i != j) {
                char s2 = M->vexs[i];
                printf("������%c�㵽%c�����", s1, s2);
                int d;
                scanf("%d", &d);
                M->arcs[j][i] = d;
            } else if (i == j) {
                M->arcs[i][j] = 0;
            }
        }
    }
}

//sΪ��ʼ�����
void Dijkstra(MGraph *M, int s) {
    //�½�S����
    VertexType S[MVNum];
    int syt = 0;
    S[0] = M->vexs[s];
    //������
    int n = sizeof(M->vexs);
    //�ҳ�������̾���
    int a1[n];
    //��ǰ���㵽�������
    int a2[n];

    //��a1����ֵ
    for (int i = 0; i < n; ++i) {
        a1[i] = M->arcs[s][i];
    }
    //printf("\n");
    for (int m = 0; m < n - 1; ++m) {
        //����
        int d;
        int min = 20000;
        //���
        int l;
        for (int j = 0; j < n; ++j) {
            if (!judge(S, M->vexs[j]) && a1[j] != 0 && a1[j] <= min) {
                min = a1[j];
                l = j;
            }
        }
        d = min;
        //��a2��ֵ
        for (int i = 0; i < n; ++i) {
            a2[i] = M->arcs[l][i] + d;
        }
        printf("\n");
        for (int k = 0; k < n; ++k) {
            if (!judge(S, M->vexs[k]) && a1[k] != 0 && a2[k] != 0) {
                //��a1��ֵ����a2���滻a1
                if (a1[k] >= a2[k]) {
                    a1[k] = a2[k];
                }
            }
        }
    }
    for (int q = 0; q < n; q++) {
        printf("%d ", a1[q]);
    }
}

//�ж����޸�Ԫ�أ��������򷵻�1�����򷵻�0
int judge(char *arr, char s) {
    int n = sizeof(arr);
    for (int i = 0; i < n; ++i) {
        if (s == arr[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    printf("�����붥����");
    scanf("%d", &n);
    MGraph M;
    InitGraph(&M, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", M.arcs[i][j]);
        }
        printf("\n");
    }
    Dijkstra(&M, 0);
    return 0;
}