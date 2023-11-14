#This is a python script to build the whole project 
import shutil
import os

Dest="./"

TDSHeaderFilePath="../TDS/inc/TDS.h"
TDSWrapperFilePath="../TDS/inc/TDS_Wrp.h"


# Copy
shutil.copy(TDSHeaderFilePath , Dest)
#shutil.copy(TDSWrapperFilePath , "./")

print("Hello World")
