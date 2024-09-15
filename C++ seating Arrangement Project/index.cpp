#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string s[10] = {"Leo", "Vikram", "King", "Delhi-6", "Guru"};
class Seat{
private:
	string name, movie;
	int seatbooking=1;
	int Ntickets;
	int id;
	long int Tamount;
public:
	int seatnumber;
	int row;
	int mc=1;
	static int a[30][26];
	static int s1[30][26];
	static int s2[30][26];
	Seat(string n,string m,int i)
   {
    	name=n;
    	movie=m;
    	id=i;
	}
	void isavailable()
   {
    	int available = 0;
    	for (int i = 0; i < 5; i++)
    	{
        	if (s[i] == movie){
            	available  = 1;
            	cout << "Available" << endl;
            	cout << "LAYOUT OF SEAT(# represent Already booked seat):" << endl;
            	layout();
        	}
    	}
    	if (available  == 0)
    	{
        	string m;
        	cout << "Sorry! Movie is currently not available" << endl;
        	cout << "If Choose Other Movie enter 1 otherwise enter 0 : ";
        	cin >> mc;
        	if(mc==1){
            	cout << "Enter Movie Name : ";
            	cin >> m;
            	setmovie(m);
            	isavailable();
        	}
        	else if(mc==0)
        	{
            	cout << "Thank You For visit Our Site "<<endl;
        	}
        	else
        	{
                cout<<"Invalid Argument"<<endl;
        	}
    	}
	}
	void layout()
	{
    	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
    	for (int i = 0; i < 30; i++){
        	for (int j = 0; j < 26; j++){
            	if (a[i][j] > 0)
            	{
                	cout << "# ";
            	}
            	else
            	{
                	cout << "_ ";
            	}
        	}
        	cout << endl;
    	}
    	cout<<endl;
    	cout << "For Booking Seat enter 1 or else 0 : ";
    	cin >> seatbooking;
    	if (seatbooking == 0)
    	{
        	cout << "Thank you for visit our Site" << endl;
    	}
    	else if(seatbooking !=1)
   	{
            cout<<"Invalid Argument"<<endl;
    	}
    	else
   	{
        	bookseat();
    	}
	}
	void bookseat()
   {
    	cout << "Enter No of Tickets : ";
    	cin >> Ntickets;
    	for (int i = 0; i < Ntickets; i++){
        	cout<<endl;
        	cout << "Enter Row range of (1-30) First 15 rows are VIP Seats: ";
        	cin >> row;
        	cout << "Enter Seat number(1 to 30): ";
        	cin >> seatnumber;
        	isavailablerow();
    	}
	}
	void bookseat(int temp)
	{
    	int nt1;
    	cout << "Enter No of Tickets : ";
    	cin >> nt1;
    	for (int i = 0; i < nt1; i++)
    	{
        	cout<<endl;
        	cout << "Enter Row range of (1-30) First 15 rows are VIP Seats: ";
        	cin >> row;
        	cout << "Enter Seat number(1 to 30): ";
        	cin >> seatnumber;
        	isavailablerow();
    	}
    	Ntickets=Ntickets+nt1;
	}
	void isavailablerow()
	{
    	int s,r;
    	try{
        	if (a[row][seatnumber] == 0){
                a[row][seatnumber]++;
            	cout << "Seat Available" << endl;
            	isVIP();
        	}
        	else
        	{
            	throw 1;
        	}
    	}
    	catch(int i)
    	{
        	cout << "Sorry! It is already Booked Choose another seat" << endl<<endl;
        	cout << "Enter Seat row : ";
        	cin >> r;
        	cout << "Enter Another Seatnumber : ";
        	cin >> s;
        	setrow(r);
        	setseatnumber(s);
        	isavailablerow();
    	}
	}
 
	int getid(){
    	return id;
	}
	string getname(){
    	return name;
	}
	string getmovie(){
    	return movie;
	}
	int getTamount(){
    	return Tamount;
	}
	int getNtickets(){
    	return Ntickets;
	}
	int getrow(){
    	return row;
	}
	int getmc(){
    	return mc;
	}
	int getseatnumber()
	{
    	return seatnumber;
	}
 
