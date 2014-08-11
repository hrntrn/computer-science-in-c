#include <iostream.h>
#include <conio.h>
#include <fstream.h>

/*

 Sorting by exchanging -> bubblesort

*/

//prototypes
//--------------------
void read();
void display();
void bubblesort();
void swap(int i,int j);
void write();
//--------------------

//input
ifstream fin("c:\\file.in");

//output
ofstream fout("c:\\file.out");

//declare an array of integers
//global vector
int v[30],
    //store the number of elements
    //global variable
    n;

//main function
void main() {

     //clear screen
     clrscr();

     //input array
     cout<<"Bubble Sort:\n\------------\n\nInput";

     //read from file
     read();

     //display on screen
     display();

     //do sorting method insertion sort
     bubblesort();

     //output the result
     cout<<"\n\nOutput";

     //display on screen
     display();

     //write to output File
     write();

     cout<<"\n\n\nPress any key for exit\nhttp://thinkphp.ro";
     getch();
}

void read() {

     fin>>n;

     for(int i=0;i<n;i++) {

	 fin>>v[i];
     }

     fin.close();
}

void bubblesort() {

     int i,

	 j,

         k = -1,

	 swapped = 0;

	 do {

	    swapped = 0;

	    k++;

	    for(i = 0; i < n - k - 1; i++) {

		if( v[ i ] > v[ i + 1] ) {

		    swap(i, i + 1);

		    swapped = 1;
		}
	    }

	 } while(swapped);

}


void swap(int i, int j) {

     int xor;

     xor = v[i] ^ v[i+1];

     v[i] = xor ^ v[i];

     v[i+1] = xor ^ v[i+1];
}


void write() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 fout<<v[i]<<" ";
     }

     fout.close();
}

void display() {

     cout<<"\n";

     for(int i=0;i<n;i++) {

	 cout<<v[i]<<" ";
     }
}
