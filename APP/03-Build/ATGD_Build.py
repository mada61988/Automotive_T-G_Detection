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
TDSIncFilePath="../01-TDS/inc/"
TDSSrcFilePath="../01-TDS/src/"
	#GDS
GDSIncFilePath="../02-GDS/inc/"
GDSSrcFilePath="../02-GDS/src/"
	#DIO
DIOFilePath="../../MCAL/01-DIO/"
	#OS
OSFilePath="../../OS/"
	#LIB
LIBFilePath="../../LIB/"
mainFilePath = "../main.c"
	#ADC
ADCSrcFilePath = "../../MCAL/02-ADC/src/"
ADCIncFilePath = "../../MCAL/02-ADC/inc/"

	#ADC
LCDSrcFilePath = "../../HAL/01-LCD/src/"
LCDIncFilePath = "../../HAL/01-LCD/inc/"

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

	copyDirectoryContent(TDSIncFilePath)
	copyDirectoryContent(TDSSrcFilePath)

	copyDirectoryContent(GDSIncFilePath)
	copyDirectoryContent(GDSSrcFilePath)

	copyDirectoryContent(DIOFilePath)


	copyDirectoryContent(OSFilePath)

	copyDirectoryContent(ADCIncFilePath)
	copyDirectoryContent(ADCSrcFilePath)

	copyDirectoryContent(LIBFilePath)

	copyDirectoryContent(LCDIncFilePath)
	copyDirectoryContent(LCDSrcFilePath)

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