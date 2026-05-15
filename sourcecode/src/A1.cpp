#include <ilcplex/ilocplex.h>   
#include <stdio.h>              
#include <stdlib.h>             
#include <time.h>                         
#include <sys/time.h>                 
#include <fstream>  
#include <string>
#include <math.h>
#include <sstream>
#include <algorithm>            
#include "Avgminmax02.h"
#include <vector>
#include <cmath>
#define random(x) (rand()%x)
namespace patch { template < typename T > std::string to_string(const T& n) { std::ostringstream stm; stm << n; return stm.str(); } }

using namespace std;
//input data starts here
extern const int CODE = 0;
extern const int CNN = 1;
extern const int T = 1;
extern const int I = 2;
extern const int B = 2;
extern const int S = 100;
extern const int OS = 100;
int br[B][S]={{361,284,499,250,317,315,189,493,338,196,628,333,312,341,81,378,393,437,349,651,561,706,548,358,239,219,414,508,267,261,225,193,476,140,349,355,566,130,306,54,539,309,338,388,342,399,494,331,269,472,318,255,602,634,227,194,240,605,115,426,182,235,383,267,173,507,368,288,362,414,489,620,165,496,285,463,240,297,192,408,499,401,369,396,406,308,357,378,228,321,373,294,297,421,466,266,168,428,386,485},{547,1262,571,399,295,324,356,403,402,197,329,284,166,198,425,320,253,90,264,270,607,84,522,131,342,302,373,230,531,502,396,444,353,287,424,452,39,189,212,404,338,383,336,391,419,513,75,340,420,263,413,316,314,688,271,450,436,364,287,283,300,514,305,388,235,375,516,159,339,363,109,311,453,516,353,429,679,436,322,134,251,302,351,357,425,626,394,346,390,385,467,528,419,233,347,379,674,197,266,214}}; 
int vbm[I][B]={{1,1},{1,1}}; 
double Apara[I]={0.0050,0.0050}; 
double Bpara[I]={3.00,3.00}; 
double Gpara[I]={7.54,7.54}; 
double Dis[I]={121.00,98.00}; 
double Ltime[I][S]={{0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00},{0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00,0.00}}; 
int Stime[I][2]={{316,907},{256,735}}; 
int Htime[B][I][S]={{{1004,353,977,256,732,1043,593,690,1731,753,1318,717,228,750,734,1255,929,773,742,955,728,810,777,582,1503,822,671,819,1262,825,365,779,1116,640,925,1307,1944,930,1061,1414,803,1363,1088,810,912,757,726,1383,747,1061,596,854,550,786,585,561,1163,1117,1640,533,913,1013,296,789,779,614,1952,625,982,736,892,1393,2043,1179,1192,1405,1055,765,467,372,1102,143,668,219,326,706,991,934,952,632,1072,557,980,727,613,985,777,1059,726,676},{695,733,524,716,850,1231,64,491,1217,672,649,779,849,417,1047,115,959,55,693,561,852,849,983,216,849,478,1458,566,1041,679,852,681,720,699,633,302,45,174,313,173,531,669,1548,853,600,440,574,745,546,730,635,400,986,2037,457,1251,867,244,373,963,850,677,677,760,174,751,937,954,804,871,694,818,558,653,1045,721,554,1602,856,573,563,612,495,552,1015,667,775,364,382,787,564,511,168,617,509,245,752,946,703,930}},{{1004,353,977,256,732,1043,593,690,1731,753,1318,717,228,750,734,1255,929,773,742,955,728,810,777,582,1503,822,671,819,1262,825,365,779,1116,640,925,1307,1944,930,1061,1414,803,1363,1088,810,912,757,726,1383,747,1061,596,854,550,786,585,561,1163,1117,1640,533,913,1013,296,789,779,614,1952,625,982,736,892,1393,2043,1179,1192,1405,1055,765,467,372,1102,143,668,219,326,706,991,934,952,632,1072,557,980,727,613,985,777,1059,726,676},{695,733,524,716,850,1231,64,491,1217,672,649,779,849,417,1047,115,959,55,693,561,852,849,983,216,849,478,1458,566,1041,679,852,681,720,699,633,302,45,174,313,173,531,669,1548,853,600,440,574,745,546,730,635,400,986,2037,457,1251,867,244,373,963,850,677,677,760,174,751,937,954,804,871,694,818,558,653,1045,721,554,1602,856,573,563,612,495,552,1015,667,775,364,382,787,564,511,168,617,509,245,752,946,703,930}}}; 
int Vtime[I]={1868,1619}; 
double Pro[S];
double Hcost[I][B]={{9883.00,10697.00},{6939.00,8152.00}}; 
double Tcost[I]={56.74,53.75}; 
double SLP=1.05; 
double Dcost[I]={0.89,0.89}; 
double Ecost[I][2]={{0.85,0.91},{0.85,0.91}}; 

int RTBR[B]={258,319}; 
int RTHT[B][I]={{1387,879},{1387,879}}; 
int RLtime[I]={0,0}; 
int Pbr[B][1]={{356},{363}}; 
double PLtime[I][1]={{0.00},{0.00}}; 
int PHtime[B][I][1]={{{883},{708}},{{883},{708}}}; 
//input data ends here


double BM[I][I][S];  
int TSN = 0; 
vector<int> TSset; 
int TSindex[I]; 


double Xsol[I][B];     
double Ysol[B][I][I];     
double Zsol[I]; 
double Ssol[S]; 
double Scost;
double BDsol[S]; 

int NBC = 0; 
vector<int> BCS; 
vector<vector<vector<double>>> XBpara(I);  
vector<vector<vector<vector<double>>>> YBpara(B);  
vector<vector<double>> ZBpara;  
vector<double> CBpara;  

double XBtemp[I][B][S];
double YBtemp[B][I][I][S];
double ZBtemp[I][S];
double CBtemp[S];
double LZBtemp[I][S]; 
double AZBtemp[I]; 

double Fcost = 0; 
double BDgap = 0.5;
double BDgap02 = 0.5;
double Tgap = 1;

double ART[I]; 
double SBT[I]; 
double HBT[I]; 
double BRT[I]; 
double DBT[I]; 
double LST[I]; 
double Theta1[B][I][I]; 
double Psi[B][I][I];   
double delta[I];
double zeta[I];
double theta[B][I][I];
double vartheta[B][I][I];
double lambda[I];
double pi[I];
double varpi[I]; 

int TFCN; 
vector<int> FCN; 
vector<vector<int>> FCTIND; 
vector<vector<double>> FCA; 
vector<vector<double>> FCL; 
vector<double> FCTCL; 
double Hsol[I]; 

double Fgap = BDgap; 
double Rfgap = 0; 


int levels = 0; 
double upperbound = 999999;
double totallb;  
double totalgap = 100; 
int tmloc[2]; 
vector<int> nodenum;   
vector<vector<vector<int>>>nodeindx;   
vector<vector<double>> lowerbound;   
vector<vector<vector<int>>> brcho(2);   
vector<vector<int>> brtype;  
vector<vector<int>> brnd1; 
vector<vector<int>> brnd2;  
vector < vector<vector<int>>> maxvn(B);  
int NTIBD[I][B]; 
int NTIID[I][I]; 
int NTFID[I]; 

int N; 
int NN; 
int TON; 

vector <double> colcost;   
vector <int> colberth;   
vector <int> colvn; 
vector <vector <int>> colves;   
vector < vector <double>> coladcost(S); 
vector <double> colsolused; 

ILOSTLBEGIN
IloObjective   Totalcost;
IloRangeArray  Vessel; 
IloRangeArray  Berth; 
IloRangeArray  Sailtime; 
IloRangeArray  Fuelcon; 
IloRangeArray  Bendcon; 
IloRangeArray  Multicon; 
IloRangeArray  Acostcon; 

double vesdual[I];  
double berthdual[B];  
vector<double> bddual;
double acdual[S];  

int OBVN[B]; 
vector<vector<int>> OBVset(B); 

int tln = 0; 
vector < vector<double>> crttime(S); 
vector < vector<double>> crtdcost(S); 
vector<int> veslen; 
vector<vector<int>> vesseq; 
vector<int> avlen; 
vector<vector<int>> avlist; 
vector<double> flcost; 

int TCN01; 
int intsol = 1;  
int numused = 0; 
vector <double> colcostused;   
vector <int> colberthused;   
vector <int> colvnused; 
vector <vector <int>> colvesused;   
vector < vector <double>> coladcostused(S); 


double BXsol[I][B];     
double BYsol[B][I][I];     
double BZsol[I]; 


double EAtime[I][S]; 
double AVEEAtime[I]; 

double CXsol[I][B];     
double CYsol[B][I][I];     
double CZsol[I]; 
struct timeval t_start, t_crt; 

int NODEMVN[B];
double Minivescost[I]; 
double Minifcost[I];  
double minicost[B][I];
double minitotalcost[B];

int BESTBVN[B];
int INIBVN[B];
vector < vector<int>>  BESTBVset(B);
vector < vector<int>> INIBVset(B);

double avetime[I][B]; 
double avebr[B];
double avelt[I];

double lbves[B][I]; 

long VI = 0x00;  
long inimark = 0x01; 
vector<long> vlset; 

string num2str(double i)
{
	stringstream ss;
	ss << i;
	return ss.str();
}

ofstream mycout01("//scratch//lxwu//2026//SBASP//Results//A1//Solution//B" + num2str(B) + "_S" + num2str(S) + "_CN" + num2str(CNN) + "_Code_" + num2str(CODE) + ".txt");
ofstream mycout02("//scratch//lxwu//2026//SBASP//Results//A1//Computational//B" + num2str(B) + "_S" + num2str(S) + "_CN" + num2str(CNN) + "_Code_" + num2str(CODE) + ".txt");

