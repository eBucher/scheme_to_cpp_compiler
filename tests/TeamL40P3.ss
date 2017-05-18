;Tests various rules

(define (do_stuff a b c d e)
  (if (< (- (+ a b c d e) (* 2 9 (/ 1 9)) 90) 910)
   	(if (not (string? (+ a (- b 1))))
	  (display 'stuff_happened)
	  (display '(1 2 3 4 5))

  	)
  )
)

(define (get_second L)
  	(if (not (list? L))
    		(display 'that_aint_no_list)
    		(if (number? (car (cdr L)))
			(car (cdr L))
			(display 'that_aint_no_numbah)
		)
	)
)

(define (main)
  (if (> (get_second '(1 2 3 4 5 6 7 8 9)) 3)
    	(do_stuff 5 6 7 8 9)
	5
  )
  (newline)
)

