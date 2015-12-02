#include <stdio.h>

#include <stdlib.h>
#include <limits.h>
int main(){
    //•Заповнити елементи масиву цілих чисел розміру N значеннями, що вводить користувач із консолі.
unsigned size_masuv;
int a=0;
printf("Vedit rozmer masuvy: ");
scanf("%d ", &size_masuv);
int arr[size_masuv];
int arr1[size_masuv];
int arr2[size_masuv];
int arr3[size_masuv];
int arr4[size_masuv];
int b[size_masuv];
int i, e, j, c=0, max = 0, min=0, r, min1=0, max1=0;
for(i=0;i<size_masuv;i++)
    b[i] = 0;
for(i=0;i<size_masuv;i++)
{
    scanf("%d", &arr[i]);
}
//Вивести значення елементів масиву через кому на екран.
for(i=0;i<size_masuv;i++)
{
    printf("%d,", arr[i]);
}
for(i=0;i<size_masuv;i++){
    arr1[i]=arr[i];
}
for(i=0;i<size_masuv;i++){
    arr2[i]=arr[i];
}
for(i=0;i<size_masuv;i++){
    arr3[i]=arr[i];
}
for(i=0;i<size_masuv;i++){
    arr4[i]=arr[i];
}
//Знайти і вивести на екран суму всіх від'ємних елементів.
for(i=0;i<size_masuv;i++)
{
    if(arr[i]<0)
        a=a+arr[i];
}
printf("\nSuma vsih videmnuh chusel: %d", a);

//Знайти від'ємні елементи масиву і замінити їх на нулі.
printf("\nVsi videmni elementu -> 0 ");
for(i=0;i<size_masuv;i++)
{
    if(arr[i]<0)
        arr[i]=0;
}
for(i=0;i<size_masuv;i++)
{
    printf("\n %d", arr[i]);
}
//Вивести всі додатні елементи масиву через кому на екран консолі.
printf("\nVsi dodatni elementu: ");
for(i=0;i<size_masuv;i++)
{
    if(arr[i]>0)
        printf("%d, ", arr[i]);
}

//Замість кожного елементу масиву записати суму всіх наступних елементів масиву.
printf("\nZamist koshnogo elementa napusatu symy vsix nastypnux: ");
for(i=0;i<size_masuv;i++)
{
    for(j=i+1;j<size_masuv;j++)
    {
        c=c+arr1[j];
        arr1[i]=c;
    }
    c=0;
    printf("%d,", arr1[i]);
}
//Замість кожного елементу масиву записати різницю між поточним і наступним елементом масиву.
// Значення останнього елементу масиву зробити нулем.
printf("\nzamist koshnogo elementy masuva napusatu riznuzy mig potochnum i nastypnum, \nznachenny ostannogo elementa zrobutu 0: ");
for(i=0;i<size_masuv;i++)
{
    arr2[i]=arr2[i]-arr2[i+1];
}
arr2[size_masuv-1]=0;
for(i=0;i<size_masuv;i++)
{
    printf("%d, ", arr2[i]);

}
//Поміняти значення останнього мінімального і останнього максимального елементів місцями.

printf("\nPominatu znachenna ostannogo min i max elementa: ");
for(i=0;i<size_masuv;i++)
{
    arr3[0]=max;
    arr3[0]=min;
    if(arr3[i]>=max){
        max=arr3[i];
    }
    if(arr3[i]<=min){
        min=arr3[i];
    }

}
printf(" \nmin element %d, max element %d ", min, max);
 e=max;
    max=min;
    min=e;

printf(" min element %d, max element %d ", min, max);
//Поміняти перші K мінімальних елементів масиву з першими K максимальними.
printf("\nVedit kilkist min elementiv -> max elementu: ");
scanf("%d", &r);
int indmin, indmax;
int temp;

for(j = 0; j<r; j++){
max1 = INT_MIN;
min1 = INT_MAX;
indmax = -1;
indmin = -1;

for(i=0;i<size_masuv;i++)
{
    if(b[i] == 0){
    if(max1<arr4[i]){
        max1 = arr4[i];
        indmax = i;
    }
    if(min1<arr4[i]){
        min1 = arr4[i];
        indmin = i;
    }
    }
}
temp = arr4[indmin];
arr4[indmin] = arr4[indmax];
arr4[indmax] = temp;
b[indmin] = 1;
b[indmax] = 1;
}
for (i = 0; i < size_masuv; i++)
    printf("%6i", arr4[i]);
return 0;
}
