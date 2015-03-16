/**
 * @file CensusData.cpp   Represents census population data.
 * 
 * @brief
 *    This file contains all of the sorting functions and their helpers.
 * 
 * @author 
 * @date 
 */

#include "CensusData.h"

//CensusData::Record::Record(std::string &city, std::string &state, int population)
//{
//
//}
void CensusData::insertionSort(int type) 
{
    for(int j=1;j<this->data.size();j++)
	{
		Record *key = new Record(*this->data[j]->city,*this->data[j]->state,this->data[j]->population);

		int i = j-1;
		while(i>=0 && this->data[i]->greaterThan(type,key))
		{
			this->data[i+1] = this->data[i];
			i--;
		}

		this->data[i+1]=key;
	}
}

void CensusData::mergeSort(int type) 
{
	this->mergeSort(type,0,this->data.size()-1);
}

void CensusData::quickSort(int type) 
{
	this->quickSort(type,0,this->data.size()-1);
}

//private methods
//
bool CensusData::Record::lessThanOrEqualTo(int type,Record *object)
{
	if(type == CensusData::POPULATION)
	{
		if(this->population <= object->population)
		{
		return true;
		}
		return false;
	}
	else if (type==CensusData::NAME)
	{
		if(*this->city <= *object->city)
		{
		return true;
		}
		return false;
	}
}

bool CensusData::Record::greaterThan(int type,Record *object)
{
	if(type == CensusData::POPULATION)
	{
		if(this->population > object->population)
		{
		return true;
		}
		return false;
	}
	else if(type == CensusData::NAME)
	{
		if(*this->city > *object->city)
		{
		return true;
		}
		return false;
	}
}


//my methods



		//
		void CensusData::mergeSort(int type,int p, int r)
		{
			if(p<r)
			{
				int q = (p+r)/2;
				mergeSort(type,p,q);
				mergeSort(type,q+1,r);
				merge(type,p,q,r);
			}
	    }

		//
		void CensusData::merge(int type,int p, int q, int r)
		{
			int n1 = q+1 - p;
			int n2 = r-q;
	
			std::vector<Record*> left;
			std::vector<Record*> right;
	        
			//push the elements in left and right vectors.
			fillTheVectors(left,right,n1,n2,p,q);

			int i=0,j=0,flagi=0,flagj=0,k;
			
			for(k = p; k <= r; k++)
			{
				if(flagi==0 && flagj==0)
				{
					if(left[i]->lessThanOrEqualTo(type,right[j]))//left[i]->name<=right[j]->name)
					{
						mergeInsertElements(left,i,k,flagi,n1);	
						if(flagi == 1)
							break;
					}

					else //if(left[i]->name>right[j]->name)
					{
						mergeInsertElements(right,j,k,flagj,n2);	
						if(flagj == 1)
							break;
					}
				}
			}

			// to insert the elements left out from vector 'Right'
			if(flagi==1)
			{
				mergeInsertLeftoverElements(right,j,n2,k);				
			}

			// to insert the elements left out from vector 'Left'
			else if(flagj==1)
			{
				mergeInsertLeftoverElements(left,i,n1,k);				
			}

		}

		void CensusData::fillTheVectors(std::vector<Record*> &left, std::vector<Record*> &right,
			int n1,int n2,int p,int q)
		{
		    for(int i=0;i<n1;i++)
			{
				left.push_back(this->data[p+i]);
			}

	        //push the elements on right vector. 
			for(int i=0;i<n2;i++)
			{
				right.push_back(this->data[q+i+1]);
			}
		}
		 
		//
		void CensusData::mergeInsertElements(std::vector<Record*> &insertVector,int &var,int &vectorIndex,
			int &flag,int n)
		{
			this->data[vectorIndex] = new Record(*insertVector[var]->city, *insertVector[var]->state,insertVector[var]->population);
			var++;
			if(var==n)
			{
				flag=1;
				vectorIndex++;
			}
		}

		//
		void CensusData::mergeInsertLeftoverElements(std::vector<Record*> &insertVector,
			int var,int n,int vectorIndex)
		{
			for(int m = var;m<n;m++)
			{
				this->data[vectorIndex]= new Record(*insertVector[m]->city,*insertVector[m]->state,insertVector[m]->population);
				vectorIndex++;
			}
		}

		//
		void CensusData::quickSort(int type,int p,int r)
		{
			if(p<r)
			{
			   int q= partition(type,p,r);
			   quickSort(type,p,q-1);
			   quickSort(type,q+1,r);
			}
		}

		//
		int CensusData::partition(int type,int p,int r)
		{
			Record *pivot = new Record(*this->data[r]->city,*this->data[r]->state,this->data[r]->population);

		   int i = p-1;

		   for(int j=p;j<=r-1;j++)
		   {
			  if(this->data[j]->lessThanOrEqualTo(type,pivot))
			  {
				 i++;
				 this->swapRecords(i,j);
			  }
		   }
		   this->swapRecords(i+1,r);
		   //delete pivot;
		   return i+1;
		}

		void CensusData::swapRecords(int index1,int index2)
		{
			Record *temp= new Record(*this->data[index1]->city,*this->data[index1]->state,this->data[index1]->population);
				 this->data[index1] = this->data[index2];
				 this->data[index2] = temp;
				 //delete temp;
		}

		