void Bendersetup() {
	for (int i = 0; i != I; ++i) {
		XBpara[i].resize(B);
	}
	for (int b = 0; b != B; ++b) {
		YBpara[b].resize(I);
		for (int i = 0; i != I; ++i) {
			YBpara[b][i].resize(I);
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			BXsol[i][b] = 0;
			CXsol[i][b] = 0;
		}
	}
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				BYsol[b][i][j] = 0;
				CYsol[b][i][j] = 0;
			}
		}
	}
	for (int i = 0; i != I; ++i) { CZsol[i] = Stime[i][1] / double(60); }
	for (int b = 0; b != B; ++b) {
		avebr[b] = 0;
		for (int s = 0; s != S; ++s) {
			avebr[b] += Pro[s] * double(br[b][s]);
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			avetime[i][b] = 0;
			for (int s = 0; s != S; ++s) {
				avetime[i][b] += Pro[s] * double(Htime[b][i][s]);
			}
		}
	}
	int CBVN[B];
	vector < vector<int>> BVset(B);
	for (int b = 0; b != B; ++b) { CBVN[b] = 0; }
	double a[I];
	int SEQ[I]; 
	for (int i = 0; i != I; ++i) {
		SEQ[i] = i;
		a[i] = AVEEAtime[i];
	}
	for (int j = 1; j < I; j++)
	{
		double key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			int temp = SEQ[i + 1];
			SEQ[i + 1] = SEQ[i];
			SEQ[i] = temp;
			i--;
		}
		a[i + 1] = key;
	}
	double CBRT[B];
	for (int b = 0; b != B; ++b) {
		CBRT[b] = avebr[b];
	}
	for (int i = 0; i != I; ++i) {
		int theves = SEQ[i];
		int theberth = -1;
		double thetime = 999999;
		for (int b = 0; b != B; ++b) {
			if (vbm[theves][b] == 1) {
				if (thetime > CBRT[b]) {
					thetime = CBRT[b];
					theberth = b;
				}
			}
		}
		CBVN[theberth] += 1;
		BVset[theberth].resize(CBVN[theberth], theves);
		double thest = AVEEAtime[theves];
		if (thest < CBRT[theberth]) {
			thest = CBRT[theberth];
		}
		CBRT[theberth] = thest + avetime[theves][theberth];
	}
	for (int b = 0; b != B; ++b) {
		BESTBVN[b] = CBVN[b];
		for (int i = 0; i != CBVN[b]; ++i) {
			int theves = BVset[b][i];
			BESTBVset[b].resize(i + 1, theves);
			CXsol[theves][b] = 1;
			BXsol[theves][b] = 1;
			if (i < CBVN[b] - 1) {
				for (int j = i + 1; j < CBVN[b]; ++j) {
					CYsol[b][i][j] = 1;
					BYsol[b][i][j] = 1;
				}
			}
		}
	}
}

void BSrecord() {
	for (int b = 0; b != B; ++b) {
		BESTBVset[b].erase(BESTBVset[b].begin(), BESTBVset[b].end());
		vector<int>().swap(BESTBVset[b]);
		BESTBVN[b] = 0;
	}
	for (int cn = 0; cn != numused; ++cn) {
		int theberth = colberthused[cn];
		BESTBVN[theberth] = colvnused[cn];
		for (int vn = 0; vn != BESTBVN[theberth]; ++vn) {
			int theves = colvesused[cn][vn];
			BESTBVset[theberth].resize(vn + 1, theves);
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			BXsol[i][b] = Xsol[i][b];
		}
	}
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				BYsol[b][i][j] = Ysol[b][i][j];
			}
		}
	}
	for (int cn = 0; cn != I; ++cn) {
		BZsol[cn] = Zsol[cn]; 
	}
}

void FCsep(int theind, double thet) { 
	int thei = TSset[theind]; 
	double theaval = double(-2) * double((Dcost[thei] + Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -3)); 
	double thefcost = (Dcost[thei] + Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
	double thelval = thefcost - (theaval * thet); 
	FCN[theind] += 1;
	FCA[theind].resize(FCN[theind], theaval);
	FCL[theind].resize(FCN[theind], thelval);
	FCTIND[theind].resize(FCN[theind], TFCN);
	TFCN += 1;
	FCTCL.resize(TFCN, thelval);
}

void Fuelcutsetup() {
	TFCN = 0; 
	FCN.resize(TSN, 0);
	FCA.resize(TSN);
	FCL.resize(TSN);
	FCTIND.resize(TSN);
	
	for (int i = 0; i != TSN; ++i) { 
		int thei = TSset[i];
		double theet = double(Stime[thei][0]) / double(60); 
		FCsep(i, theet);
		double thelt = double(Stime[thei][1]) / double(60); 
		FCsep(i, thelt);
	}
	for (int i = 0; i != I; ++i) {
		for (int s = 0; s != S; ++s) {
			LZBtemp[i][s] = 0;
		}
	}
}

void CGsetup() {
	TCN01 = I + TSN + 1 + S + I; 
	for (int b = 0; b != B; ++b) {
		OBVN[b] = 0;
		for (int i = 0; i != I; ++i) {
			if (vbm[i][b] == 1) {
				OBVN[b] += 1;
				OBVset[b].resize(OBVN[b], i);
			}
		}
	}
}

void LBestimate(int theves, int theberth) {
	IloEnv env; 
	IloNumVar obj(env, -IloInfinity, IloInfinity, ILOFLOAT);
	IloNumVar Z(env, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray U(env, S, -IloInfinity, IloInfinity, ILOFLOAT); 
	IloNumVarArray V(env, S, -IloInfinity, IloInfinity, ILOFLOAT); 
	IloNumVarArray W(env, S, 0, IloInfinity, ILOFLOAT); 
	IloNumVar Gamma(env, 0, IloInfinity, ILOFLOAT); 
	IloNumVar s1(env, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray Delta(env, S, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray t1(env, S, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray t2(env, S, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray t3(env, S, 0, IloInfinity, ILOFLOAT); 
	IloNumVarArray t4(env, S, 0, IloInfinity, ILOFLOAT); 
	try {
		
		IloModel model(env);
		{   
			model.add(IloMinimize(env, obj)); 
		}
		{
			IloExpr Z2(env); 
			if (TSindex[theves] != -1) {
				Z2 += (Dcost[theves] + Ecost[theves][0]) * (Apara[theves] * double(60) * pow(Dis[theves], 3) * Gamma); 
			}
			IloExpr Z3(env); 
			for (int s = 0; s != S; ++s) {
				Z3 += Pro[s] * Ecost[theves][1] * Gpara[theves] * V[s]; 
				Z3 += Pro[s] * Tcost[theves] * Delta[s]; 
			}
			model.add((Hcost[theves][theberth] + Z2 + Z3) == obj);
			Z2.end();
			Z3.end();
		}
		model.add(Z * 60 >= Stime[theves][0]);
		model.add(Z * 60 <= Stime[theves][1]);
		for (int s = 0; s != S; ++s) {
			model.add(U[s] >= Ltime[theves][s] + Z * 60); 
			model.add(U[s] >= br[theberth][s]); 
			model.add(V[s] == U[s] + Htime[theberth][theves][s] - (Ltime[theves][s] + Z * 60));
			model.add(W[s] >= Z * 60 + V[s] - Vtime[theves]);
		}
		if (TSindex[theves] != -1) {
			model.add(1 <= s1 * Z); 
			model.add(s1 * s1 <= Gamma);      
		}
		for (int s = 0; s != S; ++s) {
			model.add(W[s] * W[s] <= Delta[s] * t1[s]); 
			model.add(t1[s] * t1[s] <= W[s] * t2[s]); 
			model.add(t2[s] * t2[s] <= Delta[s] * t3[s]); 
			model.add(t3[s] * t3[s] <= W[s] * t4[s]); 
			model.add(t4[s] * t4[s] <= W[s]); 
		}
		
		{
			IloCplex cplex(env);
			cplex.extract(model);
			cplex.setOut(env.getNullStream());
			cplex.setParam(IloCplex::Param::WorkMem, 8192);
			cplex.setParam(IloCplex::Param::MIP::Tolerances::MIPGap, 0.001);
			cplex.setParam(IloCplex::Threads, 1);  
			cplex.solve();
			
			lbves[theberth][theves] = cplex.getObjValue();
		}
	}
	catch (IloException& ex) {
		cerr << ex << endl;
	}
	catch (...) {
		cerr << "Error..." << endl;
	}
	env.end();
}

void Cplexsetup() {
	
	for (int s = 0; s != S; ++s) {
		Pro[s] = double(1) / double(S);
	}
	for (int i = 0; i != I; ++i) {
		avelt[i] = 0;
		for (int s = 0; s != S; ++s) {
			avelt[i] += Pro[s] * double(Ltime[i][s]);
		}
	}
	for (int i = 0; i != I; ++i) {
		AVEEAtime[i] = double(avelt[i] + Stime[i][0]);
		for (int s = 0; s != S; ++s) {
			EAtime[i][s] = double(Ltime[i][s] + Stime[i][0]);
		}
	}
	
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != B; ++j) {
			Hcost[i][j] = Hcost[i][j] / double(1000);
		}
	}
	for (int i = 0; i != I; ++i) {
		Tcost[i] = Tcost[i] / double(1000);
		Dcost[i] = Dcost[i] / double(1000);
	}
	for (int i = 0; i != I; ++i) {
		Ecost[i][0] = Ecost[i][0] / double(1000);
		Ecost[i][1] = Ecost[i][1] / double(1000);
	}
	for (int i = 0; i != I; ++i) {
		TSindex[i] = -1;
		if (Dis[i] >= 0.01) {
			TSindex[i] = TSN;
			TSN += 1;
			TSset.resize(TSN, i);
		}
	}
	ZBpara.resize(TSN);
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			for (int s = 0; s != S; ++s) {
				double thegap = Ltime[i][s] + Stime[i][1] - (Ltime[j][s] + Stime[j][0]);
				if (thegap < 0) {
					thegap = 0;
				}
				BM[i][j][s] = thegap;
			}
		}
	}
	
	Bendersetup();
	Fuelcutsetup();
	CGsetup();
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			LBestimate(i, b);
		}
	}
	for (int i = 0; i != I; ++i) {
		Minifcost[i] = 0;
		if (Stime[i][1] > 0) {
			double thet = Stime[i][1] / double(60);
			double thefcost = (Dcost[i] + Ecost[i][0]) * (Apara[i] * double(60) * pow(Dis[i], 3)) * pow(thet, -2); 
			Minifcost[i] = thefcost;
		}
	}
}

void Hinicolget() {
	for (int b = 0; b != B; ++b) {
		INIBVset[b].erase(INIBVset[b].begin(), INIBVset[b].end());
		vector<int>().swap(INIBVset[b]);
		INIBVN[b] = 0;
	}
	for (int b = 0; b != B; ++b) {
		for (int vn = 0; vn != BESTBVN[b]; ++vn) {
			if (INIBVN[b] >= NODEMVN[b]) {
				continue;
			}
			int theves = BESTBVset[b][vn];
			if (INIBVN[b] == 0) {
				if (NTFID[theves] == 0) { 
					continue;
				}
			}
			if (NTIBD[theves][b] == 1) {
				int doable = 1;
				for (int lvn = 0; lvn < INIBVN[b]; ++lvn) {
					int thelv = INIBVset[b][lvn];
					if (NTIID[thelv][theves] == 0) {
						doable = 0;
						break;
					}
				}
				if (doable == 1) {
					INIBVN[b] += 1;
					INIBVset[b].resize(INIBVN[b], theves);
				}
			}
		}
	}
	for (int b = 0; b != B; ++b) {
		if (INIBVN[b] == 0) { continue; }
		NN += 1; 
		TON += 1; 
		colberth.resize(TON, b);
		for (int s = 0; s != S; ++s) {
			double dcost = 0;
			double thestime = br[b][s];
			for (int vn = 0; vn != INIBVN[b]; ++vn) {
				int theves = INIBVset[b][vn];
				if (thestime < EAtime[theves][s]) {
					thestime = EAtime[theves][s]; 
				}
				double theendtime = thestime + Htime[b][theves][s]; 
				double thedelay = (theendtime - Ltime[theves][s]) - Vtime[theves];
				if (thedelay < 0) { thedelay = 0; }
				dcost += Tcost[theves] * pow(double(thedelay), double(SLP));
				double thestay = Htime[b][theves][s]; 
				if (theendtime - (Ltime[theves][s] + Stime[theves][1]) > thestay) {
					thestay = theendtime - (Ltime[theves][s] + Stime[theves][1]);
				}
				dcost += Ecost[theves][1] * Gpara[theves] * thestay;
				thestime = theendtime;
			}
			coladcost[s].resize(TON, dcost);
		}
		colvn.resize(TON, INIBVN[b]);
		colves.resize(TON);
		double tempcost = 0;
		for (int vn = 0; vn != INIBVN[b]; ++vn) {
			int theves = INIBVset[b][vn];
			colves[TON - 1].resize(vn + 1, theves);
			tempcost += Hcost[theves][b];
		}
		colcost.resize(TON, double(tempcost));
	}
	
}

