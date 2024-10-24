#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

class youtube {
	public:
	string c_name,o_name;
	int s_count=10000 , plistcount=3;
	map<string,vector<string> > mp;
	public :

		//youtube display() 
			vector<string > v1,v2,v3;
			v1.push_back("oops"); 
			mp["cpp"] = v1;
			v2.push_back("GUI");
			mp["python"] = v2;
			v3.push_back("script");
			mp["java"] = v3;
			

		void display_p_list() {
			for(int i=0;i<plistcount;i++) {
				cout<<mp.first;
			}
		}
		void p_list(string nam) {
			vector<string> v;
			mp[nam] = v;
		}
		void add_plist() {
			
		}

};



int main() {
	youtube vivek;
	vivek.c_name = "VCODER";
	vivek.o_name = " VKS";
	
	cout<<"Channel Name :" << vivek.c_name<<"   "<<" Owner Name :"<<vivek.o_name<<endl;
    cout<<"\n\n";
    while(true) {

	        int choice;
			cout<<"/t/t/t/t| 1) SUBSCRIBE    		|\n";
			cout<<"/t/t/t/t|                 		|\n";
			cout<<"/t/t/t/t| 2) UNSUBSCRIBE  		|\n";
			cout<<"/t/t/t/t|                 		|\n";
			cout<<"/t/t/t/t| 3) ADD PLAYLIST 		|\n";
			cout<<"/t/t/t/t|                 		|\n";
			cout<<"/t/t/t/t| 4) TOTAL SUBSCRIBER 	|\n";
			cout<<"/t/t/t/t|                	 	|\n";
			cout<<"/t/t/t/t| 5) See all playlist    |\n";
			cout<<"/t/t/t/t|                        |\n";
			cout<<"/t/t/t/t| 6) Add Videos          |\n";
			
			cout<<"Please enter your choice\n";
			cin>> choice;
			if(choice == 1) {
				vivek.s_count++;
				cout<<"Total Subscriber is "<<vivek.s_count<<endl;
			}
			else if(choice == 2) {
				vivek.s_count--;
				cout<<"Total Subscriber is "<<vivek.s_count<<endl;
			}
			else if(choice == 3) {
				cout<<"Enter Playlist name\n";
				string k; cin>>k;
				a_plist(k);
			}
			else if(choice == 4) {
				cout<<"Total subscriber is "<<vivek.s_count<<endl;
			}
			else if(choice == 5) {
				vivek.p_list();
			}
			else if(choice == 6) {
				vivek.p_list();
			}
			else { 
			   cout<<"Please enter valid option\n";
			   break;
		    }
		}
	
	
	
	

	
}

