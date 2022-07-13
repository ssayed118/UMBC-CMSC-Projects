;Sumaa Sayed - ssayed1@umbc.edu - CMSC331 - Homework 4

#lang racket
(require racket/trace)
(define record '(("Course" "Credits" "Grade")
                 ("CMSC 299" 2 "P")
                 ("CMSC 331" 3 87)
                 ("CMSC 341" 3 100)
                 ("CHEM 201" 4 "Incomplete")
                 ("PHYS 201" 4 77)
                 ("CMSC 491" "error" 100)))

#|Implement your functions here|#

(define(gpa record)
 (~r #:precision '(= 2) (/ (sum-of-grades record) (sum-of-credits record))))

(define(sum-of-grades record)
  (cond [(empty? record) 0]
        ;[not(number? (and (car (cdr (first record))) (car (cdr (cdr (first record)))))) (+ 0 (sum-of-grades (rest record)))]
      ;  [(not (number? (car (cdr (first record))))) (+ (car (cdr (cdr (first record)))) (sum-of-grades (rest record)))]
        [(not (number? (car (cdr (cdr (first record)))))) (+ 0 (sum-of-grades (rest record)))]
        [(not (number? (car (cdr (first record)))))  (+ (car (cdr (cdr (first record)))) (sum-of-grades (rest record)))]
        
         [(not (number? (car (cdr (cdr (first record)))))) (+ (car (cdr (first record))) (sum-of-grades (rest record)))]
         
        ;[(not (number? (car (cdr (first record)))))  (+ (car (cdr (cdr (first record)))) (sum-of-grades (rest record)))]
        ;[else (+ (* (sum-of-grades (rest record)) (sum-of-credits (rest record))) (car (cdr (cdr (first record)))))]
        ;[not(number? (and (car (cdr (first record))) (car (cdr (cdr (first record)))))) (sum-of-grades (rest record))]
        [else (+ (* (car (cdr (cdr (first record)))) (car (cdr (first record)))) (sum-of-grades (rest record)))]
     ;   [else (+ (* (car (cdr (cdr (first record)))) (sum-of-credits(record))) (sum-of-grades (rest record)))]
   ))

(define(sum-of-credits record)
  (cond [(empty? record) 0]
        [(not(number? (car (cdr (first record))))) (+ 0 (sum-of-credits (rest record)))]
        [else (+ (car (cdr (first record))) (sum-of-credits (rest record)))]
   ))

(gpa record)