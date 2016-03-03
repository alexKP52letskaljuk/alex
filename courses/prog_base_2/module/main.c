#include <stdio.h>
#include <stdlib.h>
#include "module.h"

int main()
{
    int n;
    int index, format;
    int cntMax;
    char str[200];

    printf("Vedit max kilkist rechen:");
    scanf("%i", &cntMax);
    printf("\nVedit 1 rechennya.\n");
    scanf("%s", str);
    text_t pStruct = text_new(cntMax,str);


    printf("1. Dodatu rechenya.\n2. Vudalutu rechenya.\n3.Vuberu format.\n");
    printf("4.Otrunai perelic rechen specialnogo formatu.\n5.Otrumai perelik tvoih rechen.\n6.Vuhid\n\n ");
    for(;;)
    {
        text_getList(pStruct);
        printf("\n\nVvedu nomer komandu: ");
        fflush(stdin);
        scanf("%i", &n);
        switch(n)
        {
            case 1:
            printf("Napushu index i stroku.\n");
            scanf("%i %s", &index, str);
            text_Insert(pStruct,index,str);
            break;
        case 2:
            printf("Napushu index: ");
            scanf("%i", &index);
            text_deleteStr(pStruct, index);
            break;
        case 3:
            printf("Napushu index (0...%i) i potim jogo format (0..3):\n", pStruct->cntReal - 1);
            scanf("%i %i", &index, &format);
            text_setFormat(index, format,pStruct);
            break;
        case 4:
            printf("Vedit nomer formaty (0..3):\n");
            scanf("%i", &format);
            text_getListForm(pStruct,format);
            break;
        case 5:
            printf("%i", text_getRealCntStr(pStruct));
            break;
        default:
            text_delete(pStruct);
            return 0;
            break;
        }
    }

}

