; Tests listop calls: car, cdr, cddr, cadddr

(define (main)
	(display (car '(alpha beta gamma delta)))
	(newline)
	(display (cdr '(the time has come the walrus said)))
	(newline)
	(display (cddr '(one 2 three 4)))
	(newline)
	(display (cadddr '(charlie lucy snoopy pig schroeder linus woodstock)))
	(newline)
)
