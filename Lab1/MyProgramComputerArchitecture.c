#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t *p;

int main()
{
    p = (uint8_t *)malloc(100 * sizeof(uint8_t)); // dynamic memory allocation 
    
    for(uint8_t i = 0; i < 100; i++)
    {
        p[i] = i;
        printf("i = %hu, p[i] = %hu\n",i, p[i]);
    }
    free(p);
    return 0;
}
