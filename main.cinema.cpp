#include <iostream>
#include <string>
#include <iomanip>
#include <istream>
#include <windows.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include"functions12.h"

using namespace std;

float snackPrice;
int packno;


double x, y, distance1, distance2;
double Qlat=26.565191, Qlon=49.996376;
double Dlat=26.399250, Dlon=49.984360;
double Klat=26.236355, Klon=50.032600;
double Jlat=27.0112, Jlon=49.6583;
double Clat1=26.567202, Clon1=49.997312, Clat2=27.2375, Clon2=50.1102835;
  
int numberOfItems=4;
string snacks[4]={"1.Single combo(32.SR): 1 small salt or caramel popcorn + 1 small drink + 1 small nachos",
						"2.Twin combo(92.SR): 1 large caramel popcorn + 1 large nachos + 1 buffalo fries + 2 small drinks",
						"3.Junior meal box(30.SR): 1 mini popcorn + 4 chicken nuggets pcs + 1 smll juice + small gift",
						"4.Family combo(110.SR): 2 large salt & caramel popcorn + 4 small drinks + 2 large nachos+ 1 buffalo fries"};


void displaySnacks()
{	
	string pack2="\n\n\t 1) Single combo(32.SR): 1 small salt or caramel popcorn + 1 small drink + 1 small nachos";
	
	string pack3="\n\n\t 2) Twin combo(92.SR): 1 large caramel popcorn + 1 large nachos + 1 buffalo fries + 2 small drinks";
	
	string pack4="\n\n\t 3) Junior meal box(30.SR): 1 mini popcorn + 4 chicken nuggets pcs + 1 smll juice + small gift";
	
	string pack5="\n\n\t 4) Family combo(110.SR): 2 large salt & caramel popcorn + 4 small drinks + 2 large nachos+ 1 buffalo fries\n";
	
	cout<<pack2<<pack3<<pack4<<pack5<<endl<<"\n\t--->";
	cin>>packno;
}


 
void print_array(string snacks[], int numberOfItems, int i)
{
     if (i == numberOfItems) 
	{
        cout << endl;
        return;
    }
 
    cout <<"\n\t"<< snacks[i] << "\n\n\t";
    i++;
 
    print_array(snacks, numberOfItems, i);
}


float calcPrice(int packno)
{
	if (packno==1)
	{
		return snackPrice=32;
	}
	else if (packno==2)
	{
		return snackPrice=92;
	}
	else if (packno==3)
	{
		return snackPrice=30;
	}
	else if (packno==4)
	{
		return snackPrice=110;
	}
	else
	{
		return snackPrice=10;
	}
}

void deleteSnack()
{
	print_array(snacks,numberOfItems,0);
	
	if (numberOfItems>=0)
				{
					string newSnack, Snackname;
					
					cin.ignore();					
					cout<<"\n\t Enter the full Snack package to delete :\n";
					getline(cin,Snackname);
										
					for (int i=0;i<=numberOfItems;i++)
					
						if (snacks[i]==Snackname)
						{
							for (int j=i; j< numberOfItems-1; j++)
							{
							snacks[j]=snacks[j+1];
							}
						cout<<"\n\t\t\t SnackPackage DELETED\n";

						numberOfItems--;
						}
					}

}


