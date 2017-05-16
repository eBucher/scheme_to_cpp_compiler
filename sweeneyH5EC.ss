;l Author: Matthew Sweeney
; File: sweeneyH5.ss
; Date: 4/26/17
; CS 460 Homework 5 


; 17
; Creates a copy of the elements in the odd numbered positions in a list 
; starting with the first element of the list.
(define (odd_copy mylist)
	(if (null? mylist) 
		'()
		(cons (car mylist) 
			(if (null? (cdr mylist))
				'()
				(odd_copy (cdr (cdr mylist)))
			)
		)
	)	
)

; 18
; Creates a copy of the elements in the odd numbered positions in a list 
; starting with the secondelement of the list.
(define (even_copy mylist)
	(if (null? mylist) 
		'()
		(cdr (cons (car mylist) 
			(if (null? (cdr mylist))
				'()
				(odd_copy (cdr mylist))
			)
		))
	)	
)



(define (merge L1 L2)
	(if (null? L1)
		L2
		(if (null? L2)
			L2
			(if (> (car L1) (car L2))
				(cons (car L1) (merge (cdr L1) L2))
				(cons (car L2) (merge (cdr L2) L1))
			)
		)
	)
)

(define (mergesort L)
	(if (or (null? L) (null? (cdr L)))
		L
		(merge (mergesort  (odd_copy L)) (mergesort (even_copy L)))
	)
)

(define (less_than pivot L)
  	(if (null? L)	
		L
		(if (< (car L) pivot)
		 	(cons (car L) (less_than pivot (cdr L)))
			(less_than pivot (cdr L))
		)
	)
)
(define (equal_to pivot L)
  	(if (null? L)	
		L
		(if (= (car L) pivot)
		 	(cons (car L) (equal_to pivot (cdr L)))
			(equal_to pivot (cdr L))
		)
	)
)
(define (greater_than pivot L)
  	(if (null? L)	
		L
		(if (> (car L) pivot)
		 	(cons (car L) (greater_than pivot (cdr L)))
			(greater_than pivot (cdr L))
		)
	)
)

(define (comb_helper L1 L2)
  	(if (null? L1)
	 	L2
		(cons (car L1) (comb_helper (cdr L1) L2))
	)
)

(define (combine L1 L2 L3)

  (comb_helper (comb_helper L1 L2) L3)
)

(define (qs L)
  	(if (null? L)	
	 	L
		(combine 	(qs (less_than (car L) (cdr L)))
		    		(equal_to (car L)  L)
		    		(qs (greater_than (car L) (cdr L)))
		)
	)
)

(define (numeric_copy L)
	(if (null? L)
	 	L
		(if (number? (car L))
			(cons (car L) (numeric_copy (cdr L)))
			(numeric_copy (cdr L))
		)
	)
)

(define (quicksort L)
  	(if (list? L)
	  	(qs (numeric_copy L))
		'enter_a_list
	)
)
