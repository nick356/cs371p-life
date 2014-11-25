// --------
// includes
// --------
//
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==

#define private public
#define protected public
#include "gtest/gtest.h"
#include "Life.h"

using namespace std;



TEST(ConwayConstru, construct1){
	ConwayCell h("*");
	ASSERT_TRUE(h.getStat()=="alive");
	ASSERT_TRUE(h.getName()=="*");
}

TEST(ConwayConstru, construct2){
	ConwayCell h(".");
	ASSERT_TRUE(h.getStat()=="dead");
	ASSERT_TRUE(h.getName()==".");
}

TEST(ConwayConstru, construct3){
	ConwayCell h("fd");
	ASSERT_TRUE(h.getStat()=="dead");
	ASSERT_TRUE(h.getName()==".");

}

TEST(ConwayConstru, construct4){
	ConwayCell h;
	ASSERT_TRUE(h.getStat()=="dead");
	ASSERT_TRUE(h.getName()==".");
}

TEST(ConwayConstru, construct5){
	ConwayCell h;
	ConwayCell x;
	ASSERT_TRUE(h.getStat()=="dead" && x.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="." && x.getName()==".");
}

TEST(ConwayConstru, construct6){
	ConwayCell h;
	ConwayCell x;
	ConwayCell y;
	ASSERT_TRUE(h.getStat()=="dead" && x.getStat()=="dead" && y.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="." && x.getName()=="." && y.getName()==".");

}

TEST(FredkinConstru, construct1){
	FredkinCell h("-");
	ASSERT_TRUE(h.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="-");

}

TEST(FredkinConstru, construct2){
	FredkinCell h("+");
	ASSERT_TRUE(h.getStat()=="alive");
	ASSERT_TRUE(h.getName()=="+");

}

TEST(FredkinConstru, construct3){
	FredkinCell h("0");
	ASSERT_TRUE(h.getStat()=="alive");
	ASSERT_TRUE(h.getName()=="0");
}

TEST(FredkinConstru, construct4){
	FredkinCell h("5");
	ASSERT_TRUE(h.getStat()=="alive");
	ASSERT_TRUE(h.getName()=="5");
}

TEST(FredkinConstru, construct5){
	FredkinCell h;
	ASSERT_TRUE(h.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="-");
}

TEST(FredkinConstru, construct6){
	FredkinCell h;
	FredkinCell x;
	ASSERT_TRUE(h.getStat()=="dead" && x.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="-" && x.getName()=="-");
}

TEST(FredkinConstru, construct7){
	FredkinCell h;
	FredkinCell x;
	FredkinCell y;
	ASSERT_TRUE(h.getStat()=="dead" && x.getStat()=="dead" && y.getStat()=="dead");
	ASSERT_TRUE(h.getName()=="-" && x.getName()=="-" && y.getName()=="-");
}

TEST(Constatswtch, switch1){
	ConwayCell h("*");
	ASSERT_TRUE(h.switchStat(1));
}

TEST(Constatswtch, switch2){
	ConwayCell h(".");
	ASSERT_TRUE(h.switchStat(3));
}

TEST(Constatswtch, switch3){
	ConwayCell h("*");
	ASSERT_TRUE(!h.switchStat(2));
}

TEST(Constatswtch, switch4){
	ConwayCell h(".");
	ASSERT_TRUE(!h.switchStat(8));
}

TEST(Fredstatswtch, switch1){
	FredkinCell h("-");
	ASSERT_TRUE(h.switchStat(1) &&h.switchStat(3));
}

TEST(Fredstatswtch, switch2){
	FredkinCell h("+");
	ASSERT_TRUE(h.switchStat(0) && h.switchStat(2) && h.switchStat(4));
}

TEST(Fredstatswtch, switch3){
	FredkinCell h("0");
	ASSERT_TRUE(h.switchStat(0) && h.switchStat(2) && h.switchStat(4));
}

TEST(Fredstatswtch, switch4){
	FredkinCell h("-");
	ASSERT_TRUE(!h.switchStat(0) && !h.switchStat(2) && !h.switchStat(4));
}

TEST(Fredstatswtch, switch5){
	FredkinCell h("0");
	ASSERT_TRUE(!h.switchStat(1) && !h.switchStat(3));
}

TEST(Conwayset, set1){
	ConwayCell h;
	h.setState("alive");
	ASSERT_TRUE(h.getName()=="*");
}

TEST(Conwayset, set2){
	ConwayCell h;
	h.setState("dead");
	ASSERT_TRUE(h.getName()==".");
}

TEST(Conwayset, set3){
	ConwayCell h;
	h.setState(".");
	ASSERT_TRUE(h.getStat()=="dead");
}