	void setname(string n)
	{
    	name = n;
	}
 
	void setid(int i)
	{
    	id = i;
	}
 
	void setrow(int r)
	{
    	row = r;
	}
 
	void setseatnumber(int s)
	{
    	seatnumber = s;
	}
 
	void setmovie(string m){
    	movie = m;
	}
	void setNtickets(int nt1){
    	Ntickets = nt1;
	}
	void setTamount(int amount) {
    	Tamount=amount;
	}
	int getseatbooking()
	{
    	return seatbooking;
	}
	void setseatbooking (int n){
    	seatbooking =n;
	}
 
	void display()
	{
        cout<<endl<<endl;
    	cout << "Customer ID : " << id << endl;
    	cout << "Customer Name : " << name << endl;
    	cout << "Choosing Movie : " << movie << endl;
    	cout << "Number of Tickets : " << Ntickets << endl;
    	cout << "Seat Level : ";
    	if(row<=15)
    	{
        	cout<<"VIP seat"<<endl;
    	}
    	else
    	{
            cout<<"NORMAL seat"<<endl;
    	}
    	cout << "Booked Tickets : ";
    	int count = 1;
    	for (int i = 0; i < 30; i++)
    	{
        	for (int j = 0; j < 26; j++)
        	{
            	if (a[i][j] == 1 && s1[i][j] != 1)
            	{
                	cout << count++ << "st- " << i << "," << j << " ";
                	s1[i][j] = 1;
            	}
        	}
    	}
    	cout << endl;
    	if(row<=15)
    	{
        	Tamount=Ntickets*400;
    	}
    	else
    	{
        	Tamount=Ntickets*250;
    	}
    	cout << "Total Amount : " << Tamount << endl;
    	writefile();
	}
	void writefile()
	{
    	ofstream outfile;
        outfile.open("customer_details.txt",ios::app); // Open the file in append mode
    	outfile << "Customer ID: " << id << endl;
    	outfile << "Customer Name: " << name << endl;
    	outfile << "Movie: " << movie << endl;
    	outfile << "Number of Tickets: " << Ntickets << endl;
    	outfile << "Seat Level: ";
    	if(row<=15)
    	{
            outfile<<"VIP seat"<<endl;
    	}
    	else
    	{
            outfile<<"NORMAL seat"<<endl;
    	}
    	outfile << "Booked Tickets: ";
    	int count = 1;
 
    	for (int i = 0; i < 30; i++)
    	{
        	for (int j = 0; j < 26; j++)
        	{
            	if (a[i][j] == 1 && s2[i][j] != 1)
            	{
                	outfile << count++ << "st- " << i << "," << j << " ";
                	s2[i][j] = 1;
            	}
        	}
    	}
    	outfile << endl;
 
    	outfile << "Total Amount: " << Tamount << endl;
    	outfile.close();
	}
 
	void isVIP();
	virtual void ticketprice()
	{
    	cout << "Ticket price are informed by selection" << endl;
	}
	void booking()
	{
    	int choice;
    	cout<<endl;
    	cout << "For booking enter 1 update enter 2 else enter 0: ";
    	cin >> choice;
    	if (choice == 0)
    	{
        	cout << "Thank you for visiting our site" << endl;
    	}
    	else if (choice == 1)
    	{
        	cout << "THANK YOU FOR BOOKING ENJOY THE MOVIE" << endl;
    	}
    	else if (choice == 2)
    	{
        	int u;
        	cout << "Updating Options : "<<endl;
        	cout << "1) ID" << endl;
        	cout << "2) Name" << endl;
        	cout << "3) Movie" << endl;
        	cout << "4) Add Ticket"<<endl;
        	cout << "Enter the option number :";
        	cin >> u;
        	if (u == 1)
        	{
            	int id1;
            	cout << "Enter ID : ";
            	cin >> id1;
            	setid(id1);
        	}
        	else if (u == 2)
        	{
            	string name1;
            	cout << "Enter Name : ";
            	cin >> name1;
            	setname(name1);
        	}
        	else if (u == 3){
            	string movie1;
            	cout << "Enter Movie : ";
            	cin >> movie1;
            	setmovie(movie1);
        	}
        	else if(u==4){
            	bookseat(1);
        	}
        	else
        	{
                cout<<"Invalid argument"<<endl;
        	}
    	}
	}
	void payment()
	{
    	cout<<"Payment according to the seat selection"<<endl;
	}
};
int Seat::s1[30][26]={0};
int Seat::s2[30][26]={0};
int Seat::a[30][26] = {0};
 
