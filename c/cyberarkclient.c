#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "cpasswordsdk.h"

char* getpassword (char* cbkCredFilePath,char* cbkSafe, char* cbkFolder, char* cbkObject)
{
  
    int iRc = 0;
    ObjectHandle hResponse = NULL;
    ObjectHandle hRequest = NULL;
    char** pVals = NULL;
    char QueryStr[200];

    char* password = NULL;

    //
    // Get request handle
    //
    hRequest = PSDK_CreateRequest("PASSWORD");
    if (hRequest != NULL)
    {
        //
        // Prepare request
        //
        iRc = PSDK_SetAttribute(hRequest, "AppDescs.CredFilePath", cbkCredFilePath);
        if (iRc == PSDK_RC_ERROR)
        {
            printf("set AppDescs.CredFilePath error!\n" ); 
            if (hRequest != NULL)
            {
                PSDK_ReleaseHandle(&hRequest);
            }

            return NULL;
        }
        sprintf(QueryStr, "Safe=%s;Folder=%s;Object=%s", cbkSafe, cbkFolder, cbkObject);
        iRc = PSDK_SetAttribute(hRequest, "Query", QueryStr);
        if (iRc == PSDK_RC_ERROR)
        {
            printf("set Query error!\n");
            if (hRequest != NULL)
            {
                PSDK_ReleaseHandle(&hRequest);
            }

            return NULL;
        }
                                                                                                                                                      //
        // Send request
        iRc = PSDK_GetPassword(hRequest, &hResponse);
        if (iRc == PSDK_RC_ERROR)
        {
             printf("error code: [%d], error message: [%s]\n",PSDK_GetErrorCode(hRequest),PSDK_GetErrorMsg(hRequest));
        }
        else
        {
            pVals = PSDK_GetAttribute(hResponse, "Password");
            if (pVals == NULL)
            {
                printf("error code: [%d], error message: [%s]\n",
                PSDK_GetErrorCode(hResponse),
                PSDK_GetErrorMsg(hResponse));
            }
            else
            {
                password = (char *) malloc(strlen(pVals[0])+1);
                strcpy(password,pVals[0]);
                PSDK_ReleaseAttributeData(&pVals);
            }
        }
    }

    if (hRequest != NULL)
    {
        PSDK_ReleaseHandle(&hRequest);
    }

    if (hResponse != NULL)
    {
        PSDK_ReleaseHandle(&hResponse);
    }

    return password;

}

int freepassword (char* p)
{
    if (p!=NULL)
    {
         free(p);
    }

    return EXIT_SUCCESS;
}

