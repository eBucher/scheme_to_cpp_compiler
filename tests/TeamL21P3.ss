; Tests OR

(define (main)
	(if (or (list? '2) (zero? 7))
 		(display 'one_part_is_true)
		(display 'its_all_false)
	)
)
