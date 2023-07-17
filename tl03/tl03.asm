;; Timed Lab 3, Summer 2023
;; For this Timed Lab, you will be given a binary tree.
;; Your task will be to modify the tree by making the appropriate subroutine calls.
;; Specific instructions provided in tl03.pdf


.orig x3000
	HALT

;; FIBONACCI subroutine
;;
;; Pseudocode
;;
;; FIBONACCI(int num) {
;; 	   if (num <= 1) {
;; 		   return num;
;; 	   } else {
;; 		   int a = FIBONACCI(num - 1);
;; 		   int b = FIBONACCI(num - 2);
;; 		   return a + b;
;; 	   }
;; }
; @SUBROUTINE
FIBONACCI
	;; todo
	ADD R6, R6, #-4 ;; Make space for RV, RA, old FP, LV1
    STR R7, R6, #2 ;; Save return address
    STR R5, R6, #1 ;; Save original frame pointer
    ADD R5, R6, #0 ;; New frame pointer for this subroutine

    ADD R6, R6, #-5 ;; SET X TO -4 - NUM LVs OR -5 IF NO LVs
    STR R0, R6, #0
    STR R1, R6, #1
    STR R2, R6, #2
    STR R3, R6, #3
    STR R4, R6, #4

	;; subroutine starts
	LDR R0, R5, #4 ;; R0 = num;
	ADD R0, R0, #-1 ;; if R0 - 1 <= 0; return num;
	BRp FIB_ELSE
	LDR R0, R5, #4
	STR R0, R5, #3
	BR FIB_TEARDOWN
	FIB_ELSE
	LDR R0, R5, #4
	ADD R0, R0, #-1 
	ADD R6, R6, #-1
	STR R0, R6, #0
	JSR FIBONACCI  ;; int a = FIBONACCI(num - 1);
	LDR R1, R6, #0 ;; R1 = a;
	ADD R6, R6, #2 ;; reset R6.
	;; second recursive call
	ADD R0, R0, #-1 
	ADD R6, R6, #-1
	STR R0, R6, #0 
	JSR FIBONACCI ;; int b = FIBONACCI(num - 2);
	LDR R2, R6, #0 ;; R2 = b;
	ADD R6, R6, #2
	ADD R1, R1, R2 ;; a += b;
	STR R1, R5, #3 ;; return a + b;
	BR FIB_TEARDOWN
	;; subroutine ends
	FIB_TEARDOWN

    LDR R0, R6, #0
    LDR R1, R6, #1
    LDR R2, R6, #2
    LDR R3, R6, #3
    LDR R4, R6, #4
    
    ADD R6, R5, #0
    LDR R5, R6, #1
    LDR R7, R6, #2
    ADD R6, R6, #3
	RET

;; ADDALL subroutine
;;
;; Pseudocode
;;
;; ADDALL(int num) {
;;     int sum = 0;
;; 	
;;     for (int i = 1; i - num <= 0; i++) {
;; 	       sum = sum + i;
;; 	   }
;;	 alternative int i = 1; while (i - num <= 0){ sum += i; i++;}
;; 	
;; 	   return sum;
;; }
; @SUBROUTINE
ADDALL
	;; todo
	ADD R6, R6, #-4 ;; Make space for RV, RA, old FP, LV1
    STR R7, R6, #2 ;; Save return address
    STR R5, R6, #1 ;; Save original frame pointer
    ADD R5, R6, #0 ;; New frame pointer for this subroutine

    ADD R6, R6, #-5 ;; SET X TO -4 - NUM LVs OR -5 IF NO LVs
    STR R0, R6, #0
    STR R1, R6, #1
    STR R2, R6, #2
    STR R3, R6, #3
    STR R4, R6, #4

	;; subroutine starts
	AND R0, R0, #0 ;; R0 = sum;
	LDR R1, R5, #4 ;; R1 = num;
	BRnz ADD_NEGATIVE_NUM
	AND R2, R2, #0
	ADD R2, R2, #1 ;; R2 = i; i = 1;
	NOT R3, R1
	ADD R3, R3, #1 ;; R3 = negative num;
	ADD_LOOP
	ADD R0, R0, R2
	ADD R2, R2, #1 ;; i++
	ADD R4, R2, R3 ;; i - num;
	BRnz ADD_LOOP
	BR ADD_LOOP_ENDS

	ADD_NEGATIVE_NUM
	AND R0, R0, #0
	STR R0, R5, #3
	BR ADD_ALL_TEARDOWN

	ADD_LOOP_ENDS
	STR R0, R5, #3
	BR ADD_ALL_TEARDOWN
	;; subroutine ends

	ADD_ALL_TEARDOWN
    LDR R0, R6, #0
    LDR R1, R6, #1
    LDR R2, R6, #2
    LDR R3, R6, #3
    LDR R4, R6, #4
    
    ADD R6, R5, #0
    LDR R5, R6, #1
    LDR R7, R6, #2
    ADD R6, R6, #3
	RET