void Inicolload(IloModel model, IloNumVarArray x, int Xfixed) { 
	IloEnv env = model.getEnv(); 
	IloInt i, j;   
	IloNumArray vescover(env, I);     
	IloNumArray stcover(env, I);     
	IloNumArray berthcover(env, B);     
	IloNumArray fuelcover(env, TFCN);     
	IloNumArray bdscover(env, NBC);     
	IloNumArray multicut(env, 1);  
	IloNumArray avgcut(env, S);  
	for (j = 0; j != I; ++j) { 
		for (i = 0; i != I; ++i) { vescover[i] = 0; }
		for (i = 0; i != I; ++i) { stcover[i] = 0; }
		for (i = 0; i != B; ++i) { berthcover[i] = 0; }
		for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
		for (i = 0; i != NBC; ++i) { bdscover[i] = 0; }
		for (i = 0; i != S; ++i) { avgcut[i] = 0; }
		multicut[0] = 0;
		stcover[j] = 60; 
		if (TSindex[j] != -1) { 
			int tsind = TSindex[j]; 
			for (int fn = 0; fn != FCN[tsind]; ++fn) {
				int tfind = FCTIND[tsind][fn];
				double tfca = FCA[tsind][fn];
				fuelcover[tfind] = -tfca;
			}
			for (int cn = 0; cn != NBC; ++cn) {
				bdscover[cn] = -ZBpara[tsind][cn];
			}
		}
		double thecost = 0; 
		x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut))); 
	}
	for (j = 0; j != TSN; ++j) { 
		for (i = 0; i != I; ++i) { vescover[i] = 0; }
		for (i = 0; i != I; ++i) { stcover[i] = 0; }
		for (i = 0; i != B; ++i) { berthcover[i] = 0; }
		for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
		for (i = 0; i != NBC; ++i) { bdscover[i] = 0; }
		for (i = 0; i != S; ++i) { avgcut[i] = 0; }
		for (int fn = 0; fn != FCN[j]; ++fn) {
			int tfind = FCTIND[j][fn]; 
			fuelcover[tfind] = 1;
		}
		multicut[0] = 0;
		double thecost = 1; 
		x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut))); 
	}
	{ 
		for (i = 0; i != I; ++i) { vescover[i] = 0; }
		for (i = 0; i != I; ++i) { stcover[i] = 0; }
		for (i = 0; i != B; ++i) { berthcover[i] = 0; }
		for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
		for (i = 0; i != NBC; ++i) { bdscover[i] = 0; }
		for (i = 0; i != S; ++i) { avgcut[i] = 0; }
		multicut[0] = 1;
		double thecost = 1; 
		x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut))); 
	}
	{ 
		for (j = 0; j != S; ++j) {
			for (i = 0; i != I; ++i) { vescover[i] = 0; }
			for (i = 0; i != I; ++i) { stcover[i] = 0; }
			for (i = 0; i != B; ++i) { berthcover[i] = 0; }
			for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
			for (i = 0; i != NBC; ++i) {
				if (BCS[i] == j) { bdscover[i] = 1; }
				else { bdscover[i] = 0; }
			}
			for (i = 0; i != S; ++i) { avgcut[i] = 0; }
			avgcut[j] = 1;
			multicut[0] = -Pro[j];
			double thecost = 0; 
			x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut))); 
		}
	}
	for (j = 0; j != I; ++j) { 
		for (i = 0; i != I; ++i) { vescover[i] = 0; }
		for (i = 0; i != I; ++i) { stcover[i] = 0; }
		for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
		for (i = 0; i != B; ++i) { berthcover[i] = 0; }
		for (i = 0; i != NBC; ++i) { bdscover[i] = 0; }
		for (i = 0; i != S; ++i) { avgcut[i] = 0; }
		vescover[j] = 1;
		multicut[0] = 0;
		avgcut[0] = 0;
		double thecost = 9999;
		x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut)));   
	}
	N = 0;
	NN = 0;
	if (Xfixed == 0) {

	}
	for (int cn = 0; cn != numused; ++cn) {
		NN += 1;
		colcost.resize(NN, colcostused[cn]);
		colberth.resize(NN, colberthused[cn]);
		for (int s = 0; s != S; ++s) {
			coladcost[s].resize(NN, coladcostused[s][cn]);
		}
		colvn.resize(NN, colvnused[cn]);
		colves.resize(NN);
		for (int k = 0; k != colvnused[cn]; ++k) {
			int theves = colvesused[cn][k];
			colves[NN - 1].resize(k + 1, theves);
		}
	}
	TON = NN;
	vescover.end();
	stcover.end();
	berthcover.end();
	fuelcover.end();
	bdscover.end();
	multicut.end();
	avgcut.end();
}

void netload(int lel, int ind, int branch) { 
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			NTIBD[i][b] = vbm[i][b]; 
		}
	}
	for (int i = 0; i != I; ++i) {
		NTFID[i] = 1;
		for (int j = 0; j != I; ++j) {
			NTIID[i][j] = 1;
		}
	}
	int thelel = lel;
	int theind = ind;
	int thebranch = branch;
	if (thelel != -2) {
		while (thelel != -1) {
			int thetype = brtype[thelel][theind]; 
			int then1 = brnd1[thelel][theind]; 
			int then2 = brnd2[thelel][theind]; 
			if (thebranch == 0) {
				if (thetype == 1) { 
					NTIBD[then1][then2] = 0;
				}
				if (thetype == 2) { 
					NTIID[then1][then2] = 0;
				}
			}
			if (thebranch == 1) {
				if (thetype == 1) { 
					for (int b = 0; b != then2; ++b) {
						NTIBD[then1][b] = 0;
					}
					for (int b = then2 + 1; b != B; ++b) {
						NTIBD[then1][b] = 0;
					}
				}
				if (thetype == 2) { 
					NTFID[then2] = 0; 
					for (int i = 0; i != then1; ++i) {
						NTIID[i][then2] = 0;
					}
					for (int i = then1 + 1; i != I; ++i) {
						NTIID[i][then2] = 0;
					}
				}
			}
			int tempind = nodeindx[thelel][theind][0];
			int tempbranch = nodeindx[thelel][theind][1];
			theind = tempind;
			thebranch = tempbranch;
			thelel -= 1;
		}
	}
	for (int i = 0; i != I; ++i) {
		Minivescost[i] = 999999;
		for (int b = 0; b != B; ++b) {
			if (lbves[b][i] < Minivescost[i] && NTIBD[i][b] == 1) {
				Minivescost[i] = lbves[b][i];
			}
		}
	}
}