namespace admin
{

void Menu()
{
    string choice;
    system("cls");
    cout << "\n\tWelcome to the Admin Side";
    cout << "\n\t1. Customer List";
    cout << "\n\t2. Movie List";
    cout << "\n\t3. Ticket List";
    cout << "\n\t4. Snack List";
    cout << "\n\t5. Logout";
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                modMovies();
                break;
            }
            else if (choice == "3")
            {
                displayTicketList();
                system("pause");
                admin::Menu();
                break;
            }
            else if (choice == "4")
            {
            	SnackList();
                break;
			}
            else if (choice == "5")
            {
                loginPage();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number:";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}
}

namespace customer
{
	
void Menu()
{
    string choice;
    system("cls");

    cout<< "\t\t\t\t\t\t\t"
        << "User: " << currentSession << endl;

    cout<< "\n\tWelcome to the Customer Side";
    cout<< "\n\t1. Book a Movie";
    cout<< "\n\t2. Show Movies List and Snacks";
    cout<< "\n\t3. Display My Reservation";
    cout<< "\n\t4. Show The Neartest Movie Theater";
    cout<< "\n\t5. Update my account information";
    cout<< "\n\t6. Logout";
    while (true)
    {
        cout<< "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                displayMovies();
                bookMovie();
                system("pause");
                customer::Menu();
                break;
            }
            else if (choice == "2")
            {
                displayMovies();
                print_array(snacks,numberOfItems,0);
                system("pause");
                customer::Menu();
                break;
            }
            else if (choice == "3")
            {
               displayTicket();
            	system("pause");
                customer::Menu();
                break;
            }
            else if (choice == "4")
            {
            	nearestCinema();
            	system("pause");
                customer::Menu();
            	break;
			}
			else if (choice == "5")
            {
            	updateInfo();
            	break;
			}
            else if (choice == "6")
            {
                loginPage();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}
}

void SnackList()
{
	system("cls");
    string choice;
    cout << "\n\tWELCOME to Snack list";
    cout << "\n\t1. Delete Snack";
    cout << "\n\t2. Show Snacks";
    cout << "\n\t3. Back";
    cout << "\n\t4. Exit";
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
    
            if (choice == "1")
            {
                system("cls");
                deleteSnack();
                system("pause");
                SnackList();
                break;
            }
            else if (choice == "2")
            {
                print_array(snacks,numberOfItems,0);
                system("pause");
                SnackList();
                break;
            }
            else if (choice == "3")
            {
                admin::Menu();
                break;
            }
            else if (choice == "4")
            {
                exit(0);
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number: ";
            continue;
        }
    }
}

void displayTicketList()
{
    
	cout<<"\n\t";
	for (int i = 0; i <= 145; i++)
    {
        cout << "-";
    }
    cout << "\n\t|" << left << setw(3) << "No"
         << "|"
         << setw(25) << "Customer Name"
         << "|"
         << setw(5) << "Age"
         << "|"
         << setw(25) << "Movie Name"
         << "|"
         << setw(15) << "Time and Cinema"
         << "|"
         << setw(10) << "Tickets Purchased"
         << "|"
         << setw(30) << "Seat No"
         << "|"
         << setw(12) << "Total Cost"
         << endl;
    for (int i = 0; i < bookedTickets; i++)
    {
        cout << "\n\t|" << setw(3) << left << i + 1;
        cout << "|" << setw(25) << tickets[i].cust_name;
        cout << "|" << setw(5) << tickets[i].age;
        cout << "|" << setw(25) << tickets[i].mov_name;
        cout << "|" << setw(10) << tickets[i].timeandcinema;
        cout << "|" << setw(10) << tickets[i].ticketCount;
        for (int k = 0; k < tickets[i].ticketCount; k++)
        {
            cout << "|" << setw(10) << tickets[i].seat_no[k];
        }
        cout << setw(12) << tickets[i].totalCost;
        cout << "\n";
    }
    cout<<"\n\t";
    for (int i = 0; i <= 145; i++)
    {
        cout << "-";
    }
    cout << "\n";
}

void displayMovies()
{
	sortMovi();
    cout<<"\n\t";
	for (int i = 0; i <= 135; i++)
    {
        cout << "-";
    }
    cout << "\n\t|" << left << setw(3) << "No"
         << setw(25) << "Name"
         << setw(11) << "|Genre"
         << setw(21) << "|Director"
         << setw(8) << "|Rate"
         << setw(8) << "|Price"
         << setw(36) << "|       Time and Cinema"
         << setw(2) << " " << setw(12) << "|Available Seats    |\n";
    for (int i = 0; i < movieCount; i++)
    {
        cout << "\n\t|" << setw(3) << left << i + 1
             << setw(25) << movies[i].name << "|"
             << setw(10) << movies[i].genre << "|"
             << setw(20) << movies[i].director << "|"
             << setw(7) << movies[i].rating << "|"
             << setw(7) << movies[i].price << "|"
             << setw(10) << movies[i].time_cinema[0] << " | "
             << setw(10) << movies[i].time_cinema[1] << " | "
             << setw(10) << movies[i].time_cinema[2] << " | "
             << setw(2) << " " << setw(15) << movies[i].seats << " | \n";
    }
    
    cout<<"\n\t";
    for (int i = 0; i <= 135; i++)
    {
        cout << "-";
    }
    cout << "\n";
    
}

void printMovieDetails(const Movie &movie) {
	cout << "\n\tMovie Name: "        << movie.name;
	cout << "\n\tMovie Genre: "       << movie.genre;
	cout << "\n\tMovie Director: "    << movie.director;
    cout << "\n\tMovie Rating: "      << movie.rating;
    cout << "\n\tMovie Price: "       << movie.price;
    cout << "\n\tMovie time cenima: " << movie.time_cinema[0];
    cout << "\n\tMovie time cenima: " << movie.time_cinema[1];
    cout << "\n\tMovie time cenima: " << movie.time_cinema[2];
    cout << "\n\tMovie seats: "       << movie.seats;       
} 
                                                          	    
void sortMovi()
{
	for (int i=0; i<movieCount; i++)
	{
		for (int j=0; j<movieCount-1; j++)
		{
			if (movies[j].rating < movies[j+1].rating)
			{
				float swap1 = movies[j].rating;
				movies[j].rating = movies[j+1].rating;
				movies[j+1].rating = swap1;
				
				string swap2 = movies[j].name;
				movies[j].name = movies[j+1].name;
				movies[j+1].name = swap2;
				
				string swap3 = movies[j].genre;
				movies[j].genre = movies[j+1].genre;
				movies[j+1].genre = swap3;
				
				string swap4 = movies[j].director;
				movies[j].director = movies[j+1].director;
				movies[j+1].director = swap4;
				
				float swap5 = movies[j].price;
				movies[j].price = movies[j+1].price;
				movies[j+1].price = swap5;
				
				string swap6 = movies[j].time_cinema[0];
				movies[j].time_cinema[0] = movies[j+1].time_cinema[0];
				movies[j+1].time_cinema[0] = swap6;
				
				string swap7 = movies[j].time_cinema[1];
				movies[j].time_cinema[1] = movies[j+1].time_cinema[1];
				movies[j+1].time_cinema[1] = swap7;
				
				string swap8 = movies[j].time_cinema[2];
				movies[j].time_cinema[2] = movies[j+1].time_cinema[2];
				movies[j+1].time_cinema[2] = swap8;
			}
		}
	}
}


void inputTicket(Ticket tickets[], int i)
{
    int mov, tcount, time, seatID[tcount];


    n_tickets[i].cust_name = customers[loginIndex].name;
    cout << "\n\tSelect a Movie: ";
    cin >> mov;
    mov--;

    n_tickets[i].mov_name = movies[mov].name;
    cout
        << setw(39) << "\tTime and Cinema"
        << "\n\t1. " << setw(8) << movies[mov].time_cinema[0] << " | "
        << "2. " << setw(8) << movies[mov].time_cinema[1] << " | "
        << "3. " << setw(8) << movies[mov].time_cinema[2];
    cout << "\n\tChoose a time to Watch: ";
    cin >> time;
    time--;

    n_tickets[i].timeandcinema = movies[mov].time_cinema[time];
    cout << "\n\tHow many Tickets would you like to purchase: ";
    cin >> tcount;

    n_tickets[i].ticketCount = tcount;
    n_tickets[i].age = customers[loginIndex].age;
    n_tickets[i].totalCost = movies[mov].price * tcount;


    for (int l = 0; l < tcount; l++)
    {
        cout << "\n\tChoose a seat number: ";
        cin >> seatID[l];
        movies[mov].seats--;
    }

    for (int k = 0; (k < n_tickets[i].ticketCount); k++)
    {
        n_tickets[i].seat_no[k] = seatID[k];
    }
}


void bookMovie()
{
    cout << "\n\tStarting Booking ...";
    int y = 1;

    bookedTickets += y;
    delete[] n_tickets;
    n_tickets = new Ticket[bookedTickets];
    for (int i = 0; (i < bookedTickets - y); i++)
    {
        n_tickets[i].cust_name = tickets[i].cust_name;
        n_tickets[i].mov_name = tickets[i].mov_name;
        n_tickets[i].timeandcinema = tickets[i].timeandcinema;
        n_tickets[i].ticketCount = tickets[i].ticketCount;
        n_tickets[i].age = tickets[i].age;
        n_tickets[i].totalCost = tickets[i].totalCost;
        for (int k = 0; k < tickets[i].ticketCount; k++)
        {
            n_tickets[i].seat_no[k] = tickets[i].seat_no[k];
        }
    }

    cout << "\n\tAdding New Reservation at: " << bookedTickets - y << endl;

    for (int i = 0; i < y; i++)
    {
        inputTicket(n_tickets, bookedTickets - y + i);
    }

    delete[] tickets;
    tickets = new Ticket[bookedTickets];

    for (int i = 0; i < bookedTickets; i++)
    {
        tickets[i].cust_name = n_tickets[i].cust_name;
        tickets[i].mov_name = n_tickets[i].mov_name;
        tickets[i].timeandcinema = n_tickets[i].timeandcinema;
        tickets[i].ticketCount = n_tickets[i].ticketCount;
        tickets[i].age = n_tickets[i].age;
        tickets[i].totalCost = n_tickets[i].totalCost;
        for (int k = 0; (k < n_tickets[i].ticketCount); k++)
        {
            tickets[i].seat_no[k] = n_tickets[i].seat_no[k];
        }
    }
    
    char chSnack;
    cout<<"\n\tWould you like to choose a snack(Y or N)? ";
    cin>>chSnack;
    
    if (chSnack=='Y')
    {
    	displaySnacks();

    	cout << "\n\tTicket added successfully\n";
    	for (int z = 0; z < (bookedTickets); z++)
    {
        cout << "\n\t" <<tickets[z].cust_name;
        cout << "\n\t" <<tickets[z].mov_name;
        cout << "\n\t" <<tickets[z].timeandcinema;
        cout << "\n\t" <<tickets[z].ticketCount<<" Ticket/s";
        cout << "\n\t" <<tickets[z].age<< " years old";
        cout << "\n\t" <<tickets[z].totalCost+calcPrice(packno)<< " SR";
        for (int k = 0; k < tickets[z].ticketCount; k++)
        {
            cout << "\n\t" <<tickets[z].seat_no[k] << " Seat Number ";
        }
        cout << endl;
    }
	}
	else if (chSnack=='N')
	{
	cout << "\n\tTicket added successfully";
    for (int z = 0; z < (bookedTickets); z++)
    {
        cout << "\n\t" <<tickets[z].cust_name;
        cout << "\n\t" <<tickets[z].mov_name;
        cout << "\n\t" <<tickets[z].timeandcinema;
        cout << "\n\t" <<tickets[z].ticketCount<<" Ticket/s";
        cout << "\n\t" <<tickets[z].age<< " years old";
        cout << "\n\t" <<tickets[z].totalCost+calcPrice(packno)<< " SR";
        for (int k = 0; k < tickets[z].ticketCount; k++)
        {
            cout << "\n\t" <<tickets[z].seat_no[k] << " Seat Number ";
        }
        cout << endl;
    }
	}
    system("pause");
    customer::Menu();
}

void displayTicket()
{
    for (int i = 0; i < bookedTickets; i++)
    {
        if (customers[loginIndex].name == tickets[i].cust_name)
        {
            cout << "\n\t" <<tickets[i].cust_name;
            cout << "\n\t" <<tickets[i].mov_name;
            cout << "\n\t" <<tickets[i].timeandcinema;
            cout << "\n\t" <<tickets[i].ticketCount <<" Ticket/s";
            cout << "\n\t" <<tickets[i].age << " years old";
            cout << "\n\t" <<tickets[i].totalCost+calcPrice(packno)<< " SR";
            for (int k = 0; k < tickets[i].ticketCount; k++)
            {
                cout << "\n\t" << tickets[i].seat_no[k] << " Seat Number ";
            }
            cout << endl;
        }
        else
        {
            continue;
        }
    }

    system("pause");
    customer::Menu();
}

void makeSeats(int seats[])
{
    for (int i = 1; i < 101; i++)
    {
        seats[i] = i;
    }
}

void inputMovie(Movie movies[], int i = 0)
{
    cout << "\n\tEnter Movie Information";
    cout << "\n\t-----------------------";
    cout << "\n\tEnter Movie Name: ";
    getline(cin >> ws, movies[i].name);
	
	cout << "\n\tEnter Movie Genre: ";
    getline(cin >> ws, movies[i].genre);

    cout << "\n\tEnter Director: ";
    getline(cin >> ws, movies[i].director);

    cout << "\n\tEnter Movie Rating: ";
    cin >> movies[i].rating;

    cout << "\n\tEnter Price: ";
    cin >> movies[i].price;

    cout << "\n\tEnter Available Seats: ";
    cin >> movies[i].seats;

    for (int k = 0; k < 3; k++)
    {
        cout << "\n\tEnter Time and Cinema " << k + 1 << " : ";
        getline(cin >> ws, movies[i].time_cinema[k]);
    }
}

void addMovie()
{
    cout << "\n\tHow many Movies you want to add: ";
    int j;
    cin >> j;

    movieCount += j;
    delete[] n_movies;
    n_movies = new Movie[movieCount];
    for (int i = 0; i < (movieCount - j); i++)
    {
        n_movies[i].name = movies[i].name;
        n_movies[i].genre = movies[i].genre;
        n_movies[i].director = movies[i].director;
        n_movies[i].rating = movies[i].rating;
        n_movies[i].price = movies[i].price;
        n_movies[i].seats = movies[i].seats;
        for (int k = 0; k < 3; k++)
        {
            n_movies[i].time_cinema[k] = movies[i].time_cinema[k];
        }
    }

    for (int x = 0; x < j; x++)
    {
        inputMovie(n_movies, movieCount - j + x);
    }

    delete[] movies;
    movies = new Movie[movieCount];

    for (int i = 0; i < movieCount; i++)
    {
        movies[i].name = n_movies[i].name;
        movies[i].genre = n_movies[i].genre;
        movies[i].director = n_movies[i].director;
        movies[i].rating = n_movies[i].rating;
        movies[i].price = n_movies[i].price;
        movies[i].seats = n_movies[i].seats;
        for (int k = 0; k < 3; k++)
        {
            movies[i].time_cinema[k] = n_movies[i].time_cinema[k];
        }
    }
}

void deleteMovie()
{
    displayMovies();
    int m, temp, n = 0;
    cout<< "\n\tWhich Movie would you like to delete: ";
    cin>>m;
    m--;
    temp = movieCount;
    movieCount--;
    delete[] n_movies;
    n_movies = new Movie[movieCount];

    for (int z = 0; z < temp; z++)
    {
        if (z != m)
        {
            n_movies[n].name = movies[z].name;
            n_movies[n].genre = movies[z].genre;
            n_movies[n].director = movies[z].director;
            n_movies[n].rating = movies[z].rating;
            n_movies[n].price = movies[z].price;
            n_movies[n].seats = movies[z].seats;
            for (int l = 0; l < 3; l++)
            {
                n_movies[n].time_cinema[l] = movies[z].time_cinema[l];
            }
            n++;
        }
    }

    delete[] movies;
    movies = new Movie[movieCount];
    for (int p = 0; p < movieCount; p++)
    {
        movies[p].name = n_movies[p].name;
        movies[p].genre = n_movies[p].genre;
        movies[p].director = n_movies[p].director;
        movies[p].rating = n_movies[p].rating;
        movies[p].price = n_movies[p].price;
        movies[p].seats = n_movies[p].seats;
        for (int q = 0; q < 3; q++)
        {
            movies[p].time_cinema[q] = n_movies[p].time_cinema[q];
        }
    }
    cout << "\n\tMovie Successfully Deleted, Return Back to Menu";
    Sleep(2000);
}

void modMovies()
{
    system("cls");
    string choice;
    cout << "\n\tWELCOME to Movies list";
    cout << "\n\t1. Add movie";
    cout << "\n\t2. Delete movie";
    cout << "\n\t3. Show Movies";
    cout << "\n\t4. Back";
    cout << "\n\t5. Exit";
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addMovie();
                system("cls");
                modMovies();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteMovChoice();
                break;
            }
            else if (choice == "3")
            {
                displayMovies();
                system("pause");
                modMovies();
                break;
            }
            else if (choice == "4")
            {
                admin::Menu();
                break;
            }
            else if (choice == "5")
            {
                exit(0);
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number: ";
            continue;
        }
    }
}

