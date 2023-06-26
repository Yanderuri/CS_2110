;;=============================================================
;; CS 2110 - Summer 2023
;; Homework 5 - palindrome
;;=============================================================
;; Name: Vy Mai
;;=============================================================

;;  NOTE: Let's decide to represent "true" as a 1 in memory and "false" as a 0 in memory.
;;
;;  Pseudocode (see PDF for explanation)
;;  Pseudocode values are based on the labels' default values.
;;
;;  String str = "racecar";
;;  boolean isPalindrome = true
;;  int length = 0;
;;  while (str[length] != '\0') {
;;		length++;
;;	}
;; 	
;;	int left = 0
;;  int right = length - 1
;;  while(left - right < 0) {
;;		if (str[left] != str[right]) {
;;			isPalindrome = false;
;;			break;
;;		}
;;		left++;
;;		right--;
;;	}
;;	mem[mem[ANSWERADDR]] = isPalindrome;

.orig x3000
	;; YOUR CODE HERE
	;; R2, R3 = str[left], str[right]
	AND R1, R1, #0
	ADD R1, R1, #-1


	COUNTER
	ADD R1, R1, #1
	LD R2, STRING
	ADD R2, R2, R1
	LDR R2, R2, #0
	BRz END0
	BRp COUNTER

	END0
	ST R1, LENGTH
	LD R1, LENGTH
	BRz TRUE
	BRn FALSE
	ADD R1, R1, #-1

	;; LOOP SET UP
	LD R0, STRING
	ST R0, LEFT_SAVE
	ADD R1, R0, R1
	ST R1, RIGHT_SAVE

	LOOP
	LD R0, LEFT_SAVE
	LDR R2, R0, #0
	LD R1, RIGHT_SAVE
	LDR R3, R1, #0
	NOT R3, R3
	ADD R3, R3, #1
	ADD R2, R2, R3
	BRnp FALSE

	ADD R0, R0, #1
	ST R0, LEFT_SAVE
	ADD R1, R1, #-1
	ST R1, RIGHT_SAVE

	ADD R0, R0, #-1
	ADD R1, R1, #1

	NOT R1, R1
	ADD R1, R1, #1

	ADD R1, R0, R1
	BRn LOOP
	;; END LOOP

	TRUE
	AND R0, R0, #0
	ADD R0, R0, #1
	STI R0, ANSWERADDR
	HALT
	
	FALSE
	AND R0, R0, #0
	STI R0, ANSWERADDR
	HALT


;; Do not change these values!
STRING	.fill x4004
ANSWERADDR 	.fill x5005
LENGTH .blkw 1
LEFT_SAVE .blkw 1
RIGHT_SAVE .blkw 1
.end

;; Do not change any of the .orig lines!
.orig x4004				   
	.stringz "racebar" ;; Feel free to change this string for debugging.
.end

.orig x5005
	ANSWER  .blkw 1
.end