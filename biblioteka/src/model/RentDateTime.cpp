//
// Created by pobi on 25.12.18.
//

#include "model/RentDateTime.h"
#include "boost/date_time/gregorian/gregorian.hpp"
#include <sstream>
#include <model/RentDateTime.h>

#include "model/DateExp.h"


RentDateTime::RentDateTime(int endPublic) : endPublic(endPublic), begin(boost::local_time::local_sec_clock::local_time(timeZone)){
    if(endPublic > 30) throw DateExp("max 30");
}


int RentDateTime::rentDuration(){
    if(end.is_not_a_date_time()) return 0;
    if(end.date() < begin.date()) throw DateExp("end date < begin date");
    return (end.date()-begin.date()).days()+1;
}

void RentDateTime::endRentDate(){
    end = boost::local_time::local_sec_clock::local_time(timeZone);
}

LocalTime RentDateTime::getBegin(){
    return begin;
}

int RentDateTime::getEndPublic() {
    return endPublic;
}

int RentDateTime::currentRentDuration() {

    LocalTime a = boost::local_time::local_sec_clock::local_time(timeZone);
    LocalTime b = getBegin();
    if((a.date()-b.date()).days() == 0) return 1;
    else return (int)(a.date()-b.date()).days();
}
