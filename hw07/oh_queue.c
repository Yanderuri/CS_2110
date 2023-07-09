// DO NOT MODIFY THE INCLUDE(S) LIST
#include <stdio.h>
#include "oh_queue.h"

struct Queue oh_queue;


/** enqueue
 * @brief Create a new student and enqueue him
 * onto the OH queue
 * @param studentName pointer to the student's name
 * @param topicName topic the student has a question on
 * @param questionNumber hw question number student has a question on
 * @param pub_key public key used for calculating the hash for customID
 * @return FAILURE if the queue is already at max length, SUCCESS otherwise
 */
int enqueue(const char *studentName, const enum subject topicName, const float questionNumber, struct public_key pub_key){
    if (studentName == NULL || *studentName == 0 || oh_queue.stats.no_of_people_in_queue == MAX_QUEUE_LENGTH){
        return FAILURE;
    }
    struct Student student_to_be_added;
    short i = 1;
    char *name = student_to_be_added.studentData.name;
    while(i < MAX_NAME_LENGTH && *studentName != 0){
        *name = *studentName;
        name += sizeof(char);
        studentName += sizeof(char);
        i++;
    }
    *name = 0;
    student_to_be_added.studentData.topic.topicName = topicName;
    student_to_be_added.studentData.topic.questionNumber = questionNumber;
    OfficeHoursStatus(oh_queue.stats.currentStatus);
    student_to_be_added.queue_number = oh_queue.stats.no_of_people_in_queue;
    hash(student_to_be_added.customID, student_to_be_added.studentData.name, pub_key);
    oh_queue.students[student_to_be_added.queue_number] = student_to_be_added;
    oh_queue.stats.no_of_people_visited+=1;
    oh_queue.stats.no_of_people_in_queue+=1;
    return SUCCESS;
}

/** dequeue
 * @brief remove a student out the OH queue
 * @return FAILURE if the queue is already at empty, SUCCESS otherwise
 */
int dequeue(void) {
    if (oh_queue.stats.no_of_people_in_queue == 0){
        return FAILURE;
    }
    // 1 writes into 0, 2 writes into 1, 3 writes into 2...30 writes into 29, null writes into 30.
    short i = 0;
    while (i < oh_queue.stats.no_of_people_in_queue-1){ // if there's 1 person in queue, this loop shouldn't run, and the element to be dequeue will be null.
        oh_queue.students[i] = oh_queue.students[i+1];
    }
    oh_queue.stats.no_of_people_in_queue--;
    OfficeHoursStatus(oh_queue.stats.currentStatus);
    return SUCCESS;
}

/** group_by_topic
 * @brief add pointers to students, who match the given topic, to
 * the given array "grouped"
 * @param topic the topic the students need to match
 * @param grouped an array of pointers to students
 * @return the number of students matched
 */
int group_by_topic(struct Topic topic, struct Student *grouped[]) { 
    UNUSED_PARAM(topic);
    UNUSED_PARAM(grouped);

    return 0;
}

/** hash
 * @brief Creates a hash based on pub_key provided
 * @param ciphertext the pointer where you will store the hashed text
 * @param plaintext the originak text you need to hash
 * @param pub_key public key used for calculating the hash
 */
void hash(int *ciphertext, char *plaintext, struct public_key pub_key) {
    char *start = plaintext;
    while(*start != 0){
        *ciphertext = power_and_mod(*start, pub_key.e, pub_key.n);
        start += sizeof(char);
        ciphertext += sizeof(char);
    }
    return;
}

/** update_student
 * @brief Find the student with the given ID and update his topic
 * @param customID a pointer to the id of the student you are trying to find
 * @param newTopic the new topic that should be assigned to him
 * @return FAILURE if no student is matched, SUCCESS otherwise
 */
int update_student(struct Topic newTopic, int *customID) {
    UNUSED_PARAM(newTopic);
    UNUSED_PARAM(customID);
    
    return SUCCESS;
}

/** remove_student_by_name
 * @brief Removes first instance of a student with the given name
 * @param name the name you are searching for
 * @return FAILURE if no student is matched, SUCCESS otherwise
 */
int remove_student_by_name(char *name){
    UNUSED_PARAM(name);

    return SUCCESS;
}

/** remove_student_by_topic
 * @brief Remove all instances of students with the given topic
 * @param topic the topic you are trying to remove from the queue
 * @return FAILURE if no student is matched, SUCCESS otherwise
 */
int remove_student_by_topic(struct Topic topic) {
    UNUSED_PARAM(topic);

    return SUCCESS;
}

/** OfficeHoursStatus
 * @brief Updates the "currentStatus" field based on
 * whether or not all students in the queue have been helped
 * @param resultStats A pointer the OfficeHoursStats variable
 * you are to update
 */
void OfficeHoursStatus(struct OfficeHoursStats* resultStats ){
    // enum status temp = oh_queue.stats.currentStatus;
    if (oh_queue.stats.no_of_people_in_queue != 0 && 
    my_strncmp(oh_queue.stats.no_of_people_in_queue, "C", 1) == 0){
        oh_queue.stats.currentStatus = "InProgress";
        return;
    }
    if (oh_queue.stats.no_of_people_in_queue == 0 && my_strncmp(oh_queue.stats.no_of_people_in_queue, "I", 1) == 0){
        oh_queue.stats.currentStatus = "Completed";
        return;
    }
}

/*
 * Calculates (b^e)%n without overflow
 */
int power_and_mod(int b, int e, int n) {
    long int currNum = 1;
    for (int i = 0; i < e; i++) {
        currNum *= b;
        if (currNum >= n) {
            currNum %= n;
        }
    }
    return (int) (currNum % n);
}
