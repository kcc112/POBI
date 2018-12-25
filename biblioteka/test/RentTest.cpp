#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

BOOST_AUTO_TEST_CASE(ClientTest) {

    address_ptr a1(new Address(7,"Macieja"));
    address_ptr a2(new Address(8,"Macieja2"));
    client_ptr k1(new Client("Kamil","Celejewski","123",a1,a2));

    BOOST_CHECK_EQUAL(k1->getFirstName(),"Kamil");
    BOOST_CHECK_EQUAL(k1->getPersonalID(),"123");
    BOOST_CHECK_EQUAL(k1->getLastName(),"Celejewski");
    BOOST_CHECK_THROW(Client("","Celejewski","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","","123",a1,a2), std::logic_error);
    BOOST_CHECK_THROW(Client("Kamil","Celejewski","",a1,a2), std::logic_error);
}

BOOST_AUTO_TEST_CASE(AddressTest) {

    address_ptr a1(new Address(7, "Mariana"));

    BOOST_CHECK_EQUAL(a1->getAddressNumber(),7);
    BOOST_CHECK_EQUAL(a1->getStreetName(),"Mariana");
    BOOST_CHECK_THROW(Address( 0,"Mariana"), std::logic_error);
    BOOST_CHECK_THROW(Address(10,""), std::logic_error);
}

BOOST_AUTO_TEST_SUITE_END()