int pathgen(int theberth, int MVN) { 
	int thenewcol = 0; 
	double acpbd = -0.001;
	int themini[I]; 
	minitotalcost[theberth] = 999999;
	for (int i = 0; i < MVN; ++i) {
		minicost[theberth][i] = 999999;
		themini[i] = -1;
	}
	double basecost = 0; 
	basecost -= berthdual[theberth];
	
	for (int n = 0; n != OBVN[theberth]; ++n) { 
		if (MVN < 1) { break; }
		int thev = OBVset[theberth][n];
		if (NTIBD[thev][theberth] == 1 && NTFID[thev] == 1) {
			tln += 1;
			double dcost[S];
			for (int s = 0; s != S; ++s) {
				dcost[s] = 0;
				double thestime = br[theberth][s];
				if (thestime < EAtime[thev][s]) {
					thestime = EAtime[thev][s]; 
				}
				double theendtime = thestime + Htime[theberth][thev][s]; 
				double thedelay = (theendtime - Ltime[thev][s]) - Vtime[thev];
				if (thedelay < 0) { thedelay = 0; }
				dcost[s] = Tcost[thev] * pow(double(thedelay), double(SLP));
				double thestay = Htime[theberth][thev][s]; 
				if (theendtime - (Ltime[thev][s] + Stime[thev][1]) > thestay) {
					thestay = theendtime - (Ltime[thev][s] + Stime[thev][1]);
				}
				dcost[s] += Ecost[thev][1] * Gpara[thev] * thestay;
				crtdcost[s].resize(tln, dcost[s]);
				crttime[s].resize(tln, theendtime);
			}
			veslen.resize(tln, 1);
			vesseq.resize(tln);
			vesseq[tln - 1].resize(1, thev);
			long mark = inimark * dpow(2, thev);
			long temp = VI;
			temp |= mark;
			vlset.resize(tln, temp);
			int tadn = 0; 
			avlist.resize(tln);
			for (int bn = 0; bn != n; ++bn) {
				int tempav = OBVset[theberth][bn];
				if (NTIBD[tempav][theberth] == 1 && NTIID[thev][tempav] == 1) {
					tadn += 1;
					avlist[tln - 1].resize(tadn, tempav);
				}
			}
			for (int bn = n + 1; bn != OBVN[theberth]; ++bn) {
				int tempav = OBVset[theberth][bn];
				if (NTIBD[tempav][theberth] == 1 && NTIID[thev][tempav] == 1) {
					tadn += 1;
					avlist[tln - 1].resize(tadn, tempav);
				}
			}
			avlen.resize(tln, tadn);
			double thecost = Hcost[thev][theberth] + basecost;
			thecost -= vesdual[thev];
			for (int cn = 0; cn < NBC; ++cn) {
				thecost += XBpara[thev][theberth][cn] * bddual[cn];
			}
			for (int s = 0; s != S; ++s) {
				thecost += dcost[s] * acdual[s];
			}
			flcost.resize(tln, thecost);
			if (minicost[theberth][0] > thecost) {
				minicost[theberth][0] = thecost;
				if (thecost < minitotalcost[theberth]) {
					minitotalcost[theberth] = thecost;
				}
				if (thecost <= acpbd) {
					themini[0] = tln - 1;
				}
			}
		}
	}
	for (int ln = 0; ln != tln; ++ln) { 
		gettimeofday(&t_crt, NULL);
		if (((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) > 1800) {
			cout << "Time is:" << ((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) << endl;
			break;
		}
		int thetan = avlen[ln]; 
		int thevl = veslen[ln]; 
		if (thevl + 1 > MVN) { 
			continue;
		}
		long thelq = vlset[ln]; 
		double theoridcost[S];
		double theatime[S];
		for (int s = 0; s != S; ++s) {
			theoridcost[s] = crtdcost[s][ln];
			theatime[s] = crttime[s][ln];
		}
		double theoricost = flcost[ln]; 
		double tempminicost = theoricost;
		double rcholder[I];
		double oridcostholder[I][S];
		double oriendtimeholder[I][S];
		double orireducedchangecosthoulder[I];
		double oritemprdcostholder[I];
		for (int an = 0; an != thetan; ++an) {
			int theav = avlist[ln][an]; 
			double mymrc = 0; 
			for (int bn = 0; bn < an; ++bn) {
				int theldv = avlist[ln][bn];
				double temprc = 0;
				for (int cn = 0; cn < NBC; ++cn) {
					temprc += YBpara[theberth][theldv][theav][cn] * bddual[cn];
				}
				if (temprc < 0) {
					mymrc += temprc;
				}
			}
			for (int bn = an + 1; bn < thetan; ++bn) {
				int theldv = avlist[ln][bn];
				double temprc = 0;
				for (int cn = 0; cn < NBC; ++cn) {
					temprc += YBpara[theberth][theldv][theav][cn] * bddual[cn];
				}
				if (temprc < 0) {
					mymrc += temprc;
				}
			}
			double tempcost = Hcost[theav][theberth];
			tempcost -= vesdual[theav];
			double temprdcost = 0;
			for (int cn = 0; cn < NBC; ++cn) {
				tempcost += XBpara[theav][theberth][cn] * bddual[cn];
			}
			for (int bn = 0; bn != thevl; ++bn) {
				int theldv = vesseq[ln][bn];
				for (int cn = 0; cn < NBC; ++cn) {
					tempcost += YBpara[theberth][theldv][theav][cn] * bddual[cn];
				}
			}
			for (int s = 0; s != S; ++s) {
				double dcost = theoridcost[s];
				double theendtime = 0;
				double thestime = theatime[s];
				if (thestime < EAtime[theav][s]) {
					thestime = EAtime[theav][s]; 
				}
				theendtime = thestime + Htime[theberth][theav][s]; 
				double thedelay = (theendtime - Ltime[theav][s]) - Vtime[theav];
				if (thedelay < 0) { thedelay = 0; }
				dcost += Tcost[theav] * pow(double(thedelay), double(SLP));
				double thestay = Htime[theberth][theav][s]; 
				if (theendtime - (Ltime[theav][s] + Stime[theav][1]) > thestay) {
					thestay = theendtime - (Ltime[theav][s] + Stime[theav][1]);
				}
				dcost += Ecost[theav][1] * Gpara[theav] * thestay;
				oridcostholder[an][s] = dcost;
				oriendtimeholder[an][s] = theendtime;
				tempcost += (dcost - theoridcost[s]) * acdual[s];
				temprdcost += dcost * acdual[s];
			}
			oritemprdcostholder[an] = temprdcost;
			orireducedchangecosthoulder[an] = tempcost;
			rcholder[an] = mymrc + tempcost;
			if (mymrc + tempcost < 0) {
				tempminicost += mymrc + tempcost;
			}
		}
		
		for (int j = 1; j < thetan; j++)
		{
			double key = rcholder[j];
			int i = j - 1;
			while (i >= 0 && rcholder[i] > key)
			{
				rcholder[i + 1] = rcholder[i];
				i--;
			}
			rcholder[i + 1] = key;
		}
		
		if (tempminicost >= 0) {
			if (tempminicost < minitotalcost[theberth]) {
				minitotalcost[theberth] = tempminicost;
			}
			for (int tvn = thevl; tvn != MVN; ++tvn) { 
				double levlmc = theoricost;
				for (int addn = 0; addn != tvn - thevl; ++addn) {
					levlmc += rcholder[addn];
				}
				if (levlmc < minicost[theberth][tvn]) {
					minicost[theberth][tvn] = levlmc;
				}
			}
			
			continue;
		}
		
		
		double oriprcost = 0;
		int handled[I];
		for (int i = 0; i != I; ++i) {
			handled[i] = 0;
		}
		for (int s = 0; s != S; ++s) {
			oriprcost += Pro[s] * theoridcost[s];
		}
		for (int vn = 0; vn != thevl; ++vn) {
			int theves = vesseq[ln][vn];
			oriprcost += Minifcost[theves] + Hcost[theves][theberth];
			handled[theves] = 1;
		}
		for (int i = 0; i != I; ++i) {
			if (handled[i] == 0) {
				oriprcost += Minivescost[i];
			}
		}
		for (int an = 0; an != thetan; ++an) {
			int theav = avlist[ln][an]; 
			double theprcost = oriprcost - Minivescost[theav];
			for (int s = 0; s != S; ++s) {
				theprcost += Pro[s] * oridcostholder[an][s];
			}
			theprcost += Minifcost[theav] + Hcost[theav][theberth];
			if (theprcost >= upperbound) {
				continue;
			}
			long mark = inimark * dpow(2, theav);
			long tempsl = thelq;
			tempsl |= mark;
			double tempcost = orireducedchangecosthoulder[an] + theoricost;
			int valid = 1;
			for (int pn = 0; pn != tln; ++pn) {
				if (pn == ln) {
					continue;
				}
				valid = 1;
				double pthecost = flcost[pn];
				long tempthevl = vlset[pn];
				if (tempthevl == tempsl) {
					valid = 0;
				}
				if (valid == 0) {
					valid = 1;
					double prdcost = 0;
					for (int s = 0; s != S; ++s) {
						prdcost += crtdcost[s][pn] * acdual[s];
					}
					if (pthecost - prdcost <= tempcost - oritemprdcostholder[an]) {
						valid = 0;
					}
				}
				if (valid == 0) {
					for (int s = 0; s != S; ++s) {
						double thetime = crttime[s][pn];
						double thethecost = crtdcost[s][pn];
						if (oriendtimeholder[an][s] <= thetime - 0.0001 || oridcostholder[an][s] <= thethecost - 0.0001) {
							valid = 1;
							break;
						}
					}
				}
				if (valid == 0) {
					break;
				}
			}
			if (valid == 1) {
				tln += 1; 
				veslen.resize(tln, thevl + 1);
				vesseq.resize(tln);
				for (int vn = 0; vn != thevl; ++vn) {
					int tempves = vesseq[ln][vn];
					vesseq[tln - 1].resize(vn + 1, tempves);
				}
				vesseq[tln - 1].resize(thevl + 1, theav);
				vlset.resize(tln, tempsl);
				flcost.resize(tln, tempcost);
				for (int s = 0; s != S; ++s) {
					crttime[s].resize(tln, oriendtimeholder[an][s]);
					crtdcost[s].resize(tln, oridcostholder[an][s]);
				}
				int tempal = thetan - 1;
				if (tempal >= 0) {
					int tadn = 0;
					avlist.resize(tln);
					for (int bn = 0; bn != an; ++bn) {
						int tempav = avlist[ln][bn];
						if (NTIBD[tempav][theberth] == 1 && NTIID[theav][tempav] == 1) {
							tadn += 1;
							avlist[tln - 1].resize(tadn, tempav);
						}
					}
					for (int bn = an + 1; bn != thetan; ++bn) {
						int tempav = avlist[ln][bn];
						if (NTIBD[tempav][theberth] == 1 && NTIID[theav][tempav] == 1) {
							tadn += 1;
							avlist[tln - 1].resize(tadn, tempav);
						}
					}
					avlen.resize(tln, tadn);
				}
				if (minicost[theberth][thevl] > tempcost) {
					minicost[theberth][thevl] = tempcost;
					if (tempcost < minitotalcost[theberth]) {
						minitotalcost[theberth] = tempcost;
					}
					if (tempcost <= acpbd) {
						themini[thevl] = tln - 1;
					}
				}
			}
		}
	}
	for (int i = 0; i != MVN; ++i) {
		if (themini[i] != -1) { 
			thenewcol += 1;
			NN += 1; 
			TON += 1; 
			colberth.resize(TON, theberth);
			colvn.resize(TON, veslen[themini[i]]);
			colves.resize(TON);
			double tempcost = 0;
			for (int vn = 0; vn != veslen[themini[i]]; ++vn) {
				int theves = vesseq[themini[i]][vn];
				colves[TON - 1].resize(vn + 1, theves);
				tempcost += Hcost[theves][theberth];
			}
			colcost.resize(TON, double(tempcost));
			for (int s = 0; s != S; ++s) {
				coladcost[s].resize(TON, crtdcost[s][themini[i]]);
			}
		}
	}
	return thenewcol;
}

int colgen(double thelb, int fcheck) { 
	int newcol = 0;
	for (int b = 0; b != B; ++b) {
		for (int s = 0; s != S; ++s) {
			crttime[s].erase(crttime[s].begin(), crttime[s].end());
			vector<double>().swap(crttime[s]);
			crtdcost[s].erase(crtdcost[s].begin(), crtdcost[s].end());
			vector<double>().swap(crtdcost[s]);
		}
		veslen.erase(veslen.begin(), veslen.end());
		vector<int>().swap(veslen);
		for (int ln = 0; ln != tln; ++ln) {
			vesseq[ln].erase(vesseq[ln].begin(), vesseq[ln].end());
			vector<int>().swap(vesseq[ln]);
		}
		vlset.erase(vlset.begin(), vlset.end());
		vector<long>().swap(vlset);
		avlen.erase(avlen.begin(), avlen.end());
		vector<int>().swap(avlen);
		for (int ln = 0; ln != tln; ++ln) {
			avlist[ln].erase(avlist[ln].begin(), avlist[ln].end());
			vector<int>().swap(avlist[ln]);
		}
		flcost.erase(flcost.begin(), flcost.end());
		vector<double>().swap(flcost);
		tln = 0;
		int thenewcl = pathgen(b, NODEMVN[b]);
		if (thenewcl >= 0) {
			newcol += thenewcl;
		}
	}
	
	for (int b = 0; b != B; ++b) {
		if (NODEMVN[b] == 0) {
			continue;
		}
		double templb = thelb;
		for (int b1 = 0; b1 < b; ++b1) {
			if (minitotalcost[b1] < 0) {
				templb += minitotalcost[b1];
			}
		}
		for (int b1 = b + 1; b1 < B; ++b1) {
			if (minitotalcost[b1] < 0) {
				templb += minitotalcost[b1];
			}
		}
		
		int themvn = NODEMVN[b];
		int MVN = NODEMVN[b];
		for (int i = MVN - 1; i >= 0; --i) {
			if (templb + minicost[b][i] >= upperbound) {
				themvn = i;
			}
			else { break; }
		}
		NODEMVN[b] = themvn;
	}
	double templb = thelb;
	for (int b = 0; b != B; ++b) {
		if (minitotalcost[b] < 0) {
			templb += minitotalcost[b];
		}
	}
	if (templb >= upperbound) {
		newcol = -1;
		cout << "node fixed" << endl;
	}
	return newcol;
}

double masterproblem(IloModel model, IloCplex lpsolver, IloNumVarArray x, int numsc) {
	
	IloEnv env = model.getEnv(); 
	double MVAL;
	double optvalue;
	IloInt j, i;   
	IloNumArray vescover(env, I);     
	IloNumArray stcover(env, I);     
	IloNumArray berthcover(env, B);     
	IloNumArray fuelcover(env, TFCN);     
	IloNumArray bdscover(env, NBC);     
	IloNumArray multicut(env, 1);
	IloNumArray avgcut(env, S);  
	try {
		for (j = N; j < numsc; j++) {  
			int thecol = j; 
			
			for (i = 0; i != I; ++i) { vescover[i] = 0; }
			for (i = 0; i != I; ++i) { stcover[i] = 0; }
			for (i = 0; i != B; ++i) { berthcover[i] = 0; }
			for (i = 0; i != TFCN; ++i) { fuelcover[i] = 0; }
			for (i = 0; i != S; ++i) {
				avgcut[i] = -coladcost[i][thecol];
			}
			for (int k = 0; k != colvn[thecol]; ++k) {
				int theves = colves[thecol][k];
				vescover[theves] = 1;
			}
			int theberth = colberth[thecol];
			berthcover[theberth] = 1;
			
			for (int cn = 0; cn != NBC; ++cn) {
				IloNum tempval = 0; 
				for (int k = 0; k != colvn[thecol]; ++k) {
					int theves = colves[thecol][k];
					tempval -= XBpara[theves][theberth][cn];
					if (k != colvn[thecol] - 1) {
						for (int fn = k + 1; fn != colvn[thecol]; ++fn) {
							int theves02 = colves[thecol][fn];
							tempval -= YBpara[theberth][theves][theves02][cn];
						}
					}
				}
				bdscover[cn] = tempval;
			}
			multicut[0] = 0;
			double thecost = colcost[thecol];
			x.add(IloNumVar(Totalcost(thecost) + Vessel(vescover) + Sailtime(stcover) + Berth(berthcover) + Fuelcon(fuelcover) + Bendcon(bdscover) + Multicon(multicut) + Acostcon(avgcut))); 
		}
		
		{
			
			lpsolver.solve();
			optvalue = upperbound;
			if (lpsolver.getStatus() == IloAlgorithm::Optimal) {
				optvalue = lpsolver.getObjValue();
				for (i = 0; i < I; i++) {
					vesdual[i] = lpsolver.getDual(Vessel[i]);
				}
				for (i = 0; i < B; i++) {
					berthdual[i] = lpsolver.getDual(Berth[i]);
				}
				bddual.resize(NBC, 0);
				for (i = 0; i < NBC; i++) {
					bddual[i] = lpsolver.getDual(Bendcon[i]);
				}
				for (int s = 0; s != S; ++s) {
					acdual[s] = lpsolver.getDual(Acostcon[s]);
				} 
				MVAL = optvalue;
			}
			
		}
	}
	catch (IloException& ex) {
		cout << "size of the model [" << x.getSize() << "]" << endl;
		cerr << ex << endl;
	}
	catch (...) {
		cerr << "Error..." << endl;
	}
	N = NN; 
	vescover.end();
	stcover.end();
	berthcover.end();
	fuelcover.end();
	bdscover.end();
	multicut.end();
	avgcut.end();
	return MVAL;
}

double StrongPsp(int sn) { 
	double Result = 0; 
	for (int i = 0; i != I; ++i) {
		ART[i] = Zsol[i] * double(60) + Ltime[i][sn]; 
		SBT[i] = ART[i]; 
	}
	for (int i = 0; i != I; ++i) {  
		BRT[i] = 0; 
		HBT[i] = 0; 
		for (int b = 0; b != B; ++b) {
			BRT[i] += Xsol[i][b] * br[b][sn];
			HBT[i] += Xsol[i][b] * Htime[b][i][sn];
		}
		if (SBT[i] < BRT[i]) {
			SBT[i] = BRT[i];
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			if (i == j) { continue; }
			for (int b = 0; b != B; ++b) {
				Theta1[b][i][j] = 0;
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					Theta1[b][i][j] += (Ysol[b][i][j] + Ysol[b][k][j] - Ysol[b][k][i] - 1) * Htime[b][k][sn];
				}
				Theta1[b][i][j] += ART[i] + (Ysol[b][i][j] - 1) * BM[i][j][sn] + Ysol[b][i][j] * Htime[b][i][sn];
			}
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			if (i == j) { continue; }
			for (int b = 0; b != B; ++b) {
				Psi[b][i][j] = 0;
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					Psi[b][i][j] += (Ysol[b][i][j] + Ysol[b][k][j] - Ysol[b][k][i] - 1) * Htime[b][k][sn];
				}
				Psi[b][i][j] += Ysol[b][i][j] * (br[b][sn] + Htime[b][i][sn]);
			}
		}
	}
	for (int i = 0; i != I; ++i) {
		double thetime = SBT[i]; 
		for (int b = 0; b != B; ++b) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				if (thetime < Theta1[b][j][i]) {
					thetime = Theta1[b][j][i];
				}
				if (thetime < Psi[b][j][i]) {
					thetime = Psi[b][j][i];
				}
			}
		}
		SBT[i] = thetime;
	}
	for (int i = 0; i != I; ++i) {
		DBT[i] = SBT[i] + HBT[i] - ART[i]; 
		LST[i] = 0; 
		if (Zsol[i] * double(60) + DBT[i] - Vtime[i] > 0.0001) {
			LST[i] = Zsol[i] * double(60) + DBT[i] - Vtime[i];
		}
	}
	for (int i = 0; i != I; ++i) {
		Result += Ecost[i][1] * Gpara[i] * DBT[i];
		Result += Tcost[i] * pow(double(LST[i]), double(SLP));
	}
	
	double CBRT[I];
	double CART[I];
	double CHBT[I];
	double CTheta1[B][I][I];
	double CPsi[B][I][I];
	for (int i = 0; i != I; ++i) {
		CBRT[i] = 0; 
		CHBT[i] = 0; 
		CART[i] = CZsol[i] * double(60) + DBT[i]; 
		for (int b = 0; b != B; ++b) {
			CBRT[i] += CXsol[i][b] * double(br[b][sn]);
			CHBT[i] += CXsol[i][b] * double(Htime[b][i][sn]);
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			if (i == j) { continue; }
			for (int b = 0; b != B; ++b) {
				CTheta1[b][i][j] = CART[i];
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					CTheta1[b][i][j] += (CYsol[b][i][j] + CYsol[b][k][j] - CYsol[b][k][i] - 1) * double(Htime[b][k][sn]);
				}
				CTheta1[b][i][j] += (CYsol[b][i][j] - 1) * BM[i][j][sn] + CYsol[b][i][j] * double(Htime[b][i][sn]);
			}
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			if (i == j) { continue; }
			for (int b = 0; b != B; ++b) {
				CPsi[b][i][j] = 0;
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					CPsi[b][i][j] += (CYsol[b][i][j] + CYsol[b][k][j] - CYsol[b][k][i] - 1) * double(Htime[b][k][sn]);
				}
				CPsi[b][i][j] += CYsol[b][i][j] * double(br[b][sn] + Htime[b][i][sn]);
			}
		}
	}
	
	for (int j = 0; j != I; ++j) {
		delta[j] = 0;
		zeta[j] = 0;
		pi[j] = 0;
		varpi[j] = 0;
		lambda[j] = 0;
	}
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				theta[b][i][j] = 0;
				vartheta[b][i][j] = 0;
			}
		}
	}
	for (int j = 0; j != I; ++j) {
		
		double themini = 9999999;
		int thetype = -1; 
		int thebindex = -1;
		int theiindex = -1;
		if (SBT[j] == BRT[j]) {
			themini = CART[j] - CBRT[j];
			thetype = 1;
		}
		for (int b = 0; b != B; ++b) {
			for (int nn = 0; nn != I; ++nn) {
				if (j == nn) { continue; }
				if (SBT[j] == Theta1[b][nn][j]) {
					if (themini > CART[j] - CTheta1[b][nn][j]) {
						themini = CART[j] - CTheta1[b][nn][j];
						thetype = 2;
						thebindex = b;
						theiindex = nn;
					}
				}
			}
		}
		for (int b = 0; b != B; ++b) {
			for (int nn = 0; nn != I; ++nn) {
				if (j == nn) { continue; }
				if (SBT[j] == Psi[b][nn][j]) {
					if (themini > CART[j] - CPsi[b][nn][j]) {
						themini = (CART[j] - CPsi[b][nn][j]);
						thetype = 3;
						thebindex = b;
						theiindex = nn;
					}
				}
			}
		}
		int pifixed = 0;
		if (LST[j] >= 0.00001) {
			pifixed = 1;
			pi[j] = -double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1));
		}
		if (LST[j] < 0.00001 && LST[j] >= Zsol[j] * double(60) + DBT[j] - Vtime[j] + 0.00001) {
			pifixed = 1;
			pi[j] = 0;
		}
		if (pifixed == 1) {
			if (themini <= 0 || SBT[j] >= ART[j] + 0.00001) {
				double thetempval = pi[j] - (Ecost[j][1] * Gpara[j]);
				if (thetype == 1) {
					zeta[j] = thetempval;
				}
				if (thetype == 2) {
					theta[thebindex][theiindex][j] = thetempval;
				}
				if (thetype == 3) {
					vartheta[thebindex][theiindex][j] = thetempval;
				}
			}
		}
		if (pifixed == 0) {
			double pip = Vtime[j] - CHBT[j] - CZsol[j] * double(60);
			if (SBT[j] >= ART[j] + 0.00001) {
				if (themini <= -pip) {
					pi[j] = -(Ecost[j][1] * Gpara[j]);
					if (pi[j] < -double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1))) {
						pi[j] = -double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1));
					}
				}
				if (thetype == 1) {
					zeta[j] = pi[j] - (Ecost[j][1] * Gpara[j]);
				}
				if (thetype == 2) {
					theta[thebindex][theiindex][j] = pi[j] - (Ecost[j][1] * Gpara[j]);
				}
				if (thetype == 3) {
					vartheta[thebindex][theiindex][j] = pi[j] - (Ecost[j][1] * Gpara[j]);
				}
			}
			if (SBT[j] == ART[j]) {
				if (themini <= -pip || pip <= 0) {
					pi[j] = -(Ecost[j][1] * Gpara[j]);
					if (pi[j] < -double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1))) {
						pi[j] = -double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1));
					}
				}
				if (themini <= 0) {
					if (thetype == 1) {
						zeta[j] = pi[j] - (Ecost[j][1] * Gpara[j]);
					}
					if (thetype == 2) {
						theta[thebindex][theiindex][j] = pi[j] - (Ecost[j][1] * Gpara[j]);
					}
					if (thetype == 3) {
						vartheta[thebindex][theiindex][j] = pi[j] - (Ecost[j][1] * Gpara[j]);
					}
				}
			}
		}
		double temp = 0;
		for (int b = 0; b != B; ++b) {
			for (int i = 0; i != I; ++i) {
				if (i == j) { continue; }
				temp += theta[b][i][j] + vartheta[b][i][j];
			}
		}
		delta[j] = pi[j] - (Ecost[j][1] * Gpara[j]) - zeta[j] - temp;
		lambda[j] = pi[j] - (Ecost[j][1] * Gpara[j]);
		varpi[j] = -pi[j] - double(SLP) * Tcost[j] * pow(double(LST[j]), double(SLP - 1));
	}
	double dcost = 0;
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			dcost += -(br[b][sn] * zeta[i] + Htime[b][i][sn] * lambda[i]) * Xsol[i][b];
			XBtemp[i][b][sn] += -(br[b][sn] * zeta[i] + Htime[b][i][sn] * lambda[i]);
		}
	}
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				YBtemp[b][i][j][sn] += (-(((BM[i][j][sn] + Htime[b][i][sn]) * theta[b][i][j]) + ((Htime[b][i][sn] + br[b][sn]) * vartheta[b][i][j])));
				dcost += (-(((BM[i][j][sn] + Htime[b][i][sn]) * theta[b][i][j]) + ((Htime[b][i][sn] + br[b][sn]) * vartheta[b][i][j]))) * Ysol[b][i][j];
				double temptotal = 0;
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					temptotal += Htime[b][i][sn] * theta[b][k][j];
					temptotal += Htime[b][i][sn] * vartheta[b][k][j];
				}
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					temptotal -= Htime[b][i][sn] * theta[b][j][k];
					temptotal -= Htime[b][i][sn] * vartheta[b][j][k];
				}
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					temptotal += Htime[b][k][sn] * theta[b][i][j];
					temptotal += Htime[b][k][sn] * vartheta[b][i][j];
				}
				YBtemp[b][i][j][sn] += -((temptotal));
				dcost += -(temptotal)*Ysol[b][i][j];
			}
		}
	}
	for (int i = 0; i != I; ++i) {
		double thetatotal02 = 0;
		for (int b = 0; b != B; ++b) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				thetatotal02 += theta[b][i][j];
			}
		}
		dcost += ((lambda[i] - pi[i] - delta[i] - thetatotal02) * double(60) * Zsol[i]);
		ZBtemp[i][sn] += ((lambda[i] - pi[i] - delta[i] - thetatotal02) * double(60));
	}
	double cttotal = 0;
	for (int i = 0; i != I; ++i) {
		cttotal += Ecost[i][1] * Gpara[i] * DBT[i];
		cttotal += Tcost[i] * pow(LST[i], SLP);
		cttotal += (SBT[i] - Ltime[i][sn]) * delta[i];
		cttotal += SBT[i] * zeta[i];
		cttotal += (DBT[i] - SBT[i] + Ltime[i][sn]) * lambda[i];
	}
	for (int i = 0; i != I; ++i) {
		cttotal += (LST[i] - DBT[i] + Vtime[i]) * pi[i];
		cttotal += LST[i] * varpi[i];
	}
	for (int b = 0; b != B; ++b) {
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				cttotal += (SBT[j] - Ltime[i][sn] + BM[i][j][sn]) * theta[b][i][j];
				cttotal += SBT[j] * vartheta[b][i][j];
				for (int k = 0; k != I; ++k) {
					if (k == i || k == j) { continue; }
					cttotal += Htime[b][k][sn] * theta[b][i][j];
					cttotal += Htime[b][k][sn] * vartheta[b][i][j];
				}
			}
		}
	}
	dcost += cttotal;
	CBtemp[sn] += cttotal;
	
	
	if (dcost - Result >= 0.001 || dcost - Result <= -0.001) {
		cout << "wrong wrong wrong" << endl;
	}
	return Result;  
}

