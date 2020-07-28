#include <iostream>
#include <string>
#include <stdexcept>
#include "phone_number.h"

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
    if (international_number.substr(0,1) != "+")
        throw invalid_argument("");

    int Switch = 0;
    for (size_t i = 0; i < international_number.size(); ++i) {
        if (international_number[i] == '-') {
            Switch++;
        }
        switch (Switch) {
            case 0:
                country_code_ += international_number[i];
                break;
            case 1:
                city_code_ += international_number[i];
                break;
            case 2:
                local_number_ += international_number[i];
                break;
            default:
                local_number_ += international_number[i];
        }
    }

    country_code_.erase(0,1 ); city_code_.erase(0,1 ); local_number_.erase(0,1 );

    if (country_code_.empty() || city_code_.empty() || local_number_.empty())
        throw invalid_argument("");
}

string PhoneNumber::GetCountryCode() const { return country_code_; }
string PhoneNumber::GetCityCode() const { return city_code_; }
string PhoneNumber::GetLocalNumber() const { return  local_number_; }
string PhoneNumber::GetInternationalNumber() const { return "+" + country_code_ + "-" + city_code_ + "-" + local_number_; }