TEST(Conwayset, set4){
	ConwayCell h;
	h.setState("*");
	ASSERT_TRUE(h.getStat()=="alive");

}

TEST(Conwayset, set5){
	ConwayCell h;
	h.setState("5");
	ASSERT_TRUE(h.getStat()=="dead" && h.getName()==".");
}

TEST(Conwayset, set6){
	ConwayCell h;
	h.setState("/");
	ASSERT_TRUE(h.getStat() == "dead" && h.getName() == ".");

}


TEST(Fredkinset, set1){
	FredkinCell h;
	h.setState("alive");
	ASSERT_TRUE(h.getStat()=="alive" && h.getName()=="0");
}

TEST(Fredkinset, set2){
	FredkinCell h;
	h.setState("0");
	ASSERT_TRUE(h.getStat()=="alive" && h.getName()=="0");
}

TEST(Fredkinset, set3){
	FredkinCell h;
	h.setState("+");
	ASSERT_TRUE(h.getStat()=="alive" && h.getName()=="+");
}

TEST(Fredkinset, set4){
	FredkinCell h;
	h.setState("5");
	ASSERT_TRUE(h.getStat()=="alive" && h.getName()=="5");
}

TEST(Fredkinset, set5){
	FredkinCell h;
	h.setState("-");
	ASSERT_TRUE(h.getStat()=="dead" && h.getName()=="-");
}

TEST(Fredkinset, set6){
	FredkinCell h;
	h.setState("dead");
	ASSERT_TRUE(h.getStat()=="dead" && h.getName()=="-");
}

TEST(Conrules, rules1){
	ConwayCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[0]==1 && t[1]==2);
}

TEST(Conrules, rules2){
	ConwayCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[2]==3 && t[3]==4);
}

TEST(Conrules, rules3){
	ConwayCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[4]==6 && t[5]==7);
}

TEST(Conrules, rules4){
	ConwayCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[6]==8 && t[7]==9);
}

TEST(Fredrules, rules1){
	FredkinCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[0]==2 && t[1]==4);
}

TEST(Fredrules, rules2){
	FredkinCell h;
	vector<int> t=h.retrules();
	ASSERT_TRUE(t[2]==6 && t[3]==8);
}

TEST(Conclone, clone1){
	ConwayCell h;
	ConwayCell* t=h.clone();
	ASSERT_TRUE(h.getStat()==(*t).getStat());
	delete t;
}

TEST(Conclone, clone2){
	ConwayCell h;
	ConwayCell* t=h.clone();
	ASSERT_TRUE(h.getName()==(*t).getName());
	delete t;
}

TEST(Conclone, clone3){
	ConwayCell h;
	ConwayCell* t=h.clone();
	ASSERT_TRUE(h.getName()==(*t).getName() && h.getStat()==(*t).getStat());
	delete t;
}

TEST(Conclone, clone4){
	ConwayCell h(".");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName()==t->getName());
	delete t;
}

TEST(Conclone, clone5){
	ConwayCell h("*");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	delete t;
}

TEST(Conclone, clone6){
	ConwayCell h("1");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	ASSERT_TRUE(t->getName() == ".");
	delete t;

}

TEST(Conclone, clone7){
	ConwayCell h("*");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	t->setState("dead");
	ASSERT_TRUE(h.getName() != t->getName());
	delete t;
}

TEST(Conclone, clone8){
	ConwayCell h(".");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	t->setState("alive");
	ASSERT_TRUE(h.getName() != t->getName());
	delete t;
}

TEST(Conclone, clone9){
	ConwayCell h("*");
	ConwayCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	t->setState(".");
	ASSERT_TRUE(h.getName() != t->getName());
	delete t;
}

TEST(Fredclone, clone1){
	FredkinCell h;
	FredkinCell* t=h.clone();
	ASSERT_TRUE(h.getStat()==(*t).getStat());
	delete t;
}

TEST(Fredclone, clone2){
	FredkinCell h;
	FredkinCell* t=h.clone();
	ASSERT_TRUE(h.getName()==(*t).getName());
	delete t;
}

TEST(Fredclone, clone3){
	FredkinCell h;
	FredkinCell* t=h.clone();
	ASSERT_TRUE(h.getName()==(*t).getName() && h.getStat()==(*t).getStat());
	delete t;
}

TEST(Fredclone, clone4){
	FredkinCell h("-");
	FredkinCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	delete t;
}

TEST(Fredclone, clone5){
	FredkinCell h("+");
	FredkinCell* t = h.clone();
	ASSERT_TRUE(h.getName()== t->getName());
	delete t;
}

