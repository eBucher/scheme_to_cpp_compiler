; Tests the 'not' keyword.
(define (main)
	(if (not (null? '()))
		(display 'that_list_has_something_in_it)
		(display 'that_list_is_empty)
	)
)
