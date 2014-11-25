#include <iostream> // istream, ostream
#include <vector>
#include <fstream>
#include <string>
#include "Life.h"



using namespace std;

	string AbstractCell::getStat(){
		return state;
	}

	string AbstractCell::getName(){
		return name;
	}
	vector<int> AbstractCell::retrules(){
		return rules;
	}
	
	//A simple print statement for when we need to print out the grid.
bool ConwayCell::printsta(){
	if(state == "dead"){
		cout<<".";
		return true;
	}else if(state == "alive"){
		cout<<"*";
		return true;			
	}
	return false;
}

//This function tells us whether or not the state can be switched if it can be switched then we
//return the bool value true. If true we can make the change in the Life grid, if false don't change.
bool ConwayCell::switchStat(int count){
	if(state=="dead" && count==3)
		return true;
	else if(state=="alive" && (count<2 || count>3))
		return true;
	else return false;	
}

void ConwayCell::setState(string x){
	if(x == "*"){
		state = "alive";
		name = x;
	}else if(x == "alive"){
		state = x;
		name = "*";
	}else if(x =="dead"){
		state = x;
		name = ".";
	}else{
		state = "dead";
		name = ".";

	}
}

ConwayCell* ConwayCell::clone(){
	return new ConwayCell(*this);
}


bool FredkinCell::switchStat(int count){
	if(state=="dead" && (count == 1 || count == 3))
		return true;
	else if(state=="alive" && (count == 0 || count == 2 || count == 4))
		return true;
	else return false;	
}

void FredkinCell::setState(string x){
	if(x == "alive" && state=="alive"){
			age++;
		if(age<10)
			name=static_cast<ostringstream*>(& (ostringstream()<<age))->str();
		else
			name="+";
		state = x;
	}else if(x=="alive" && state=="dead"){
			if(age<10)
			name=static_cast<ostringstream*>(& (ostringstream()<<age))->str();
		else
			name="+";
		state = x;
	}else if(x =="+"){
		state = "alive";
		name = x;
	}else if(x =="dead"){
		state = x;
		name = "-";
	}else if(x == "-"){
		name = x;
		state = "dead";
	}else if(atoi(x.c_str()) >=0 ){
		state = "alive";
		name = x;
		age=atoi(x.c_str());
	}else{
		state = "dead";
		name = "-";

	}
}

bool FredkinCell::printsta(){
	if(state == "dead"){
		cout<<name;
		return true;
	}else if(state == "alive"){
		cout<<name;
		return true;			
	}
	return false;
}

FredkinCell* FredkinCell::clone(){
	return new FredkinCell(*this);
}

	void Cell::setState(string x){
		 get()->setState(x);
		if(get()->getName()=="2")
			mutate();}
	bool Cell::switchStat(int x){
		return get()->switchStat(x);}
	bool Cell::printsta(){
		return get()->printsta();}
	vector<int> Cell::retrules(){
		return get()->retrules();}
	string Cell::getStat(){
		return get()->getStat();}
	string Cell::getName(){
		return get()->getName();}