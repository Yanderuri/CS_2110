// DO NOT MODIFY THE INCLUDE(S) LIST
#include <stdio.h>
#include "oh_queue.h"

struct Queue oh_queue;


void nullify_student(struct Student* student);

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
    student_to_be_added.queue_number = oh_queue.stats.no_of_people_in_queue;
    hash(student_to_be_added.customID, student_to_be_added.studentData.name, pub_key);
    oh_queue.students[student_to_be_added.queue_number] = student_to_be_added;
    oh_queue.stats.no_of_people_in_queue+=1;
    OfficeHoursStatus(&oh_queue.stats);
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
        i++;
    }
    // nullify the last element in the queue
    nullify_student(&oh_queue.students[i]);

    oh_queue.stats.no_of_people_in_queue -= 1;
    oh_queue.stats.no_of_people_visited += 1;
    OfficeHoursStatus(&oh_queue.stats);
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
    // iterate through queue, if topic matches, add student to grouped
    // return the number of students matched
    short i = 0;
    short j = 0;
    while (i < oh_queue.stats.no_of_people_in_queue){
        if (oh_queue.students[i].studentData.topic.topicName == topic.topicName){
            grouped[j] = &oh_queue.students[i];
            j++;
        }
        i++;
    }
    return j;
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
    // iterate through queue, if customID matches, update topic
    short i = 0;
    while(i < oh_queue.stats.no_of_people_in_queue){
        if (*oh_queue.students[i].customID == *customID){
            oh_queue.students[i].studentData.topic = newTopic;
            return SUCCESS;
        }
        i++;
    }
    return FAILURE;
}

/** remove_student_by_name
 * @brief Removes first instance of a student with the given name
 * @param name the name you are searching for
 * @return FAILURE if no student is matched, SUCCESS otherwise
 */
int remove_student_by_name(char *name){
    short i = 0;
    while (i < oh_queue.stats.no_of_people_in_queue){
        if (my_strncmp(oh_queue.students[i].studentData.name, name, my_strlen(name)) == 0){
            short j = i;
            while (j < oh_queue.stats.no_of_people_in_queue-1){ 
                oh_queue.students[j] = oh_queue.students[j+1];
                j++;
            }
            // j was the last element in the queue, so we need to nullify it.
            nullify_student(&oh_queue.students[j]);
            oh_queue.stats.no_of_people_in_queue -= 1;
            oh_queue.stats.no_of_people_visited += 1;   
            OfficeHoursStatus(&oh_queue.stats);
            return SUCCESS;
        }
        i++;
    }
    return FAILURE;
}

/** remove_student_by_topic
 * @brief Remove all instances of students with the given topic
 * @param topic the topic you are trying to remove from the queue
 * @return FAILURE if no student is matched, SUCCESS otherwise
 */
int remove_student_by_topic(struct Topic topic) {
    //create a struct student array
    //call group_by_topic and store the number of students in the array
    //iterate through the array and call remove_student_by_name
    struct Student *grouped[MAX_QUEUE_LENGTH];
    short students_removed = 0;
    short i = 0;
    short no_of_students = group_by_topic(topic, grouped);
    while (i < no_of_students){
        if (remove_student_by_name(grouped[i]->studentData.name) == SUCCESS){
            students_removed++;
        }
        i++;
    }
    if (students_removed == 0){
        return FAILURE;
    }
    return SUCCESS;
}

/** OfficeHoursStatus
 * @brief Updates the "currentStatus" field based on
 * whether or not all students in the queue have been helped
 * @param resultStats A pointer the OfficeHoursStats variable
 * you are to update
 */
void OfficeHoursStatus(struct OfficeHoursStats* resultStats){
    if (oh_queue.stats.no_of_people_in_queue == 0){
        resultStats->currentStatus = "Completed";
    }
    if (oh_queue.stats.no_of_people_in_queue > 0){
        resultStats->currentStatus = "InProgress";
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
/*
Short function to nullify the student struct from the pointer
*/
void nullify_student(struct Student* student){
    short i = 0;
    while (i < MAX_NAME_LENGTH){
        student->studentData.name[i] = 0;
        i++;
    }
    student->studentData.topic.topicName = Other;
    student->studentData.topic.questionNumber = 0;
    student->queue_number = 0;
    i = 0;
    while (i < 30){
        student->customID[i] = 0;
        i++;
    }
}