#include <stdio.h>
#include<math.h>

int ColorMap(float minVal, float maxVal, int maxValColor, float val)
{
    // YOUR CODE STARTS HERE
	int ans;
    float R, G, B;
  	float p = (val - minVal)/(maxVal - minVal);
    R = p * (float)(maxValColor >> 16);
    // printf("%f", R);
    G = p * (float)(maxValColor >> 8 & 0xff);
    // printf("%f", G);
    B = p * (float)(maxValColor & 0xff);
    // printf("%f", B);
    ans = (int)(R) * pow(2,16) + (int)(G) * pow(2,8) + (int)(B);
    return ans;


    // YOUR CODE ENDS HERE
}

int main()
{
    float minVal, maxVal, val;
    int maxValColor;
    scanf("%f %f %x %f", &minVal, &maxVal, &maxValColor, &val);
    int color = ColorMap(minVal, maxVal, maxValColor, val);
    printf ("0x%x\n", color);
    return 0;
}
