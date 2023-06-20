;;=============================================================
;; CS 2110 - Summer 2023
;; Homework 5 - octalStringToInt
;;=============================================================
;; Name: Vy Mai
;;=============================================================

;;  Pseudocode (see PDF for explanation)
;;  Pseudocode values are based on the labels' default values.
;;
;;  String octalString = "2023";
;;  int length = 4;
;;  int value = 0;
;;  int i = 0;
;;  while (i < length) { ;; while (length - i > 0)
;;      MANUAL BLOCK
;;      value += value;
;;      value += value;
;;      value += value; 
;;      // END MANUAL
;;      int digit = octalString[i] - 48;
;;      value += digit;
;;      i++;
;;  }
;;  mem[mem[RESULTADDR]] = value;

.orig x3000
    ;; YOUR CODE HERE
    ;; R0 = length
    ;; R1 = negative length
    ;; The intention is to have R0 - R1 = 0,1,2,3 by increasing R1 from -4 -> 0
    ;; This makes the looping condition easy.
    
    LD R0, LENGTH
    NOT R1, R0
    ADD R1, R1, #1
    AND R4, R4, #0
    LD R3, ASCII
    LOOP
    ADD R4, R4, R4
    ADD R4, R4, R4
    ADD R4, R4, R4
    LD R2, OCTALSTRING
    ADD R2, R2, R0
    ADD R2, R2, R1
    LDR R2, R2, #0
    ADD R2, R2, R3
    ADD R4, R4, R2
    ADD R1, R1, #1
    BRn LOOP
    STI R4, RESULTADDR
    TRAP x25


;; Do not change these values! 
;; Notice we wrote some values in hex this time. Maybe those values should be treated as addresses?
RESULTADDR      .fill x4000
ASCII           .fill -48
OCTALSTRING     .fill x5000
LENGTH          .fill 4

;;
.end

.orig x5000                    ;;  Don't change the .orig statement
    .stringz "2023"            ;;  You can change this string for debugging!
.end
