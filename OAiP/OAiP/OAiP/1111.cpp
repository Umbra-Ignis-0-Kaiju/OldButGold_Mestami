#include <stdio.h> // ����������� ���������� �����/������
int main()
{
    int i = 0;
    int A[10]; //����� �������
    printf("Vvedite elementy massiva:\n"); //���� ����� � ������
    for (int m = 0; m < 10; m++)
    {
        printf("%d element: ", m + 1); //������� �� ����� �� �������
        scanf_s("%d", &A[m]);
    }
    int sh, j, a; //����������
    int step = 9; //���
    for (sh = step / 2; sh > 0; sh /= 2) {
        for (i = sh; i < step; i++) {
            a = A[i];
            for (j = i; j >= sh; j -= sh) {
                if (a < A[j - sh])
                    A[j] = A[j - sh];
                else
                    break;
            }
            A[j] = a;
        }
    }
    printf("\posle raboty algoritma:\n"); //����� ������ �������������� �������
    for (int m = 0; m < 10; m++)
        printf("%d = [%d]\n", m + 1, A[m]);
    return 0; //���������
}