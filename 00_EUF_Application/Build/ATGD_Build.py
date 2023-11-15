#This is a python script to build the whole project 
import shutil
import os

print("--------- 1- Build project---------")
print("--------- 2- Flash Binaries ---------")
print("--------- 3- Build and Flash ---------")
USER_INPUT=int(input("ACTION: "))

#Stds
destination_folder="./"


#DirectoryPath
	#TDS
TDSIncFilePath="../TDS/inc/"
TDSSrcFilePath="../TDS/src/"
	#GDS
GDSIncFilePath="../GDS/inc/"
GDSSrcFilePath="../GDS/src/"
	#DIO
DIOFilePath="../../01_ECF_Package/Appl/Source/BSW/DIO/"
	#LM35
LM35IncFilePath="../../01_ECF_Package/Appl/Source/BSW/LM35/inc/"
LM35SrcFilePath="../../01_ECF_Package/Appl/Source/BSW/LM35/src/"
	#MQ2
MQ2IncFilePath="../../01_ECF_Package/Appl/Source/BSW/MQ2/inc/"
MQ2SrcFilePath="../../01_ECF_Package/Appl/Source/BSW/MQ2/src/"
	#OS
OSFilePath="../../01_ECF_Package/Appl/Source/BSW/OS/"
	#RTE
RTEIncFilePath="../../01_ECF_Package/Appl/Source/BSW/RTE/inc/"
RTESrcFilePath="../../01_ECF_Package/Appl/Source/BSW/RTE/src/"
	#CONFIG
ConfigFilePath="../../01_ECF_Package/Appl/Source/BSW/Config/"
mainFilePath = "../main.c"

ADCSrcFilePath = "../../01_ECF_Package/Appl/Source/BSW/ADC/src/"
ADCIncFilePath = "../../01_ECF_Package/Appl/Source/BSW/ADC/inc/"

# Function Implementation
def copyDirectoryContent(source_folder):
	# fetch all files
	
	for file_name in os.listdir(source_folder):
		# construct full file path
		source=source_folder+file_name
		destination=destination_folder+file_name
		# copy only files
		if os.path.isfile(source):
			shutil.copy(source, destination)
			print('copied', file_name)

def deleteDirectoryContents():
	# Fetch all files
	
	for file_name in os.listdir(destination_folder):
		if (file_name == "ATGD_Build.py") | (file_name == "makefile"):
			print("======================== This is a restricted file ============================")
		else:
				if os.path.isfile(file_name):
					print("FILE: "+file_name+" Deleted")
					os.remove(file_name)
					
				else: 
					shutil.rmtree(".dep")
					print("DIR: .dep Deleted")
				

#Build or Build and flash
if((USER_INPUT == 1) | (USER_INPUT == 3)): 
	deleteDirectoryContents()

	copyDirectoryContent(RTEIncFilePath)
	copyDirectoryContent(RTESrcFilePath)

	copyDirectoryContent(TDSIncFilePath)
	copyDirectoryContent(TDSSrcFilePath)

	copyDirectoryContent(GDSIncFilePath)
	copyDirectoryContent(GDSSrcFilePath)

	copyDirectoryContent(DIOFilePath)


	copyDirectoryContent(LM35IncFilePath)
	copyDirectoryContent(LM35SrcFilePath)

	copyDirectoryContent(MQ2IncFilePath)
	copyDirectoryContent(MQ2SrcFilePath)

	copyDirectoryContent(OSFilePath)

	copyDirectoryContent(ADCIncFilePath)
	copyDirectoryContent(ADCSrcFilePath)

	copyDirectoryContent(ConfigFilePath)
	shutil.copy(mainFilePath,"./main.c")

	print(" ")
	print("========= MAKE Started ===========")
	print(" ")

	os.system("make")

	if(USER_INPUT == 3):
		os.system("avrdude -p atmega32 -c usbasp -U flash:w:ATGD.hex:i -F -P usb")
	#Endif

if(USER_INPUT==2):
	os.system("avrdude -p atmega32 -c usbasp -U flash:w:ATGD.hex:i -F -P usb")




#avrdude -p atmega32 -c usbasp -U flash:w:ATGD.hex:i -F -P usb