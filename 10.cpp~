#include<iostream>
using namespace std;

class RRB;
class SRTF;

#include<iostream>
using namespace std;
class SRTF;
class RRB;

class Process { //Class to represent a process as an object.

	int at ,bt ,rt; //Arrival Time, Burst Time and Remaining Time
	public:
		Process() { } //Default Constructor
		void set(int a,int b) { //Function to set values of at,bt and rt for individual processess.
			at=a;
			bt=rt=b;
		}
	friend class SRTF;
	friend class RRB;
};

Process p[10],p2[10];int np=0; //An array of processes, such that each "Process" 'object' will have its set of at,bt and rt. and the number of processes "np"

class RRB {

	public:
		double awt=0.0 ,atat=0.0; //Avg waiting time and Avg. turn around time.
		int wt,tat,tq; //Waiting time,turn around time and quantum.

		RRB(){ /*This is the constructor for this class. Everytime we make an object of this class eg. RRB obj . This will be used to initizlize
			its member variables */
	
		//We already have Process p[10] and np outside so we dont need it again.
	
		//Since this is RRB we need quanta. Lets get it.
		cout<<"Enter the quantum \n";
		cin>>tq;

		}

		void compute(){
			int finish=0, i=0,time=0;
			//  i will denote the current process
			while(finish<np){
		
			
				if(p[i].rt > 0){
			
					if(p[i].rt>tq){
						time+=tq;
						p[i].rt-=tq;
					}
					else {
						time+=p[i].rt;
						p[i].rt=0;
			
						wt=time-p[i].at-p[i].bt;
						tat= time-p[i].at;
			
						cout<<"\np["<<i<<"]\t"<<wt<<"\t"<<tat<<endl;
						awt+=wt;
						atat+=tat;
						finish++;
					}
				}
			
				// If we have Process 0,1,2,3 then we need to use them in order they are available if they have arrived
				if( i == (np-1) )  //If we reach last process ie 3 ; go back to process 0 
					i = 0;
				else
					for(int next_proc = i + 1 ;next_proc<np;next_proc++){  //Otherwise choose next process that has arrived
						if( p[next_proc].at<=time && p[next_proc].rt > 0 ){
							i=next_proc;
							break;
						}
					}
			}
		cout<<"\nAWT="<<awt/np<<endl;
		cout<<"\nATAT="<<atat/np<<endl;
		}
		
};

class SRTF {

	public:
		double awt=0.0 ,atat=0.0; //Avg waiting time and Avg. turn around time.
		int wt,tat,tq; //Waiting time,turn around time and quantum.

		SRTF(){}
		void compute(){
			int wt,tat,min,time,t,finish=0;
			p2[9].rt=9999;//Set RT of process 9 (not in range) to 9999 such that all other remaining time would always be lesser
			for(t=0;finish<np;t++){
				min=9; //Set min to 9 again since if some RT becomes 0 , itll be minimum and loop will get stuck 
					// So we always begin comparison with p[9]=9999 since eveything will be smaller than that
					
				for(int i=0;i<np;i++)
					if(p2[i].at <= t && p2[i].rt<p2[min].rt && p2[i].rt > 0 ) // If process has arrived, has lesser burst time and has not finished yet; we will use that process next;
						min=i;
				//Whichever is min from previous logic is now used for one unit time.
				p2[min].rt--;
				
				//If it is finished; print the result.
				if(p2[min].rt==0){
					time=t+1;		
					wt=time-p2[min].at-p2[min].bt;
					tat= time-p2[min].at;
					cout<<"\np2["<<min<<"]\t"<<wt<<"\t"<<tat<<endl;
					awt+=wt;
					atat+=tat;
					finish++;
				}
			}
		cout<<"\nAWT="<<awt/np<<endl;
		cout<<"\nATAT="<<atat/np<<endl;
		}
			
};
int main(){
	
	cout<<"Enter the number of processes : ";
	cin>>np;

	int at,bt;
	for(int i=0;i<np;i++){
		cout<<"\nEnter the arrival time and burst time for Process "<<i<<endl;
		cin>>at;
		cin>>bt;
		p[i].set(at,bt);
		p2[i].set(at,bt);
	}
	
	RRB r;
	cout<<"\n\n----------RRB----------\n\n";
	cout<<"Process\tWT\tTAT\n";
	r.compute();
	
	SRTF s;
	cout<<"\n\n----------SRTF----------\n\n";
	cout<<"Process\tWT\tTAT\n";
	s.compute();

		
	return -1;
}
					
/* DEMO output 

Enter the number of processes : 4

Enter the arrival time and burst time for Process 0
0 2

Enter the arrival time and burst time for Process 1
1 4

Enter the arrival time and burst time for Process 2
2 5

Enter the arrival time and burst time for Process 3
3 6
Enter the quantum 
2


----------RRB----------

Process	WT	TAT

p[0]	0	2

p[1]	5	9

p[2]	8	13

p[3]	8	14

AWT=5.25

ATAT=9.5


----------SRTF----------

Process	WT	TAT

p2[0]	0	2

p2[1]	1	5

p2[2]	4	9

p2[3]	8	14

AWT=3.25

ATAT=7.5
*/