void displayCustomers()
{
	string searchCustomer;
	cin.ignore();
	
	cout << "\n\tEnter the customer name to diplay more details: ";
	getline(cin,searchCustomer);

	for (int i = 0; i < customerCount; i++)
    {
    while (customers[i].name == searchCustomer)	
	{
   	   	cout<<"\n\t";
	 	for (int i = 0; i <= 120; i++)
   		{
       		cout << "-";
   		}
	   	cout << "\n\t|" << left << setw(3) << "No"
   	 		 << setw(30) << "Name"
       		 << "|"
      		 << setw(15) << "Age"        		 
			 << "|"
        	 << setw(30) << "Phone"
       		 << "|"
       		 << setw(38) << "Address"
       		 << "|"
       		 << endl;
        	
		cout << "\n\t|" << setw(3) << left << i + 1
		   	 << setw(30) << customers[i].name << "|"
           	 << setw(15) << customers[i].age << "|"
           	 << setw(30) << customers[i].phone << "|"
           	 << setw(38) << customers[i].address << "|"
           	 << endl;
            	
			 break;
		}
		
	}
	cout<<endl;
	
} 
    

void inputCustomer(Customer customers[], int i = 0)
{
    cout << "\n\tEnter Customer Information";
    cout << "\n\t--------------------------";
    cout << "\n\tEnter name: ";
    getline(cin >> ws, customers[i].name);

    cout << "\n\tEnter Age: ";
    cin >> customers[i].age;

    cout << "\n\tEnter Phone: ";
    cin >> customers[i].phone;

    cout << "\n\tEnter Address: ";
    cin >> customers[i].address;

    cout << "\n\tEnter Username: ";
    getline(cin >> ws, customers[i].username);

    cout << "\n\tEnter Password: ";
    getline(cin >> ws, customers[i].password);
}

