; Tests AND

(define (main)
	(if (and (list? '2) (zero? 7))
 		(display 'both_parts_are_true)
		(display 'something_is_false)
	)
)
