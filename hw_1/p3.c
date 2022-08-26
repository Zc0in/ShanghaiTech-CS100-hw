#include<stdio.h>
#include<math.h>

int main()
{
    int num, sign, exponent, fraction, E;
    float ans, frac;
    scanf("%x", &num);
    E = 63;
    sign = num >> 31;
    exponent = num >> 24 & 0x7f;
    fraction = num & 0xffffff;
    frac = 1 + (float)(fraction) / 16777216;//相当于2的24次方
    ans = pow(-1, sign) * frac * pow(2, exponent - E);
    printf("The number converts to %f\n", ans);
    return 0;
}