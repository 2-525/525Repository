#include <stdio.h>

//����������
int arr[100][100];


int main() {
    int n, x1, y1, x2, y2;
    printf("������Ҫ���ľ��εĸ���");
    scanf("%d", &n);
    if (n >= 0 && n <= 100) {
        //�����������ڴ洢����
        int a[n][4];
        //��������
        for (int i = 0; i < n; ++i) {
            printf("������Ҫ���ľ��ε����½ǵĺ�����");
            scanf("%d", &x1);
            if (x1 >= 0 && x1 <= 100) {
                a[i][0] = x1;
            }
            printf("������Ҫ���ľ��ε����½ǵ�������");
            scanf("%d", &y1);
            if (y1 >= 0 && y1 <= 100) {
                a[i][1] = y1;
            }
            printf("������Ҫ���ľ��ε����Ͻǵĺ�����");
            scanf("%d", &x2);
            if (x2 >= 0 && x2 <= 100) {
                a[i][2] = x2;
            }
            printf("������Ҫ���ľ��ε����½ǵ�������");
            scanf("%d", &y2);
            if (y2 >= 0 && y2 <= 100) {
                a[i][3] = y2;
            }
        }
        //�������
        int s[n];
        //�ص���
        int c = 0;
        //�����
        int S = 0;
        for (int j = 0; j < n; ++j) {
            //���������������
            s[j] = (a[j][2] - a[j][0]) * (a[j][3] - a[j][1]);
            S = s[j] + S;
            //Ϳɫ����δͿɫ��ΪNULL������ͿɫΪ1
            for (int i = a[j][0]+1; i <= a[j][2]; ++i) {
                for (int k = a[j][1]+1; k <= a[j][3]; ++k) {
                    //����ɫ�鲻ΪNULL
                    if (arr[i][k] != NULL) {
                        //�ص�һ�ξͼ�һ
                        c++;
                    } else {
                        arr[i][k] = 1;
                    }
                }
            }
        }
        S = S - c;
        printf("%d", S);
    } else {
        printf("�������");
    }
    return 0;
}