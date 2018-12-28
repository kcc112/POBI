cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES include/Client/Client.h src/Client/Client.cpp include/Exceptions/ClientExp src/Exceptions/ClientExp.cpp include/Address/Address.h src/Address/Address.cpp src/Exceptions/AddressExp.cpp include/Exceptions/AddressExp.h src/Vehicle/Vehicle.cpp include/Vehicle/Vehicle.h src/Exceptions/VehicleExp.cpp include/Exceptions/VehicleExp.h src/Rent/Rent.cpp include/Rent/Rent.h src/Date/RentDateTime.cpp include/Date/RentDateTime.h src/Exceptions/DateExp.cpp include/Exceptions/DateExp.h src/Exceptions/RentExp.cpp include/Exceptions/RentExp.h src/Vehicle/MotorVehicle.cpp include/Vehicle/MotorVehicle.h src/Vehicle/Car.cpp include/Vehicle/Car.h src/Vehicle/Moped.cpp include/Vehicle/Moped.h src/Vehicle/Bicycle.cpp include/Vehicle/Bicycle.h src/Repository/CurrentRentsRepository.cpp include/Repository/CurrentRentsRepository.h src/Exceptions/RepositoryExp.cpp include/Exceptions/RepositoryExp.h src/Repository/VehicleRepository.cpp include/Repository/VehicleRepository.h include/Client/ClientType.h src/Client/ClientSilver.cpp include/Client/ClientSilver.h src/Client/ClientGold.cpp include/Client/ClientGold.h include/Client/ClientTypes.h src/Repository/ClientRepository.cpp include/Repository/ClientRepository.h)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_HUMAN_FILES
        test/master.cpp
        test/RentTest.cpp)

add_executable (TestRent ${SOURCE_TEST_HUMAN_FILES})

target_link_libraries (TestRent
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestRent. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(TestBiblioteki1 TestRent
        --report_level=detailed
        --log_level=all
        --color_output=yes
        --show_progress=true
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})