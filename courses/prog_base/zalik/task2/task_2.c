#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
char str[1000];
FILE *f = fopen("in.txt", "r");
FILE* out = fopen("out.txt", "w");
int old_index = 0, old_sum = 0, old_n = 1;
double old_dob = 0;
int index, sum, n;
double dob;
index =0;
 while (fgets(str, 1000, f) != NULL)
    {
        char *num = strtok(str, " ");
        sum = 0;
        n = 0;
        dob = 1;
        while(num != NULL){
            int t;
            sscanf(num, "%u", &t);
            sum += t;
            dob *= t;
            n++;
            num = strtok(NULL, " ");
        }
        if(old_sum < sum)
        {
            old_sum = sum;
            old_dob = dob;
            old_n = n;
            old_index = index;
        }
        index++;
    }
fprintf(out, "%u %lf %u", old_index, old_dob / old_n, old_n);
fclose(f);
fclose(out);
return 0;
}
