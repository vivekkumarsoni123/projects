#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class shopping {
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
	    void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();	
};

void shopping :: menu() {
	m:
	int choice;
	string email;
	string password; 
	
	cout<<"\t\t\t\t\t\t\t\t\t_______________________________"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t                               "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t  SUPERMARKET MAIN MENU        "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t                               "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t_______________________________"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t "<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t| 1.) Administrator            |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|                              |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t| 2.) Buyer                    |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t|                              |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t| 3.) Exit                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t\t\t| \n";
	cout<<"\t\t\t\t\t\t\t\t\t Please Select:     "<<endl;
	cin>>choice;
	switch(choice)
		{
			case 1:
				cout<<"\t\t\t Please Login \n";
				cout<<"\t\t\t Enter Email \n";
				cin>>email;
				cout<<"\t\t\t Enter Password \n";
				cin>>password;
				if(email == "v" && password == "s") {
					administrator();
				}
				else cout<<"Invalid email/password \n";
				break;
				
			case 2:
			   buyer();
			   
			case 3:
	    		exit(0);  
			default:
			    cout<<"Plese select from the given option\n";	 	
		}
	goto m;	 	
}

void shopping:: administrator() {
	m:
	int choice;
	cout<<"\n\n\t\t\t Administrator menu\n";
	cout<<"\t\t\t |______1) Add the product_____|\n";
	cout<<"\t\t\t |                             |\n";
	cout<<"\t\t\t |______2) Modify the product__|\n";
	cout<<"\t\t\t |                             |\n";
	cout<<"\t\t\t |______3) Delete the product__|\n";
	cout<<"\t\t\t |                             |\n";
	cout<<"\t\t\t |______4) Back to main menu___|\n";
	
	cout<<"\n\n\t Please enter your choice\n";
	cin>>choice;
	
	switch(choice) {
		case 1:
			add();
			break;
		case 2:
		    edit();
		    break;
		case 3:
		    rem();
			break;
		case 4:
		    menu();
			break;	
		default:
		   cout<<"Invalid choice\n";			
	}
	goto m;
}

void shopping:: buyer() {
	
	m:
	cout<<"\t\t\t Buyer________________\t\t\t\t\n";
	cout<<"\t\t\t\n";
	cout<<"\t\t\t |______1) Buy the product___|\n";
	cout<<"\n";
	cout<<"\t\t\t |______2) Go Back___|\n";
	int choice;
	cin>>choice;
	
	switch(choice) {
		case 1:
			receipt();
			break;
		case 2:
		    menu();	
		default:
		   cout<<"Invalid choice\n";			
	}
	
	goto m;
}