TEST(Fredclone, clone6){
	FredkinCell h("1");
	FredkinCell* t = h.clone();
	ASSERT_TRUE(h.getName() == t->getName());
	ASSERT_TRUE(t->getName() == "1");
	ASSERT_TRUE(t->getStat() == "alive");
	delete t;
}



TEST(CellConstr, construct1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(y.getName()=="-" && y.getStat()=="dead");
}


TEST(CellConstr, construct2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	ASSERT_TRUE(y.getName()=="0" && y.getStat()=="alive");
}

TEST(CellConstr, construct3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	ASSERT_TRUE(y.getName()=="1" && y.getStat()=="alive");
}


TEST(CellConstr, construct4){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("alive");
	y.setState("alive");
	ASSERT_TRUE(y.getName()=="*" && y.getStat()=="alive");
}


TEST(Cellswtch, switch1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(y.switchStat(1) && y.switchStat(3));
}

TEST(Cellswtch, switch2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	ASSERT_TRUE(y.switchStat(0) && y.switchStat(2) && y.switchStat(4));
}

TEST(Cellswtch, switch3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	ASSERT_TRUE(y.switchStat(0) && y.switchStat(2) && y.switchStat(4));
}

TEST(Cellswtch, switch4){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(!y.switchStat(0) && !y.switchStat(2) && !y.switchStat(4));
}

TEST(Cellswtch, switch5){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	ASSERT_TRUE(!y.switchStat(1) && !y.switchStat(3));
}

TEST(Cellswtch, switch6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	ASSERT_TRUE(!y.switchStat(1) && !y.switchStat(3));
}

TEST(Cellswtch, switch7){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	ASSERT_TRUE(y.switchStat(1) && y.switchStat(4));
}

TEST(Cellswtch, switch8){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	ASSERT_TRUE(y.switchStat(3));
}

TEST(Cellswtch, switch9){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	ASSERT_TRUE(!y.switchStat(2) && !y.switchStat(4));
}

TEST(Cellswtch, switch10){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	ASSERT_TRUE(!y.switchStat(3) && !y.switchStat(2));
}

TEST(Cellret, return1){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[0]==2 && x[1]==4);
}

TEST(Cellret, return2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[2]==6 && x[3]==8);
}

TEST(Cellret, return3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[0]==1 && x[1]==2);
}

TEST(Cellret, return4){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[2]==3 && x[3]==4);
}

TEST(Cellret, return5){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[4]==6 && x[5]==7);
}

TEST(Cellret, return6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	vector<int> x=y.retrules();
	ASSERT_TRUE(x[6]==8 && x[7]==9);
}

TEST(CellSet, set1){
	AbstractCell* t = new FredkinCell("-");
	Cell y(t);
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="0");
}

TEST(CellSet, set2){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="1");
}

TEST(CellSet, set3){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="*");
}

TEST(CellSet, set4){
	AbstractCell* t = new FredkinCell("0");
	Cell y(t);
	y.setState("dead");
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()=="-");
}

TEST(CellSet, set5){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()==".");
}

TEST(CellSet, set6){
	AbstractCell* t = new FredkinCell("1");
	Cell y(t);
	y.setState("alive");
	y.setState("dead");
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="*");
}

TEST(CellSet, set7){
	AbstractCell* t=new FredkinCell("0");
	Cell y(t);
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="0");
	y.setState("-");
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()=="-");
}

TEST(CellSet, set8){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()=="-");
	y.setState("0");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="0");

}

TEST(CellSet, set9){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()=="-");
	y.setState("1");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="1");
}

TEST(CellSet, set10){
	AbstractCell* t=new FredkinCell("-");
	Cell y(t);
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()=="-");
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="0");
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="1");
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="*");
	y.setState("alive");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="*");
	y.setState("dead");
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()==".");
	y.setState("*");
	ASSERT_TRUE(y.getStat()=="alive" && y.getName()=="*");
	y.setState(".");
	ASSERT_TRUE(y.getStat()=="dead" && y.getName()==".");
}

TEST(Conwayget, get1){
	ConwayCell t;
	ASSERT_TRUE(t.getStat()=="dead" && t.getName()==".");
}

TEST(Conwayget, get2){
	ConwayCell t(".");
	ASSERT_TRUE(t.getStat()=="dead" && t.getName()==".");
}

TEST(Conwayget, get3){
	ConwayCell t("*");
	ASSERT_TRUE(t.getStat()=="alive" && t.getName()=="*");
}

TEST(Fredkinget, get1){
	FredkinCell t;
	ASSERT_TRUE(t.getStat()=="dead" && t.getName()=="-");
}

TEST(Fredkinget, get2){
	FredkinCell t("-");
	ASSERT_TRUE(t.getStat()=="dead" && t.getName()=="-");
}

