//#include <iostream>
//#include <fstream>
//#include <pthread.h>
//
//using namespace std;
//
//int Sender_balance = 50000, Reciever_Balance = 20000, Input = 0; 
//pthread_mutex_t Sender_lock, Reciever_lock;
//
//
//void* Deduction_of_balance_of_sender(void*) {
//
//    pthread_mutex_lock(&Sender_lock);
//
//    cout << "Enter the amount you want to transfer: ";
//
//    cin >> Input;cout << endl;
//
//    Sender_balance -= Input;
//
//    pthread_mutex_unlock(&Sender_lock);
//
//    return NULL;
//}
//
//void* Addition_of_balance_to_Reciever(void*) {
//    
//    int transferAmount;
//    
//    pthread_mutex_lock(&Sender_lock);
//    
//    transferAmount = Input;
//    
//    pthread_mutex_unlock(&Sender_lock);
//
//    pthread_mutex_lock(&Reciever_lock);
//
//    Reciever_Balance += transferAmount;
//
//    pthread_mutex_unlock(&Reciever_lock);
//
//    return NULL;
//}
//
//void* Fee(void*) {
//
//    pthread_mutex_lock(&Sender_lock);
//
//    int transactionFees = 70;
//
//    Sender_balance -= transactionFees;
//
//    pthread_mutex_unlock(&Sender_lock);
//
//    return NULL;
//}
//
//void* History_updation(void*) {
//
//    pthread_mutex_lock(&Sender_lock);
//
//    pthread_mutex_lock(&Reciever_lock);
//
//
//    ofstream transactionFile("HISTORY.txt", ios::app);
//
//    if (transactionFile.is_open()) {
//
//        transactionFile << "Transfer from Sender to Reciever : " << Input << " $\n";
//
//        transactionFile.close();
//
//    } else {
//
//        cout << "Error opening transaction history file." << endl;
//
//    }
//
//    pthread_mutex_unlock(&Reciever_lock);
//
//    pthread_mutex_unlock(&Sender_lock);
//
//    return NULL;
//}
//
//void* sendEmailNotifications(void*) {
//
//    cout<<"NOTIFICATION SENT!!!"<<endl;
//
//    return NULL;
//}
//
//int main() {
//
//    pthread_t thread1, thread2, thread3, thread4, thread5;
//
//    pthread_create(&thread1, NULL, Deduction_of_balance_of_sender, NULL);
//
//    pthread_create(&thread2, NULL, Addition_of_balance_to_Reciever, NULL);
//
//    pthread_create(&thread3, NULL, Fee, NULL);
//
//    pthread_create(&thread4, NULL, History_updation, NULL);
//
//    pthread_join(thread1, NULL);
//
//    pthread_join(thread2, NULL);
//
//    pthread_join(thread3, NULL);
//
//    pthread_join(thread4, NULL);
//    
//
//    cout << "User's Account Balance: " << Sender_balance << endl;
//
//    cout << "Recipient's Account Balance: " << Reciever_Balance << endl;
//
//    pthread_create(&thread5, NULL, sendEmailNotifications, NULL);    
//
//    pthread_join(thread5, NULL);
//
//    return 0;
//}