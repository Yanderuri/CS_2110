;;=============================================================
;; CS 2110 - Summer 2023
;; Homework 5 - buildMinArray
;;=============================================================
;; Name: 
;;=============================================================

;;  Pseudocode (see PDF for explanation)
;;  Pseudocode values are based on the labels' default values.
;;
;;	int A[] = {-4, 6, 0};
;;	int B[] = {1, 5, 2};
;;	int C[3];
; int i = 0;
; int length = 2;
; while(length + 1 > 0){
;     if (A[length] <= B[length]){
;         C[i] = 1;
;     }
;     else{
;         C[i] = 0;
;     }
;     length--;
;     i++;
; }


.orig x3000
	;; YOUR CODE HERE
	LD R0, LENGTH 	;; int length = 3
	ADD R0, R0, #-1; ;; int length = 2;
	AND R1, R1, #0	;; int i = 0;

	LOOP
	LEA R2, A
	LDR R2, R2, #0
	ADD R2, R2, R0
	LDR R2, R2, #0

	LEA R3, B
	LDR R3, R3, #0
	ADD R3, R3, R0
	LDR R3, R3, #0

	;; A[i] and B[i]decoded
	NOT R3, R3
	ADD R3, R3, x0001 	;; R3 <-- negative B[length]

	ADD R2, R2, R3 	;; R2 <-- A[length] - B[length]

	BRnz NOT_POSITIVE
	AND R3, R3, #0 	;; clear R3
	BR ENDIF

	NOT_POSITIVE
	AND R3, R3, #0 	;; clear R3
	ADD R3, R3, #1 	;; R3 <- 0 + 1
	BR ENDIF

	ENDIF
	LEA R4, C 		;; R4 <- addr of C
	LDR R4, R4, #0 	;; R4 <- addr of C[0]
	ADD R4, R4, R1
	STR R3, R4, #0

	ADD R1, R1, #1	;; i++
	ADD R0, R0, #-1	;; length--

	BRzp LOOP
	HALT

;; Do not change these addresses! 
;; We populate A and B and reserve space for C at these specific addresses in the orig statements below.
A 		.fill x3200		
B 		.fill x3300		
C 		.fill x3400		
LENGTH 	.fill 3			;; Change this value if you decide to increase the size of the arrays below.
.end

;; Do not change any of the .orig lines!
;; If you decide to add more values for debugging, make sure to adjust LENGTH and .blkw 3 accordingly.
.orig x3200				;; Array A : Feel free to change or add values for debugging.
	.fill -4
	.fill 6
	.fill 0
.end

.orig x3300				;; Array B : Feel free change or add values for debugging.
	.fill 1
	.fill 5
	.fill 2
.end

.orig x3400
	.blkw 3				;; Array C: Make sure to increase block size if you've added more values to Arrays A and B!
.end