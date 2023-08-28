#include "fcgi_stdio.h"
#include <stdlib.h>
int main()
{
    const char *Data = ""
            "Hello World!";
    while(FCGI_Accept() >=0 )
        printf("Content-type: application/json\r\n"
               "\r\n"
               "%s", Data);
    return 0;
}