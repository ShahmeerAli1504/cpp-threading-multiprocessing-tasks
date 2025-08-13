//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <sstream>
//#include <queue>
//#include <pthread.h>
//#include <string>
//#include <cmath>
//#include <bits/stdc++.h>
//using namespace std;
//
//const int S = 5000;  // constant for Unit 0
//const int M = 3;     // constant for Unit 2
//
//struct Task {
//    int task_id;
//    clock_t completion_time;
//    int unit_count;
//    vector<int> unit_ids;
//    vector<int> task_values;
//};
//
//queue<Task> waiting_queue;
//queue<Task> result_queue;
//pthread_mutex_t waiting_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
//pthread_mutex_t result_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
//
//void* reception_room(void* file_path_ptr) 
//{
//    char* file_path = (char*)file_path_ptr;
//    ifstream file(file_path);
//
//    if (file.is_open()) 
//    {
//        string line;
//        while (getline(file, line)) 
//        {
//            pthread_mutex_lock(&waiting_queue_mutex);
//
//            Task task;
//            istringstream iss(line);
//            iss >> task.task_id >> task.unit_count;
//
//            task.task_values.resize(task.unit_count);
//            for (int i = 0; i < task.unit_count; ++i) 
//            {
//                iss >> task.task_values[i];
//            }
//            task.completion_time = clock();
//            waiting_queue.push(task);
//            pthread_mutex_unlock(&waiting_queue_mutex);
//        }
//
//        file.close();
//    }
//    else
//    {
//        cout << "Error opening file" << std::endl;
//    }
//
//    pthread_exit(NULL);
//}
//
//void* unit0(void* args)
//{
//    Task* task = (Task*)args;
//    task->task_values[4] = (task->task_values[4]+5)%S;
//    task->unit_ids.push_back(1);
//    pthread_exit(NULL);
//}
//void* unit1(void* args)
//{
//    Task* task = (Task*)args;
//    task->task_values[1] = (task->task_values[1]*7)%S;
//    task->unit_ids.push_back(1);
//    pthread_exit(NULL);
//}
//void* unit2(void* args)
//{
//    Task* task = (Task*)args;
//    task->task_values[2] = (int)(pow(task->task_values[2],5))%M;
//    task->unit_ids.push_back(2);
//    pthread_exit(NULL);
//}
//void* unit3(void* args)
//{
//    Task* task = (Task*)args;
//    task->task_values[3] = task->task_values[3]-100;
//    task->unit_ids.push_back(3);
//    pthread_exit(NULL);
//}
//void* unit4(void* args)
//{
//    Task* task = (Task*)args;
//    task->task_values[4] = (pow(task->task_values[4],2));
//    task->unit_ids.push_back(4);
//    pthread_exit(NULL);
//}
//
//void* dispatcher_room(void*) 
//{
//    while (true) 
//    {
//        pthread_mutex_lock(&waiting_queue_mutex);
//
//        if (!waiting_queue.empty()) 
//        {
//            Task task = waiting_queue.front();
//            waiting_queue.pop();
//            task.completion_time = clock() - task.completion_time;
//            pthread_mutex_unlock(&waiting_queue_mutex);
//            
//            pthread_t unit_thread[task.unit_count];
//            if(task.unit_count == 1)
//            {
//                pthread_create(&unit_thread[0],NULL,unit0, (void*)&task);
//            }
//            else if(task.unit_count == 2)
//            {
//                pthread_create(&unit_thread[0],NULL,unit0, (void*)&task);
//                pthread_create(&unit_thread[1],NULL,unit1, (void*)&task);
//            }
//            else if(task.unit_count == 3)
//            {
//                pthread_create(&unit_thread[0],NULL,unit0, (void*)&task);
//                pthread_create(&unit_thread[1],NULL,unit1, (void*)&task);
//                pthread_create(&unit_thread[2],NULL,unit2, (void*)&task);
//            }
//            else if(task.unit_count == 4)
//            {
//                pthread_create(&unit_thread[0],NULL,unit0, (void*)&task);
//                pthread_create(&unit_thread[1],NULL,unit1, (void*)&task);
//                pthread_create(&unit_thread[2],NULL,unit2, (void*)&task);
//                pthread_create(&unit_thread[3],NULL,unit3, (void*)&task);
//            }
//            else if(task.unit_count == 5)
//            {
//                pthread_create(&unit_thread[0],NULL,unit0, (void*)&task);
//                pthread_create(&unit_thread[1],NULL,unit1, (void*)&task);
//                pthread_create(&unit_thread[2],NULL,unit2, (void*)&task);
//                pthread_create(&unit_thread[3],NULL,unit3, (void*)&task);
//                pthread_create(&unit_thread[4],NULL,unit4, (void*)&task);
//            }
//
//            for (int i = 0; i < task.unit_count; ++i)
//            {
//                pthread_join(unit_thread[i], NULL);
//            }
//
//            result_queue.push(task);
//        }
//        else 
//        {
//            pthread_mutex_unlock(&waiting_queue_mutex);
//            break;
//        }
//    }
//
//    pthread_exit(NULL);
//}
//
//void* print_room(void* file_path_ptr) {
//    char* file_path = (char*)file_path_ptr;
//    ofstream outfile(file_path);
//
//    if (outfile.is_open()) 
//    {
//        while (true) 
//        {
//            pthread_mutex_lock(&result_queue_mutex);
//
//            if (!result_queue.empty()) 
//            {
//                Task result = result_queue.front();
//                result_queue.pop();
//
//                pthread_mutex_unlock(&result_queue_mutex);
//
//                outfile << result.task_id << " " << (double)result.completion_time << " ";
//
//                for (int i = 0; i < result.unit_count; ++i) 
//                {
//                    outfile << result.unit_ids[i] << ",";
//                }
//
//                for (int i = 0; i < result.unit_count; ++i)
//                {
//                    outfile << result.task_values[i] << " ";
//                }
//                outfile << "\n";
//            }
//            else
//            {
//                pthread_mutex_unlock(&result_queue_mutex);
//            }
//        }
//
//        outfile.close();
//    }
//    else
//    {
//        cout << "Error opening file " << file_path << " for writing." << std::endl;
//    }
//
//    pthread_exit(NULL);
//}
//
//int main() {
//    pthread_t reception_thread, dispatcher_thread, print_thread;
//
//    char* file_path = "tasks.txt";
//    char* output_file_path = "output.txt";
//
//    pthread_create(&reception_thread, NULL, reception_room, (void*)file_path);
//    pthread_create(&dispatcher_thread, NULL, dispatcher_room, NULL);
//    pthread_create(&print_thread, NULL, print_room, (void*)output_file_path);
//
//    pthread_join(reception_thread, NULL);
//    pthread_join(dispatcher_thread, NULL);
//
//    pthread_join(print_thread, NULL);
//
//    return 0;
//}
