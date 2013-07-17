# -*- coding: utf-8 -*-
from ctypes import *
import os
import sys

abspath = os.path.dirname(__file__)
sys.path.append(abspath)
os.chdir(abspath)
#sys.path.append(os.getcwd())


def getpasswod(cbkCredFilePath,cbkSafe,cbkFolder,cbkObject)
    lib = cdll.LoadLibrary("libcyberarkclient.so")
    pi=lib.getpassword(cbkCredFilePath,cbkSafe,cbkFolder, cbkObject)  # modified by actual parameter
    p=c_char_p(pi)
    print p.value
    lib.freepassword(p)


if __name__ == '__main__' :
    getpasswod("/etc/opt/CARKaim/vault/AppUser.cred","XXX","Root", "Object")  # modified by actual parameter