void addCustomer()
{
    int j = 1;

    customerCount += j;
    delete[] n_customers;
    n_customers = new Customer[customerCount];
    for (int i = 0; i < (customerCount - j); i++)
    {
        n_customers[i].name = customers[i].name;
        n_customers[i].age = customers[i].age;
        n_customers[i].phone = customers[i].phone;
        n_customers[i].address = customers[i].address;
        n_customers[i].username = customers[i].username;
        n_customers[i].password = customers[i].password;
    }

    for (int i = 0; i < j; i++)
    {
        inputCustomer(n_customers, customerCount - j + i);
    }
    delete[] customers;
    customers = new Customer[customerCount];

    for (int i = 0; i < customerCount; i++)
    {
        customers[i].name = n_customers[i].name;
        customers[i].age = n_customers[i].age;
        customers[i].phone = n_customers[i].phone;
        customers[i].address = n_customers[i].address;
        customers[i].username = n_customers[i].username;
        customers[i].password = n_customers[i].password;
    }
}

void deleteCustomer()
{
    system("cls");
    displayCustomers();
    int m, temp, n = 0;
    cout<< "\n\tWhich Customer would you like to remove: ";
    cin >> m;
    m--;
    temp = customerCount;
    customerCount--;
    delete[] n_customers;
    n_customers = new Customer[customerCount];

    for (int z = 0; z < temp; z++)
    {
        if (z != m)
        {
            n_customers[n].name = customers[z].name;
            n_customers[n].age = customers[z].age;
            n_customers[n].phone = customers[z].phone;
            n_customers[n].address = customers[z].address;
            n_customers[n].username = customers[z].username;
            n_customers[n].password = customers[z].password;
            n++;
        }
    }

    delete[] customers;
    customers = new Customer[customerCount];
    for (int p = 0; p < customerCount; p++)
    {
        customers[p].name = n_customers[p].name;
        customers[p].age = n_customers[p].age;
        customers[p].phone = n_customers[p].phone;
        customers[p].address = n_customers[p].address;
        customers[p].username = n_customers[p].username;
        customers[p].password = n_customers[p].password;
    }

    cout << "\n\tCustomer Successfully Removed, Return Back to Menu";
    Sleep(2000);
}