double Seperation() {
	double totalcost = 0;
	for (int sn = 0; sn != S; ++sn) {
		CBtemp[sn] = 0;
		for (int i = 0; i != I; ++i) {
			for (int b = 0; b != B; ++b) {
				XBtemp[i][b][sn] = 0;
			}
		}
		for (int b = 0; b != B; ++b) {
			for (int i = 0; i != I; ++i) {
				for (int j = 0; j != I; ++j) {
					if (i == j) { continue; }
					YBtemp[b][i][j][sn] = 0;
				}
			}
		}
		for (int i = 0; i != I; ++i) {
			ZBtemp[i][sn] = 0;
		}
		double theresult = StrongPsp(sn);
		BDsol[sn] = theresult;
		totalcost += theresult * Pro[sn];
	}
	double tempub = Fcost + totalcost;
	return tempub;
}

void Benderfulsep() { 
	for (int i = 0; i != TSN; ++i) {
		int thei = TSset[i];
		double theval = 0; 
		if (AZBtemp[thei] > 0) {
			double tempval = (AZBtemp[thei] / ((Dcost[thei] + Ecost[thei][0]) * Apara[thei] * double(60) * pow(Dis[thei], 3) * 2));
			double theoeff = double(-1) / double(3);
			theval = pow(tempval, theoeff); 
			if (theval >= Stime[thei][0] / double(60) + 0.01 && theval <= Stime[thei][1] / double(60) + 0.01) {
				FCsep(i, theval);
			}
		}
	}
}

