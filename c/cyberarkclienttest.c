#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "cyberarkclient.h"

int main(int argc,char* argv[])
{
    char* cbkCredFilePath=argv[1];
    char* cbkSafe=argv[2];
    char* cbkFolder=argv[3];
    char* cbkObject=argv[4];

    char* p = getpassword(cbkCredFilePath,cbkSafe,cbkFolder,cbkObject);
    printf("#####password:%s\n",p);
    free(p);
}