void nullifyCustomerlist()
{
    delete[] customers;
    customerCount = 0;
    customers = new Customer[customerCount];

    cout << "\n\tSuccessfully Deleted all Entries, Return back to menu";
    Sleep(2000);
    modCustomers();
}

void nullifyMovieList()
{
    delete[] movies;
    movieCount = 0;
    movies = new Movie[movieCount];

    cout << "\n\tSuccessfully Deleted all Entries, Return back to menu";
    Sleep(2000);
    modMovies();
}

void deleteAllCustomer()
{
    string choice;
    cout<< "\n\tAre you sure you want to remove all entries?";
    cout<< "\n\t1. Yes";
    cout<< "\n\t2. No";
    while (true)
    {
        cout<< "\n\tEnter your Choice: ";
        cin>> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                nullifyCustomerlist();
                break;
            }
            else if (choice == "2")
            {
                deleteCustChoice();
                system("pause");
                modCustomers();
                break;
            }
            else
                cout<< "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number: ";
            continue;
        }
    }
}

void deleteAllMovie()
{
    string choice;
    cout<< "\n\tAre you sure you want to remove all entries?";
    cout<< "\n\t1. Yes";
    cout<< "\n\t2. No";
    while (true)
    {
        cout << "\n\tEnter your Choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                nullifyMovieList();
                break;
            }
            else if (choice == "2")
            {
                deleteMovChoice();
                system("pause");
                modMovies();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number: ";
            continue;
        }
    }
}