TEST(Fredkinget, get3){
	FredkinCell t("0");
	ASSERT_TRUE(t.getStat()=="alive" && t.getName()=="0");
}

TEST(Lifecon, construct1){
	Life<FredkinCell> x;
	ASSERT_TRUE(x.generation()==0 && x.population()==0);
}

TEST(Lifecon, construct2){
	Life<FredkinCell> x(10,10);
	ASSERT_TRUE(x.getSta(1,1)=="dead");
}

TEST(Lifecon, construct3){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	ASSERT_TRUE(x.getSta(1,1)=="alive");
}

TEST(Lifecon,construct4){
	Life<Cell> x;
	ASSERT_TRUE(x.generation()==0 && x.population()==0);
}

TEST(Lifecon,construct5){
	Life<Cell> x(10,10);
	ASSERT_TRUE(x.getSta(1,1)=="dead");
}

TEST(Lifecon,construct6){
	Life<Cell> x(10,10);
	x.init(1,1,"0");
	ASSERT_TRUE(x.getSta(1,1)=="alive");
}

TEST(Lifecon, construct7){
	Life<ConwayCell> x;
	ASSERT_TRUE(x.generation()==0 && x.population()==0);
}

TEST(Lifecon, construct8){
	Life<ConwayCell> x(10,10);
	ASSERT_TRUE(x.getSta(1,1)=="dead");
}

TEST(Lifecon, construct9){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	ASSERT_TRUE(x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation1){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0);
}

TEST(Lifegen, generation2){
	Life<ConwayCell> x(10,10);
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==4 && x.getSta(1,1)=="alive" && x.getSta(2,2)=="alive");
}

TEST(Lifegen, generation3){
	Life<ConwayCell> x(10,10);
	x.init(1,3,"*");
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==4 && x.getSta(1,2)=="dead" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation4){
	Life<ConwayCell> x(10,10);
	x.init(1,3,"*");
	x.init(1,1,"*");
	x.init(2,2,"*");
	x.init(1,2,"*");
	x.init(2,1,"*");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0 && x.getSta(1,2)=="dead" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="dead");
}

TEST(Lifegen, generation5){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==2);
}

TEST(Lifegen, generation6){
	Life<FredkinCell> x(10,10);
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==4 && x.getSta(1,1)=="dead" && x.getSta(2,2)=="dead");
}

TEST(Lifegen, generation7){
	Life<FredkinCell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
}

TEST(Lifegen, generation8){
	Life<FredkinCell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"0");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==12 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation9){
	Life<Cell> x(10,10);
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==2);
}

TEST(Lifegen, generation10){
	Life<Cell> x(10,10);
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==4 && x.getSta(1,1)=="dead" && x.getSta(2,2)=="dead");
}

TEST(Lifegen, generatio11){
	Life<Cell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
}

TEST(Lifegen, generation12){
	Life<Cell> x(10,10);
	x.init(1,3,"0");
	x.init(1,1,"1");
	x.init(2,2,"0");
	x.init(1,2,"0");
	x.init(2,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==5 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,3)=="alive");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==12 && x.getSta(1,2)=="alive" && x.getSta(2,2)=="dead" && x.getSta(1,1)=="alive");
}

TEST(Lifegen, generation13){
	Life<ConwayCell> x(5,5);
	x.init(1,1,"1");
	ASSERT_TRUE(x.population()==0 && x.getSta(1,1)=="dead");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0 && x.getSta(1,1)=="dead");

}

TEST(Lifegen, generation14){
	Life<Cell> x(5,5);
	x.init(1,1,"0");
	x.init(1,2,"0");
	ASSERT_TRUE(x.population()==2 && x.getSta(1,1)=="alive");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==5 && x.getSta(1,1)=="alive");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.getSta(1,1)=="dead");
}

TEST(Lifegen,generation15){
	Life<Cell> x(1,1);
	x.init(1,1,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0);
}

TEST(Lifegen, generation16){
	Life<ConwayCell> x(1,1);
	x.init(1,1,"*");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0);
}

TEST(Lifegen, generation17){
	Life<FredkinCell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==4);
}

TEST(Lifegen, generation18){
	Life<FredkinCell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0);
}

TEST(Lifegen,generation19){
	Life<Cell> x(3,3);
	x.init(1,1,"0");
	x.init(1,2,"0");
	x.init(1,3,"0");
	x.init(2,1,"0");
	x.init(2,2,"0");
	x.init(2,3,"0");
	x.init(3,1,"0");
	x.init(3,2,"0");
	x.init(3,3,"0");
	x.incrementOneGeneration();
	x.incrementOneGeneration();
	ASSERT_TRUE(x.population()==0);	
}
