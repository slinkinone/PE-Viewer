all: pe clean_object

pe: main.o peheader.o dosheader.o datadirectory.o fileheader.o ntheader.o optionalheader.o importtable.o sectionheader.o peloader.o pefile.o peprinter.o 
	g++ main.o peheader.o dosheader.o datadirectory.o fileheader.o ntheader.o optionalheader.o importtable.o sectionheader.o peloader.o pefile.o peprinter.o -o pe

main.o: main.cpp
		g++ -c main.cpp

peheader.o: peheader.cpp
		g++ -c peheader.cpp

dosheader.o: dosheader.cpp
		g++ -c dosheader.cpp

datadirectory.o: datadirectory.cpp
		g++ -c datadirectory.cpp

fileheader.o: fileheader.cpp
		g++ -c fileheader.cpp

ntheader.o: ntheader.cpp
		g++ -c ntheader.cpp

optionalheader.o: optionalheader.cpp
		g++ -c optionalheader.cpp

importtable.o: importtable.cpp
		g++ -c importtable.cpp

sectionheader.o: sectionheader.cpp
		g++ -c sectionheader.cpp

peloader.o: peloader.cpp
		g++ -c peloader.cpp

pefile.o: pefile.cpp
		g++ -c pefile.cpp

peprinter.o: peprinter.cpp
		g++ -c peprinter.cpp

clean_object:
	rm *o

clean:
	rm *o pe