int Fuelsep(double lb) { 
	int recal = 0; 
	double totalgap = 0;
	for (int n = 0; n != TSN; ++n) {
		int thei = TSset[n]; 
		double thet = Zsol[thei]; 
		double thefcost = (Dcost[thei] + Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
		totalgap += double(thefcost - Hsol[n]); 
	}
	Rfgap = totalgap;
	if ((totalgap / lb) * 100 >= Fgap) {
		
		
		for (int n = 0; n != TSN; ++n) {
			int thei = TSset[n];
			double thet = Zsol[thei]; 
			double thefcost = (Dcost[thei] + Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
			double tempgap = double(thefcost - Hsol[n]);
			if ((tempgap / thefcost) * 100 >= Fgap) {
				recal = 1;
				FCsep(n, thet);
			}
		}
	}
	return recal;
}

void BDsep() {
	for (int sn = 0; sn != S; ++sn) {
		double sgap = double(BDsol[sn] - Ssol[sn]) / BDsol[sn] * 100;
		if (sgap > BDgap) {
			
			NBC += 1;
			BCS.resize(NBC, sn); 
			CBpara.resize(NBC, CBtemp[sn]);
			for (int i = 0; i != I; ++i) {
				for (int b = 0; b != B; ++b) {
					XBpara[i][b].resize(NBC, XBtemp[i][b][sn]);
				}
			}
			for (int b = 0; b != B; ++b) {
				for (int i = 0; i != I; ++i) {
					for (int j = 0; j != I; ++j) {
						if (i == j) { continue; }
						YBpara[b][i][j].resize(NBC, YBtemp[b][i][j][sn]);
					}
				}
			}
			for (int i = 0; i != TSN; ++i) {
				int thei = TSset[i];
				ZBpara[i].resize(NBC, ZBtemp[thei][sn]);
				LZBtemp[i][sn] = ZBtemp[thei][sn];
			}
		}
	}
	for (int i = 0; i != TSN; ++i) {
		int thei = TSset[i];
		AZBtemp[thei] = 0;
		for (int sn = 0; sn != S; ++sn) {
			AZBtemp[thei] += Pro[sn] * LZBtemp[i][sn];
		}
	}
	Benderfulsep(); 
}

void Colclear() {
	colcost.erase(colcost.begin(), colcost.end());
	vector<double>().swap(colcost);
	for (int s = 0; s != S; ++s) {
		coladcost[s].erase(coladcost[s].begin(), coladcost[s].end());
		vector<double>().swap(coladcost[s]);
	}
	colberth.erase(colberth.begin(), colberth.end());
	vector<int>().swap(colberth);
	colvn.erase(colvn.begin(), colvn.end());
	vector<int>().swap(colvn);
	for (int cn = 0; cn != TON; ++cn) {
		colves[cn].erase(colves[cn].begin(), colves[cn].end());
		vector<int>().swap(colves[cn]);
	}
	colvn.erase(colvn.begin(), colvn.end());
	vector<int>().swap(colvn);
	TON = 0; 
}

void USEDColclear() {
	colcostused.erase(colcostused.begin(), colcostused.end());
	vector<double>().swap(colcostused);
	colberthused.erase(colberthused.begin(), colberthused.end());
	vector<int>().swap(colberthused);
	for (int s = 0; s != S; ++s) {
		coladcostused[s].erase(coladcostused[s].begin(), coladcostused[s].end());
		vector<double>().swap(coladcostused[s]);
	}
	colvnused.erase(colvnused.begin(), colvnused.end());
	vector<int>().swap(colvnused);
	colsolused.erase(colsolused.begin(), colsolused.end());
	vector<double>().swap(colsolused);
	for (int cn = 0; cn != numused; ++cn) {
		colvesused[cn].erase(colvesused[cn].begin(), colvesused[cn].end());
		vector<int>().swap(colvesused[cn]);
	}
	numused = 0; 
}

void Solutioncheck(int lel, int ind, int branch, double lwbd) {
	double Seqscore[I][I];
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			Seqscore[i][j] = 0;
		}
	}
	for (int i = 0; i != I; ++i) {
		for (int j = 0; j != I; ++j) {
			for (int b = 0; b != B; ++b) {
				Seqscore[i][j] += Ysol[b][i][j];
			}
		}
	}
	int thetype = -1; 
	int then1 = -1;
	int then2 = -1;
	double minscore = 0.5;
	double tempd = 0;
	for (int i = 0; i != I; ++i) {
		for (int b = 0; b != B; ++b) {
			double trv = Xsol[i][b];
			if (trv <= 0.0001 || trv >= 0.9999) { continue; }
			if (trv >= 0.5) {
				tempd = trv - 0.5;
			}
			else {
				tempd = 0.5 - trv;
			}
			if (minscore > tempd) { 
				minscore = tempd;
				thetype = 1; 
				then1 = i;
				then2 = b;
			}
			if (minscore < 0.0001) {
				break;
			}
		}
	}
	if (thetype == -1) { 
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				double trv = Seqscore[i][j];
				if (trv <= 0.0001 || trv >= 0.9999) { continue; }
				if (trv >= 0.5) {
					tempd = trv - 0.5;
				}
				else {
					tempd = 0.5 - trv;
				}
				if (minscore > tempd) { 
					minscore = tempd;
					thetype = 2; 
					then1 = i;
					then2 = j;
				}
				if (minscore < 0.0001) { break; }
			}
		}
	}
	if (thetype == -1) {
		cout << "check check" << endl;
	}
	if (thetype != -1) {
		int crtlel = lel + 1; 
		if (crtlel + 1 > levels) { 
			levels += 1;
			nodenum.resize(levels, 0); 
			nodeindx.resize(levels);
			lowerbound.resize(levels);
			brcho[0].resize(levels); 
			brcho[1].resize(levels);
			brnd1.resize(levels);   
			brnd2.resize(levels);   
			brtype.resize(levels);  
			for (int b = 0; b != B; ++b) {
				maxvn[b].resize(levels);
			}
		}
		nodenum[crtlel] += 1;
		int lenum = nodenum[crtlel];
		nodeindx[crtlel].resize(lenum);
		nodeindx[crtlel][lenum - 1].resize(1, ind); 
		nodeindx[crtlel][lenum - 1].resize(2, branch); 
		lowerbound[crtlel].resize(lenum, lwbd);
		brcho[0][crtlel].resize(lenum, 1);
		brcho[1][crtlel].resize(lenum, 1);
		brtype[crtlel].resize(lenum, thetype);
		brnd1[crtlel].resize(lenum, then1);
		brnd2[crtlel].resize(lenum, then2);
		for (int b = 0; b != B; ++b) {
			
			maxvn[b][crtlel].resize(lenum, NODEMVN[b]);
		}
	}
}

