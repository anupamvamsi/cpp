#include <iostream>
#include <vector>

class Person
{
protected:
    std::string first_name;
    std::string last_name;
    int id;

public:
    // Person() = default; ref: https://stackoverflow.com/questions/4981241/no-default-constructor-exists-for-class

    Person(std::string first_name, std::string last_name, int identification)
    {
        this->first_name = first_name;
        this->last_name = last_name;
        this->id = identification;
    }

    void PrintPerson()
    {
        std::cout << "Name: " << last_name << ", " << first_name << "\nID: " << id << "\n";
    }
};

class Student : public Person
{
private:
    std::vector<int> test_scores;

public:
    Student(std::string f_name, std::string l_name, int id_num, std::vector<int> t_scores)
        : Person(f_name, l_name, id_num), test_scores{t_scores} {}

    char Calculate()
    {
        int avg = 0;
        for (int score : test_scores)
        {
            avg += score;
        }
        avg /= test_scores.size();

        if (avg > 89 && avg < 101)
        {
            return 'O';
        }
        else if (avg > 79 && avg < 90)
        {
            return 'E';
        }
        else if (avg > 69 && avg < 80)
        {
            return 'A';
        }
        else if (avg > 54 && avg < 70)
        {
            return 'P';
        }
        else if (avg > 39 && avg < 55)
        {
            return 'D';
        }
        else if (avg < 40)
        {
            return 'T';
        }
        return 'Y';
    }
};

int main()
{
    std::string first_name;
    std::string last_name;
    int id;

    int num_scores;
    std::cin >> first_name >> last_name >> id >> num_scores;

    std::vector<int> scores;
    for (int i = 0; i < num_scores; i++)
    {
        int temp_score;
        std::cin >> temp_score;
        scores.push_back(temp_score);
    }

    Student *student_obj = new Student(first_name, last_name, id, scores);
    student_obj->PrintPerson();
    std::cout << "Grade: " << student_obj->Calculate() << "\n";

    return 0;
}