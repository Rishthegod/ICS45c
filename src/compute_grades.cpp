#include "compute_grades.hpp"
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

void Student::validate() const {
    for (const auto& score : quiz) {
        if (score < 0 || score > 100)
            throw std::domain_error("Error: invalid percentage " + std::to_string(score));
    }
    for (const auto& score : hw) {
        if (score < 0 || score > 100)
            throw std::domain_error("Error: invalid percentage " + std::to_string(score));
    }
    if (final_score < 0 || final_score > 100)
        throw std::domain_error("Error: invalid percentage " + std::to_string(final_score));
}

void Student::compute_quiz_avg() {
    std::ranges::sort(quiz);
    //auto minimum = quiz.begin()
    if (quiz.size() > 1) {
        //quiz.erase(quiz.begin());
        quiz_avg = std::accumulate(quiz.begin()+1, quiz.end(), 0.0) / quiz.size();
    }
    else if(quiz.size() == 0){
        quiz_avg = 0.0;
    }
    else{
        quiz_avg = std::accumulate(quiz.begin(), quiz.end(), 0.0) / quiz.size();
    }
    
    //quiz.insert(minimum);
}

void Student::compute_hw_avg() {
    if (hw.size() == 0) {
        hw_avg = 0.0;
        
    }
    else{
        
    hw_avg = std::accumulate(hw.begin(), hw.end(), 0.0) / hw.size();}
}

void Student::compute_course_score() {
    compute_quiz_avg();
    compute_hw_avg();

    double total = 0.4 * quiz_avg + 0.3 * hw_avg + 0.3 * final_score;
    //course_score = static_cast<int>(std::round(total));
    course_score = static_cast<int>(total);
}

/*void Student::compute_letter_grade() {
    static const std::vector<std::pair<int, std::string>> grade_boundaries = {
        {97, "A+"}, {93, "A"}, {90, "A-"},
        {87, "B+"}, {83, "B"}, {80, "B-"},
        {77, "C+"}, {73, "C"}, {70, "C-"},
        {67, "D+"}, {63, "D"}, {60, "D-"},
        {0, "F"}
    };

    for (const auto& [min_score, grade] : grade_boundaries) {
        if (course_score >= min_score) {
            course_grade = grade;
            break;
        }
    }
}*/

void Student::compute_grade() {
    compute_course_score();
    //compute_letter_grade();
    static const std::vector<std::pair<int, std::string>> grade_boundaries = {
        {97, "A+"}, {93, "A"}, {90, "A-"},
        {87, "B+"}, {83, "B"}, {80, "B-"},
        {77, "C+"}, {73, "C"}, {70, "C-"},
        {67, "D+"}, {63, "D"}, {60, "D-"},
        {0, "F"}
    };

    for (const auto& [min_score, grade] : grade_boundaries) {
        if (course_score >= min_score) {
            course_grade = grade;
            break;
        }
    }
}

std::strong_ordering Student::operator<=>(const Student& other) const {
    if(last_name == other.last_name){
        return first_name <=> other.first_name;
    }
    return last_name <=> other.last_name;
}
bool Student::operator==(const Student& other) const {
    if(last_name == other.last_name && first_name == other.first_name){
        return true;
    }
    return false;
}

std::istream& operator>>(std::istream& in, Student& s) {
    std::string line, keyword;

    while (std::getline(in, line)) {
        if (line.empty()) break;

        std::istringstream iss(line);
        iss >> keyword;

        if (keyword == "Name") {
            s.last_name = "";
            iss >> s.first_name;
            std::string name_part;
            while (iss >> name_part) {
                if (!s.last_name.empty()){ s.last_name += " ";}
                s.last_name += name_part;
            }
        } else if (keyword == "Quiz") {
            s.quiz.clear();
            std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(s.quiz));
        } else if (keyword == "HW") {
            s.hw.clear();
            std::copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(s.hw));
        } else if (keyword == "Final") {
            iss >> s.final_score;
        }
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Name:   " << s.first_name << " " << s.last_name << "\n"
        << "HW Ave: " << static_cast<int>(s.hw_avg) << "\n"
        << "QZ Ave: " << static_cast<int>(s.quiz_avg) << "\n"
        << "Final:  " << static_cast<int>(s.final_score) << "\n"
        << "Total:  " << s.course_score << "\n"
        << "Grade:  " << s.course_grade << "\n";

    return out;
}

void Gradebook::compute_grades() {
    for (auto& student : students) {
        student.compute_grade();
    }
}

void Gradebook::sort() {
    std::ranges::sort(students);
}

void Gradebook::validate() const {
    for (const auto& student : students) {
        student.validate();
    }
}

std::istream& operator>>(std::istream& in, Gradebook& b) {
    //Student s;
    copy(std::istream_iterator<Student>(in), std::istream_iterator<Student>(), back_inserter(b.students));
    /*while (in >> s) {
        b.students.push_back(s);
    }*/
    return in;
}

std::ostream& operator<<(std::ostream& out, const Gradebook& b) {
    copy(b.students.begin(), b.students.end(), std::ostream_iterator<Student>(out, "\n"));
    //copy(b.students.begin(), b.students.end(), std::ostream_iterator(out));
    /*for (const auto& student : b.students) {
        out << student;
    }*/
    return out;
}

