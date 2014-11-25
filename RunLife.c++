// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------
// --------
// includes
// --------

/*
To run the program:
% g++ -pedantic -std=c++0x -Wall AbstractCell.c++ Cell.c++ ConwayCell.c++ FredkinCell.c++ -o RunLife
% valgrind RunLife > RunLife.out

To configure Doxygen:
doxygen -g
That creates the file Doxyfile.
Make the following edits:
EXTRACT_ALL = YES
EXTRACT_PRIVATE = YES
EXTRACT_STATIC = YES
GENERATE_LATEX = NO

To document the program:
doxygen Doxyfile
*/
#include <cassert> // assert
#include <iostream> // cout, endl
#include <stdexcept> // invalid_argument, out_of_range
#include <fstream>
#include <string>
#include "Life.h"
	// ----
	// main
	// ----
	int main () {

	try {
		ifstream myfile ("RunLife.in");
		using namespace std;
		if(myfile.is_open()){
			string line;
 			getline (myfile,line);

			int height_;
			int width_;



			
		// -----------------
		// Conway Cell 21x13
		// -----------------
			cout << "*** Life<ConwayCell> 21x13 ***" << endl;
			cout<<endl;
		/*
		Simulate 12 evolutions.
		Print every grid (i.e. 0, 1, 2, 3, ... 12)
		*/
			getline(myfile,line);
			height_=atoi(line.c_str());
			getline(myfile,line);
			width_ = atoi(line.c_str());
			getline(myfile, line);
			Life<ConwayCell> temp(width_,height_);
			int line_number = 1;
			while(!line.empty()){
				for(int j = 1 ; j < width_; ++j)
					temp.init(line_number, j, line.substr(j-1,1));
				getline(myfile,line);
				++line_number;
			}

			for(int i = 0; i<13; ++i){
				cout<<"Generation = "<<temp.generation()<<", Population = "<<temp.population()<<"."<<endl;
				temp.printgrd();
				temp.incrementOneGeneration();
				cout<<endl;
			}
		// -----------------
		// Conway Cell 20x29
		// -----------------

		/*
		Simulate 28 evolutions.
		Print every 4th grid (i.e. 0, 4, 8, ... 28)
		*/
		cout << "*** Life<ConwayCell> 20x29 ***" << endl;
		cout<<endl;
		getline(myfile, line);

		getline(myfile,line);
		height_=atoi(line.c_str());
		getline(myfile,line);
		width_ = atoi(line.c_str());
		getline(myfile, line);
		Life<ConwayCell> temp2(width_,height_);
		line_number = 1;
		while(!line.empty()){
			for(int j = 1 ; j <= width_; ++j)
				temp2.init(line_number, j, line.substr(j-1,1));
			getline(myfile,line);
			++line_number;
		}

		for(int i = 0; i<=28; ++i){
			if( i%4 == 0){			
				cout<<"Generation = "<<temp2.generation()<<", Population = "<<temp2.population()<<"."<<endl;
				temp2.printgrd();
				temp2.incrementOneGeneration();
				cout<<endl;
			}else
				temp2.incrementOneGeneration();

		}
		// ------------------
		// Conway Cell 109x69
		// ------------------
		/*
		Simulate 283 evolutions.
		Print the first 10 grids (i.e. 0, 1, 2, ... 9).
		Print the 283rd grid.
		Simulate 40 evolutions.
		Print the 323rd grid.
		Simulate 2177 evolutions.
		Print the 2500th grid.
		*/
		cout << "*** Life<ConwayCell> 109x69 ***" << endl;
		cout<<endl;
		getline(myfile, line);

		getline(myfile,line);
		height_=atoi(line.c_str());
		getline(myfile,line);
		width_ = atoi(line.c_str());
		getline(myfile, line);
		Life<ConwayCell> temp3(width_,height_);
		line_number = 1;
		while(!line.empty()){
			for(int j = 1 ; j <= width_; ++j)
				temp3.init(line_number, j, line.substr(j-1,1));
			getline(myfile,line);
			++line_number;
		}

		for(int i = 0; i<2501; ++i){
			if( i<10 || i == 283 || i == 323 || i == 2500){			
				cout<<"Generation = "<<temp3.generation()<<", Population = "<<temp3.population()<<"."<<endl;
				temp3.printgrd();
				temp3.incrementOneGeneration();
				cout<<endl;
			}else
				temp3.incrementOneGeneration();

		}
		// ------------------
		// Fredkin Cell 20x20
		// ------------------
		cout << "*** Life<FredkinCell> 20x20 ***" << endl;
		cout<<endl;
		getline(myfile, line);

		getline(myfile,line);
		height_=atoi(line.c_str());
		getline(myfile,line);
		width_ = atoi(line.c_str());
		getline(myfile, line);
		Life<FredkinCell> temp4(width_,height_);
		line_number = 1;
		while(!line.empty()){
			for(int j = 1 ; j <= width_; ++j)
				temp4.init(line_number, j, line.substr(j-1,1));
			getline(myfile,line);
			++line_number;
		}

		for(int i = 0; i<6; ++i){	
			cout<<"Generation = "<<temp4.generation()<<", Population = "<<temp4.population()<<"."<<endl;
			temp4.printgrd();
			temp4.incrementOneGeneration();
			cout<<endl;
		}
		/*
		Simulate 5 evolutions.
		Print every grid (i.e. 0, 1, 2, ... 5)
		*/
		// ----------
		// Cell 20x20
		// ----------
		cout << "*** Life<Cell> 20x20 ***" << endl;
		cout<<endl;
		getline(myfile, line);

		getline(myfile,line);
		height_=atoi(line.c_str());
		getline(myfile,line);
		width_ = atoi(line.c_str());
		getline(myfile, line);
		Life<Cell> temp5(width_,height_);
		line_number = 1;
		while(!line.empty()){
			for(int j = 1 ; j <= width_; ++j)
				temp5.init(line_number, j, line.substr(j-1,1));
			getline(myfile,line);
			++line_number;
		}

		for(int i = 0; i<6; ++i){	
			cout<<"Generation = "<<temp5.generation()<<", Population = "<<temp5.population()<<"."<<endl;
			temp5.printgrd();
			temp5.incrementOneGeneration();
			cout<<endl;
		}
	myfile.close();
	}
    }
    catch (const invalid_argument&) {
        assert(false);}
    catch (const out_of_range&) {
        assert(false);}
		/*
		Simulate 5 evolutions.
		Print every grid (i.e. 0, 1, 2, ... 5)
		*/
		return 0;
}