void deleteCustChoice()
{
    system("cls");
    string choice;
    cout<< "\n\tSelect a Delete Option";
    cout<< "\n\t1. Single Entry";
	cout<< "\n\t2. All Entries";
    cout<< "\n\t3. Back";
    while (true)
    {
        cout<< "\n\tEnter your choice: ";
        cin>> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                deleteCustomer();
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                deleteAllCustomer();
                cout << "\n\tAll Entries Successfully deleted.";
                Sleep(2000);
                modCustomers();
                break;
            }
            else if (choice == "3")
            {
                modCustomers();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}

void deleteMovChoice()
{
    system("cls");
    string choice;
    cout<< "\n\tSelect a Delete Option";
    cout<< "\n\t1. Single Entry";
    cout<< "\n\t2. All Entries";
    cout<< "\n\t3. Back";
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                deleteMovie();
                modMovies();
                break;
            }
            else if (choice == "2")
            {
                deleteAllMovie();
                cout << "\n\tAll Entries Successfully deleted";
                Sleep(2000);
                modMovies();
                break;
            }
            else if (choice == "3")
            {
                modMovies();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}

void modCustomers()
{
    system("cls");
    string choice;
    cout<< "\n\tWELCOME TO CUSTOMERS LIST";
    cout<< "\n\t1. Add customer";
    cout<< "\n\t2. Delete customer";
    cout<< "\n\t3. Show customers";
    cout<< "\n\t4. Back";
    cout<< "\n\t5. Exit";
    while (true)
    {
        cout<< "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                addCustomer();
                system("cls");
                modCustomers();
                break;
            }
            else if (choice == "2")
            {
                system("cls");
                deleteCustChoice();
                break;
            }
            else if (choice == "3")
            {
                displayCustomers();
                system("pause");
                modCustomers();
                break;
            }
            else if (choice == "4")
            {
                admin::Menu();
                break;
            }
            else if (choice == "5")
            {
                exit(0);
                break;
            }
            else
                cout<< "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number: ";
            continue;
        }
    }
}

void customerLogin()
{
    string uName, pass;

    system("cls");
    cout << "\n\tWELCOME TO CUSTOMER SIDE ... LOGIN!";
    while (true)
    {
        cout << "\n\t0. Back";
        cout << "\n\n\tEnter your Username: ";
        cin >> uName;
        if (uName == "0")
        {
            customerLoginChoice();
        }

        for (int i = 0; i < customerCount; i++)
        {
            if (uName == customers[i].username)
            {
                loginIndex = i;
                break;
            }
        }

        cout << "\n\tEnter your Password: ";
        cin >> pass;
        if (pass == "0")
        {
            customerLoginChoice();
        }
        if (pass == customers[loginIndex].password)
        {
            currentSession = uName;
            system("cls");
            cout << "\n\tLogin Successful, Redirecting";
            cout << "\n\t| # - - - - - - - - |";
            Sleep(500);
            system("cls");
            cout << "\n\tLogin Successful, Redirecting";
            cout << "\n\t| # # # # # # # # # |";
            Sleep(250);
            customer::Menu();
        }
        else
        {
            cout << "\n\tInvalid Credentials, Try Again";
            continue;
        }

        system("pause");
        customerLogin();
    }
}

