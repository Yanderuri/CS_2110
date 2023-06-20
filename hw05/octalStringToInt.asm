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
;;  while (i < length) { ;; while (i - length < 0)


;;      int leftShifts = 3;
;;      while (leftShifts > 0) {
;;          value += value;
;;          leftShifts--;


;;      } // MANUAL BLOCK
;;      value += value;
;;      value += value;
;;      value += value; // END MANUAL


;;      int digit = octalString[i] - 48;
;;      value += digit;
;;      i++;
;;  }
;;  mem[mem[RESULTADDR]] = value;

.orig x3000
    ;; YOUR CODE HERE
    ;; R0 = answer
    ;; R1 = current char

    ;; R4 = temp register for storing/reading from memory
    
    HALT

;; Do not change these values! 
;; Notice we wrote some values in hex this time. Maybe those values should be treated as addresses?
ASCII           .fill -48
OCTALSTRING     .fill x5000
LENGTH          .fill 4
RESULTADDR      .fill x4000

CURRENT_CHAR    .blkw 1
NEG_LENGTH      .blkw 1
;;
.end

.orig x5000                    ;;  Don't change the .orig statement
    .stringz "2023"            ;;  You can change this string for debugging!
.end
