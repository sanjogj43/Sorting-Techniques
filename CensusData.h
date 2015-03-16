/**	
 * @file CensusData.h   Declaration of the CensusData class.
 *
 * @author Judy Challinger
 * @date 2/22/13
 */

#ifndef CSCI_311_CENSUSDATA_H
#define CSCI_311_CENSUSDATA_H

#include <fstream>
#include <vector>
#include <string>

class CensusData {
private:
   class Record {                         // declaration of a Record
   public:
      std::string* city;
      std::string* state;
      int population;
      Record(std::string&, std::string&, int);
      ~Record();
	  bool lessThanOrEqualTo(int type,Record *object);
      bool greaterThan(int type, Record* object);
   };
   std::vector<Record*> data;             // data storage

   //my methods
   void mergeSort(int type,int p, int r);

   void merge(int type,int p,int q,int r);

   void fillTheVectors(std::vector<Record*> &left, std::vector<Record*> &right,
			int n1,int n2,int p,int q);

   void mergeInsertElements(std::vector<Record*> &insertVector,
	        int &var,int &vectorIndex,int &flag,int n);

   void mergeInsertLeftoverElements(std::vector<Record*> &insertVector,
			int var,int n,int vectorIndex);

   void quickSort(int type,int p,int r);

   int partition(int type,int p,int r);

   void swapRecords(int index1,int index2);

public:
   static const int POPULATION = 0;       // type of sort
   static const int NAME = 1;
   ~CensusData();
   void initialize(std::ifstream&);       // reads in data
   int getSize(){return this->data.size();}
   void print();                          // prints out data
   void insertionSort(int);               // sorts data using insertionSort
   void mergeSort(int);                   // sorts data using mergeSort
   void quickSort(int);                   // sorts data using quickSort

   
   
//
// You may add private helper functions here - do not change anything above!!
//

};

#endif // CSCI_311_CENSUSDATA_H