;;=============================================================
;; CS 2110 - Summer 2023
;; Homework 5 - modulus
;;=============================================================
;; Name: 
;;=============================================================

;;  Pseudocode (see PDF for explanation)
;;  Pseudocode values are based on the labels' default values.
;;
;;  int x = 14;
;;  int mod = 3;
;;  while (x >= mod) {
;;      x -= mod;
;;  }
;;  mem[ANSWER] = x;

.orig x3000
    ;; YOUR CODE HERE
    HALT

    ;; Feel free to change the below values for debugging. We will vary these values when testing your code.
    X      .fill 14
    MOD    .fill 3     
    ANSWER .blkw 1
.end