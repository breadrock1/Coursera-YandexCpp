#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;

    explicit Specialization(const string& init_spec) {
        value = init_spec;
    }
};

struct Course {
    string value;

    explicit Course(const string& init_course) {
        value = init_course;
    }
};

struct Week {
    string value;

    explicit Week(const string& init_week) {
        value = init_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(const Specialization& init_spec, const Course& init_course, const Week& init_week) {
        specialization = init_spec.value;
        course = init_course.value;
        week = init_week.value;
    }
};
