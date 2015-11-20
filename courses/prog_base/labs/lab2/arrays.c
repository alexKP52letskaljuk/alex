#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void fillRand3(int arr[], int size);
int checkRand3(int arr[], int size);
float meanValue(int arr[], int size);
int minValue(int arr[], int size);
int meanIndex(int arr[], int size);
int minIndex(int arr[], int size);
int maxOccurance(int arr[], int size);
int diff(int arr1[], int arr2[], int res[], int size);
void mult(int arr1[], int arr2[], int res[], int size);
int gt(int arr1[], int arr2[], int size);
void lxor(int arr1[], int arr2[], int res[], int size);
int main()
{
    int arr1[6] = {1, 6, 3, 5, 9, 4 } , arr2[6] = {2, 3, 4, 3, 6, 4 }, res[6], size = 6;
    int arr[size], i;
    float b;
    srand(time(NULL));
    fillRand3(arr, size);
    for(i=0;i<size;i++)
    {
        printf("%d ", arr[i]);
    }
    b = meanValue(arr , size);
    printf("\n meanValue %f ", b);
    int c;
    c = minValue(arr, size);
    printf("\n minValue %d", c);
    int d;
    d=meanIndex(arr, size);
    printf("\n meanIndex %d", d);
    int e;
    e=minIndex(arr, size);
    printf("\n minIndex %d", e);
    int f;
    f=maxOccurance(arr, size);
    printf("\n maxOccurance %d", f);
    int g;
    g=gt(arr1, arr2, size);
    printf("\n gt %d", g);
return 0;
}
void fillRand3(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i] = rand() % 2;
    }
}
int checkRand3(int arr[], int size)
{
        int i;
    for(i=0;i<size; i++)
    {
        if(arr[i]!=1&&arr[i]!=0)
            return 0;
        else
            return 1;
    }
}
float meanValue(int arr[], int size)
{

    int a=0;
    float b;
    int i;
    for(i=0;i<size;i++)
    {
        a=a+arr[i];
    }
b=((float)a)/size;
return b;
}
int minValue(int arr[], int size)
{
    int i,a=arr[0];
    for(i=0;i<size;i++)
    {
        if(arr[i]<a)
            a=arr[i];
    }
    return a;
}
int meanIndex(int arr[], int size)
{

int i , index = 0;
float a, b;
//b=vidstan mig ser znach i 0 elementom, a=ser znach
 a=meanValue(arr, size);
 b=fabs(a-arr[0]);
 for(i=1; i<size; i++)
    {
    if(b>fabs(a-arr[i]))
        {
            b=fabs(a-arr[i]);
            index = i;
        }
    }
 return index;
}
//toxa
int minIndex(int arr[], int size)
{
    int a=arr[0], i, b = 0;
    for(i=0;i<size;i++)
    {
      if(arr[i]<a)
      {


            a=arr[i];
            b=i;
      }
    }
    return b;
}

int maxOccurance(int arr[], int size)
{
    int i, p=1, a=1, j, max= arr[0];
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(arr[j] == a)
            {
                p++;
            }

        }
        if(p>=a)
        {
            a=p;
            max = arr[i];
        }
        if(p == a && arr[i] > max)
        max = arr[i];
        p=1;
    }
    return max;
}

int diff(int arr1[], int arr2[], int res[], int size)
{
    int i, a;
    for(i=0;i<size;i++){
        res[i] = arr1[i] - arr2[i];
    }
    if(res[i]!=0)
        return 0;
    else
        return 1;
}
void mult(int arr1[], int arr2[], int res[], int size)
{
    int i;
    for(i=0;i<size;i++){
        res[i]=arr1[i]*arr2[i];
        }
}
int gt(int arr1[], int arr2[], int size)
{
    int i, result = 1;
    for(i=0;i<size;i++)
    {
        if(arr1[i]>=arr2[i])
            return result;
    }
    return 0;
}
void lxor(int arr1[], int arr2[], int res[], int size)
{
int i;
for(i=0;i<size;i++)
{
    res[i]=arr1[i]^arr2[i];
}

}
