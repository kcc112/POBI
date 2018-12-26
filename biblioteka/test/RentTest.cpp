#include <boost/test/unit_test.hpp>
#include "Client/Client.h"
#include "Address/Address.h"
#include "Vehicle/Vehicle.h"
#include "Date/RentDateTime.h"
#include "Rent/Rent.h"
#include "Vehicle/Car.h"
#include "Vehicle/Moped.h"
#include "Vehicle/Bicycle.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(ClientTest) {
    address_ptr a1(new Address(7,"Macieja"));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",a1,a2));
    BOOST_CHECK_EQUAL(k1->getFirstName(),"Kamil");
    BOOST_CHECK_EQUAL(k1->getPersonalID(),"123");
    BOOST_CHECK_EQUAL(k1->getLastName(),"Celejewski");
    BOOST_CHECK_EQUAL(k1->getRents().size(),0);
    BOOST_CHECK_THROW(Client("","Celejewski","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","Celejewski","",a1,a2), std::logic_error);
}

BOOST_AUTO_TEST_CASE(AddressTest) {
    address_ptr a1(new Address(7,"Mariana"));
    BOOST_CHECK_EQUAL(a1->getAddressNumber(),7);
    BOOST_CHECK_EQUAL(a1->getStreetName(),"Mariana");
    BOOST_CHECK_THROW(Address( 0,"Mariana"), std::logic_error);
    BOOST_CHECK_THROW(Address(10,""), std::logic_error);
}

BOOST_AUTO_TEST_CASE(CarTest) {
    car_ptr c1(new Car("A",10,"123",10));
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->getSegment(),"A");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getEngineDisplacement(),10);
    BOOST_CHECK_THROW(Car("L",10,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("",10,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("A",0,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Car("L",10,"",10), std::logic_error);
    BOOST_CHECK_THROW(Car("L",10,"123",0), std::logic_error);
}

BOOST_AUTO_TEST_CASE(MopedTest) {
    moped_ptr c1(new Moped(10,"123",10));
    moped_ptr c2(new Moped(2001,"123",10));
    BOOST_CHECK_EQUAL(c2->actualRentPrice(),15);
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getEngineDisplacement(),10);
    BOOST_CHECK_THROW(Moped(0,"123",10), std::logic_error);
    BOOST_CHECK_THROW(Moped(10,"123",0), std::logic_error);
    BOOST_CHECK_THROW(Moped(10,"",10), std::logic_error);
}

BOOST_AUTO_TEST_CASE(BicycleTest) {
    bicycle_ptr c1(new Bicycle("123",10));
    BOOST_CHECK_EQUAL(c1->getBaseRentPrice(),10);
    BOOST_CHECK_EQUAL(c1->getID(),"123");
    BOOST_CHECK_EQUAL(c1->actualRentPrice(),10);
    BOOST_CHECK_THROW(Bicycle("123",0), std::logic_error);
    BOOST_CHECK_THROW(Bicycle("",10), std::logic_error);
}


BOOST_AUTO_TEST_CASE(RentalDateTimeTest) {
    rentDateTime d1(new RentDateTime(20));
    BOOST_CHECK_EQUAL(d1->rentDuration(),0);
    d1->endRentDate(); // zakonczenie wyporzyczenia
    BOOST_CHECK_EQUAL(d1->rentDuration(),1);
    BOOST_CHECK_THROW(RentDateTime(40), std::logic_error);
    BOOST_CHECK_EQUAL(d1->currentRentDuration(),1);
}

BOOST_AUTO_TEST_CASE(RentTest) {
    rentDateTime d1(new RentDateTime(20));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",NULL,a2));
    vehicle_ptr c1(new Car("A",10,"123",10));
    rent_ptr r1(new Rent(k1,c1,d1));
    BOOST_CHECK_EQUAL(r1->countRentPrice(),0.0);//cena przed zwroceniem
    BOOST_CHECK_EQUAL(r1->rentEndDate(),0);//ile trwalo wyporzyczenie przed zakonczeniem zawsze 0
    BOOST_CHECK_EQUAL(k1->getRents().size(),1);
    BOOST_CHECK_EQUAL(r1->countRentPrice(),0);// cena przed oddaniem vehicle
    r1->returnVehicle();
    BOOST_CHECK_EQUAL(r1->countRentPrice(),20);//cena po oddaniu
    BOOST_CHECK_EQUAL(k1->getRents().size(),0);//czy client ma wyporzyczenie po oddaniu
    BOOST_CHECK_EQUAL(r1->rentEndDate(),1);//ilosc dni wyporzyczenia
}

BOOST_AUTO_TEST_SUITE_END()