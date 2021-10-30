#pragma once
#include <string>
#include <iostream>

struct Date {
	int year;
	int month;
	int day;
	int hour;
	int minute;

	Date(int year, int month, int day, int hour, int minutes ) {
		this->year = year;
		this->month = month;
		this->day = day;
		this->hour = hour;
		this->minute = minute;
	}

	Date(){}

	std::string write() const {
		return static_cast<std::string>( std::to_string(year) + '.' + std::to_string(month)+ '.' 
			+ std::to_string(day) + ' ' + std::to_string(hour) + ':' + std::to_string(minute) );
	}
};

struct File {
	std::string name;
	std::string extension;
	Date date;
	bool is_file;
	std::vector<File> files;

	std::string write() const {
		std::string result;

		result = static_cast<std::string>(name + '.' + extension + ' ' + date.write());

		return result;
	}
};