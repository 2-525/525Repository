#include <stdio.h>
#include <string.h>

typedef char VertexType;
typedef int Adjmatrix;

#define MVNum 4 //最大顶点数
#define MaxDis 10000 //最大距离
typedef struct {
    VertexType vexs[MVNum]; //顶点数组，类型假定为 char 型
    Adjmatrix arcs[MVNum][MVNum]; //邻接矩阵，假定为 int 型 }
} MGraph; //图的邻接矩阵存储类型

int judge(char *arr, char s);

void Dijkstra(MGraph *M, int s);

void InitGraph(MGraph *M, int l);

//初始化 l为顶点个数
void InitGraph(MGraph *M, int l) {
    //初始化顶点信息
    for (int i = 0; i < l; ++i) {
        printf("请输入顶点信息");
        char s;
        scanf("%s", &s);
        M->vexs[i] = s;
    }
    //初始化有向边长度
    for (int j = 0; j < l; ++j) {
        char s1 = M->vexs[j];
        for (int i = 0; i < l; ++i) {
            if (i != j) {
                char s2 = M->vexs[i];
                printf("请输入%c点到%c点距离", s1, s2);
                int d;
                scanf("%d", &d);
                M->arcs[j][i] = d;
            } else if (i == j) {
                M->arcs[i][j] = 0;
            }
        }
    }
}

//s为初始顶点号
void Dijkstra(MGraph *M, int s) {
    //新建S数组
    VertexType S[MVNum];
    int syt = 0;
    S[0] = M->vexs[s];
    //顶点数
    int n = sizeof(M->vexs);
    //找出来的最短距离
    int a1[n];
    //当前顶点到个点距离
    int a2[n];

    //给a1赋初值
    for (int i = 0; i < n; ++i) {
        a1[i] = M->arcs[s][i];
    }
    //printf("\n");
    for (int m = 0; m < n - 1; ++m) {
        //距离
        int d;
        int min = 20000;
        //标记
        int l;
        for (int j = 0; j < n; ++j) {
            if (!judge(S, M->vexs[j]) && a1[j] != 0 && a1[j] <= min) {
                min = a1[j];
                l = j;
            }
        }
        d = min;
        //给a2赋值
        for (int i = 0; i < n; ++i) {
            a2[i] = M->arcs[l][i] + d;
        }
        printf("\n");
        for (int k = 0; k < n; ++k) {
            if (!judge(S, M->vexs[k]) && a1[k] != 0 && a2[k] != 0) {
                //若a1的值大于a2则替换a1
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

//判断有无该元素，若存在则返回1，否则返回0
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
    printf("请输入顶点数");
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