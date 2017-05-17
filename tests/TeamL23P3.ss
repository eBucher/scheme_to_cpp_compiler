; Tests or with more than 2 arguments

(define (main)
	(if (or (null? '()) (list? '1) (list? '()))
		(display 'something_is_true)
		(display 'all_parts_are_false)
	)
	(newline)
)
