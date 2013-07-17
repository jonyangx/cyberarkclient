#ifndef CYBERARKCLIENT_H
#define CYBERARKCLIENT_H

#ifdef __cplusplus
extern "C"
{
#endif

char* getpassword  (char* cbkCredFilePath,char* cbkSafe, char* cbkFolder, char* cbkObject);
int   freepassword (char* p);

#ifdef __cplusplus
}
#endif

#endif