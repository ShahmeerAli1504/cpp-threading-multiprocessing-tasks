//#include <iostream>
//#include <pthread.h>
//#include <semaphore.h>
//#include <unistd.h>
//using namespace std;
//
//const int table_numbers = 5;const int seats_on_each_table = 5;const int total_number_of_philosophers = table_numbers * seats_on_each_table;
//
//sem_t semophore[table_numbers][seats_on_each_table];
//pthread_mutex_t Lock;
//
//void* PHILOSOPHERS(void* arg) {
//    int ID = *(int*)arg;
//    int TID = ID / seats_on_each_table; // Table ID
//    int SID = ID % seats_on_each_table; // seat ID
//
//    while (true) {
//        // Thinking
//        cout << "PHILOSOPHERS at Table " << TID + 1<< ", Seat " << SID + 1 << " is thinking." << endl;
//
//        // left fork
//        sem_wait(&semophore[TID][SID]);
//        cout << "PHILOSOPHERS at Table " << TID + 1<< ", Seat " << SID + 1 << " picked up left fork." << endl;
//
//        // right fork
//        sem_wait(&semophore[TID][(SID + 1) % seats_on_each_table]);
//        cout << "PHILOSOPHERS at Table " << TID + 1<< ", Seat " << (SID + 1) % seats_on_each_table + 1<< " picked up right fork." << endl;
//
//        // KAHANA I mean eating 
//        cout << "PHILOSOPHERS at Table " << TID + 1<< ", Seat " << SID + 1 << " is eating." << endl;
//
//        sem_post(&semophore[TID][SID]);
//        sem_post(&semophore[TID][(SID + 1) % seats_on_each_table]);
//
//        // Simulate thinking and eating time
//        usleep(2000000); // 2 seconds
//    }
//}
//
//int main() {
//    pthread_t Philososphers[total_number_of_philosophers];
//    int PID[total_number_of_philosophers]; // philosopher ID
//
//    int i = 0;
//    while (i < table_numbers) {
//        int j = 0;
//        while (j < seats_on_each_table) {
//            sem_init(&semophore[i][j], 0, 1);
//            ++j;
//        }
//        ++i;
//    }
//
//    i = 0;
//    while (i < total_number_of_philosophers) {
//        PID[i] = i;
//        pthread_create(&Philososphers[i], NULL, PHILOSOPHERS, (void*)&PID[i]);
//        ++i;
//    }
//
//    // Let the simulation run for a while
//    usleep(10000000); // 10 seconds
//
//    //for (int i = 0; i < total_number_of_philosophers; ++i) {
//    //    pthread_cancel(Philososphers[i]);
//    //}
//
//    //for (int i = 0; i < table_numbers; ++i) {
//     //   for (int j = 0; j < seats_on_each_table; ++j) {
//    //        sem_destroy(&semophore[i][j]);
//  //      }
////    }
//
//    return 0;
//}
