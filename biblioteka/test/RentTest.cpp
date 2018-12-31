#include <boost/test/unit_test.hpp>
#include "Client/Client.h"
#include "Address/Address.h"
#include "Vehicle/Vehicle.h"
#include "Date/RentDateTime.h"
#include "Rent/Rent.h"
#include "Vehicle/Car.h"
#include "Vehicle/Moped.h"
#include "Vehicle/Bicycle.h"
#include "Repository/RentsRepository.h"
#include "Repository/VehicleRepository.h"
#include "Client/ClientType.h"
#include "Client/ClientTypes.h"
#include "Repository/ClientRepository.h"
#include "Managers/RentsManager.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(ClientTest) {
    address_ptr a1(new Address(7,"Macieja"));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",a1,a2));
    BOOST_CHECK_EQUAL(k1->getFirstName(),"Kamil");//Sprawdza czy imie poprawne
    BOOST_CHECK_EQUAL(k1->getPersonalID(),"123");//Sprawdza czy ID poprawne
    BOOST_CHECK_EQUAL(k1->getLastName(),"Celejewski");//Sprawdza czy nazwisko poprawne
    BOOST_CHECK_EQUAL(k1->getRents().size(),0);//Sprawdza czy po utworzeniu klienta nie posiada on wypożyczeni
    BOOST_CHECK(k1->getClientType() != nullptr);//Sprawdza czy klient został stworzony z podstawowym typem
    clientType_ptr s = k1->getClientType();
    BOOST_CHECK_EQUAL(s->discount(1.0),0);//Sprawdza czy typ jest podstawowy czy zwraca discount 0
    BOOST_CHECK_EQUAL(s->maxVehicle(),1);//Sprawdza czy klient o podstawowym typie może wypożyczyć tylko 1 vehicle
    clientType_ptr g(new ClientGold());
    k1->setClientType(g);
    s = k1->getClientType();
    BOOST_CHECK_EQUAL(s->discount(100.0),75.0);//Sprawdza czy zmiana typu odbyła się pomyślnie i czy zniżka jest poprawnie obliczana
    BOOST_CHECK_EQUAL(s->maxVehicle(),3);//Sprawdza czy po zmianie typy na gold może wypożyczyć max 3 vehicle
    //Sprawdza czy jeśli jakaś wartość jest pusta zostanie rzucony wyjątek zadanie zakłada że adres nie musi być podany.
    BOOST_CHECK_THROW(Client("","Celejewski","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","Celejewski","",nullptr,nullptr), std::logic_error);
}