double mastersolver(int lel, int ind, int branch, double thelb) { 
	
	double lwbd;
	Colclear();
	
	IloEnv env; 
	IloModel msmodel(env);
	IloCplex lpsolver(msmodel);
	lpsolver.setOut(env.getNullStream());
	lpsolver.setParam(IloCplex::Threads, 1);  
	IloNumVarArray x(env);   
	IloInt i;   
	Totalcost = IloAdd(msmodel, IloMinimize(env));
	IloNumArray vstimelb(env, I);  
	IloNumArray vstimeub(env, I);  
	for (i = 0; i != I; ++i) { vstimelb[i] = Stime[i][0]; }  
	for (i = 0; i != I; ++i) { vstimeub[i] = Stime[i][1]; }  
	Sailtime = IloAdd(msmodel, IloRangeArray(env, vstimelb, vstimeub));  
	IloNumArray fuelreach(env, TFCN);  
	for (i = 0; i != TFCN; ++i) { fuelreach[i] = FCTCL[i]; }  
	Fuelcon = IloAdd(msmodel, IloRangeArray(env, fuelreach, IloInfinity));  
	IloNumArray vesreach(env, I);  
	for (i = 0; i != I; ++i) { vesreach[i] = 1; }  
	Vessel = IloAdd(msmodel, IloRangeArray(env, vesreach, vesreach));  
	IloNumArray berthocp(env, B);  
	for (i = 0; i != B; ++i) { berthocp[i] = 1; } 
	Berth = IloAdd(msmodel, IloRangeArray(env, -IloInfinity, berthocp));  
	IloNumArray bdscut(env, NBC);  
	for (i = 0; i != NBC; ++i) { bdscut[i] = CBpara[i]; } 
	Bendcon = IloAdd(msmodel, IloRangeArray(env, bdscut, IloInfinity));  
	IloNumArray multicut(env, 1);  
	for (i = 0; i != 1; ++i) { multicut[i] = 0; } 
	Multicon = IloAdd(msmodel, IloRangeArray(env, multicut, IloInfinity));  
	IloNumArray avgcut(env, S);  
	for (i = 0; i != S; ++i) { avgcut[i] = 0; } 
	Acostcon = IloAdd(msmodel, IloRangeArray(env, avgcut, IloInfinity));  
	if (lel != -1 && lel != -2) {
		for (int b = 0; b != B; ++b) {
			NODEMVN[b] = maxvn[b][lel][ind];
		}
	}
	else {
		for (int b = 0; b != B; ++b) {
			NODEMVN[b] = OBVN[b];
		}
	}
	Inicolload(msmodel, x, 0); 
	lwbd = masterproblem(msmodel, lpsolver, x, NN); 
	if (lel != -2) {
		int ncs = colgen(lwbd, 1);
		if (ncs == -1) {
			lwbd = upperbound + 1;
		}
		while (ncs > 0) {
			lwbd = masterproblem(msmodel, lpsolver, x, NN); 
			ncs = colgen(lwbd, 1);
			if (ncs == -1) {
				lwbd = upperbound + 1;
			}
		}
	}
	if (lwbd < upperbound) {
		for (int i = 0; i != I; ++i) {
			for (int b = 0; b != B; ++b) {
				Xsol[i][b] = 0;
			}
		}
		for (int b = 0; b != B; ++b) {
			for (int i = 0; i != I; ++i) {
				for (int j = 0; j != I; ++j) {
					if (i == j) { continue; }
					Ysol[b][i][j] = 0;
				}
			}
		}
		USEDColclear();
		intsol = 1;
		for (int cn = TCN01; cn != TCN01 + NN; ++cn) {
			double temp = lpsolver.getValue(x[cn]);
			if (temp > 0.0001) {
				if (temp >= 0.9999) {
					temp = 1;
				}
				int thecol = cn - TCN01;
				numused += 1;
				colsolused.resize(numused, temp);
				colcostused.resize(numused, colcost[thecol]);
				colberthused.resize(numused, colberth[thecol]);
				colvnused.resize(numused, colvn[thecol]);
				for (int s = 0; s != S; ++s) {
					coladcostused[s].resize(numused, coladcost[s][thecol]);
				}
				colvesused.resize(numused);
				int theberth = colberth[thecol];
				for (int k = 0; k != colvn[thecol]; ++k) {
					int theves = colves[thecol][k];
					colvesused[numused - 1].resize(k + 1, theves);
					Xsol[theves][theberth] += temp;
					if (k != colvn[thecol] - 1) {
						for (int fn = k + 1; fn != colvn[thecol]; ++fn) {
							int theves02 = colves[thecol][fn];
							Ysol[theberth][theves][theves02] += temp;
						}
					}
				}
				if (temp <= 0.999) {
					intsol = 0;
				}
			}
		}
		for (int cn = 0; cn != I; ++cn) {
			double temp = lpsolver.getValue(x[cn]);
			Zsol[cn] = temp; 
		}
		for (int cn = I; cn != I + TSN; ++cn) {
			double temp = lpsolver.getValue(x[cn]);
			Hsol[cn - I] = temp;
		}
		for (int cn = (I + TSN + 1); cn != (I + TSN + 1 + S); ++cn) {
			int thes = cn - (I + TSN + 1);
			Ssol[thes] = lpsolver.getValue(x[cn]);
		}
		Scost = lpsolver.getValue(x[I + TSN]);
		Fcost = lwbd - Scost; 
	}
	env.end();
	return lwbd;
	
}

void Benders(int lel, int ind, int branch, double thelb) {
	double tempgap = 100;
	double bdlb = 0; 
	double bdub; 
	netload(lel, ind, branch);
	USEDColclear();
	int themfrc = 1;
	while (themfrc == 1 && bdlb <= upperbound - 0.001) {
		bdlb = mastersolver(lel, ind, branch, thelb); 
		themfrc = Fuelsep(bdlb); 
	}
	for (int i = 0; i != I; ++i) { CZsol[i] = 0.5 * CZsol[i] + 0.5 * Zsol[i]; }
	if (intsol == 1 && bdlb <= upperbound - 0.001) {
		for (int i = 0; i != I; ++i) {
			for (int b = 0; b != B; ++b) { CXsol[i][b] = 0.5 * CXsol[i][b] + 0.5 * Xsol[i][b]; }
		}
		for (int b = 0; b != B; ++b) {
			for (int i = 0; i != I; ++i) {
				for (int j = 0; j != I; ++j) { CYsol[b][i][j] = 0.5 * CYsol[b][i][j] + 0.5 * Ysol[b][i][j]; }
			}
		}
		double tempub = Seperation(); 
		bdub = tempub + Rfgap;
		if (upperbound > bdub) {
			upperbound = bdub;
			cout << "new upperbound by branch and bound=" << upperbound << endl;
			BSrecord();
		}
		bdub = tempub + Rfgap;
		tempgap = (bdub - (bdlb + Rfgap)) / bdub * 100;
		if (tempgap > BDgap02) {
			BDsep();
		}
		Colclear();
		
	}
	
	if (lel != -2 && bdlb <= upperbound - 0.0001) { 
		USEDColclear();
		tempgap = 100;
		intsol = 1;
		while (intsol == 1 && tempgap > BDgap02 && bdlb <= upperbound - 0.001) {
			themfrc = 1;
			while (themfrc == 1 && bdlb <= upperbound - 0.001) {
				bdlb = mastersolver(lel, ind, branch, thelb); 
				themfrc = Fuelsep(bdlb); 
			}
			for (int i = 0; i != I; ++i) { CZsol[i] = 0.5 * CZsol[i] + 0.5 * Zsol[i]; }
			
			if (intsol == 0 && bdlb <= upperbound - 0.001) {
				Solutioncheck(lel, ind, branch, bdlb);
			}
			if (intsol == 1 && bdlb <= upperbound - 0.001) {
				for (int i = 0; i != I; ++i) {
					for (int b = 0; b != B; ++b) { CXsol[i][b] = 0.5 * CXsol[i][b] + 0.5 * Xsol[i][b]; }
				}
				for (int b = 0; b != B; ++b) {
					for (int i = 0; i != I; ++i) {
						for (int j = 0; j != I; ++j) { CYsol[b][i][j] = 0.5 * CYsol[b][i][j] + 0.5 * Ysol[b][i][j]; }
					}
				}
				double tempub = Seperation(); 
				bdub = tempub + Rfgap;
				if (upperbound > bdub) {
					upperbound = bdub;
					cout << "new upperbound by branch and bound=" << upperbound << endl;
					BSrecord();
				}
				tempgap = (bdub - (bdlb + Rfgap)) / bdub * 100;
				if (tempgap > BDgap02) {
					
					BDsep();
				}
			}
		}
	}
}

