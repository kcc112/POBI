#include <iostream>
#include "Address/Address.h"
#include "Client/Client.h"
#include "Vehicle/Vehicle.h"
#include <iostream>

using namespace std;

int main(){

    address_ptr a1(new Address(7,"Macieja"));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",a1,a2));

    cout << k1->clientInfo() << endl;

    client_ptr k2(new Client("Kamil","Celejewski","123",NULL,NULL));

    cout << k2->clientInfo() << endl;
    
    vehicle_ptr v1(new Vehicle("123", 10));
    
    cout << v1->vehicleInfo() << endl;

    return 0;
}