class VIPseat : public Seat
{
public:
	int VIPchoice;
	VIPseat() : Seat("", "", 0){ }
	static void islevel(){
    	cout << "Complementary Drinks are provided" << endl;
	}
	void ticketprice(){
    	cout <<endl<<"Ticket Price per Seat - Rs.400" << endl;
    	cout<<"Pay Rs.100 Extra for snacks"<<endl;
    	cout<<"For snack enter 1 else enter 0 : ";
    	cin>>VIPchoice;
	}
	void payment(){
     	if(VIPchoice==1){
        	cout<<"Snack Payment : "<<"100"<<endl;
        	cout << "--------------------------------------" << endl;
        	ofstream outfile;
            outfile.open("customer_details.txt",ios::app);
            outfile<<"Snack Payment : "<<"100"<<endl;
        	outfile << "--------------------------------------" << endl;
    	}
	}
};
class NORMALseat : public Seat{
public:
	int NORMALchoice;
	NORMALseat() : Seat("", "", 0){}
	static void islevel(){
    	cout << "Seat Comfort Good No complementary drinks are provided" << endl;
	}
	void ticketprice(){
    	cout <<endl<<"Ticket Price per Seat - Rs.250" << endl;
    	cout<<"Pay Rs.200 Extra for snacks"<<endl;
    	cout<<"For snack enter 1 else enter 0 : ";
    	cin>>NORMALchoice;
	}
	void payment(){
    	if(NORMALchoice==1){
        	cout<<"Snack Payment : "<<"200"<<endl;
        	cout << "--------------------------------------" << endl;
        	ofstream outfile;
            outfile.open("customer_details.txt",ios::app);
            outfile<<"Snack Payment : "<<"200"<<endl;
        	outfile << "--------------------------------------" << endl;
    	}
	}
};
void Seat::isVIP(){
	if (row <= 15){
    	cout << "You select VIP seat" << endl;
    	VIPseat::islevel();
	}
	else{
    	cout << "You select NORMAL seat" << endl;
    	NORMALseat::islevel();
	}
}
int main(){
	cout << "Welcome to Our Cinematic Universe" << endl;
	cout << "Available Movies:" << endl;
	cout << "1) Guru" << endl;
	cout << "2) Delhi-6" << endl;
	cout << "3) King" << endl;
	cout << "4) Vikram" << endl;
	cout << "5) Leo" << endl;
	cout<<endl;
	int numCustomers;
	cout << "Enter the number of customers: ";
	cin >> numCustomers;
	cout<<endl;
	for (int i = 0; i < numCustomers; ++i){
    	string name, movie;
    	int id;
    	cout << "Enter Your Id : ";
    	cin >> id;
    	cout << "Enter Your Name: ";
    	cin>>name;
    	cout << "Enter Movie name: ";
    	cin>>movie;
    	Seat s(name, movie, id);
    	s.isavailable();
    	int moviechoice = s.getmc();
    	int seatbook = s.getseatbooking();
    	int r = s.getrow();
    	if (r <= 15 && moviechoice!=0 && seatbook!=0){
        	VIPseat ob;
        	ob.ticketprice();
        	s.booking();
        	s.display();
        	ob.payment();
    	}
    	else if(moviechoice!=0 && seatbook!=0){
        	NORMALseat ob;
        	ob.ticketprice();
        	s.booking();
        	s.display();
        	ob.payment();
    	}
    	cout << endl<< endl;
	}
	return 0;
}