void shopping ::add() {
	m:
	fstream data;
	int c, token = 0;
	float p, d;
	string n;
	
	cout<<"\n\t\t\t__Add new Product__\n\n\n";
	cout<<"\n\t\t__Enter Product code of Product__";
	cin>>pcode;
	cout<<"\n\t\t__Enter Name of Product__";
	cin>>pname;
	cout<<"\n\t\t__Enter Price of Product__";
	cin>>price;
	cout<<"\n\t\t__Enter discount on Product__";
	cin>>dis;
	data.open("database.txt", ios::in);
	
	if(!data) {
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
		
	}
	
	else {
		data>>c>>n>>p>>d;
		
		while(!data.eof()) {
			
			if(c == pcode) {
				token++;
			}
			
			data>>c>>n>>p>>d;
		}
		data.close();
		
		if(token == 1) {
			goto m;
		}
		else {
			data.open("database.txt",ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
			
			
		}
	}
	
	
	cout<<"\n\n\t\t\t___Record inserted__\n";
	
}

void shopping ::edit()  {
	
	fstream data, data1;
	int c, token = 0, pkey;
	float p, d;
	string n;
	
	cout<<"\n\t\t Enter the product key\n";
	cin>>pkey;

	data.open("database.txt",ios::in);
	
	if(!data) {
		cout<<"File not found\n";
	}
	else {
		data1.open("database1.txt",ios::app|ios::out);
		
		data>>pcode>>pname>>price>>dis;
		
			
		while(!data.eof()) {
			if(pkey == pcode) {
				cout<<"\t\t\t___Edit the product__\n\n";
				cout<<"\n\t\t__Enter new Product code of Product__";
				cin>>c;
				cout<<"\n\t\t__Enter new Name of Product__";
				cin>>n;
				cout<<"\n\t\t__Enter Price of Product__";
				cin>>p;
				cout<<"\n\t\t__Enter discount on Product__";
				cin>>d;
				token++;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t\t\t Record Edited \n";
			}
			else {
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0) {
			cout<<"\n\n\t\t Product code not found, Sorry! \n\n";
		}
	
	}
	
}


void shopping ::rem() {
	
	fstream data, data1;
	int token = 0, pkey;
	
	cout<<"\n\t\t\t__Delete the product__\n";
	cout<<"\n\t\t Enter the product key\n";
	cin>>pkey;
	
	data.open("database.txt", ios::in);
	
	if(!data) {
		cout<<"\n\t\t\tFile doesn't exist\n";
	}
	else {
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()) {
			if(pkey == pcode) {
				cout<<"\n\t\t Product has been deleted \n";
				token++;
			}
			else {
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt", "database.txt");
		
		if(token == 0) {
			cout<<"\n\n\t\t\t Product not found \n";
		}
	}
}


void shopping ::list() {
	fstream data;
	cout<<"\n\n___________________________________________________\n";
	cout<<"ProNo\t\t ProName\t ProPrice \n";
	cout<<"___________________________________________________\n";
	data.open("database.txt",ios::in);
	
	if(!data) {
		cout<<"\n\t\t File is Empty\n";
	}
	else {
		data>>pcode>>pname>>price>>dis;
		
		while(!data.eof()) {
			cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
			data>>pcode>>pname>>price>>dis;
		}
	}
	data.close();
}



void shopping ::receipt() {

	fstream data;
	int arrc[100];
	int arrq[100];
	float amount = 0, total = 0;
	char choice;
	int c = 0;
	
	data.open("database.txt",ios::in);
	if(!data) {
		cout<<"\n\n\t\t\t__Data is empty__\n";
	}
	else {
		data.close();
		
		list();
		cout<<"\n\n\t\t__________________________________________\n\n";
		cout<<"\t\t             Place an order ";
		cout<<"\n\n\t\t__________________________________________\n"; 
		
		do {
			m:
			cout<<"\n\t\t Enter thr product code: \n";
			cin>>arrc[c];
			cout<<"\n\t\t Enter thr product quantity: \n";
			cin>>arrq[c];
			for(int i = 0; i < c; i++) {
				if(arrc[i] == arrc[c]) {
					cout<<"\n\t\t Duplicate code, Please try another one \n";
					c--;
					goto m;
				}
			}
			c++;
			cout<<"\t\t if you want to buy another product then please type 'y' else 'n'\n";
			cin>>choice;
		}
		while(choice == 'y');
		
		cout<<"\n\t\t_______RECEIPT________\n";
		cout<<"\n\n\n";
		cout<<"\tProcode\t\t ProName\t\t ProQuan\t Price\t\t Amount\t\t At_after_dis \t\t\n";
		
		
		for(int i = 0; i < c; i++) {
			data.open("database.txt",ios::in);
			
			data>>pcode>>pname>>price>>dis;
		    while(!data.eof()) {
				if(arrc[i] == pcode) {
					amount = price*arrq[i];
					dis = amount*dis/100;
					total += amount - dis;
					cout<<"\t"<<pcode<<"\t\t"<<pname<<"t\t\t\t"<<arrq[i]<<"\t\t\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<amount-dis<<"\n";
				}
					
				data>>pcode>>pname>>price>>dis;
				
			}
			data.close();
		}
		
		cout<<"\n\n\n\t\t__________________________________________\n";
		cout<<"Total Amount = "<<total;
		
	}
	
}

int main() {
	
	shopping user;
	user.menu();
}
