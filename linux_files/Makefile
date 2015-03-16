csort : CensusSort.o CensusData.o CensusDataSorts.o
	g++ -o csort CensusSort.o CensusData.o CensusDataSorts.o -lrt

CensusSort.o : CensusSort.cpp CensusData.h
	g++ -c CensusSort.cpp

CensusData.o : CensusData.cpp CensusData.h
	g++ -c CensusData.cpp

CensusDataSorts.o : CensusDataSorts.cpp CensusData.h
	g++ -c CensusDataSorts.cpp
	
clean :
	rm csort *.o