void adminLogin()
{
    string uName, pass;
    system("cls");
    cout << "\n\tWELCOME TO ADMIN SIDE ... LOGIN!";
    while (true)
    {
        cout << "\n\t0. Back";
        cout << "\n\n\n\tEnter your Username: ";
        cin >> uName;
        if (uName == "0")
        {
            loginPage();
        }
        cout << "\n\tEnter your Password: ";
        cin >> pass;
        if (pass == "0")
        {
            loginPage();
        }

        if (uName == adminUname && pass == adminPass)
        {
            admin::Menu();
            break;
        }
        else
        {
            cout << "\n\tInvalid Credentials, Try Again";
            continue;
        }
    }
}

void customerLoginChoice()
{
    string choice;
    system("cls");
    cout<< "\n\t1. Registered Customer";
    cout<< "\n\t2. New Customer";
    cout<< "\n\t3. Back";
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                customerLogin();
                break;
            }
            else if (choice == "2")
            {
                addCustomer();
                cout << "\n\tCustomer Successfully Registered, Please Login..";
                Sleep(2000);
                system("cls");
                customerLogin();
                break;
            }
            else if (choice == "3")
            {
                loginPage();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}



void loginPage()
{
    string choice;
    system("cls");
    cout<<"\n    ##      ## ####### ##      ####### ####### #### #### #######";
    cout<<"\n    ##      ## ##      ##      ##      ##   ## ## ### ## ##     ";
    cout<<"\n    ##  ##  ## #####   ##      ##      ##   ## ##  #  ## #####  ";
    cout<<"\n    ##  ##  ## ##      ##      ##      ##   ## ##     ## ##     ";
    cout<<"\n    ########## ####### ####### ####### ####### ##     ## #######";
	cout<<"\n    ************************************************************";
	cout<<"\n                   CINEMA IS A WORLD OF IMAGINATION             ";
	cout<<"\n    ************************************************************";
	time_t now;
	time (&now);
	cout<<"\n\n\t Current Date & Time is: "<<ctime(&now);;	
    cout<< "\n\tWelcome .. Please choose your side. ";
    cout<< "\n\t1.Customer";
    cout<< "\n\t2.Admin";
    
    while (true)
    {
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (floatCheck(choice))
        {
            if (choice == "1")
            {
                customerLoginChoice();
                break;
            }
            else if (choice == "2")
            {
                adminLogin();
                break;
            }
            else
                cout << "\n\tPlease Enter a Valid Number: ";
            continue;
        }
        else
        {
            cout << "\n\tPlease Enter a Number";
            continue;
        }
    }
}

void updateInfo()
{
	char upCh;
	int upAge;
	string upPhone, upEmail, upAddress, upUsername, upPassword;
	

	   		cout<<"\n\t1.Age";
   			cout<<"\n\t2.Phone";
   			cout<<"\n\t3.Email";
   			cout<<"\n\t4.Address";
   			cout<<"\n\t5.Username";
   			cout<<"\n\t6.Password";
   			cout<<"\n\tWhich information would you like to update:";

   			cin>>upCh;
   			
	for (int i = 0; i < customerCount; i++)
    {
   			if (upCh == '1')
   			{
   				cout<<"\n\tNew Age: ";
   				cin>>upAge;
   				
   				customers[i].age = upAge;
   				
   				cout<<"\n\tAge updated successfully\n";
   				break;
			}
			else if (upCh == '2')
			{
				cout<<"\n\tNew Phone: ";
   				cin>>upPhone;
   				
   				customers[i].phone = upPhone;
   				
   				cout<<"\n\tPhone updated successfully\n";
   				break;
			}
			else if (upCh == '3')
			{
				cout<<"\n\tNew Email: ";
   				cin>>upEmail;
   				
   				customers[i].email = upEmail;
   				
   				cout<<"\n\tEmail updated successfully\n";
   				break;
			}
			else if (upCh == '4')
			{
				cout<<"\n\tNew Address: ";
   				cin>>upAddress;
   				
   				customers[i].address = upAddress;
   				break;
			}
			else if (upCh == '5')
			{
				cout<<"\n\tNew Username: ";
   				cin>>upUsername;
   				
   				customers[i].username = upUsername;
   				
   				cout<<"\n\tUsername updated successfully\n";
   				break;
			}
			else if (upCh == '6')
			{
				cout<<"\n\tNew Password: ";
   				cin>>upPassword;
   				
   				customers[i].password = upPassword;
   			
			   	cout<<"\n\tPassword updated successfully\n";
			   	break;

			}
			else
			{
				cout<<"\n\tInvalid option!\n";
				break;
			}
	}
}

