#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926535897923846

double termOfSinh(double);
double termOfCosh(double);
double taylorSeries(double, double, double, double(*)(double));

double epslion, theta, radius;
int choose;

int main(void) {
    printf("�p��������Ʈ��Ǯi�}���ΡA�п�J�e�\\�~�t�q�G");
    scanf("%lf", &epslion);
    printf("%s", "��J�p��Ϊ����סG");
    scanf("%lf", &theta);
    radius = theta * M_PI / 180;
    do {
        printf("%s", "�п�ܭn�p�⪺���(1)SINH (2)COSH �G");
        scanf("%d", &choose);
    } while(choose != 1 && choose != 2);
    switch(choose) {
    case 1:
        printf("%lf\n", taylorSeries(radius, epslion, sinh(radius), termOfSinh));
        printf("%s%lf\n", "���ب�ƭp�⵲�G�G", sinh(radius));
        break;
    case 2:
        printf("%lf\n", taylorSeries(radius, epslion, cosh(radius), termOfCosh));
        printf("%s%lf\n", "���ب�ƭp�⵲�G�G", cosh(radius));
        break;
    }
    return 0;
}

double termOfSinh(double a) {
    return a;
}

double termOfCosh(double a) {
    return 1;
}

double taylorSeries(double x, double min, double builtin, double (*fun)(double)) {
    double result = 0, term = (*fun)(x), sign = 1;
    int i;
    if(term == 1) {
        i = 0;
    } else {
        i = 1;
    }
    do {
        result += term;
        term *= sign * x * x / ((i + 1) * (i + 2));
        i += 2;
    } while(fabs(builtin - result) > min);

    if(i % 2 == 0) {
        i--;
    }
    i /= 2;
    printf("���Ǯi�}�������ơG%d\n", i);
    printf("%s", "���Ǯi�}���p�⵲�G�G");
    return result;
}
