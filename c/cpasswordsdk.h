#ifndef CPASSWORDSDK_H
#define CPASSWORDSDK_H

typedef void* ObjectHandle;

#define PSDK_RC_SUCCESS 0
#define PSDK_RC_ERROR -1

#ifdef __cplusplus
extern "C"
{
#endif

ObjectHandle PSDK_CreateRequest(char* pzRequestType);
int PSDK_SetAttribute(ObjectHandle hRequest, char* pzAttrName, char* pzAttrVal);	
char** PSDK_GetAttribute(ObjectHandle hResponse, char* pzAttrName);	
int PSDK_GetPassword(ObjectHandle hRequest, ObjectHandle* phResponse);
void PSDK_ReleaseHandle(ObjectHandle* phObj);
void PSDK_ReleaseAttributeData(char*** pppData);
int PSDK_GetErrorCode(ObjectHandle hObj);
const char* PSDK_GetErrorMsg(ObjectHandle hObj);

#ifdef __cplusplus
}
#endif

#endif
