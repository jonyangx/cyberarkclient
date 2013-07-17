cyberark client
-----------------
主要是封装c客户端，供c语言程序和python程序调用  

### 复制头文件  
- 从/opt/CARKaim/sdk/中获取cpasswordsdk.h,放到程序编译目录

### 复制动态链接库  
- 从/opt/CARKaim/sdk/中获取libcpasswordsdk.so放到/usr/lib目录下
- 在/lib64下做ln -s /usr/lib/libcpasswordsdk.so /lib64/libcpassword.so

### 编译客户端成动态链接库

        gcc -c -fPIC cyberarkclient.c -o cyberarkclient.o
        gcc -shared -o libcyberarkclient.so  cyberarkclient.o -lcpasswordsdk