bool floatCheck(string a)
{
    int len = 0;
    for (int j = 0; a[j]; j++)
    {
        len++;
    }

    for (int i = 0; a[i]; i++)
    {

        if ((int(a[i]) > 58 || int(a[i]) < 48) && int(a[i]) != 46)
        {
            return false;
        }
        if (i == len - 1)
        {
            if ((int(a[i]) < 58 && int(a[i]) >= 48))
            {
                return true;
            }
        }
    }
    return true;
}
void nearestCinema()
{
	string wh;
	
	cout<<"\n\t To choose the nearst movie theater enter WHERE are you from ?";
	cout<<"\n\t\t Qatif - Dammam - Khobar - Jubail\n\n\t --->";
				cin>>wh;
				
				if (wh=="Qatif" || wh=="qatif")
				{
					x=Qlat; 
					y=Qlon;
					
					cout<<"\n\tYour Current Location is: \n";
					cout<<"\n\tLongitude: "<<x<<"\n\tLatitude: "<<y<<endl;					
					recgn();

					cout<<"\n\tCinema Thearter 1 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon1<<"\n\tLatitude: "<<Clat1<<endl;					
					recgn();

					cout<<"\n\tCinema Theater 2 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon2<<"\n\tLatitude: "<<Clat2<<endl;					
					recgn();

					
					distance1 = Distance(x,y,Clat1, Clon1);
					distance2 = Distance(x,y,Clat2, Clon2);
					
					double checkNearest= Distance(distance1 , distance2);
					cout<<"\n\t\t\t\t The cinema theater #"<<checkNearest<<" is the nearest one \n";
					recgn();

				}
				else if (wh=="Dammam" || wh=="dammam")
				{
					x=Dlat; 
					y=Dlon;
					
					cout<<"\n\tYour Current Location is: \n";
					cout<<"\n\tLongitude: "<<x<<"\n\tLatitude: "<<y<<endl;					
					recgn();

					cout<<"\n\tCinema Thearter 1 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon1<<"\n\tLatitude: "<<Clat1<<endl;					
					recgn();

					cout<<"\n\tCinema Theater 2 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon2<<"\n\tLatitude: "<<Clat2<<endl;						
					recgn();

						
					distance1 = Distance(x,y,Clat1, Clon1);
					distance2 = Distance(x,y,Clat2, Clon2);
					
					double checkNearest= Distance(distance1 , distance2);
					cout<<"\n\t\t\t\t The cinema theater #"<<checkNearest<<" is the nearest one \n";
					recgn();

				}
				else if (wh=="Khobar" || wh=="khobar")
				{
					
					x=Klat; 
					y=Klon;
				
					cout<<"\n\tYour Current Location is: \n";
					cout<<"\n\tLongitude: "<<x<<"\n\tLatitude: "<<y<<endl;					
					recgn();

					cout<<"\n\tCinema Thearter 1 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon1<<"\n\tLatitude: "<<Clat1<<endl;					
					recgn();

					cout<<"\n\tCinema Theater 2 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon2<<"\n\tLatitude: "<<Clat2<<endl;					
					recgn();

										
					distance1 = Distance(x,y,Clat1, Clon1);
					distance2 = Distance(x,y,Clat2, Clon2);
			
					double checkNearest= Distance(distance1 , distance2);
					cout<<"\n\t\t\t\t The cinema theater #"<<checkNearest<<" is the nearest one \n";
					recgn();

				}
				else if (wh=="Jubail" || wh=="jubail")
				{
					x=Jlat; 
					y=Jlon;
								
					cout<<"\n\tYour Current Location is: \n";
					cout<<"\n\tLongitude: "<<x<<"\n\tLatitude: "<<y<<endl;					
					recgn();

					cout<<"\n\tCinema Thearter 1 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon1<<"\n\tLatitude: "<<Clat1<<endl;					
					recgn();

					cout<<"\n\tCinema Theater 2 Location is: \n";
					cout<<"\n\tLongitude: "<<Clon2<<"\n\tLatitude: "<<Clat2<<endl;						
					recgn();
	
					
					distance1 = Distance(x,y,Clat1, Clon1);
					distance2 = Distance(x,y,Clat2, Clon2);
					
					double checkNearest= Distance(distance1 , distance2);
					cout<<"\n\t\t\t\t The cinema theater #"<<checkNearest<<" is the nearest one \n";
					recgn();

				}
				else
				{
					cout<<"\n\\t\t\t Your city is not available now";
				}
}

double Distance (double &x, double &y,double lat, double lon)
{
	return sqrt(pow(lon-y,2)+ pow(lat-x,2));
}


double Distance (double Loc1, double Loc2) 
{
	if (Loc1 < Loc2)
		return 1;
	else
		return 2;
}

void recgn()	
{
	cout<<"\n|_______________________________________________________________________________________________________|\n";
}

int main()
{
	ofstream outFile;
	ifstream inFile;
	
	outFile.open("opinionout.txt",ios::out);
	inFile.open("opinionIn.txt",ios::in);
	
	if(outFile.is_open()==true && inFile.is_open()==true)
	{
		string FavMovie;
			
			cout<<"\n\tOur Cinema Will Play This Movie Next Month <3 : ";
			
		while (!inFile.eof())
		{
		
			getline(inFile,FavMovie);
			
			cout<<FavMovie;
		
			outFile<<"\n\tWhat was your favourite film, and wants to watch it"
			<<" again in our cinema theatre next time ? "<<FavMovie<<endl;
		}
	outFile.close();
	inFile.close();
	cout<<"\n\n\tCopied Successfully\n";
	}
	else
	{
		cout<<"\n\tFailed\n";
	}
	
    system("pause");

    loginPage();
    
    return 0;
}
