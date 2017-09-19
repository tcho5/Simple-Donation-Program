#
# Specifiy the target
all:	CA2

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
CA2:	CA2.o
	g++  Donor.o CA2.o DonorDatabase.o -o Donate.exe


# Specify how the object files should be created from source files
CA2.o:	CA2.cpp Donor.h Donor.cpp DonorDatabase.h DonorDatabase.cpp

	g++ -c CA2.cpp
	g++ -c Donor.cpp
	g++ -c DonorDatabase.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o Donate.exe

