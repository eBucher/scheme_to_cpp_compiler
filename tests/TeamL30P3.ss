; Tests embedded arithmetic operations,
; function calls, and listops.

(define (getThird myList) ;Gets the third element in myList
	(if (or (null? myList) (null? (cdr myList)) (null? (cdr (cdr myList))))
		'()
		(car (cdr (cdr myList)))
	)
)

(define (firsts list1 list2)
	(cons (car list1) (cons (car list2) '()))
)

(define (main)
	(if (< (car (firsts '(1 2 3 4 5) '(6 7 8 9 10)))  (+ 1 2 2 (* 0 8 9 (/ 6 2))))
		(display 'the_first_value_is_greater_than_5)
		(display 'the_first_value_is_not_greater_than_5)
	)
	(newline)
)
