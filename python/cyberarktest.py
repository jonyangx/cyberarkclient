# -*- coding: utf-8 -*-
from ctypes import *
import os
import sys
import getopt

abspath=os.path.abspath(__file__)
sys.path.append(os.path.dirname(abspath))
#os.chdir(abspath)
#sys.path.append(os.getcwd())


lib = cdll.LoadLibrary("libcyberarkclient.so")

def getpasswod(cbkCredFilePath,cbkSafe,cbkFolder,cbkObject):
    #lib = cdll.LoadLibrary("libcyberarkclient.so")
    pi=lib.getpassword(cbkCredFilePath,cbkSafe,cbkFolder, cbkObject)  # modified by actual parameter
    p=c_char_p(pi)
    #a = p.value
    #lib.freepassword(p)
    return p

def freepassword(p) :
    if p :
        lib.freepassword(p)

def usage() :
    print '''
            cyberarktest.py -c credfilepath -s safe -f folder -o object
            '''

if __name__ == '__main__' :
    try :
        opts,args = getopt.getopt(sys.argv[1:],'hc:s:f:o:')
    except getopt.GetoptError:
        usage()
        sys.exit()

    if len(opts) == 0 :
        usage()
        sys.exit

    cbkCredFile=None
    cbkSafe=None
    cbkFolder=None
    cbkObject=None

    for opt,arg in opts :
        if opt in ('-h','--help') :
            usage()
            sys.exit()
        elif opt == '-c':
            cbkCredFile=arg
        elif opt == '-s':
            cbkSafe=arg
        elif opt == '-f' :
            cbkFolder=arg
        elif opt == '-o' :
            cbkObject=arg
    print cbkCredFile,',',cbkSafe,',',cbkFolder,',',cbkObject    
    p = getpasswod(cbkCredFile,cbkSafe,cbkFolder,cbkObject)  # modified by actual parameter
    print p.value
    freepassword(p);
