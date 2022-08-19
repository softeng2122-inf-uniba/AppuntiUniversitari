#include <stdio.h>
#include <stdlib.h>

int main()
{
    int esito;
    srand(time(NULL));
    esito=(rand()%100)+1;//genera numeri casuali tra 1 e 100
    printf("\n Il numero uscito è %d ",esito);
    esito=(rand()%50)+100;//genera numeri casuali tra 100 e 150
    printf("\n Il numero uscito è %d ",esito);
    return 0;
}
