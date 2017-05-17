; Tests AND with more than 2 arguments

(define (main)
	(if (and (null? '()) (list? '1) (list? '()))
		(display 'all_parts_are_true)
		(display 'something_is_false)
	)
	(newline)
)