void nodebranch() { 
	int fnode;               
	int flayer;              
	int ffind = 0;             
	double LL = upperbound + 1;
	double totalgap02=100;
	while (1) {
		flayer = -10;
		fnode = -10;  
		totallb = upperbound;
		int tnn = 0; 
		
		for (int ll = 0; ll != levels; ++ll) {
			int tndn = nodenum[ll];
			for (int nn = 0; nn != tndn; ++nn) {
				double thelb = lowerbound[ll][nn];
				if (thelb < upperbound) {
					if (brcho[0][ll][nn] == 0 && brcho[1][ll][nn] == 0) { 
						lowerbound[ll][nn] = LL;
					}
					else {
						tnn += 1; 
						if (thelb < totallb) {
							flayer = ll;
							fnode = nn;
							totallb = thelb;
						}
					}
				}
			}
		}
		if (totalgap <= (100 * (upperbound - totallb) / upperbound) - 0.01) {
			cout << "gap wrong wrong" << (100 * (upperbound - totallb) / upperbound) << endl;
			break;
		}
		totalgap = 100 * (upperbound - totallb) / upperbound;
		cout << "the optimality gap is:" << totalgap << "%" << endl;
		gettimeofday(&t_crt, NULL);
		cout << "Time is:" << ((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) << endl;
		if (((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) <= 1800) {
			totalgap02 = totalgap;
		}
		if (tnn == 0) {
			cout << "all nodes have been closed" << endl;
			break;
		}
		if (totalgap <= Tgap) {
			break;
		}
		
		if (tnn > 0) {
			if (fnode != -10) {
				cout << "branch on node[" << flayer << "][" << fnode << "]" << endl;
				if (brcho[1][flayer][fnode] == 1) {
					brcho[1][flayer][fnode] = 0;
					
					double crtlb = lowerbound[flayer][fnode];
					Benders(flayer, fnode, 1, crtlb); 
				}
				gettimeofday(&t_crt, NULL);
				if (((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) > 1800) {
					cout << "Time limit is reached" << endl;
					break;
				}
				if (brcho[0][flayer][fnode] == 1) {
					brcho[0][flayer][fnode] = 0;
					
					double crtlb = lowerbound[flayer][fnode];
					Benders(flayer, fnode, 0, crtlb); 
				}
			}
		}
		gettimeofday(&t_crt, NULL);
		if (((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) > 1800) {
			cout << "Time limit is reached" << endl;
			break;
		}
	}
	cout << endl;
	cout << endl;
	cout << "the final optimality gap is:" << totalgap02 << "%" << endl;
	cout << "Calculation time is:" << ((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) << " Seconds" << endl;
	cout << endl;
	mycout02 << "the final optimality gap is:" << endl << totalgap02 << endl;
	mycout02 << "Calculation time is:" << endl << ((t_crt.tv_sec - t_start.tv_sec) * 1000000 + (t_crt.tv_usec - t_start.tv_usec)) / double(1000000) << endl;
}

void Realtest() { 
	double thehcost = 0; 
	double thefcost = 0; 
	double theecost = 0; 
	double thedcost = 0; 
	for (int b = 0; b != B; ++b) {
		for (int n = 0; n != BESTBVN[b]; ++n) {
			int theves = BESTBVset[b][n];
			thehcost += Hcost[theves][b];
		}
	}
	for (int n = 0; n != TSN; ++n) {
		int thei = TSset[n]; 
		double thet = BZsol[thei]; 
		double temp01 = (Dcost[thei]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
		double temp02 = (Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
		thefcost += temp01; 
		theecost += temp02;
	}
	for (int b = 0; b != B; ++b) {
		double crttime = RTBR[b];
		for (int n = 0; n != BESTBVN[b]; ++n) {
			int theves = BESTBVset[b][n];
			double theea = BZsol[theves] * double(60) + RLtime[theves];
			double thest = theea;
			if (thest < crttime) {
				thest = crttime;
			}
			double theet = thest + double(RTHT[b][theves]);
			crttime = theet;
			double thestay = theet - theea;
			
			double thedelay = (theet - RLtime[theves]) - Vtime[theves];
			if (thedelay < 0) { thedelay = 0; }
			
			double tempdc = Tcost[theves] * pow(double(thedelay), double(SLP));
			
			double tempec = Ecost[theves][1] * Gpara[theves] * thestay;
			theecost += tempec;
			thedcost += tempdc;
		}
	}
	cout << "Real Fuel cost=" << thefcost << endl;
	cout << "Real Handling cost=" << thehcost << endl;
	cout << "Real Emission cost=" << theecost << endl;
	cout << "Real Delay cost=" << thedcost << endl;
	cout << "Real Total cost=" << thefcost + thehcost + thedcost + theecost << endl;
	mycout02 << "Real Fuel cost=" << endl << thefcost << endl;
	mycout02 << "Real Handling cost=" << endl << thehcost << endl;
	mycout02 << "Real Emission cost=" << endl << theecost << endl;
	mycout02 << "Real Delay cost=" << endl << thedcost << endl;
	mycout02 << "Real Total cost=" << endl << thefcost + thehcost + thedcost + theecost << endl;
}

void Solvebap() {
	Benders(-2, -2, -2, 0);
	Benders(-1, -1, -1, 0);
	nodebranch();
	double totalcost = 0;
	cout << "Upperbound=" << upperbound << endl;
	mycout02 << "Upperbound=" << endl << upperbound << endl;
	double thehcost = 0; 
	double thefcost = 0; 
	double thetecost = 0; 
	double thedcost[S]; 
	double theecost[S]; 
	double thetdcost = 0; 
	mycout01 << "int OCODE=" << CODE << ";" << endl;
	mycout01 << "int BESTBVN [B]={";
	for (int b = 0; b != B; ++b) {
		mycout01 << BESTBVN[b];
		if (b < B - 1) {
			mycout01 << ",";
		}
	}
	mycout01 << "};" << endl;
	mycout01 << "int BESTBVset[B][I]={";
	for (int b = 0; b != B; ++b) {
		mycout01 << "{";
		for (int n = 0; n != BESTBVN[b]; ++n) {
			int theves = BESTBVset[b][n];
			thehcost += Hcost[theves][b];
			mycout01 << BESTBVset[b][n];
			if (n < BESTBVN[b] - 1) {
				mycout01 << ",";
			}
		}
		mycout01 << "}";
		if (b < B - 1) {
			mycout01 << ",";
		}
	}
	mycout01 << "};" << endl;
	mycout01 << "double BZsol[I]={";
	for (int i = 0; i != I; ++i) {
		mycout01 << BZsol[i];
		if (i < I - 1) {
			mycout01 << ",";
		}
	}
	mycout01 << "};" << endl;
	for (int n = 0; n != TSN; ++n) {
		int thei = TSset[n]; 
		double thet = BZsol[thei]; 
		double temp01 = (Dcost[thei]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
		double temp02 = (Ecost[thei][0]) * (Apara[thei] * double(60) * pow(Dis[thei], 3)) * pow(thet, -2); 
		thefcost += temp01; 
		thetecost += temp02;
	}
	for (int sn = 0; sn != S; ++sn) {
		double Result01 = 0; 
		double Result02 = 0; 
		for (int i = 0; i != I; ++i) {
			ART[i] = BZsol[i] * double(60) + Ltime[i][sn]; 
			SBT[i] = ART[i]; 
		}
		for (int i = 0; i != I; ++i) {  
			BRT[i] = 0; 
			HBT[i] = 0; 
			for (int b = 0; b != B; ++b) {
				BRT[i] += BXsol[i][b] * br[b][sn];
				HBT[i] += BXsol[i][b] * Htime[b][i][sn];
			}
			if (SBT[i] < BRT[i]) {
				SBT[i] = BRT[i];
			}
		}
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				for (int b = 0; b != B; ++b) {
					Theta1[b][i][j] = 0;
					for (int k = 0; k != I; ++k) {
						if (k == i || k == j) { continue; }
						Theta1[b][i][j] += (BYsol[b][i][j] + BYsol[b][k][j] - BYsol[b][k][i] - 1) * Htime[b][k][sn];
					}
					Theta1[b][i][j] += ART[i] + (BYsol[b][i][j] - 1) * BM[i][j][sn] + BYsol[b][i][j] * Htime[b][i][sn];
				}
			}
		}
		for (int i = 0; i != I; ++i) {
			for (int j = 0; j != I; ++j) {
				if (i == j) { continue; }
				for (int b = 0; b != B; ++b) {
					Psi[b][i][j] = 0;
					for (int k = 0; k != I; ++k) {
						if (k == i || k == j) { continue; }
						Psi[b][i][j] += (BYsol[b][i][j] + BYsol[b][k][j] - BYsol[b][k][i] - 1) * Htime[b][k][sn];
					}
					Psi[b][i][j] += BYsol[b][i][j] * (br[b][sn] + Htime[b][i][sn]);
				}
			}
		}
		for (int i = 0; i != I; ++i) {
			double thetime = SBT[i]; 
			for (int b = 0; b != B; ++b) {
				for (int j = 0; j != I; ++j) {
					if (i == j) { continue; }
					if (thetime < Theta1[b][j][i]) {
						thetime = Theta1[b][j][i];
					}
					if (thetime < Psi[b][j][i]) {
						thetime = Psi[b][j][i];
					}
				}
			}
			SBT[i] = thetime;
		}
		for (int i = 0; i != I; ++i) {
			DBT[i] = SBT[i] + HBT[i] - ART[i]; 
			LST[i] = 0; 
			if (BZsol[i] * double(60) + DBT[i] - Vtime[i] > 0.0001) {
				LST[i] = BZsol[i] * double(60) + DBT[i] - Vtime[i];
			}
		}
		for (int i = 0; i != I; ++i) {
			Result01 += Tcost[i] * pow(double(LST[i]), double(SLP));
			
			Result02 += Ecost[i][1] * Gpara[i] * DBT[i];
		}
		thedcost[sn] = Result01;
		theecost[sn] = Result02;
		thetdcost += Pro[sn] * Result01;
		thetecost += Pro[sn] * Result02;
	}
	cout << "Fuel cost=" << thefcost << endl;
	cout << "Handling cost=" << thehcost << endl;
	cout << "Delay cost=" << thetdcost << endl;
	cout << "Emission cost=" << thetecost << endl;
	cout << "Total cost=" << thefcost + thehcost + thetdcost + thetecost << endl;
	mycout02 << "Fuel cost=" << endl << thefcost << endl;
	mycout02 << "Handling cost=" << endl << thehcost << endl;
	mycout02 << "Delay cost=" << endl << thetdcost << endl;
	mycout02 << "Emission cost=" << endl << thetecost << endl;
	mycout02 << "Total cost=" << endl << thefcost + thehcost + thetdcost + thetecost << endl;
	Realtest();
}

int main(int argc, char** argv) {
	srand(2);
	srand((int)time(NULL));
	cout << "Fgap=" << Fgap << endl;
	gettimeofday(&t_start, NULL);
	Cplexsetup();
	Solvebap();
	cout << endl << "Full Algorithm" << endl;
	return 0;
}