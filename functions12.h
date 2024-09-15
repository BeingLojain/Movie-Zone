#ifndef FUNCTIONS12_H
#define FUNCTIONS12_H
#include<string>
using namespace std;

//Declaring Structures and Pointers
typedef string s;

struct Customer{
	string name;
	int age;
	s phone, email, address, username, password;
};

int customerCount= 2;
Customer *customers{new Customer[customerCount]{{"Mohamed",34, "214321434","moahef@dsgf.com","adfasfsad","mohamed","123"},
														{"Shatha",20,"322352","aig@sdfh.com","asdfsaf","shatha","1234"}}};
Customer *n_customers = new Customer[customerCount]; 

struct Movie{
	s name, genre, director;
	float rating, price;
	string time_cinema[3];
	int seats;
};
int movieCount = 8;
Movie *movies{new Movie[movieCount]{{"The Avengers", "Action", "Russo Brothers", 10.0, 55.00, {"9:45 C1", "3:30 C3", "11:10 C2"}, 100},
                                    {"A Quiet Place", "Horror", "John Krasinski", 6.8, 60.00, {"21:20 C1", "10:55 C3", "2:40 C2"}, 66},
                                    {"Fast 9", "Action", "Justin Lin", 5.1, 45.00, {"6:00 C1", "13:30 C3", "15:00 C2"}, 72},
                                    {"Den of Thieves", "Adventure", "Christian Gudegast", 4.6, 40.00, {"17:30 C1", "8:00 C3", "11:00 C2"}, 120},
                                    {"Bullet Train", "Action", "David Leitch", 9.8, 70.00, {"7:30 C1", "5:00 C3", "14:15 C2"}, 50},
                                    {"One Piece:RED", "Anime", "Goro Taniguchi", 8.4, 50.00, {"19:30 C1", "4:00 C3", "12:15 C2"}, 12},
                                    {"Home Alone", "Comedy", "Chris Colimbus", 7.6, 25.00, {"18:30 C1", "16:00 C3", "10:35 C2"}, 150},
                                    {"What Happedned", "Drama", "Tom Noonan", 3.2, 30.00, {"20:00 C1", "22:45 C3", "9:10 C2"}, 100}}};
Movie *n_movies = new Movie[movieCount];

struct Ticket
{
    s cust_name, mov_name, timeandcinema;
    int seat_no[10];
    int age, ticketCount;
    double totalCost;
};

int bookedTickets = 2;
Ticket *tickets{new Ticket[bookedTickets]{{"Wesagn", "The Avengers", "10:00 C2", {56, 57}, 21, 2, 110},
	 									{"Enas", "Harry Potter", "19:00 C3", {11, 23, 24, 12}, 21, 4, 249}}};
Ticket *n_tickets = new Ticket[bookedTickets];

Ticket *newOrder = new Ticket;

string currentSession;
int loginIndex, ticketIndex;

string adminUname = "admin", adminPass = "admin";


//prototyping Functions

bool floatCheck(string);
void print_array(string snacks[], int numberOfItems);
float calcPrice(int packno);
void deleteSnack();
void SnackList();
void displaySnacks();
void adminLogin();
void loginPage();
void customerLoginChoice();
void customerLogin();
void displayMovies();
void sortMovi();
void inputTicket(Ticket, int);
void bookMovie();
void displayTicket();
void makeSeats(int);
void inputMovie(Movie, int);
void addMovie();
void deleteMovie();
void modMovies();
void displayCustomers();
void inputCustomer(Customer, int);
void addCustomer();
void deleteCustomer();
void deleteCustChoice();
void modCustomers();
void nullifyCustomerList();
void displayTicketList();
void deleteMovChoice();
void deleteAllMovie();
void updateInfo();
double Distance (double &x, double &y,double lat, double lon);
double Distance (double Loc1, double Loc2);
void recgn();
void nearestCinema();

#endif
