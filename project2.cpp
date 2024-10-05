#include <iostream>
#include <string>
using namespace std;

// Structure to store customer details
struct Customer {
    string name;
    string phone;
    string address;

    // Function to input customer details
    void inputCustomerDetails() {
        cout << "\nEnter Customer Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Address: ";
        getline(cin, address);
    }

    // Function to display customer details
    void displayCustomerDetails() const {
        cout << "\nCustomer Name: " << name << endl;
        cout << "Phone Number: " << phone << endl;
        cout << "Address: " << address << endl;
    }
};

// Room class for managing rooms in the hotel
class Room {
    int roomNumber;
    string roomType;
    bool isBooked;
    Customer* customer;  // Pointer to store customer information for the booked room

public:
    // Constructor to initialize a room
    Room(int number, string type) {
        roomNumber = number;
        roomType = type;
        isBooked = false;
        customer = nullptr;  // Initially, no customer is assigned
    }

    // Destructor to release allocated memory
    ~Room() {
        if (customer != nullptr) {
            delete customer;
        }
    }

    // Function to display room details
    void displayRoom() const {
        cout << "\nRoom Number: " << roomNumber << endl;
        cout << "Room Type: " << roomType << endl;
        cout << "Booking Status: " << (isBooked ? "Booked" : "Available") << endl;
    }

    // Function to check if room is available
    bool checkAvailability() const {
        return !isBooked;
    }

    // Overloaded == operator to compare room number
    bool operator==(int number) const {
        return roomNumber == number;
    }

    // Function to book the room
    void bookRoom(const Customer& cust) {
        if (!isBooked) {
            isBooked = true;
            customer = new Customer(cust);  // Allocate memory and store customer details
            cout << "Room " << roomNumber << " has been successfully booked!" << endl;
        } else {
            cout << "Room " << roomNumber << " is already booked." << endl;
        }
    }

    // Function to cancel the room booking
    void cancelBooking() {
        if (isBooked) {
            isBooked = false;
            delete customer;
            customer = nullptr;
            cout << "Room " << roomNumber << " booking has been cancelled." << endl;
        } else {
            cout << "Room " << roomNumber << " is not booked yet." << endl;
        }
    }
};

// Hotel class for managing hotel operations
class Hotel {
    Room** rooms;  // Array of pointers to Room objects
    int totalRooms;

public:
    // Constructor to initialize hotel with rooms
    Hotel(int size) {
        totalRooms = size;
        rooms = new Room*[totalRooms];

        for (int i = 0; i < totalRooms; i++) {
            if (i < 4)
                rooms[i] = new Room(i + 1, "Single");
            else if (i < 7)
                rooms[i] = new Room(i + 1, "Double");
            else
                rooms[i] = new Room(i + 1, "Suite");
        }
    }

    // Destructor to clean up allocated memory
    ~Hotel() {
        for (int i = 0; i < totalRooms; i++) {
            delete rooms[i];
        }
        delete[] rooms;
    }

    // Function to display all rooms
    void displayAllRooms() const {
        for (int i = 0; i < totalRooms; i++) {
            rooms[i]->displayRoom();
        }
    }

    // Function to check available rooms
    void checkAvailableRooms() const {
        bool available = false;
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i]->checkAvailability()) {
                rooms[i]->displayRoom();
                available = true;
            }
        }
        if (!available) {
            cout << "\nNo rooms are currently available." << endl;
        }
    }

    // Function to book a room
    void bookRoom(int roomNumber, const Customer& customer) {
        for (int i = 0; i < totalRooms; i++) {
            if (*rooms[i] == roomNumber) {
                rooms[i]->bookRoom(customer);
                return;
            }
        }
        cout << "Invalid room number!" << endl;
    }

    // Function to cancel a booking
    void cancelRoomBooking(int roomNumber) {
        for (int i = 0; i < totalRooms; i++) {
            if (*rooms[i] == roomNumber) {
                rooms[i]->cancelBooking();
                return;
            }
        }
        cout << "Invalid room number!" << endl;
    }
};

// Main function to manage hotel reservations
int main() {
    int totalRooms = 10;
    Hotel hotel(totalRooms);  // Initialize hotel with 10 rooms
    Customer customer;
    int choice, roomNumber;

    while (true) {
        cout << "\n\n=== OYO Room Reservation System ===\n";
        cout << "1. Show All Rooms\n";
        cout << "2. Check Available Rooms\n";
        cout << "3. Book a Room\n";
        cout << "4. Cancel a Booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayAllRooms();
                break;
            case 2:
                hotel.checkAvailableRooms();
                break;
            case 3:
                customer.inputCustomerDetails();
                cout << "Enter Room Number to Book: ";
                cin >> roomNumber;
                hotel.bookRoom(roomNumber, customer);
                customer.displayCustomerDetails();
                break;
            case 4:
                cout << "Enter Room Number to Cancel Booking: ";
                cin >> roomNumber;
                hotel.cancelRoomBooking(roomNumber);
                break;
            case 5:
                cout << "Thank you for using the Hotel Reservation System!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
}
