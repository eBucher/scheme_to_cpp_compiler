; Tests rule 72:
; <any_other_token> -> QUOTE_T <any_other_token>
; Right now this may not be working properly because
; we don't know what the output is supposed to look
; like.

(define (main)
	(display ''not)
	(display '('one 'two 'three))
)
