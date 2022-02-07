#include<iostream>
#include<stdio.h>
#include<string>
#define size_ 100
using namespace std;



//////////////////////////////////////////SAAD ATHER 21L-7289 MS(DS) FAST NUCES LAHORE//////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////THIS PROGRAM SHOWS ARRAY IN LINEAR FORMAT FOR DIMENSIONS GREATER THAN 3//////////////////////
//////////////////////////////////////////THAT IS IN THE FORM OF ARRAY O ARRAYS/////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
class ndarray {


public:

	int rows;
	int cols;
	int dim, t_size = 1;
	int* arry;
	int* ext_arry;
	int* shrink_arry;
	int index_arr[size_];
	

	friend class Vector;

	ndarray() {							////constructor

		cout << "enter the number of dimensions ";
		cin >> dim;


		for (int i = 0; i < dim; i++) {
			cout << "enter total rows/column index " << i << " of array ";
			cin >> index_arr[i];
			
			t_size = t_size * index_arr[i];
		}
		if (dim < 3) { rows = index_arr[0]; cols = index_arr[1];  }

		arry = new int[dim];
		ext_arry = new int[dim * 2];
	}
	
	ndarray(const ndarray& p1) {		/////copy constructor

		dim=p1.dim;
		t_size=p1.t_size;
		arry = p1.arry;
		
		for (int i = 0; i < t_size; i++) { arry[i] = p1.arry[i]; }
	}



	T* enter_elements() {			/////elements entry into array


		for (int i = 0; i < t_size;) {

			
			cout << "enter elements for the array index [" << i << "] " << " ";
			cin >> arry[i];
			if (arry[i]<=t_size){
				i++;
			}
			else { cout << " enter valid array index " << endl; }
		}
		return arry;

	}

	T* insert()					////single element insertion at a certian index
	{
		int pos;
		int add;
		char function[][50] = { "INSERTION" };
		cout << endl;
		cout << "enter elememt to be add " << endl;
		cin >> add;
		pos = element_pos_calculator(dim, *function);
		
		arry[pos] = add;
		for (int i = 0; i < t_size; i++) {	
			cout << arry[i] << "   ";
		}


		return arry;

	}

	T* delete_element() {				////// delete the element at the specified index

		int pos,j=0;
		int add;
		bool found = false;
		char function[][50] = { "DELETION" };
		cout << endl;
		cout << "enter elememt to be deleted " << endl;
		cin >> add;
		pos = element_pos_calculator(dim, *function);



		for (int i = 0; i < t_size; i++) {
			if (arry[i] == add) {
				arry[pos] = NULL;
				found = true;
				j = i;
			}
		}
		if (found) {
			for (; j < t_size; j++) {
				arry[j] = arry[j + 1];
			}
		}

		cout << " ARRAY AFTER DELETION IS: ";
		for (int i = 0; i < t_size;  i++) {
			cout << arry[i]<<" ";
		}cout << endl;  return arry;

	}

	void retrieve() {			///retrieve the elements from given index of array

		int pos;
		int serach_elem = 0;
		int add;
		bool found=false;
		cout << endl;

		while (!found )
		{
			cout << "Enter elememt to be retrived " << endl;
			cin >> add;

			for (int i = 0; i < t_size;)
			{

				if (arry[i] == add) {
					cout << "found required element '" << add << "' at index " << i << " of the arry" << endl;
					serach_elem = add;
					found = true;
				}

				i++;
			}

			if(!found){
			cout << "ELEMENT NOT FOUND IN ARRAY, ENTER VALID NUMBER "<<endl; }
		}

		//return serach_elem;
	}

	void print() {					////print the aray

		cout <<endl<< "PRINTING ARRAY : ";

		if (dim < 3) {

			for (int k = 0; k < rows; k++)
				{							
					for (int m = 0; m < cols; m++)
						{
						cout << *((arry + k) + m) << " ";
						}	
				}
		}

		if (dim >= 3)
		{
			for (int i = 0; i < t_size; i++) {

				cout << "Elements for the array at index [" << i << "] " << " " << *arry<< endl;
			}
		}
	}

	void extend() {					////double the array in size for multi dimension

		for (int i = 0; i < t_size; i++)
		{
			ext_arry[i] = arry[i];
		}

		//return *ext_arry;
	}


	void shrink() {				////////// half the size of the array

		for (int i = 0; i < (t_size/2); i++)
		{
			shrink_arry[i] = arry[i];
		}


	}

	int element_pos_calculator(int dims, char* fun) {  ///// position calculations based on given index of rows,cols and rows of cols etc..

		int multi, summ = 0;
		int pos_arr[size_];

		for (int i = 0; i < dims; )
		{
			cout << "enter the array elements for index " << " " << fun << " ";
			cin >> pos_arr[i];
			if (pos_arr[i] <= index_arr[i]) {
				i++;
			}
			else { cout << "enter valid value: " << endl; }

		}

		for (int i = 0; i < dims; i++)
		{
			multi = pos_arr[i];
			for (int j = i + 1; j < dims; j++)
			{
				multi = multi * pos_arr[j];
			}
			summ = summ + multi;
		}
		return summ;
		cout << summ;
	}



	class subscript_opt			////subscript operators
	{
	private:
		int* ptr;
		int items;  // Number of actual elements in the vector

	public:
		friend class ndarray;


		subscript_opt(int t_size, int arr[]) {

			ptr = new int[t_size];
			for (int i = 0; i < t_size; i++) {
				ptr[i] = arr[i];
			}
			items = t_size;
		}

		int& operator[] (int i) {
			return ptr[i];
		}


		int& operator()(int i, int j) {
			return ptr[i + j];
		}


		int& operator()(int i, int j, int k) {
			return ptr[i + j + k];
		}
		int& operator()(int arr[]) {
			return ptr[arr[1]];
		}

		~subscript_opt() {
			
			delete ptr;
			
		}

	};

		~ndarray() {

			for (int i = 0; i < t_size; i++) {

				delete[] arry;
				delete[] ext_arry;
				delete[] shrink_arry;
				delete[] index_arr;
			}

		}

};







int main() {

	ndarray<int> ndobj;
	ndarray<int> ndobj2(ndobj);

	int* arryy;


	cout << endl << endl<<"THIS PROGRAM SHOWS ARRAY IN LINEAR FORM i.e. IN ARRAY OF ARRAYS FORM " << endl << endl;


	arryy = ndobj.enter_elements();

	ndobj.insert();
	ndobj.delete_element();
	ndobj.retrieve();
	ndobj.print();
	ndobj.extend();
	ndobj.shrink();


	cout << endl << endl;
	
	ndarray<int> :: subscript_opt v2(size_, arryy);

	cout << v2[2] << endl;
	cout << v2(2, 2) << endl;
	cout << v2(2, 2, 1) << endl; 
}