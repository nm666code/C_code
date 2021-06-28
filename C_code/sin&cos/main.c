#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926535897923846

double termOfSinh(double);
double termOfCosh(double);
double taylorSeries(double, double, double, double(*)(double));

double epslion, theta, radius;
int choose;

int main(void) {
    printf("計算雙曲函數泰勒展開式用，請輸入容許\誤差量：");
    scanf("%lf", &epslion);
    printf("%s", "輸入計算用的角度：");
    scanf("%lf", &theta);
    radius = theta * M_PI / 180;
    do {
        printf("%s", "請選擇要計算的函數(1)SINH (2)COSH ：");
        scanf("%d", &choose);
    } while(choose != 1 && choose != 2);
    switch(choose) {
    case 1:
        printf("%lf\n", taylorSeries(radius, epslion, sinh(radius), termOfSinh));
        printf("%s%lf\n", "內建函數計算結果：", sinh(radius));
        break;
    case 2:
        printf("%lf\n", taylorSeries(radius, epslion, cosh(radius), termOfCosh));
        printf("%s%lf\n", "內建函數計算結果：", cosh(radius));
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
    printf("泰勒展開式的項數：%d\n", i);
    printf("%s", "泰勒展開式計算結果：");
    return result;
}
