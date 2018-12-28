//
// Created by pobi on 25.12.18.
//

#ifndef POBIPROJECT_RENTDATETIME_H
#define POBIPROJECT_RENTDATETIME_H

#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <string>
#include <memory>

typedef boost::local_time::local_date_time LocalTime;
typedef boost::local_time::time_zone_ptr TZone;
typedef boost::posix_time::ptime PTime;

class RentDateTime {

    int endPublic; //koniec renty podany jawnie;
    TZone timeZone{new boost::local_time::posix_time_zone("CET+1")};
    LocalTime begin = LocalTime(PTime(), TZone());
    LocalTime end = LocalTime(PTime(), TZone());

public:

    RentDateTime(int endPublic);
    ~RentDateTime() = default;
    int rentDuration();
    void endRentDate();
    LocalTime getBegin();
    int getEndPublic();
    int currentRentDuration(); //ile dni minelo od rozpoczecia

};

typedef  std::shared_ptr<RentDateTime> rentDateTime;

#endif //POBIPROJECT_RENTDATETIME_H
