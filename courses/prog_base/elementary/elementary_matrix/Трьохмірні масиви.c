#include <stdio.h>
#include <stdlib.h>
int main(){
srand(time(NULL));
//•Створити трьохмірний масив NхMxL і заповнити його випадковими символами. Вивести його у консолі у вигляді набору матриць.
int i, j, k;
int size1, size2, size3;
printf("vedit rozmiru masuvy x, y, z: ");
scanf("%d,%d,%d", size1, size2, size3);
int arr[size1][size2][size3];

for(i=0;i<size1;i++){
    for(j=0;j<size2;j++){
        for(k=0;k<size3;k++)
        {
            arr[i][j][k] = rand()% 2 + 1;
            printf("%d", arr[j][k]);
        }
    }
}1
}
