;;=======================================
;; CS 2110 - Summer 2022
;; Final Exam - Modulo
;;=======================================
;; Name:
;;=======================================
.orig x3000
HALT

mod
;; See the PDF for more information on what this subroutine should do.
;;
;; Arguments of mod: integer a, positive integer b
;;
;; Pseudocode:
;; 
;; mod(a, b) {
;;     if (a < 0) {
;;         return mod(a + b, b);
;;     }
;;
;;     if (a - b < 0) {
;;         return a;
;;     }
;;
;;     return mod(a - b, b);
;; }
;;

    ;; stack setup
    ADD R6, R6, #-4
    STR R7, R6, #2 
    STR R5, R6, #1 
    ADD R5, R6, #0 

    ADD R6, R6, #-5
    STR R0, R6, #0
    STR R1, R6, #1
    STR R2, R6, #2
    STR R3, R6, #3
    STR R4, R6, #4
    ;; YOUR CODE HERE

    LDR R0, R5, #4
    ADD R0, R0, #0
    BRn NEGATIVE_CASE
    ;;
    LDR R0, R5, #4
    LDR R1, R5, #5
    NOT R1, R1
    ADD R1, R1, #1
    ADD R0, R0, R1 ;; R0 = a - b
    BRn LESS_CASE
    BR ELSE_CASE
    ;; a < 0
    NEGATIVE_CASE
    LDR R0, R5, #4
    LDR R1, R5, #5
    ADD R0, R0, R1
    ADD R6, R6, #-2
    STR R0, R6, #0
    STR R1, R6, #1
    JSR mod
    LDR R2, R6, #0
    ADD R6, R6, #3
    STR R2, R5, #3
    BR TEARDOWN
    ;; a < b => a - b < 0
    LESS_CASE
    LDR R0, R5, #4
    STR R0, R5, #3
    BR TEARDOWN

    ELSE_CASE
    LDR R0, R5, #4
    LDR R1, R5, #5
    NOT R1, R1
    ADD R1, R1, #1
    ADD R0, R0, R1
    LDR R1, R5, #5
    
    ADD R6, R6, #-2
    STR R0, R6, #0
    STR R1, R6, #1
    JSR mod
    LDR R2, R6, #0
    ADD R6, R6, #3
    STR R2, R5, #3
    BR TEARDOWN

    TEARDOWN
    LDR R0, R6, #0
    LDR R1, R6, #1
    LDR R2, R6, #2
    LDR R3, R6, #3
    LDR R4, R6, #4
    ;;
    ADD R6, R5, #0
    LDR R5, R6, #1
    LDR R7, R6, #2
    ADD R6, R6, #3
RET

;; Needed by Simulate Subroutine Call in Complx
STACK .fill xF000
.end


; .orig x3000
; HALT

; mod
; ;; See the PDF for more information on what this subroutine should do.
; ;;
; ;; Arguments of mod: integer a, positive integer b
; ;;
; ;; Pseudocode:
; ;; 
; ;; mod(a, b) {
; ;;     if (a < 0) {
; ;;         return mod(a + b, b);
; ;;     }
; ;;
; ;;     if (a < b) {
; ;;         return a;
; ;;     }
; ;;
; ;;     return mod(a - b, b);
; ;; }
; ;;

;     ;; stack setup
;     ADD R6, R6, #-4
;     STR R7, R6, #2 
;     STR R5, R6, #1 
;     ADD R5, R6, #0 
;     ADD R6, R6, #-5
;     STR R0, R6, #4
;     STR R1, R6, #3
;     STR R2, R6, #2
;     STR R3, R6, #1
;     STR R4, R6, #0

;     LDR R0, R5, #4 ; R0 = a
;     LDR R1, R5, #5 ; R1 = b

;     ADD R0, R0, #0 ; set CC on a
;     BRn CASE1

;     NOT R2, R1
;     ADD R2, R2, #1 ; R2 = -b
;     ADD R2, R2, R0 ; R2 = a - b
;     BRn CASE2
;     BR CASE3

;     CASE1
;     ADD R3, R0, R1 ; R3 = a + b
;     ADD R6, R6, #-2
;     STR R1, R6, #1 ; push b
;     STR R3, R6, #0 ; push a + b
;     JSR mod ; call mod(a + b, b)
;     LDR R4, R6, #0 ; R4 = mod(a + b, b)
;     ADD R6, R6, #3
;     BR RETURN

;     CASE2
;     ADD R4, R0, #0 ; R4 = a
;     BR RETURN

;     CASE3
;     ADD R6, R6, #-2
;     STR R1, R6, #1 ; push b
;     STR R2, R6, #0 ; push a - b
;     JSR mod ; call mod(a - b, b)
;     LDR R4, R6, #0 ; R4 = mod(a - b, b)
;     ADD R6, R6, #3

;     RETURN
;     STR R4, R5, #3 ; return R4

;     TEARDOWN
;         LDR R4, R6, #0
;         LDR R3, R6, #1
;         LDR R2, R6, #2
;         LDR R1, R6, #3
;         LDR R0, R6, #4
;         ADD R6, R5, #0
;         LDR R5, R6, #1
;         LDR R7, R6, #2
;         ADD R6, R6, #3
; RET

; ;; Needed by Simulate Subroutine Call in Complx
; STACK .fill xF000
; .end