BOOST_AUTO_TEST_CASE(AddressTest) {
    address_ptr a1(new Address(7,"Mariana"));
    BOOST_CHECK_EQUAL(a1->getAddressNumber(),7);//Sprawdza czy nr ulicy jest równe 7
    BOOST_CHECK_EQUAL(a1->getStreetName(),"Mariana");//Nprawdza czy nazwa ulicy jest równa Mariana
    //Numer ulicy nie może być równy 0 a nazwa nie może być pusta
    BOOST_CHECK_THROW(Address( 0,"Mariana"), std::logic_error);
    BOOST_CHECK_THROW(Address(10,""), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CarTest) {
    car_ptr c1(new Car("A",10,"123",10));
    //Sprawdza czy podstawowa cena, ID, segment tylko dla samochodu, aktualna cena zależna od pojemności silnika i segmenty i pojemność silnika się zgadzają
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->getSegment(),"A");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getEngineDisplacement(),10);
    //Sprawdza czy wyjątki się zgadzają podstawowa cena ani pojemność silnika nie mogą być równe 0 i czy segment mieści się w zakresie od A-F
    BOOST_CHECK_THROW(Car("L",10,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("",10,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("A",0,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("L",10,"",10), std::logic_error);
    BOOST_CHECK_THROW(Car("L",10,"123",0), std::logic_error);
}

BOOST_AUTO_TEST_CASE(MopedTest) {
    moped_ptr c1(new Moped(10,"123",10));
    moped_ptr c2(new Moped(2001,"123",10));
    //Sprawdza czy cena podstawowa , wyliczona w zależności od pojemności silnika , Id oraz pojemność silnikazgadzają się
    BOOST_CHECK_EQUAL(c2->actualRentPrice(),15);
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    //Sprawdza czy pojazd posiada ID i czy cena bazowa lub pojemność nie są równe 0
    BOOST_CHECK_EQUAL(c1->getEngineDisplacement(),10);
    BOOST_CHECK_THROW(Moped(0,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Moped(10,"123",0), std::logic_error);
    BOOST_CHECK_THROW(Moped(10,"",10), std::logic_error);
}

BOOST_AUTO_TEST_CASE(BicycleTest) {
    bicycle_ptr c1(new Bicycle("123",10));
    //Sprawdza ID podstawową i stateczną cenę. W przypadku bicycle cena cena podstawowa powinna być równa ostatecznej
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    //ID nie może być puste a cena nie może mieć wartości 0
    BOOST_CHECK_THROW(Bicycle("123",0), std::logic_error);
    BOOST_CHECK_THROW(Bicycle("",10), std::logic_error);
}


BOOST_AUTO_TEST_CASE(RentalDateTimeTest) {
    rentDateTime d1(new RentDateTime(20));
    BOOST_CHECK_EQUAL(d1->rentDuration(),0);//Przed zakończeniem wypożyczenia jej okres powinien być równy 0
    d1->endRentDate(); // zakonczenie wyporzyczenia
    BOOST_CHECK_EQUAL(d1->rentDuration(),1);//Po zakończeniu renty tego samego dnia i tak powinien zostać naliczony 1 dzień
    BOOST_CHECK_THROW(RentDateTime(40), std::logic_error);//Nie można wypożyczyć na więcej niż 30 dni
    BOOST_CHECK_EQUAL(d1->currentRentDuration(),1);//Ilość dni ile trwa wypożyczeni zawsze dzień wypożyczenia jest naliczany jako cały
}

BOOST_AUTO_TEST_CASE(RentTest) {
    rentDateTime d1(new RentDateTime(20));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",nullptr,a2));
    vehicle_ptr c1(new Car("A",10,"123",10));
    rent_ptr r1(new Rent(k1,c1,d1));
    BOOST_CHECK_EQUAL(r1->countRentPrice(),0.0);//Cena przed zwroceniem
    BOOST_CHECK_EQUAL(r1->rentEndDate(),0);//Ile trwalo wyporzyczenie przed zakonczeniem zawsze 0
    BOOST_CHECK_EQUAL(k1->getRents().size(),1);//Czy klient posiada to wypożyczenie
    BOOST_CHECK_EQUAL(r1->countRentPrice(),0);//Cena przed oddaniem vehicle
    r1->returnVehicle();
    BOOST_CHECK_EQUAL(r1->countRentPrice(),10);//Cena po oddaniu klient ma typ podstawowy więc zniżka 0
    BOOST_CHECK_EQUAL(k1->getRents().size(),0);//Czy client ma wyporzyczenie po oddaniu
    BOOST_CHECK_EQUAL(r1->rentEndDate(),1);//Ilosc dni wyporzyczenia
}

BOOST_AUTO_TEST_CASE(RentsRepositoryTest) {
    rentsRepository_ptr R(new RentsRepository());
    rentDateTime d1(new RentDateTime(20));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",nullptr,a2));
    vehicle_ptr c1(new Car("A",10,"123",10));
    vehicle_ptr c2(new Car("A",10,"124",10));
    rent_ptr r1(new Rent(k1,c1,d1));
    R->addRent(r1);
    //Klient ma typ podstawowy więc zniżka 0
    BOOST_CHECK_EQUAL(R->getClientForRentedVehicle(c1),k1);
    BOOST_CHECK_EQUAL(R->getClientForRentedVehicle(c2), nullptr);//Nie ma w repozytorium wypożyczenie które odpowiadało by danemu pojazdowi
    R->removeRent(r1);
    BOOST_CHECK_EQUAL(R->getRents().size(),0);//Czy wypożyczenie zostało pomyślnie usunięte
}

BOOST_AUTO_TEST_CASE(VehicleRepositorTest) {
    vehicleRepository_ptr V(new VehicleRepository());
    vehicle_ptr c1(new Car("A", 10, "123", 10));
    vehicle_ptr c2(new Car("A", 10, "124", 10));
    V->addVehicle(c1);
    V->addVehicle(c2);
    //Sprawdza czy istnieją pojazdy o podanych indeksach jeśli nie istnieje to wyjatek
    BOOST_CHECK_EQUAL(V->findVehicle(0),c1);
    BOOST_CHECK_EQUAL(V->findVehicle(1),c2);
    BOOST_CHECK_THROW(V->findVehicle(2),std::logic_error);
    V->removeVehicle(c2);
    BOOST_CHECK_THROW(V->findVehicle(1),std::logic_error);//Czy po usunięciu pojazdu znajduje się jeszcze w repozytorium
    BOOST_CHECK_EQUAL(V->findVehicle(0),c1);//czy zostały usunięte wszystkie pojazdy
}

BOOST_AUTO_TEST_CASE(ClientRepositoryTest) {
    client_ptr k1(new Client("Kamil", "Celejewski", "123", nullptr, nullptr));
    client_ptr k2(new Client("Kamil", "Celejewski", "124", nullptr, nullptr));
    clientRepository_ptr R(new ClientRepository());
    clientGold_ptr g(new ClientGold());
    R->addClient(k1);
    R->addClient(k2);
    R->changeType(k1,g);
    BOOST_CHECK_EQUAL(k1->getClientType(), g);
    R->removeClient(k1);
    R->removeClientById(0);
}

BOOST_AUTO_TEST_CASE(RentManagerTest) {
    clientRepository_ptr K(new ClientRepository());
    vehicleRepository_ptr V(new VehicleRepository());
    rentsRepository_ptr CR(new RentsRepository());
    rentsRepository_ptr AR(new RentsRepository());
    rentsManager_ptr M(new RentsManager(CR, AR, K, V));
    BOOST_CHECK_THROW(RentsManager(CR,nullptr,nullptr,nullptr), std::logic_error);
    BOOST_CHECK_THROW(RentsManager(CR,AR,nullptr,nullptr), std::logic_error);
    BOOST_CHECK_THROW(RentsManager(CR,AR,K,nullptr), std::logic_error);

    vehicle_ptr c1(new Car("A", 10, "123", 10));
    vehicle_ptr c2(new Car("A", 10, "124", 10));
    vehicle_ptr c3(new Car("A", 10, "125", 10));
    V->addVehicle(c1);

    client_ptr k1(new Client("Kamil", "Celejewski", "123", nullptr, nullptr));
    client_ptr k2(new Client("Kamil", "Celejewski", "124", nullptr, nullptr));
    client_ptr k3(new Client("Kamil", "Celejewski", "125", nullptr, nullptr));
    K->addClient(k1);

    rentDateTime d1(new RentDateTime(20));
    rentDateTime d2(new RentDateTime(22));

    M->rentVehicle(k1,c1,d1);
    BOOST_CHECK_THROW(M->rentVehicle(k2,c1,d1), std::logic_error);//Klienta nie ma w bazie
    BOOST_CHECK_THROW(M->rentVehicle(k1,c2,d1), std::logic_error);//Pojazdu nie ma w bazie
    BOOST_CHECK_THROW(M->rentVehicle(k1,c1,d1), std::logic_error);//Dany pojazd jest już wypożyczony
    BOOST_CHECK_EQUAL(CR->getRents().size(),1);//Czy w repozytorium wypożyczeni znajduje się utworzone wypożyczenie

    V->addVehicle(c2);
    K->addClient(k2);

    BOOST_CHECK_THROW(M->rentVehicle(k1,c2,d2), std::logic_error);//Czy dany typ nie pozwala na wypożyczenie większej ilości pojazdów

    BOOST_CHECK_THROW(M->returnVehicle(k3,c1), std::logic_error);//Klient nie istnieje w bazie
    BOOST_CHECK_THROW(M->returnVehicle(k1,c3), std::logic_error);//Nie ma takiego pojazdu
    BOOST_CHECK_THROW(M->returnVehicle(k1,c2), std::logic_error);//Klient nie wypożyczył tego pojazdu

    M->returnVehicle(k1,c1);
    BOOST_CHECK_EQUAL(CR->getRents().size(),0);//Czy repozytorium aktualnych wypożyczeni jest puste
    BOOST_CHECK_EQUAL(AR->getRents().size(),1);//Czy repozytorium archiwalnych wypożyczeni zawiera jedno wypożyczenie
    BOOST_CHECK_EQUAL(k1->getRents().size(),0);//Czy klient posiada to wypożyczenie na liście swoich wypożyczeń
    BOOST_CHECK_EQUAL(M->getAllClientRents(k1).size(),1);//Ilość zarchiwizowanych rent klięta
    BOOST_CHECK_EQUAL(M->checkClientRentBallance(k1),10.0);//Łączna suma ostatecznych cen klienta

    M->rentVehicle(k1,c1,d1);
    BOOST_CHECK_EQUAL(CR->getRents().size(),1);//Czy w repozytorium wypożyczeni znajduje się utworzone wypożyczenie
    M->returnVehicle(k1,c1);
    BOOST_CHECK_EQUAL(CR->getRents().size(),0);//Czy repozytorium aktualnych wypożyczeni jest puste
    BOOST_CHECK_EQUAL(AR->getRents().size(),2);//Czy repozytorium archiwalnych wypożyczeni zawiera dwa wypożyczenie
    BOOST_CHECK_EQUAL(M->getAllClientRents(k1).size(),2);//Ilość zarchiwizowanych rent klięta
    BOOST_CHECK_EQUAL(M->checkClientRentBallance(k1),20.0);//Łączna suma ostatecznych cen klienta
}
BOOST_AUTO_TEST_SUITE_END()