;; CHANGETREE subroutine
;;
;; Pseudocode
;;
;; CHANGETREE(Node node (address)) {
;; 	   if (node == 0) {
;; 		   return -1;
;; 	   }
;; 	
;; 	   int data = mem[node];
;; 	
;; 	   if (data % 2 == 0) {
;; 		   mem[node] = FIBONACCI(data);
;; 	   } else {
;; 		   mem[node] = ADDALL(data);
;; 	   }
;; 	
;; 	   Node left = mem[node + 1];
;; 	   CHANGETREE(left);
;; 	
;; 	   Node right = mem[node + 2];
;; 	   CHANGETREE(right);
;; 	
;; 	   return 0;
;; }

; @SUBROUTINE
CHANGETREE
		;; todo
	ADD R6, R6, #-4 ;; Make space for RV, RA, old FP, LV1
    STR R7, R6, #2 ;; Save return address
    STR R5, R6, #1 ;; Save original frame pointer
    ADD R5, R6, #0 ;; New frame pointer for this subroutine

    ADD R6, R6, #-5 ;; SET X TO -4 - NUM LVs OR -5 IF NO LVs
    STR R0, R6, #0
    STR R1, R6, #1
    STR R2, R6, #2
    STR R3, R6, #3
    STR R4, R6, #4

	;; subroutine starts
	LDR R0, R5, #4
	BRz NO_CHILDREN
	LDR R1, R0, #0 ;; R1 = data = mem[node];

	AND R1, R1, #1
	BRz FIB_CASE
	BR ADD_ALL_CASE

	FIB_CASE
	LDR R1, R0, #0
	ADD R6, R6, #-1;
	STR R1, R6, #0 ;; pushing R1 (data value) onto stack
	JSR FIBONACCI
	LDR R2, R6, #0 ;; return of FIBONACCI
	ADD R6, R6, #2
	STR R2, R0, #0 ;; mem[node] = FIB
	BR LEFT_NODE

	ADD_ALL_CASE
	LDR R1, R0, #0
	ADD R6, R6, #-1
	STR R1, R6, #0
	JSR ADDALL
	LDR R2, R6, #0
	ADD R6, R6, #2
	STR R2, R0, #0
	BR LEFT_NODE

	NO_CHILDREN
	AND R0, R0, #0
	ADD R0, R0, #-1
	STR R0, R5, #3
	BR CHG_TEARDOWN


	LEFT_NODE
	LDR R0, R5, #4
	LDR R0, R0, #1 ;; Node left = mem[node + 1];
	ADD R6, R6, #-1
	STR R0, R6, #0
	JSR CHANGETREE
	ADD R6, R6, #2
	RIGHT_NODE
	LDR R0, R5, #4
	LDR R0, R0, #2 ;; Node right = mem[node + 2];
	ADD R6, R6, #-1
	STR R0, R6, #0
	JSR CHANGETREE
	ADD R6, R6, #2
	;; subroutine ends

	AND R4, R4, #0
	STR R4, R5, #3

	CHG_TEARDOWN
	LDR R0, R6, #0
    LDR R1, R6, #1
    LDR R2, R6, #2
    LDR R3, R6, #3
    LDR R4, R6, #4
    
    ADD R6, R5, #0
    LDR R5, R6, #1
    LDR R7, R6, #2
    ADD R6, R6, #3
	RET
.end