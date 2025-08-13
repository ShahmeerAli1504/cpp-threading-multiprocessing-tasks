//#include <iostream>
//#include <fstream>
//#include <pthread.h>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//class Student {
//public:
//    string name;
//    int roll_number;
//    string main_course;
//    int grade;
//
//    Student() {
//        name = "\0";
//        roll_number = 0;
//        main_course = "\0";
//        grade = 0;
//    }
//
//    Student(string abc, int R, string cs, int W) {
//        name = abc;
//        roll_number = R;
//        main_course = cs;
//        grade = W;
//    }
//    static void Counseling_Needed(Student* Std, int num, int Limit, pthread_mutex_t* lock) {
//        pthread_mutex_lock(lock);
//
//        cout << "Students needing counseling (grade below " << Limit << "):" << endl;
//
//        bool* different = new bool[num]();
//
//        int i = 0;
//
//        while (i < num) {
//            if (Std[i].grade < Limit && !different[i]) {
//                cout << "Student name : " << Std[i].name << ", Grade obtained: " << Std[i].grade << endl;
//                different[i] = true;
//            }
//
//            ++i;
//        }
//
//        pthread_mutex_unlock(lock);
//    }
//
//    static double AVGgrade(Student* Std, int num, pthread_mutex_t* lock) {
//        pthread_mutex_lock(lock);
//
//        int total_grade = 0;
//        int i = 0;
//
//        while (i < num) {
//            total_grade += Std[i].grade;
//            ++i;
//        }
//
//        pthread_mutex_unlock(lock);
//
//        return static_cast<double>(total_grade) / num;
//    }
//
//    static void Sort(Student* Std, int num, pthread_mutex_t* lock) {
//        pthread_mutex_lock(lock);
//
//        int i = 0;
//
//        while (i < num - 1) {
//            int j = 0;
//
//            while (j < num - i - 1) {
//                if (Std[j].grade < Std[j + 1].grade) {
//                    swap(Std[j], Std[j + 1]);
//                }
//
//                ++j;
//            }
//
//            ++i;
//        }
//
//        pthread_mutex_unlock(lock);
//
//        cout << "\nStudents sorted by grade :\n" << endl;
//
//        int k = 0;
//
//        while (k < num) {
//            cout << "Student name : " << Std[k].name << ", Grade obtainded: " << Std[k].grade << endl;
//            ++k;
//        }
//    }
//};
//
//void Writing_Student_Data() {
//    
//    srand(time(0));
//
//    int numStudents = 100;
//    
//    Student* students = new Student[numStudents];
//
//    for (int i = 0; i < numStudents; ++i) {
//    
//        students[i] = Student("Student" + to_string(i + 1),1000 + i,"Course" + to_string(i % 5 + 1),rand() % 100 + 1);
//    }
//
//    ofstream outputFile("student_data.txt");
//
//    if (outputFile.is_open()) {
//        for (int i = 0; i < numStudents; ++i) {
//            outputFile << students[i].name << " "<< students[i].roll_number << " "<< students[i].main_course << " "<< students[i].grade << endl;
//        }
//
//        outputFile.close();
//    } else {
//        cout << "Error opening output file." << endl;
//        return;
//    }
//
//}
//
//void Reading_Student_Data(Student* students, int num) {
//    ifstream inputFile("student_data.txt");
//
//    if (inputFile.is_open()) {
//    
//        for (int i = 0; i < num; ++i) {
//    
//            inputFile >> students[i].name >> students[i].roll_number >> students[i].main_course >> students[i].grade;
//    
//        }
//
//        inputFile.close();
//    
//    }
//    else
//    {
//        cout << "Error opening input file." << endl;
//        return ;
//    }
//}
//
//void* TSort(void* arg)
// {
// 
//    Student* students = static_cast<Student*>(arg);
// 
//    pthread_mutex_t* lock = static_cast<pthread_mutex_t*>(arg);
//
//    Student::Sort(students, 100, lock);
//
//    pthread_exit(NULL);
//
//}
//
//void* TAVGgrade(void* arg) 
//{
//    Student* students = static_cast<Student*>(arg);
//    
//    pthread_mutex_t* lock = static_cast<pthread_mutex_t*>(arg);
//
//    double avg = Student::AVGgrade(students, 100, lock);
//
//    cout << "Average Grade: " << avg << endl;
//
//    pthread_exit(NULL);
//
//}
//
//void* TCounseling(void* arg) 
//{
//
//    Student* students = static_cast<Student*>(arg);
//
//    pthread_mutex_t* lock = static_cast<pthread_mutex_t*>(arg);
//
//    Student::Counseling_Needed(students, 100, 60, lock);
//
//    pthread_exit(NULL);
//
//}
//
//int main() {
//    pthread_t thread1, thread2, thread3;
////    pthread_mutex_t lock;//  pthread_mutex_init(&lock, NULL);
//
//    Student* students = new Student[100];
//
//    Writing_Student_Data();
//
//    Reading_Student_Data(students, 100);
//
//    pthread_create(&thread1, NULL, TAVGgrade, students);
//
//    pthread_create(&thread2, NULL, TCounseling, students);
//
//    pthread_create(&thread3, NULL, TSort, students);
//
//    pthread_join(thread1, NULL);
//
//    pthread_join(thread2, NULL);
//
//    pthread_join(thread3, NULL);
//
////    pthread_mutex_destroy(&lock);
//
//    return 0;
//}
