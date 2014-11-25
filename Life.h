#ifndef Life_h
#define Life_h
#include <iostream> // istream, ostream
#include <vector>


using namespace std;
class AbstractCell{
	protected:
		string name;
		string state;
		vector<int> rules;
	public:
		AbstractCell(){
			state="dead";	
			name=" ";	
		}

		AbstractCell(string stat, string chr){
			name=chr;
			state=stat;
		}
	
		virtual bool switchStat(int)=0;

		virtual void setState(string x) = 0;
		string getName();

		string getStat();
		virtual bool printsta() = 0;
		vector<int> retrules();
		virtual AbstractCell* clone() = 0;

};

class ConwayCell : public AbstractCell{


	public:

		ConwayCell(){
			name=".";
			state="dead";
			for(int i=1;i<10;i++){
				if(i!=5)
				  rules.push_back(i);
			}
		}

		ConwayCell(string chr){
			if(chr=="*"){
				name=chr;
				state="alive";
			}else{
				name=".";
				state="dead";
			}
			for(int i=1;i<10;i++){
				if(i!=5)
				  rules.push_back(i);
			}
		}

		bool printsta();
		bool switchStat(int);
		//Sets the state of the cell
		void setState(string);
		ConwayCell* clone();
};

class FredkinCell : public AbstractCell{

	protected:
		int age;
	public:
		FredkinCell(){

		}

		FredkinCell(string chr){

		}


	void setState(string);
	bool switchStat(int);
	bool printsta();
	FredkinCell* clone();
};

class Cell: Handle<AbstractCell>{
	public:
	Cell (AbstractCell* p) : Handle<AbstractCell>(p)
		{}

	Cell ():Handle<AbstractCell>(){
	}

	void setState(string);
	bool switchStat(int);
	bool printsta();
	vector<int> retrules();
	string getStat();
	string getName();


};

template <typename T>
class Handle{
	friend bool operator == (const Handle& lhs, const Handle& rhs){
		return (!lhs._p && !rhs._p == *rhs._p);}

	friend bool operator != (const Handle& lhs, const Handle& rhs){
		return !(lhs==rhs);}

	public:
		typedef T			value_type;

		typedef value_type*		pointer;
		typedef const value_type*	const_pointer;

		typedef value_type&		reference;
		typedef const value_type&	const_reference;

	private:
		pointer _p;
	protected:
		pointer get(){

		}

		const_pointer get() const{

		}

		void mutate(){

		}
	public:

		Handle (pointer p){

		}

		Handle(){

		}

		Handle (const Handle& that){
			if(!that._p){

		}

		~Handle(){
		
		}

		Handle& operator = (Handle that){

		}

		void swap(Handle& that){

		}

		
};

template <typename T>
class Life{

	private:
	vector< vector<T> > grid;
	vector< vector<bool> > marker;
	int width_;
	int height_;
	int pop;
	int gen;

	public:
	Life(){

	}
	Life(int width, int height){

	}

	/*
	We initilize the grid with the given coordinates with the given value
	*/
	void init(int i, int j, string x){

	}

	/*
	This is to be used in the TestCases
	*/

	string getSta(int i, int j){

	}

	/*
	Checks all the cells to see if they must be updated, it calls the checkSurrounding function which proceeds to
	update the mark array. Once all the Surroundings have been checked and updated, it calls the update
	method which proceeds to update the grid.
	*/
	void incrementOneGeneration(){

	}

	/*
	Each Cell type must have it's own vector of rules. We implemented this because a cell as a class doesn't know
	whether it is surrounded by other cells. But each cell has it's own rules, so by creating a list of if
	else statements we allow for additional Cell types to be added as long as they check the adjacent indexes.
	*/
	void checkSurrounding(int row, int col){

	}

	/*
	The update function goes through the second marked matrix and checks to see if any of it's 
	indexes are true. If one is true that means we must change the state of the cell in the adjacent cell grid.
	If the indedx is false then we only care about whether it is alive, if it is alive we set the state to alive again
	We do this because Fredkin cell must monitor the age of it's cell and by calling setState with
	the "alive" string then the age is incremented.
	*/
	void update(){

	}

	/*
	This is a simple print out grid function it calls upon the printsta() function of any Cell that currently
	resides in it, which does the actual printing.
	*/
	void printgrd(){

	}

	/*
	This function returns the population of a given grid.
	We keep it constant time because we do the bookkeeping when we change a cell from a dead cell to a living cell
	and vise versus
	*/
	int population(){

	}
	/*
	This function is also constant time because the generation bookkeeping is done 
	when we increment a generation
	*/
	int generation(){

	}
	
};

#endif